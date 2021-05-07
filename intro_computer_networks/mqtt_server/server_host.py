#!/usr/bin/env python3
import os
import socket
import threading
import client
import database

HOST = '127.0.0.1'
PORT = 8000
SRTMSG = 16
TYPE_SIZE = 16
TOPIC_SIZE = 64
DATA_SIZE = 1024
database = database.Database()
# client_id is the index in clients
clients = []
server_threads = []
'''
This server_host uses a self-serve model where servants are dispatched when a new client connects.
Servants access a communal pool of resources that include a client pool and a database of all
topics.
'''


def notify(topic, contents):
    """
    This method needs to tell all clients that 'topic' has been updated
    If the 'topic' in question is in the client's subscriptions, then they
    print out the new message
    """
    # send to all clients
    for _client in clients:
        if _client.notify(topic):
            _client.getSock().send(contents.encode("utf-8"))


def server_thread(listen_conn, broadcast_conn, listen_addr, broadcast_addr, push_conn, push_addr, client_id):
    """
    server thread to serve clients
    listens for commands from the client and carries them out
    """
    global database
    global clients
    _client = client.Client(listen_conn, broadcast_conn,
                            listen_addr, broadcast_addr, push_conn, push_addr)
    clients.append(_client)
    while True:
        with listen_conn and broadcast_conn:
            print('Connected by', listen_addr)
            print('alternatively, ', broadcast_addr)
            while True:
                # check for updated messages, this should happen before receiving
                # should be split into data[0]@data[1]@data[2]
                # where data[0] is the command (CONN, DISC, etc.), data[1] is the topic, data[2] is the contents
                data = listen_conn.recv(DATA_SIZE).decode("utf-8").split("@")
                data[0] = data[0].upper()
                print("client: ", data)
                if not data:
                    break
                if data[0] == "CONNECT":
                    # send ACK
                    broadcast_conn.send(
                        "CONNACK".encode("utf-8"))
                elif data[0] == "DISCONNECT":
                    # send ACK
                    broadcast_conn.send("DISCACK".encode("utf-8"))
                    response = listen_conn.recv(SRTMSG).decode("utf-8")
                    print("client: " + response)

                    if response == "DISCACK":
                        listen_conn.shutdown(socket.SHUT_RDWR)
                        listen_conn.close()
                        broadcast_conn.shutdown(socket.SHUT_RDWR)
                        broadcast_conn.close()
                        # "break" is essentially where the server full shuts down for that client
                        break
                elif data[0] == "PUBLISH":
                    # only proceed if there is topic and contents
                    if len(data) == 3:
                        topic = data[1]
                        contents = data[2]
                        # subscribe the publisher to the topic
                        _client.subscribe(topic)
                        # notify all subscribers
                        notify(topic, contents)
                        broadcast_conn.send("PUBACK".encode("utf-8"))
                    elif len(data) == 4:
                        topic = data[1]
                        contents = data[2]
                        database.publish(topic, contents)
                        # subscribe the publisher to the topic
                        _client.subscribe(topic)
                        # notify all subscribers
                        notify(topic, contents)
                        broadcast_conn.send("PUBACK".encode("utf-8"))
                    else:
                        broadcast_conn.send("PUBFAIL".encode("utf-8"))
                elif data[0] == "SUBSCRIBE":
                    # adds the topic to the client's profile
                    _client.subscribe(data[1])
                    # need to account for wildcard

                    # immediately allow the subscriber to have the latest message
                    path = data[1].split("/")
                    db = database.getDatabase()
                    db_lag = db
                    msg = ""
                    for t in path:
                        db_lag = db
                        if t == "*" or t == "+":
                            t = list(db.keys())[0]
                        msg = db[t][1]
                        db = db[t][0]
                    push_conn.send(msg.encode("utf-8"))
                    broadcast_conn.send("SUBACK".encode("utf-8"))
                elif data[0] == "UNSUBSCRIBE":
                    _client.unsubscribe(data[1])
                    # need to account for wildcard
                    broadcast_conn.send("UNSUBACK".encode("utf-8"))
                elif data[0] == "LIST":
                    print(database)
                    broadcast_conn.send("LIST".encode("utf-8"))
                    print(str(database))
                    broadcast_conn.send(str(database).encode("utf-8"))
                else:
                    # send ACK
                    broadcast_conn.send(
                        "invalid type".encode("utf-8"))
                    print("invalid type")


def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        # Bind the socket to the IP address and port number
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        s.bind((HOST, PORT))
        s.listen()
        client_id = 0
        while True:
            listen_conn, listen_addr = s.accept()
            broadcast_conn, broadcast_addr = s.accept()
            push_conn, push_addr = s.accept()

            # multithreading code
            t = threading.Thread(target=server_thread, args=(
                listen_conn, broadcast_conn, listen_addr, broadcast_addr, push_conn, push_addr, client_id,))
            server_threads.append(t)
            t.start()

        # in case of graceful termination, create loop end condition so that joining
        # can happen
        for t in server_threads:
            t.join()


if __name__ == "__main__":
    main()

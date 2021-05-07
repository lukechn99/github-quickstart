import socket
import database
import threading

# IP and port used by server's accepting connection
HOST = '127.0.0.1'
PORT = 8000
SRTMSG = 8
DICT = 1000

"""
CONNECT: clients send <CONN> after socket connection to confirm and will
receive a <CONN_ACK> back from the server

DISCONNECT: clients send <DISC> when it wants to disconnect and waits for
server to send <DISC_ACK> before disconnecting
<CONN>, <CONN_ACK>, <DISC>, and <DISC_ACK> are all message types that do
not have data associated

PUBLISH: Clients send <PUB, TOPIC, MSG>

SUBSCRIBE: Clients can send request to subscribe to 
topics they are interested in.
Client: <SUB, TOPIC>

We may need to split a message if it is too big. We will need some way for
the receiver to know that continued messages are together. 
"""


def acceptPush(push):
    while True:
        incoming = push.recv(1000).decode("utf-8")
        if incoming != "":
            print('\r' + incoming)


def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as o:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as i:
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as push:
                o.connect((HOST, PORT))
                i.connect((HOST, PORT))
                push.connect((HOST, PORT))
                push_thread = threading.Thread(target=acceptPush, args=(push,))
                push_thread.start()
                while True:
                    data = input(
                        "enter with format <type@topic@contents@flag>: ")
                    o.send(data.encode("utf-8"))
                    print("client message sent")
                    response = i.recv(SRTMSG).decode("utf-8")
                    print("server: " + response)
                    if response == "DISCACK":
                        o.send("DISCACK".encode("utf-8"))
                        break
                    if response == "LIST":
                        # for the list function, we need to potentially break it down
                        # and send chunk by chunk
                        print(i.recv(DICT).decode("utf-8"))
                push_thread.join()


if __name__ == "__main__":
    main()

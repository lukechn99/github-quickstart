import socket
import database


class Client:
    def __init__(self, listen_conn, broadcast_conn,
                 listen_addr, broadcast_addr, push_conn, push_addr):
        self.client_listen_conn = listen_conn
        self.client_listen_addr = listen_addr
        self.client_broadcast_conn = broadcast_conn
        self.client_broadcast_addr = broadcast_addr
        self.push = push_conn
        self.addr = push_addr
        self.topics = {}

    def addTopic(self, topic):
        self.topics[topic] = {}

    def getTopics(self):
        return self.topics

    def getSock(self):
        return self.push

    def getAddr(self):
        return self.client_broadcast_addr

    def subscribe(self, topic):
        # check validity of the topic string
        path = topic.split("/")
        for i in range(len(path)):
            # there is a wild card in the wrong place
            if path[i] == "#" and i != len(path) - 1:
                return False
            # we can check for other invalidities with a for loop

        topic_level = self.topics
        last_level = topic_level
        for t in path:
            if t in topic_level:
                topic_level = topic_level[t][0]
            else:
                if t == path[-1]:
                    topic_level[t] = [{}, 1]
                topic_level[t] = [{}, 0]
                last_level = topic_level
                topic_level = topic_level[t][0]
        print("current subs: " + str(self.topics))
        return True

    def unsubscribe(self, topic):
        '''
        Goes through topic tree to decrement or eliminate fully the topic
        '''
        # consider the case where we unsubscribe
        path = topic.split("/")
        topic_level = self.topics
        # last sub looks for a '1' inside of
        last_sub = topic_level
        for t in path:
            topic_level = topic_level[t]
            if topic_level[t][1] == 1:
                last_sub = topic_level
        # if the topic level is not the highest level then that means there
        # is a higher level subscription. In this case, just remove the 1

        # if topic level is the highest level, then erase subscriptions beyond
        # last_sub
        return True
        return False

    def notify(self, topic):
        path = topic.split("/")
        topic_level = self.topics
        for t in path:
            if t in topic_level:
                topic_level = topic_level[t][0]
            elif "*" in topic_level:
                topic_level = topic_level["*"][0]
            elif "+" in topic_level:
                topic_level = topic_level["+"][0]
            else:
                return False
        return True

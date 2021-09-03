class Database:
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

    def __init__(self):
        self._database = {'weather': [{}, ''], 'news': [
            {}, ''], 'health': [{}, ''], 'security': [{}, '']}

    def publish(self, topic, message):
        path = topic.split("/")
        topic_level = self._database
        last_level = topic_level
        for t in path:
            if t in topic_level:
                topic_level = topic_level[t][0]
            else:
                topic_level[t] = [{}, ""]
                last_level = topic_level
                topic_level = topic_level[t][0]
        last_level[t][1] = message

    def __str__(self):
        return str(self._database)

    def getDatabase(self):
        return self._database


# data = Database()
# data.publish("weather", "weather is good")
# data.publish("weather/temperature", "98.0F")
# data.publish("news", "gunshots in downtown")
# data.publish("sports", "olympics coming up")
# data.publish("sports/soccer", "Manchester wins")
# print(data.getDatabase())

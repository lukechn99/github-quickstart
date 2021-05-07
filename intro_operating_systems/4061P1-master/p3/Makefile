CC = gcc
CFLAGS = -D_REENTRANT -g -Og
LDFLAGS = -lpthread -pthread

web_server: server.c
	${CC} ${CFLAGS} -Wall -o web_server server.c util.o ${LDFLAGS}

clean:
	rm web_server webserver_log

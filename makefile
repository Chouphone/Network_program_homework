CC = g++
LIBPATH = ./linklib
all:
	$(CC) -c -o $(LIBPATH)/connectsock.o connectsock.cpp 
	$(CC) -o TCPECHO TCPecho.cpp $(LIBPATH)/connectsock.o

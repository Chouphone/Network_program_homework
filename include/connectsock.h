#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#ifndef CONNECTSOCK_H
#define CONNECTSOCK_H
#ifndef	INADDR_NONE
#define	INADDR_NONE	0xffffffff
#endif	/* INADDR_NONE */
//using two inline method 

int	errexit(const char *format, ...);//output errormessage &exit

//int _connectsock(const char *host, const char *service, const char *transport );

//
/*int _connectTCP(const char *host, const char *service ){
	return _connectsock( host, service, "tcp");
}

int _connectUDP(const char *host, const char *service ){
	return _connectsock(host, service, "udp");
}*/
int _connectTCP(const char *host, const char *service );
int _connectUDP(const char *host, const char *service );
#endif

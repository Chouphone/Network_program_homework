#include "./include/connectsock.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int TCPecho(const char *host, const char *service);
#define LINELEN 128//buffer length
int main(int argc, char* argv[])
{
    char* host = (char *)"localhost";
    char* service = (char *)"echo";	
    //connect to local & use echo default 
    
	switch (argc) {
	case 1:
		host = "localhost";
		break;
	case 3:
		service = argv[2];
		/* FALL THROUGH */
	case 2:
		host = argv[1];
		break;
	default:
		fprintf(stderr, "usage: TCPecho [host [port]]\n");
		exit(1);
	}
    printf("connect to host:%s\n",host);
	TCPecho(host, service);
    return 0;
}

int TCPecho(const char *host, const char *service){
    char	buf[LINELEN + 1];		/* buffer for one line of text	*/
	int	s, n;			/* socket descriptor, read count*/
	int	outchars, inchars;	/* characters sent and received	*/

	s = _connectTCP(host, service);

	while (fgets(buf, sizeof(buf), stdin)) {
		buf[LINELEN] = '\0';	/* insure line null-terminated	*/
		outchars = strlen(buf);
		(void) write(s, buf, outchars);

		/* read it back */
		for (inchars = 0; inchars < outchars; inchars+=n ) {
			n = read(s, &buf[inchars], outchars - inchars);
			if (n < 0)
				errexit("socket read failed: %s\n",
				strerror(errno));
		}
		fputs(buf, stdout);
	}
}

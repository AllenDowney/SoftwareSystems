#include	"unp.h"

char *reply = "HTTP/1.0 200 OK\r\n"
    "\r\n"
    "<body>1111</body>\r\n"
    "\r\n";

void handle_request(int sockfd)
{
    ssize_t n;
    char line[MAXLINE];

    n = Readline(sockfd, line, MAXLINE);
    if (n == 0) {
	return;
    }
    printf("Received %s\n", line);

    printf("Sending %s\n", reply);
    n = strlen(reply);
    Writen(sockfd, reply, n);
}

int main(int argc, char **argv)
{
    int	listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family      = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port        = htons(8081);

    Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);
    printf("Listening\n");

    for ( ; ; ) {
	clilen = sizeof(cliaddr);
	connfd = Accept(listenfd, (SA *) &cliaddr, &clilen);
	printf("Accepted\n");
	
	if ( (childpid = Fork()) == 0) {
	    printf("Forked\n");
	    Close(listenfd);
	    handle_request(connfd);
	    exit(0);
	}
	Close(connfd);
    }
}

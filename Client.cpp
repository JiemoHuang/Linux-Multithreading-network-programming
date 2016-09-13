#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

using namespace std;

#define CLIENT_PORT		8080
#define SERVER_PORT		8080
#define SERVER_IP	    "127.0.0.1"

typedef struct sockaddr_in		SOCK_ADDR_T;

int main()
{
	SOCK_ADDR_T stClientAddr = {0};
	SOCK_ADDR_T stServAddr   = {0};

	//Client socket address config
	stClientAddr.sin_family = AF_INET;
	stClientAddr.sin_port = htons(CLIENT_PORT);
	stClientAddr.sin_addr.s_addr = INADDR_ANY;

	//Server socket address config
	stServAddr.sin_family = AF_INET;
	stServAddr.sin_port = htons(CLIENT_PORT);
	stServAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

	int tcpSocketFd = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 != tcpSocketFd)
	{
		int connectRet = connect(tcpSocketFd, (struct sockaddr *)&stServAddr, sizeof(SOCK_ADDR_T));
		if (0 == connectRet)
		{
			
		}
		else
		{
			perror("Client TCP connect to server error:");
			return -1;
		}
	}
	else
	{
		perror("Client create TCP socket fd error!!!");
		return -1;
	}

	while (1);
	return 1;
}
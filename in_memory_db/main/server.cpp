/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <vector>

#include "../hash_table/hash_table.h"
#include "../string/string.h"
#include "../list/list.h"
#include "../set/set.h"
#include "../priority_queue/priority_queue.h"
#include "../imdat/imdat.h"
#include "../parser/parser.h"

void error(const char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{
	int sockfd, newsockfd, portno;
	socklen_t clilen;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	int n;
	if (argc < 2) {
		fprintf(stderr,"ERROR, no port provided\n");
		exit(1);
	}
	sockfd = socket(AF_INET, SOCK_STREAM, 0);	//create
	
	if (sockfd < 0)	error("ERROR opening socket");
	
	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)   //bind
		error("ERROR on binding");

	listen(sockfd,5);	//listen
	
	clilen = sizeof(cli_addr);
	
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);	//accept
	
	if (newsockfd < 0) error("ERROR on accept");
	
	Imdat db;
	Parser parser;
	std::vector<String> command;
	
	while (strcmp(buffer, "exit\n")) {	//read and write with infinite loop
		bzero(buffer,256);
		command.clear();
		parser.clear();
		
		n = read(newsockfd,buffer,255);
		
		if (n < 0) error("ERROR reading from socket");

		String entry = buffer;
		parser.parse_command(entry);
		command = parser.get_tokens();
		
		if (!parser.is_valid(command)) {
			n = write(newsockfd, "Wrong command", 13);
			if (n < 0) error("ERROR writing to socket");
			
			continue;
		}
		
		printf("Command: %s", buffer);

		String str = db.call(command);
		char* reply = str.c_str();
		n = write(newsockfd, reply, str.strlen());
		if (n < 0)
			error("ERROR writing to socket");
	}

	close(newsockfd);
	close(sockfd);
	return 0; 
}

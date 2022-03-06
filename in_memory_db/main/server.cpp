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

		String com = buffer;
		parser.parse_command(com);
		command = parser.get_tokens();
		
		if (!parser.is_valid(command)) {
			n = write(newsockfd, "Wrong command", 13);
			if (n < 0) error("ERROR writing to socket");
			
			continue;
		}
		
		printf("Command: %s", buffer);
		
		if (command[0] == "set") {
			db.set(command);
			n = write(newsockfd, "OK", 2);
			if (n < 0) error("ERROR writing to socket");
		
		} else if (command[0] == "get") {
			String str = db.get(command);
			char* reply = str.c_str();
			n = write(newsockfd, reply, str.strlen());
			if (n < 0) error("ERROR writing to socket");

		} else if (command[0] == "del") {
			db.del(command);
			n = write(newsockfd, "String cleaned", 14);
			if (n < 0) error("ERROR writing to socket");
		
		} else if (command[0] == "lpushb") {
			db.lpushb(command);
			n = write(newsockfd, "OK", 2);
			if (n < 0) error("ERROR writing to socket");
		
		} else if (command[0] == "lpushf") {
			db.lpushf(command);
			n = write(newsockfd, "OK", 2);
			if (n < 0) error("ERROR writing to socket");
		
		} else if (command[0] == "lget") {
			String str = db.lget(command);
			char* reply = str.c_str();
			n = write(newsockfd, reply, str.strlen());
			if (n < 0) error("ERROR writing to socket");
		
		} else if (command[0] == "lpopb") {
			db.lpopb(command);
			n = write(newsockfd, "OK", 2);
			if (n < 0) error("ERROR writing to socket");
		
		} else if (command[0] == "lpopf") {
			db.lpopf(command);
			n = write(newsockfd, "OK", 2);
			if (n < 0) error("ERROR writing to socket");
		
		} else if (command[0] == "ldel") {
			db.ldel(command);
			n = write(newsockfd, "List cleaned", 12);
			if (n < 0) error("ERROR writing to socket");
		
		} else if (command[0] == "spush") {
			db.spush(command);
			n = write(newsockfd, "OK", 2);
			if (n < 0) error("ERROR writing to socket");
		
		} else if (command[0] == "sget") {
			String str = db.sget(command);
			char* reply = str.c_str();
			n = write(newsockfd, reply, str.strlen());
			if (n < 0) error("ERROR writing to socket");
		
		} else if (command[0] == "sdel") {
			db.sdel(command);
			n = write(newsockfd, "Set cleaned", 11);
			if (n < 0) error("ERROR writing to socket");
		
		} else if (command[0] == "qpush") {
			db.qpush(command);
			n = write(newsockfd, "OK", 2);
			if (n < 0) error("ERROR writing to socket");
		
		} else if (command[0] == "qpop") {
			db.qpop(command);
			n = write(newsockfd, "OK", 2);
			if (n < 0) error("ERROR writing to socket");
		
		} else if (command[0] == "qtop") {
			String str = db.qtop(command);
			char* reply = str.c_str();
			n = write(newsockfd, reply, str.strlen());
			if (n < 0) error("ERROR writing to socket");
		
		} else if (command[0] == "qdel") {
			db.qdel(command);
			n = write(newsockfd, "Queue cleaned", 13);
			if (n < 0) error("ERROR writing to socket");
		
		} else if (command[0] == "hpush") {
			db.hpush(command);
			n = write(newsockfd, "OK", 2);
			if (n < 0) error("ERROR writing to socket");
		
		} else if (command[0] == "hget") {
			String str = db.hget(command);
			char* reply = str.c_str();
			n = write(newsockfd, reply, str.strlen());
			if (n < 0) error("ERROR writing to socket");
		
		} else if (command[0] == "hdel") {
			db.hdel(command);
			n = write(newsockfd, "Hash Table cleaned", 18);
			if (n < 0) error("ERROR writing to socket");
		} else {
			n = write(newsockfd, "Wrong command", 13);
			if (n < 0) error("ERROR writing to socket");
		}
	}

	close(newsockfd);
	close(sockfd);
	return 0; 
}

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <unistd.h>

#define PORT 9002
#define BUFFER_SIZE 256

int main (int argc, char const *argv[])
{

	char server_message[BUFFER_SIZE] = "You have reached the server juan-antonio-ubuntu";
	char client_message[BUFFER_SIZE] = "";

	//create socket
	int server_socket;
	server_socket = socket(AF_INET,SOCK_STREAM,0);

	// specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family =AF_INET;
	server_address.sin_port = htons(PORT);
	//server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_addr.s_addr = inet_addr("0.0.0.0");

	// Init time-out for receiving packets
    struct timeval tv;
    tv.tv_sec = 30;     // Timeout 
    tv.tv_usec = 0;     // Not initing this can cause strange errors
    setsockopt(server_socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,sizeof(struct timeval));
    

	bind(server_socket, (struct sockaddr *) &server_address,sizeof(server_address));
	listen(server_socket,5);

	//Accept client socket
	int client_socket;
	client_socket = accept(server_socket,NULL,NULL);

	//Send hello message
	int received_message_size;
	send(client_socket,server_message,sizeof(server_message),0);
	bzero(server_message, BUFFER_SIZE);

	int counter = 0;
	while( counter < 15)
	{
		received_message_size = recv(client_socket, &client_message,sizeof(client_message),0);
		printf("client message: %s \n",client_message);
		
		sprintf(server_message,"juan-antonio-ubuntu %d",counter);
		send(client_socket,server_message,sizeof(server_message),0);
		

		bzero(client_message, BUFFER_SIZE);
		counter++;
	}
	
	//Close socket
	close(server_socket);

	return 0;
}



#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <unistd.h>
#include <unistd.h>



#define PORT 9002
#define BUFFER_SIZE 256

int main(int argc, char const *argv[])
{
	char client_message[BUFFER_SIZE] = "";

	//create socket
	int network_socket;
	network_socket = socket(AF_INET,SOCK_STREAM,0);

	// specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family =AF_INET;
	server_address.sin_port = htons(PORT);
	server_address.sin_addr.s_addr = INADDR_ANY;
	//server_address.sin_addr.s_addr = "0.0.0.0";

	int connection_status = connect(network_socket, (struct sockaddr *) &server_address,sizeof(server_address));

	struct timeval tv;
    tv.tv_sec = 3;     // 5 Secs Timeout 
    tv.tv_usec = 0;    // Not initing this can cause strange errors
    setsockopt(network_socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,sizeof(struct timeval));

	if (connection_status == -1)
	{
		printf("There was an error making the connection \n");
		return -1;
	}

	//receive data from the server
	char server_response[256];
	recv(network_socket, &server_response,sizeof(server_response),0);

	printf("The server sent the data: %s \n", server_response);

	unsigned int microseconds = 1000000;
	
	int counter = 0;
	while(counter <15)
	{
		sprintf(client_message, "ok %d", counter);
		send(network_socket, &client_message,sizeof(client_message),0);
		bzero(client_message, BUFFER_SIZE);
		usleep(microseconds);

		recv(network_socket, &server_response,sizeof(server_response),0);
		printf("The server sent the data: %s \n\n", server_response);

		counter++;
	}
	
	printf("Finishing! \n");
	close(network_socket);

	return 0;
}
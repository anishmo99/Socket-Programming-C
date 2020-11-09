
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>
int main()
{	
	// create a socket
	int network_socket;
	// syntax -> socket(int domain, int type, int protocol);
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	// AF_INET is an address family that is used to designate the type of addresses that your socket can communicate with 
	// (in this case, Internet Protocol v4 addresses) or IPv4
	// When you create a socket, you have to specify its address family,
	// and then you can only use addresses of that type with the socket.

	// SOCK_STREAM (compare to TCP) – for a stream-oriented socket

	// specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9001);
	server_address.sin_addr.s_addr = INADDR_ANY;

	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	if(connection_status == -1)
		printf("There was an error making a connection.\n\n");

	// recieve message from a socket
	char server_response[256];
	// syntax -> recv(int socket, void *buffer, size_t length, t flags);
	recv(network_socket, &server_response, sizeof(server_response), 0);
	
	// print out server's response
	printf("The server sent the data : %s\n", server_response);

	// close the socket
	close(network_socket);

	return 0;
}

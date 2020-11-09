#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main()
{
    int sockd, r;
    char buffer[1024];
    
    socklen_t servlen;
    sockd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(1234);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    
    sendto(sockd, buffer, sizeof(buffer), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    r = recvfrom(sockd, buffer, sizeof(buffer), 0, (struct sockaddr *)&servaddr, &servlen);
    buffer[r] = 0;
    printf("\n The time received from the server:%s\n", buffer);
    exit(0);
    return 0;
}
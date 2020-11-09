#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <time.h>

int main()
{
    int sfd, r, bi, port;
    char buff[1024];
   
    socklen_t clilen;
    sfd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in serv_addr, client_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(1234);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    bi = bind(sfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    clilen = sizeof(client_addr);
    r = recvfrom(sfd, buff, sizeof(buff), 0, (struct sockaddr *)&client_addr, &clilen);
    buff[r] = 0;
    time_t ticks;
    ticks = time(NULL);
    snprintf(buff, sizeof(buff), "%24s\r\n", ctime(&ticks));
    sendto(sfd, buff, sizeof(buff), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
    exit(0);
    return 0;
}
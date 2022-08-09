#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080


int main() {
    int clientfd;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("Value of sockfd: %d\n", sockfd);

    struct sockaddr_in my_addr, serv_addr;
    char *intro = "Hello, this is Om Shree";
    char buffer[1024] = {0};
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    int bin = inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    if(bin == -1) {
        printf("Conversion falied\n");
    } else {
        printf("Conversion successful\n");
    }
    if ((clientfd = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) == -1) {
        printf("Connection Failed \n");
    }

    send(sockfd, intro, strlen(intro), 0);
    printf("Introduction sent\n");
    int valread = read(sockfd, buffer, 1024);
    printf("%s\n", buffer);
  
    close(clientfd);
    return 0;
}

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080


int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("Value of sockfd: %d\n", sockfd);

    struct sockaddr_in my_addr = {
    my_addr.sin_family = AF_INET,
    my_addr.sin_port = htons(PORT),
    my_addr.sin_addr.s_addr = INADDR_ANY
    };
    int addrlen = sizeof(my_addr);

    int bindval = bind(sockfd, (struct sockaddr*)&my_addr, sizeof(my_addr));
    if(bindval == -1) {
        printf("Binding failure\n");
    } else {
        printf("Bindning Successful\n");
    }

    if(listen(sockfd, 10) == -1) {
        printf("Listening error\n");
    } else {
        printf("Started listening on Port: %d\n", PORT);
    }

    int chat = accept(sockfd, (struct sockaddr *)&my_addr, (socklen_t *)&addrlen);
    char buffer[1024] = {0};
    int readval = read(chat, buffer, 1024);
    printf("%s\n", buffer);
    send(chat, "Hello, this is Om Shree", strlen("Hello, this is Om Shree, 2006077"), 0);
    printf("Introduction initiated.\n");

    close(chat);
    shutdown(sockfd, SHUT_RDWR);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#define MYPORT 8080

struct in_addr {
    unsigned long s_addr;
};

struct sockaddr_in {
    short int sin_family;
    unsigned short sin_port;
    struct in_addr sin_addr;
    unsigned char sin_zero[8];
};

int close(int sockfd) {
    shutdown(sockfd, SHUT_RDWR);
}

int main() {
    struct sockaddr_in my_addr;

    int sockfd1 = socket(AF_INET, SOCK_STREAM, 0);
    printf("Value of sockfd: %d\n", sockfd1);
    int sockfd2 = socket(AF_INET, SOCK_STREAM, 0);
    printf("Value of sockfd: %d\n", sockfd2);
    int sockfd3 = socket(AF_INET, SOCK_STREAM, 0);
    printf("Value of sockfd: %d\n", sockfd3);

    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(MYPORT);
    my_addr.sin_addr.s_addr = inet_addr("10.0.0.1");
    memset(&(my_addr.sin_zero), '\0', 8);

    int bindval = bind(sockfd1, (struct sockaddr*)&my_addr, sizeof(struct sockaddr));
    if (bindval <= -1) {
        printf("Binding failure\n");
    } else {
        printf("Binding successful\n");
    }

    close(sockfd1);
    return 0;
}

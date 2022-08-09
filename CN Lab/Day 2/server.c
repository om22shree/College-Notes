#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

int main() {
	int serverfd, chat, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = { 0 };
	char* hello = "Hello from server. My name is Om Shree";


	if ((serverfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("socket failed");
	}
    printf("\nServerfd: %d", serverfd);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	if (bind(serverfd, (struct sockaddr*)&address, sizeof(address)) < 0) {
		perror("bind failed");
	} else {
        printf("\nBinding successful\n");
    }

    if (listen(serverfd, 3) < 0) {
		perror("listen");
	} else {
        printf("\nStarted listening on port: %d\n", PORT);
    }

    if ((chat = accept(serverfd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
		perror("accept");
	} else {
        printf("\nAccept successful\n");
    }

    valread = read(chat, buffer, 1024);
	printf("Message received from client:-\n%s\n", buffer);
	send(chat, hello, strlen(hello), 0);
	printf("Hello message sent from server\n");
	

	close(chat);
	shutdown(chat, SHUT_RDWR);
	return 0;
}

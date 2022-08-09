#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

int main() {
	int sock = 0, valread, client_fd;
	struct sockaddr_in serv_addr;
	char* hello = "Hello from client. My name is Om Shree";
	char buffer[1024] = { 0 };

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("Socket creation error\n");
	} else {
        printf("Clientfd: %d\n", sock);
    }
    serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
		printf("Invalid address\n");
	}

	if ((client_fd = connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0) {
		printf("\nConnection Failed \n");
	}

	send(sock, hello, strlen(hello), 0);
	printf("Hello message sent from client\n");
	valread = read(sock, buffer, 1024);
	printf("Message Received from server:-\n%s\n", buffer);


	close(client_fd);
	return 0;
}

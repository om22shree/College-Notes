#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>

int main() {
	int i, sock, flag=0;
	char buf[100], mes[100];
	struct sockaddr_in server;

	sock = socket(AF_INET,SOCK_STREAM,0);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = 60018;

	connect(sock, (struct sockaddr *)&server, sizeof(server));

	for(i=0; i < 100; i++) { 	
		buf[i] = '\0'; 
		mes[i]='\0';
	}
	strcpy(mes,"exit");

	while(flag == 0) {
		for(i=0; i < 100; i++) buf[i] = '\0';
		printf("\nString: ");
		scanf("%[^\n]%*c", buf); 
		send(sock, buf, 100, 0);
		for(i=0; i < 100; i++) 
			buf[i] = '\0';
		recv(sock, buf, 100, 0);
		printf("Server sent: %s\n", buf);
		
		if(strcmp(buf,mes) == 0) {
			flag = 1;
			break;
		}
	}
	
	close(sock);
	return 0;
}


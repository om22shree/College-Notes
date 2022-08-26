#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>

int main() {
	int socket_desc, client_sock1, length, i, flag=0;
    char buf[100], mes[100];
    struct sockaddr_in server, client;

    socket_desc = socket(AF_INET,SOCK_STREAM,0);
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=60018;

	i = bind(socket_desc, (struct sockaddr *)&server, sizeof(server));
	printf("test %d %d\n",socket_desc, i);
	listen(socket_desc, 2);
	length = sizeof(socket_desc);
	
	client_sock1 = accept(socket_desc, (struct sockaddr *) &client, &length);

    strcpy(mes, "exit");
    for (i = 0; i < 100; i++)
        buf[i] ='\0';

	while(flag == 0) {
		for(i=0; i < 100; i++)
            buf[i] = '\0';

		recv(client_sock1, buf, 100, 0);
        printf("Client: %s\n", buf);
		printf("Server receives: %s\n", buf);
		char c1 = *(buf);
		char c2 = *(buf);
		int num1 = (int)(*buf);
		int num2 = (int)(c2);
		printf("Numbers are: %d %d\n", num1, num2);
		int num = num1 * num2;
		for(i=0; i < 100; i++)    
            buf[i] = '\0';
		sprintf(buf, "%d", num);
        send(client_sock1, buf, 100, 0);
		
		if(strcmp(buf, mes) == 0) {
		 	flag = 1;
		 	break;
		}
	}

	close(client_sock1);
	return 0;
}


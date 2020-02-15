#include <stdio.h>

#include <sys/socket.h>
#include <linux/in.h>
#include <sys/types.h>

int main()
{
	struct sockaddr_in adres,klient;
	adres.sin_family=AF_INET;
	adres.sin_port=htons(2222);
	adres.sin_addr.s_addr=INADDR_ANY;
	int gniazdo;
	gniazdo=socket(AF_INET,SOCK_STREAM,0);
	if(bind(gniazdo,(struct sockaddr*)&adres,sizeof(adres))<0);
		perror("bind");
	listen(gniazdo,5);
	int gniazdo2;
	int len=sizeof(klient);
	gniazdo2=accept(gniazdo,(struct sockaddr*)&klient,(socklen_t*)&len);
	sleep(10);
	char buff[100];
	while(1)
	{	
		recv(gniazdo2,buff,100,0);
		printf("%s\n",buff);
	}	
}

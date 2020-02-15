#include <sys/socket.h>
#include <linux/in.h>
#include <sys/types.h>

int main()
{
struct sockaddr_in adres;
adres.sin_addr.s_addr=inet_addr("127.0.0.1");
adres.sin_port=htons(2222);
adres.sin_family=AF_INET;

int gniazdo;

gniazdo=socket(AF_INET,SOCK_STREAM,0);
connect(gniazdo,(struct sockaddr*) &adres,sizeof(adres));
	perror("");
write(gniazdo,"aaacos",4);
sleep(10);
close(gniazdo);
}

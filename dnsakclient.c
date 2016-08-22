#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#define SER_PORT 8013
int main(int count,char *argv[])
{
            int a;
            int clisock,x,b,c;
            char str[25],host[25];
            char str2[25];
            struct sockaddr_in cliaddr;
            cliaddr.sin_port=htons(SER_PORT);
            cliaddr.sin_family=AF_INET;
            cliaddr.sin_addr.s_addr=inet_addr(argv[1]);
            clisock=socket(AF_INET,SOCK_STREAM,0);
            if(clisock<0)
            {
                        perror("\n no socket");
                        exit(0);
            }
            if((x=connect(clisock,(struct sockaddr*)&cliaddr,sizeof(cliaddr)))<0)
            {
                        perror("\n no connect");
                        exit(0);
            }
            printf("enter domain name");
            scanf("%s",host);
            write(clisock,host,strlen(host)+1);
            read(clisock,str2,sizeof(str2));
            printf("%s\n",str2);
            close(clisock);
            return 0;
} 
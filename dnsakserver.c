#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>
#define SER_PORT 8013
int main()
{
            int a,c;
            FILE *f1,*f2;
            int sersock,newsock,n;
            char str[25],str2[25],host[25];
            void *buf,*buf2;
            struct sockaddr_in seraddr;
            struct sockaddr_in clinfo;
            struct hostent *hp;
            socklen_t size=sizeof(clinfo);
            seraddr.sin_family=AF_INET;
            seraddr.sin_port=htons(SER_PORT);
            seraddr.sin_addr.s_addr=htonl(INADDR_ANY);
            if((sersock=socket(AF_INET,SOCK_STREAM,0))<0)
            {
                        error(" socket\n");
                        exit(0);
            }
            if(bind(sersock,(struct sockaddr*)&seraddr,sizeof(seraddr))<0)
            {
                        error(" bind\n");
                        exit(0);
            }
            if(listen(sersock,1)<0)
            {
                        error(" listen\n");
                        exit(0);
            }
            if((newsock=accept(sersock,(struct sockaddr*)&clinfo,&size))<0)
            {
                         error(" accept \n");
                        exit(0);
            }
            else
                        printf("connected to m%s \n",inet_ntoa(clinfo.sin_addr));
            read(newsock,host,sizeof(host));
            printf("%s",host);
            hp=gethostbyname(host);
            inet_ntop(AF_INET,hp->h_addr,str2,sizeof(str2));
            printf("%s\n",str2);
            write(newsock,str2,strlen(str2)+1);
            close(newsock);
            close(sersock);
            return 0;
}
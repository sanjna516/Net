#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
main()
{
    FILE *fp;
    struct sockaddr_in server,client;
    int s,n,check=0;
    char b1[100],b2[100],a[100];
    s=socket(AF_INET,SOCK_DGRAM,0);
    server.sin_family=AF_INET;
    server.sin_port=3000;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    bind(s,(struct sockaddr *)&server,sizeof(server));
    n=sizeof(client);
    while(1)
    {
        strcpy(b2,"");
        fp=fopen("DNS.txt","r");
        recvfrom(s,b1,sizeof b1, 0,(struct sockaddr *)&client,&n);
        while(check!=1)
       {
           fscanf(fp,"%s",a);
           if(strcmp(a,b1)==0)
          {
                fscanf(fp,"%s",b2);
		check=1;
                break;
          }
      }
      if(strcmp(b2,"")==0)
     {
           strcpy(b2,"Not found...");
      }
     fclose(fp);
     sendto(s,b2,sizeof b2,0,(struct sockaddr *)&client,n); 
    }
}

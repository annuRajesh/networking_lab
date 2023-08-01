#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>

int main()
{
    char *ip="127.0.0.1";
    int sock;
    struct sockaddr_in addr;
    char buffer[100];
    int port=8080;
    int n;
    sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock<0){
        perror("[-]Socket creation failed");
        exit(1);
    }
    printf("[+]Socket created successfully\n");
    memset(&addr,'\0',sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_port=htons(port);
    addr.sin_addr.s_addr=inet_addr(ip);
    n=bind(sock,(struct sockaddr*)&addr,sizeof(addr));
    bzero(buffer,100);
    
    printf("Enter the message: ");
    fgets(buffer,sizeof(buffer),stdin);
    
    send(sock,buffer,strlen(buffer),0);
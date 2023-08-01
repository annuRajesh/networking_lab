/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>

int main()
{
    char *ip="127.0.0.1";
    int server_sock,client_sock;
    struct sockaddr_in server_addr,client_addr;
    char buffer[100];
    int port=8080;
    int n;
    server_sock=socket(AF_INET,SOCK_STREAM,0);
    if(server_sock<0){
        perror("[-]Socket creation failed");
        exit(1);
    }
    printf("[+]Socket created successfully\n");
    memset(&server_addr,'\0',sizeof(server_addr));
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(port);
    server_addr.sin_addr.s_addr=inet_addr(ip);
    n=bind(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr));
    if(n<0){
        perror("[-]Binding failed..");
        exit(1);
    }
    printf("[+]Binding successful\n");
    listen(server_sock,5);
    printf("Listening....\n");
    while(1){
       int size_addr=sizeof(client_addr);
        accept(server_sock,(struct sockaddr*)&client_addr,&size_addr);
        bzero(buffer,100);
        recv(client_sock,buffer,sizeof(buffer),0);
        printf("Recieved message from client:%s",buffer);
        
    }
    return 0;
}

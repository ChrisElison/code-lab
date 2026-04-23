/*
 * Vibecoded Minimal IRC daemon
 * Does nothing so far except accept connections
 * 
 * To-Do:
 *  - Allow joining of channels
 * 
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 6667
#define MAX_CLIENTS 2
#define BUF_SIZE 512

/* Array storing connected client sockets */
int clients[MAX_CLIENTS];

/* Nicknames for each client */
char nicks[MAX_CLIENTS][32];

/* Channels for clients */
char channels[MAX_CLIENTS][32];

/* Broadcast a message to all clients except sender */
void broadcast(int sender, char *msg)
{
    for(int i = 0; i < MAX_CLIENTS; i++)
    {
        if(clients[i] != -1 && i != sender)
        {
            send(clients[i], msg, strlen(msg), 0);
        }
    }
}

int main()
{
    int server_fd;
    int new_socket;

    struct sockaddr_in addr;

    char buffer[BUF_SIZE];

    /* Initialize client slots */
    for(int i=0;i<MAX_CLIENTS;i++)
        clients[i] = -1;

    /* Create TCP socket */
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(server_fd < 0)
    {
        perror("socket");
        exit(1);
    }

    /* Setup server address */
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    /* Bind socket to port */
    if(bind(server_fd,(struct sockaddr*)&addr,sizeof(addr)) < 0)
    {
        perror("bind");
        exit(1);
    }

    /* Start listening for connections */
    listen(server_fd,5);

    printf("Minimal IRC server running on port %d\n",PORT);

    while(1)
    {
        fd_set readfds;

        /* Clear the socket set */
        FD_ZERO(&readfds);

        /* Add server socket */
        FD_SET(server_fd,&readfds);

        int maxfd = server_fd;

        /* Add client sockets */
        for(int i=0;i<MAX_CLIENTS;i++)
        {
            if(clients[i] != -1)
            {
                FD_SET(clients[i],&readfds);

                if(clients[i] > maxfd)
                    maxfd = clients[i];
            }
        }

        /* Wait for activity on any socket */
        select(maxfd+1,&readfds,NULL,NULL,NULL);

        /* New connection? */
        if(FD_ISSET(server_fd,&readfds))
        {
            struct sockaddr_in client_addr;
            socklen_t addr_len = sizeof(client_addr);
            
            new_socket = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);

            /*printf("New client connected\n");*/
            if(new_socket >= 0) {
                printf("New client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            }
            
            /* Add client to list */
            for(int i=0;i<MAX_CLIENTS;i++)
            {
                if(clients[i] == -1)
                {
                    clients[i] = new_socket;
                    strcpy(nicks[i],"unknown");
                    break;
                }
            }
        }

        /* Check each client socket */
        for(int i=0;i<MAX_CLIENTS;i++)
        {
            if(clients[i] != -1 && FD_ISSET(clients[i],&readfds))
            {
                int len = recv(clients[i],buffer,sizeof(buffer)-1,0);

                /* Client disconnected */
                if(len <= 0)
                {
                    printf("Client disconnected\n");

                    close(clients[i]);
                    clients[i] = -1;
                    continue;
                }

                buffer[len] = 0;

                printf("Received: %s",buffer);

                /* Handle NICK command */
                if(strncmp(buffer,"NICK ",5)==0)
                {
                    sscanf(buffer+5,"%s",nicks[i]);

                    printf("Client set nick: %s\n",nicks[i]);
                }

                /* Handle PING from IRC client */
                else if(strncmp(buffer,"PING",4)==0)
                {
                    char reply[BUF_SIZE];

                    /* IRC protocol requires PONG reply */
                    snprintf(reply,sizeof(reply),"PONG %s",buffer+5);

                    send(clients[i],reply,strlen(reply),0);

                    printf("Sent PONG\n");
                }

                /* Handle PRIVMSG or other text */
                else
                {
                    char msg[BUF_SIZE+64];

                    /* Format message with nickname */
                    snprintf(msg,sizeof(msg),"%s: %s",nicks[i],buffer);

                    /* Send message to other clients */
                    broadcast(i,msg);
                }
            }
        }
    }

    return 0;
}

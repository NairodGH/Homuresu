#ifndef CLIENT_H_
#define CLIENT_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <arpa/inet.h>

typedef struct client_s
{
    int sock;
    char *ip;
    int port;
    struct sockaddr_in cliaddr;
} client_t;

// memory.c
client_t *init_struct();
void free_memory(client_t *client);

// network/client.c
int client_manage(char *ip, int port, client_t *client);

#endif /* !CLIENT_H_ */

#ifndef SERVER_H_
#define SERVER_H_

#include <arpa/inet.h>
#include <ctype.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024
#define EOF_NETWORK "\r\n"

typedef struct client_s client_t;
struct client_s
{
    int sock;
    char *ip;
    int port;
    client_t *next;
    client_t *prev;
};

typedef struct server_s
{
    int sock;
    size_t port;
    struct sockaddr_in servaddr;
    fd_set read_fd;
    fd_set write_fd;
    client_t *clients;
} server_t;

// memory.c
server_t *init_struct();
void free_memory(server_t *server);

// network/server.c
int start_server(server_t *server);

// network/server.c
int start_server(server_t *server);

// network/init.c
int init_server(server_t *server);

// network/connection.c
int check_connection(server_t *server);

// network/get.c
char *get_message(client_t *client);

// network/send.c
int send_message(client_t *client, char const *msg, char const *eof);

// network/action.c
int manage_commands(server_t *server, client_t *client);

// network/utils.c
int count_client(client_t *clients);

// network/client.c
client_t *init_clients(int sock);
client_t *add_client(client_t *clients, int sock);

// network/cliclose.c
void remove_client(client_t *client);
void free_clients(client_t *clients);

#endif /* !SERVER_H_ */
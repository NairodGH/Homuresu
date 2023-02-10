#ifndef CLIENT_H_
#define CLIENT_H_

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

typedef struct client_s {
  struct sockaddr_in cliaddr;
  char *ip;
  int port;
  int sock;
  fd_set read_fd;
  fd_set write_fd;
} client_t;

// memory.c
client_t *init_struct();
void free_memory(client_t *client);

// network/init.c
int client_manage(char *ip, int port, client_t *client);

// network/client.c
int select_manage(client_t *client);

// network/send.c
int send_message(client_t *client, char const *msg, char const *eof);

// network/get.c
char *get_message(client_t *client);

#endif /* !CLIENT_H_ */

#include "server.h"

server_t *init_struct()
{
    server_t *server = malloc(sizeof(server_t));

    if (server == NULL)
        return NULL;
    server->sock = 0;
    server->port = 8080;
    server->clients = NULL;
    return server;
}

void free_memory(server_t *server)
{
    free_clients(server->clients);
    free(server);
}
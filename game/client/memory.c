#include "general.h"

client_t *init_struct()
{
    client_t *client = malloc(sizeof(client_t));

    if (client == NULL)
        return NULL;
    client->sock = 0;
    client->ip = NULL;
    client->port = 0;
    return client;
}

void free_memory(client_t *client)
{
    if (client == NULL)
        return;
    if (client->ip != NULL)
        free(client->ip);
    free(client);
}

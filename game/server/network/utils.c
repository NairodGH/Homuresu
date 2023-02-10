#include "server.h"

int count_client(client_t *clients)
{
    int cpt = 0;

    for (; clients != NULL; clients = clients->next)
        cpt++;
    return cpt - 1;
}
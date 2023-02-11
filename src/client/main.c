#include "includes.h"
#include "iencli.h"

client_t *client = NULL;

static int init_client(client_t *client, game_t *game)
{
    int check = 0;

    if ((check = init_client_tcp(client)) != 0)
        return check;
    if ((check = init_client_udp(client)) != 0)
        return check;
    if ((check = loop_client(client, game)) != 0)
        return check;
    return check;
}

int main(int ac, char **av)
{
    game_t *game = calloc(1, sizeof(game_t));
    int check = 0;

    client = init_struct();
    if (client == NULL) {
        printf("Error: Client structure initialization failed\n");
        return 84;
    }
    client->ip = strdup(av[1]);
    client->port_tcp = atoi(av[2]);
    client->port_udp = client->port_udp + 1;
    initGame(game);
    if ((check = init_client(client, game)) != 0) {
        free_memory(client);
        return check;
    }
    free(game);
    return 0;
}

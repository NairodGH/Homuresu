#include "server.h"

static void reset_fd_connection(server_t *server)
{
    client_t *tmp = server->clients;

    for (; tmp != NULL; tmp = tmp->next) {
        FD_SET(tmp->sock, &server->read_fd);
        FD_SET(tmp->sock, &server->write_fd);
    }
}

static int loop_server(server_t *server)
{
    server->clients = init_clients(server->sock);
    if (server->clients == NULL)
        return 84;
    
    while (true) {
        FD_ZERO(&server->read_fd);
        FD_ZERO(&server->write_fd);
        reset_fd_connection(server);
        if (check_connection(server) != 0)
            return 84;
        // ACTION OF PLAYER
        // if (player_action(server) != 0)
        //     return 84;
    }
    return 0;
}

int start_server(server_t *server)
{
    printf("Server initialization...\n");
    if (init_server(server) != 0) {
        printf("Error: Server initialization failed\n");
        return 84;
    }
    printf("Server starts\n");
    if (loop_server(server) != 0)
        return 84;
    return 0;
}

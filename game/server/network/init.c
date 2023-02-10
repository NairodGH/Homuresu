#include "server.h"

static int set_server_options(server_t *server)
{
    if (setsockopt(server->sock, SOL_SOCKET, SO_REUSEADDR, &(int){1},
        sizeof(int)) == -1) {
        printf("Error: setsockopt failed\n");
        return 84;
    }
    server->servaddr.sin_family = AF_INET;
    server->servaddr.sin_port = htons(server->port);
    server->servaddr.sin_addr.s_addr = INADDR_ANY;
    return 0;
}

int init_server(server_t *server)
{
    server->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sock == -1) {
        printf("Error: Socket creation failed\n");
        return 84;
    }
    if (set_server_options(server) != 0)
        return 84;
    if (bind(server->sock, (struct sockaddr *)&server->servaddr,
        sizeof(server->servaddr)) == -1) {
        printf("Error: Bind failed\n");
        return 84;
    }
    if (listen(server->sock, MAX_CLIENTS) == -1) {
        printf("Error: Listen failed\n");
        close(server->sock);
        return 84;
    }
    return 0;
}

#include "server.h"

static int assign_fd_connection(server_t *server, int con_fd)
{
    client_t *tmp = NULL;

    if (count_client(server->clients) >= MAX_CLIENTS) {
        printf("Warning : Fail to add client, limit has been reached\n");
        return 0;
    }
    tmp = add_client(server->clients, con_fd);
    if (tmp == NULL) {
        printf("Error : Fail to add client\n");
        return 84;
    }
    printf("++ %s:%i\n", tmp->ip, tmp->port);
    return 0;
}

static int connection_action_manage(server_t *server)
{
    int check = 0;
    client_t *tmp = server->clients->next;

    for (; tmp != NULL; tmp = tmp->next) {
        if (FD_ISSET(tmp->sock, &server->read_fd)) {
            check = manage_commands(server, tmp);
            if (check == 1) {
                remove_client(tmp);
                tmp = server->clients;
            } else if (check == 84)
                return 84;
        }
    }
    return 0;
}

int check_connection(server_t *server)
{
    int con_fd = 0;
    struct sockaddr_in con_addr;
    socklen_t addrlen = sizeof(con_addr);

    if (select(FD_SETSIZE, &server->read_fd,
        &server->write_fd, NULL, NULL) >= 0) {
        if (FD_ISSET(server->sock, &server->read_fd)) {
            con_fd = accept(server->sock, (struct sockaddr *)&con_addr,
                &addrlen);
            if (con_fd == -1) {
                printf("Error : Fail to accept connection\n");
                return 0;
            }
            if (assign_fd_connection(server, con_fd) != 0)
                return 84;
        }
        if (connection_action_manage(server) != 0)
            return 84;
    }
    return 0;
}

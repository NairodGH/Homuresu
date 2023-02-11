#include "general.h"

static int count_client(client_t *clients)
{
    int cpt = 0;

    for (; clients != NULL; clients = clients->next)
        cpt++;
    return cpt - 1;
}

int assign_fd_connection(server_tcp_t *server, int con_fd)
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

int client_action_manage(server_tcp_t *server)
{
    int check = 0;
    client_t *tmp = server->clients->next;

    for (; tmp != NULL; tmp = tmp->next) {
        if (FD_ISSET(tmp->sock, &server->read_fd)) {
            check = manage_tcp_recv_actions(server, tmp);
            if (check == 1) {
                remove_client(tmp);
                tmp = server->clients;
            } else if (check == 84)
                return 84;
        }
    }
    return 0;
}

int check_client_connected(server_tcp_t *server, server_udp_t *server_udp)
{
    struct sockaddr_in con_addr;
    socklen_t addrlen = sizeof(con_addr);

    recvfrom(server_udp->sock, NULL, 0, 0,
        (struct sockaddr *)&con_addr, &addrlen);
    for (client_t *tmp = server->clients->next; tmp != NULL; tmp = tmp->next) {
        if (tmp->ip == inet_ntoa(con_addr.sin_addr) &&
            tmp->port == ntohs(con_addr.sin_port))
            return manage_udp_recv_actions(server_udp, tmp);
    }
    printf("Warning : Client %s:%i is not connected to TCP\n",
        inet_ntoa(con_addr.sin_addr), ntohs(con_addr.sin_port));
    return 0;
}
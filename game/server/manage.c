#include "general.h"

int manage_tcp_recv_actions(server_tcp_t *server, client_t *client)
{
    int check = 0;
    char *msg = get_tcp_packet(client->sock);

    if (msg == NULL) {
        printf("-? %s:%i\n", client->ip, client->port);
        return 1;
    } else {
        printf("Message from %s:%i : %s\n", client->ip, client->port, msg);
        //! ACTION EN FONCTION DU MESSAGE TCP
    }
    free(msg);
    return check;
}

int manage_udp_recv_actions(server_udp_t *server, client_t *client)
{
    int check = 0;
    char *msg = get_udp_packet(server->sock);

    if (msg == NULL) {
        printf("-? %s:%i\n", client->ip, client->port);
        return 1;
    } else {
        printf("Message from %s:%i : %s\n", client->ip, client->port, msg);
        //! ACTION EN FONCTION DU MESSAGE UDP
    }
    free(msg);
    return check;
}
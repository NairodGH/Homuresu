#include "general.h"

static void reset_fd_clients(server_tcp_t *server)
{
    client_t *tmp = server->clients;

    for (; tmp != NULL; tmp = tmp->next) {
        FD_SET(tmp->sock, &server->read_fd);
        FD_SET(tmp->sock, &server->write_fd);
    }
}

static int loop_recv_srv_tcp(server_tcp_t *server)
{
    int con_fd = 0;
    struct sockaddr_in con_addr;
    socklen_t addrlen = sizeof(con_addr);

    // printf("LOOP TCP BEGIN\n");
    if (select(FD_SETSIZE, &server->read_fd,
        &server->write_fd, NULL, NULL) >= 0) {
        if (FD_ISSET(server->sock, &server->read_fd)) {
            con_fd = accept(server->sock, (struct sockaddr *)&con_addr,
                &addrlen);
            if (con_fd == -1) {
                printf("Error : Fail to accept TCP connection\n");
                return 0;
            }
            if (assign_fd_connection(server, con_fd) != 0)
                return 84;
        }
        if (client_action_manage(server) != 0)
            return 84;
    }
    // printf("LOOP TCP END\n");
}

static int loop_recv_srv_udp(nom_de_merde_t *gn)
{
    // printf("LOOP UDP BEGIN\n");
    if (select(FD_SETSIZE, &gn->srv_udp->read_fd,
        &gn->srv_udp->write_fd, NULL, NULL) >= 0) {
        if (FD_ISSET(gn->srv_udp->sock, &gn->srv_udp->read_fd)) {
            if (check_client_connected(gn->srv_tcp, gn->srv_udp) != 0)
                return 84;
        }
    }
    // printf("LOOP UDP END\n");
    return 0;
}

int loop_server(nom_de_merde_t *gn)
{
    gn->srv_tcp->clients = init_clients(gn->srv_tcp->sock);
    if (gn->srv_tcp->clients == NULL)
        return 84;

    while (true) {
        FD_ZERO(&gn->srv_tcp->read_fd);
        FD_ZERO(&gn->srv_tcp->write_fd);
        FD_ZERO(&gn->srv_udp->read_fd);
        FD_ZERO(&gn->srv_udp->write_fd);
        reset_fd_clients(gn->srv_tcp);
        //! GESTION DES ACTIONS DE RECEPTION DES CLIENTS
        if (loop_recv_srv_tcp(gn->srv_tcp) != 0)
            return 84;
        // TODO : JULIEN TIME = ALED
        // if (loop_recv_srv_udp(gn) != 0)
        //     return 84;
        //! GESTION DES ACTIONS A ENVOYER AUX CLIENTS
    }
    return 0;
}
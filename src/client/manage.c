#include "iencli.h"

int manage_tcp_recv_actions(client_t *client, game_t *game)
{
    int check = 0;
    char *msg = get_tcp_packet(client->sock_tcp);

    if (msg == NULL) {
        printf("-? %s:%i\n", client->ip, client->port_tcp);
        return 0;
    } else {
        printf("Message from %s:%i (tcp) : %s\n", client->ip, client->port_tcp, msg);
        if (strncmp(msg, "HELLO", 5) == 0) {
            game->id = atoi(msg + 6);
        } else if (strncmp(msg, "BULLET", 6) == 0) {
            addBulletToGame(game, msg + 7);
        } else if (strncmp(msg, "PLAYER", 6) == 0) {
            addInfoPlayerToGame(game, msg + 7);
        }
    }
    free(msg);
    return check;
}

int manage_udp_recv_actions(client_t *client)
{
    int check = 0;
    char *msg = get_udp_packet(client->sock_udp);

    if (msg == NULL) {
        printf("-? %s:%i\n", client->ip, client->port_udp);
        return 0;
    } else {
        printf("Message from %s:%i (udp) : %s\n", client->ip, client->port_udp, msg);
    }
    free(msg);
    return check;
}

int manage_tcp_send_actions(client_t *client)
{
    int check = 0;
    char *msg = malloc(sizeof(char) * BUFFER_SIZE);
    int msglen = BUFFER_SIZE;

    if (msg == NULL) {
        printf("Error: malloc failed\n");
        return 84;
    }
    bzero(msg, msglen);
    msglen = read(0, msg, msglen);
    if (msglen == -1) {
        printf("Error: read failed\n");
        return 84;
    }
    if (msglen == 0)
        printf("Read get EOF | Press Ctrl+C to leave\n");
    msg[msglen - 1] = '\0';
    if ((check = send_tcp_packet(client->sock_tcp, msg, EOF_NETWORK)) != 0) {
        printf("Error: send_message failed\n");
        free(msg);
        return check;
    }
    return check;
}

int manage_udp_send_actions(client_t *client)
{
    int check = 0;
    // char *msg = malloc(sizeof(char) * BUFFER_SIZE);
    // int msglen = BUFFER_SIZE;

    // if (msg == NULL) {
    //     printf("Error: malloc failed\n");
    //     return 84;
    // }
    // bzero(msg, msglen);
    // msglen = read(0, msg, msglen);
    // if (msglen == -1) {
    //     printf("Error: read failed\n");
    //     return 84;
    // }
    // if (msglen == 0)
    //     printf("Read get EOF | Press Ctrl+C to leave\n");
    // msg[msglen - 1] = '\0';
    // if ((check = send_udp_packet(client->sock_tcp, msg, EOF_NETWORK, client)) != 0) {
    //     printf("Error: send_message failed\n");
    //     free(msg);
    //     return check;
    // }
    return check;
}
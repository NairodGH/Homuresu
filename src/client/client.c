#include "iencli.h"
#include "includes.h"

static void reset_fd(client_t *client)
{
    FD_ZERO(&client->read_fd);
    FD_ZERO(&client->write_fd);
    FD_SET(client->sock_tcp, &client->read_fd);
    FD_SET(client->sock_udp, &client->read_fd);
    FD_SET(client->sock_tcp, &client->write_fd);
    FD_SET(client->sock_udp, &client->write_fd);
}

static int loop_send_cli_tcp(client_t *client)
{
    int check = 0;
    struct timeval timeout = {0, 100};

    if (select(client->sock_tcp + 1, NULL,
        &client->write_fd, NULL, &timeout) >= 0) {
        if (FD_ISSET(client->sock_tcp, &client->read_fd)) {
            if ((check = manage_tcp_send_actions(client)) != 0)
                return check;
        }
    }
    return check;
}

static int loop_send_cli_udp(client_t *client)
{
    int check = 0;
    struct timeval timeout = {0, 100};

    if (select(client->sock_udp + 1, NULL,
        &client->write_fd, NULL, &timeout) >= 0) {
        if (FD_ISSET(client->sock_udp, &client->read_fd)) {
            if ((check = manage_udp_send_actions(client)) != 0)
                return check;
        }
    }
    return check;
}

static int loop_recv_cli_tcp(client_t *client)
{
    int check = 0;
    struct timeval timeout = {0, 100};

    if (select(client->sock_tcp + 1, &client->read_fd,
        NULL, NULL, &timeout) >= 0) {
        if (FD_ISSET(client->sock_tcp, &client->read_fd)) {
            if ((check = manage_tcp_recv_actions(client)) != 0)
                return check;
        }
    }
    return check;
}

static int loop_recv_cli_udp(client_t *client)
{
    int check = 0;
    struct timeval timeout = {0, 100};

    if (select(client->sock_udp + 1, &client->read_fd,
        NULL, NULL, &timeout) >= 0) {
        if (FD_ISSET(client->sock_udp, &client->read_fd)) {
            if ((check = manage_udp_recv_actions(client)) != 0)
                return check;
        }
    }
    return check;
}

int loop_client(client_t *client, game_t *game)
{
    int check = 0;
    float x = 0;

    while (!WindowShouldClose()) {
        if (game->menu->is_menu) {
            if (menu(game->menu, &x) == 1)
               break;
        } else {
            updateGame(game);
            drawGame(game);
        }
        reset_fd(client);
        if ((check = loop_recv_cli_tcp(client)) != 0)
            return check;
        reset_fd(client);
        /* if ((check = loop_send_cli_tcp(client)) != 0)
            return check;
        reset_fd(client); */
    }
    return check;
}

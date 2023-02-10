#include "general.h"

static void reset_fd_connection(client_t *client)
{
    FD_ZERO(&client->read_fd);
    FD_ZERO(&client->write_fd);
    FD_SET(client->sock, &client->read_fd);
    FD_SET(client->sock, &client->write_fd);
    FD_SET(0, &client->read_fd);
    FD_SET(0, &client->write_fd);
}

static int manage_input(client_t *client)
{
    char *msg = malloc(sizeof(char) * BUFFER_SIZE);
    int msglen = BUFFER_SIZE;

    if (msg == NULL) {
        printf("Error: malloc failed\n");
        return 84;
    }
    msglen = read(0, msg, msglen);
    if (msglen == -1) {
        printf("Error: read failed\n");
        return 84;
    }
    if (msglen == 0)
        printf("Read get EOF | Press Ctrl+C to leave\n");
    if (send_message(client, msg, EOF_NETWORK) != 0) {
        printf("Error: send_message failed\n");
        free(msg);
        return 84;
    }
    return 1;
}

static int select_choice(client_t *client)
{
    int check = 1;

    // if (FD_ISSET(client->sock, &client->read_fd)) {
    //     if ((check = manage_commands(client)) != 1)
    //         return check;
    // }
    if (FD_ISSET(0, &client->read_fd)) {
        if ((check = manage_input(client)) != 1)
            return check;
    }
    return check;
}

int select_manage(client_t *client)
{
    int check = 1;

    reset_fd_connection(client);
    while (true) {
        reset_fd_connection(client);
        if (select(FD_SETSIZE, &client->read_fd,
            &client->write_fd, NULL, NULL) >= 0) {
            if ((check = select_choice(client)) != 1)
                return check;
        }
    }
    return check;
}

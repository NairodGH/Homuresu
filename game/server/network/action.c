#include "server.h"

int manage_commands(server_t *server, client_t *client)
{
    int check = 0;
    char *msg = get_message(client);

    if (msg == NULL) {
        printf("-? %s:%i\n", client->ip, client->port);
        return 1;
    } else {
        printf("Message from %s:%i : %s\n", client->ip, client->port, msg);
        // manage action
    }
    free(msg);
    return check;
}

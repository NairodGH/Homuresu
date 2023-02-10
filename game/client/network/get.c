#include "general.h"

static int check_eof(client_t *client, char *msg, ssize_t size)
{
    if (size >= 2 && memcmp(msg + size - 2, EOF_NETWORK, 2) == 0) {
        msg[size - 2] = '\0';
        return 1;
    }
    return 0;
}

char *get_message(client_t *client)
{
    char *msg = NULL;
    char buffer[BUFFER_SIZE];
    ssize_t size_read = 0;
    ssize_t size = 0;

    while (true) {
        if ((size_read = read(client->sock, buffer, BUFFER_SIZE)) <= 0) {
            printf("Client %s read intterupted\n", client->ip);
            return NULL;
        }
        if ((msg = realloc(msg, size + size_read + 1)) == NULL)
            return NULL;
        memcpy(msg + size, buffer, size_read);
        msg[size + size_read] = '\0';
        size += size_read;
        if (check_eof(client, msg, size) != 0)
            break;
    }
    return msg;
}

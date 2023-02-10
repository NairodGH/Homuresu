#include "general.h"

static char *set_send_opt(char const *msg, char const *eof)
{
    char *message = calloc(strlen(msg) + 3, sizeof(char));
    
    if (message == NULL)
        return NULL;
    strcpy(message, msg);
    strcat(message, eof);
    return message;
}

int send_message(client_t *client, char const *msg, char const *eof)
{
    char *message = NULL;
    ssize_t write_size = 0;
    ssize_t size = 0;
    ssize_t current = 0;

    if (msg == NULL)
        return 84;
    if ((message = set_send_opt(msg, eof)) == NULL)
        return 84;
    size = strlen(message);
    do {
        write_size = write(client->sock, message + current, size - current);
        if (write_size == -1) {
            printf("Error: write failed\n");
            return 84;
        }
        current += write_size;
    } while (current < size);
    free(message);
    return 0;
}

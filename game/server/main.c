#include "raylib.h"
#include "server.h"

server_t *server = NULL;

void sig_handler(int sig)
{
    if (sig == SIGINT || sig == SIGTERM) {
        if (server != NULL) {
            printf("\nServer is shutting down...\n");
            free_memory(server);
        }
        printf("Bye!\n");
        exit(0);
    }
}

int main(int ac, char **av)
{
    int check = 0;

    signal(SIGINT, sig_handler);
    signal(SIGTERM, sig_handler);
    server = init_struct();
    if (server == NULL) {
        printf("Error: Server structure initialization failed\n");
        return 84;
    }
    server->port = 4242;
    check = start_server(server);
    free_memory(server);
    return check;
}
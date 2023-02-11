#include "general.h"

nom_de_merde_t *gn = NULL;

static nom_de_merde_t *init_gn_struct()
{
    nom_de_merde_t *gn = malloc(sizeof(nom_de_merde_t));

    if (gn == NULL)
        return NULL;
    gn->srv_tcp = init_srv_struct_tcp();
    gn->srv_udp = init_srv_struct_udp();
    if (gn->srv_tcp == NULL || gn->srv_udp == NULL)
        return NULL;
    return gn;
}

void free_gn_struct(nom_de_merde_t *gn)
{
    free_srv_struct_tcp(gn->srv_tcp);
    free_srv_struct_udp(gn->srv_udp);
    free(gn);
}

void sig_handler(int sig)
{
    if (sig == SIGINT || sig == SIGTERM) {
        if (gn != NULL) {
            printf("\nServer is shutting down...\n");
            free_gn_struct(gn);
        }
        printf("Bye!\n");
        exit(0);
    }
}

int main(int ac, char **av)
{
    signal(SIGINT, sig_handler);
    signal(SIGTERM, sig_handler);
    gn = init_gn_struct();
    if (gn == NULL)
        return 84;
    gn->srv_tcp->port = DEFAULT_PORT;
    gn->srv_udp->port = DEFAULT_PORT + 1;
    printf("Server initialization...\n");
    if (init_server_tcp(gn->srv_tcp) != 0)
        return 84;
    if (init_server_udp(gn->srv_udp) != 0)
        return 84;
    printf("Server starts\n");
    if (loop_server(gn) != 0)
        return 84;
    return 0;
}
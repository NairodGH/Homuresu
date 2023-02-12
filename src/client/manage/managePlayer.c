#include "includes.h"

char **splitMsg(char *msg, char *delim)
{
    char **tab = NULL;
    char *token = strtok(msg, delim);
    int i = 0;

    for (; token != NULL; i++) {
        tab = realloc(tab, sizeof(char *) * (i + 1));
        tab[i] = strdup(token);
        token = strtok(NULL, delim);
    }
    tab = realloc(tab, sizeof(char *) * (i + 1));
    tab[i] = NULL;
    return (tab);
}

void freeDoubleTab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

static player_t * createPlayer(int id, game_t *game)
{
    player_t *player = calloc(1, sizeof(player_t));

    player->position = (Vector3){0, 0, 0};
    player->direction = (Vector3){0, 0, 0};
    player->isAlive = true;
    player->model.type = MODEL_DORION;
    player->model.model = *getModel(game, player->model.type);
    player->id = id;
    player->stat.life = 100;
    player->stat.score = 0;
    return (player);
}

void addInfoPlayerToGame(game_t *game, char *msg)
{
    char **tab = splitMsg(msg, " ");
    int id = atoi(tab[0]);
    player_t *player = NULL;
    node_t *node = NULL;
    bool find = false;

    foreach(game->player->head, node) {
        player = (player_t *)node->data;
        if (player->id == id) {
            find = true;
            break;
        }
    }
    if (!find) {
        player = createPlayer(id, game);
        list_push_data(game->player, player);
    }
    player->position.x = atof(tab[1]);
    player->position.y = atof(tab[2]);
    player->position.z = atof(tab[3]);
    player->direction.x = atof(tab[4]);
    player->direction.y = atof(tab[5]);
    player->direction.z = atof(tab[6]);
    player->stat.life = atoi(tab[7]);
    player->stat.score = atoi(tab[8]);
    freeDoubleTab(tab);
}
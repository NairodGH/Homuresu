#include "iencli.h"

void createBullet(game_t *game, float speed, float size)
{
    bullet_t *new = calloc(1, sizeof(bullet_t));
    char msg[100];

    new->position = (Vector3){game->camera.position.x, game->camera.position.y, game->camera.position.z};
    new->direction = Vector3Normalize(Vector3Subtract((Vector3){game->camera.target.x, game->camera.target.y, game->camera.target.z}, new->position));
    new->speed = speed;
    new->size = size;
    new->model = *getModel(game, MODEL_BATARANG);
    new->model.transform = MatrixMultiply(new->model.transform, MatrixRotateY(atan2(new->direction.x, new->direction.z)));
    new->isAlive = true;
    list_push_data(game->bullet, new);
    game->stat->lastShoot = time(NULL);
    game->stat->ammo--;
    sprintf(msg, "BULLET %d pos %f %f %f dir %f %f %f speed %f size %f", game->id, new->position.x, new->position.y, new->position.z,
                    new->direction.x, new->direction.y, new->direction.z, new->speed, new->size);
    send_tcp_packet(((client_t *)game->client)->sock_tcp, msg, EOF_NETWORK);
}

void createAmmoBox(game_t *game)
{
    item_t *new = calloc(1, sizeof(item_t));

    new->position = (Vector3){GetRandomValue(-(MAP_SIZE / 2) + 1, (MAP_SIZE / 2) - 1),
                              0, GetRandomValue(-(MAP_SIZE / 2) + 1, (MAP_SIZE / 2) - 1)};
    new->texture = LoadTexture("resources/ammoBox.png");
    new->height = 1.0f;
    new->width = 1.0f;
    new->length = 1.0f;
    new->name = "ammoBox";
    new->isAlive = true;
    list_push_data(game->item, new);
}

void addBulletToGame(game_t *game, char *msg)
{
    char **tab = splitMsg(msg, " ");
    int id = atoi(tab[0]);
    bullet_t *new = calloc(1, sizeof(bullet_t));

    new->position = (Vector3){atof(tab[1]), atof(tab[2]), atof(tab[3])};
    new->direction = (Vector3){atof(tab[4]), atof(tab[5]), atof(tab[6])};
    new->speed = atof(tab[7]);
    new->size = atof(tab[8]);
    new->model = *getModel(game, MODEL_BATARANG);
    new->model.transform = MatrixMultiply(new->model.transform, MatrixRotateY(atan2(new->direction.x, new->direction.z)));
    new->isAlive = true;
    list_push_data(game->bullet, new);
}
#include "includes.h"

void createBullet(bullet_t *head, float speed, float size, Camera *camera)
{
    bullet_t *new = malloc(sizeof(bullet_t));
    bullet_t *tmp = head;

    new->position = (Vector3){camera->position.x, camera->position.y, camera->position.z};
    new->target = (Vector3){camera->target.x, camera->target.y, camera->target.z};
    new->direction = Vector3Normalize(Vector3Subtract(new->target, new->position));
    new->speed = speed;
    new->size = size;
    new->colors = RED;
    new->head = head;
    new->next = NULL;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}

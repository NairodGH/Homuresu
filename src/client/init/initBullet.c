#include "includes.h"

bullet_t *initListBullet(float speed, float size, Camera *camera)
{
    bullet_t *head = malloc(sizeof(bullet_t));

    head->position = (Vector3){camera->position.x, camera->position.y, camera->position.z};
    head->target = (Vector3){camera->target.x, camera->target.y, camera->target.z};
    head->direction = Vector3Normalize(Vector3Subtract(head->target, head->position));
    head->speed = speed;
    head->size = size;
    head->colors = RED;
    head->head = head;
    head->next = NULL;
    return head;
}

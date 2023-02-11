#include "includes.h"

void drawBullet(bullet_t *head)
{
    bullet_t *tmp = head;

    while (tmp != NULL) {
        DrawSphere(tmp->position, tmp->size, tmp->colors);
        DrawSphereWires(tmp->position, tmp->size, 4, 4, BLACK);
        tmp->position = Vector3Add(tmp->position, Vector3Scale(tmp->direction, tmp->speed));
        tmp = tmp->next;
    }
}

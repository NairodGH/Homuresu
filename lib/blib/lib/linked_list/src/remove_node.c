/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "linked_list.h"

void remove_node(list_t *list, list_node_t *node)
{
    if (!node || !list)
        return;
    list->lenght--;
    if (node->prev)
        node->prev->next = node->next;
    else list->head = node->next;
    if (node->next)
        node->next->prev = node->prev;
    else list->tail = node->prev;
    node->prev = NULL;
    node->next = NULL;
}

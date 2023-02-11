/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "linked_list.h"

void destroy_node(list_node_t *node, void (*destroy_data)(void *data))
{
    if (node == NULL)
        return;
    if (destroy_data)
        destroy_data(node->data);
    if (node->data)
        free(node->data);
}

/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "linked_list.h"

list_node_t *create_node(void *data)
{
    list_node_t *result = calloc(sizeof(list_node_t), 1);

    if (result) {
        result->data = data;
    }
    return result;
}

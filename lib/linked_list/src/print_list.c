/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "linked_list.h"

void print_list(list_t *list, void (*print_data)(void *))
{
    list_node_t *node_temp = NULL;

    foreach(list->head, node_temp) {
        print_data(node_temp->data);
    }
}
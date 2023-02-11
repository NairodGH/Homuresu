/*
** EPITECH PROJECT, 2022
** superheroes
** File description:
** menu.h
*/

#include "raylib.h"

#ifndef SUPERHEROES_MENU_H
    #define SUPERHEROES_MENU_H

    typedef struct menu_s {
        Camera camera;
        Vector2 mousePoint;

        Texture2D button;

        float frameHeight;
        Rectangle sourceRec;
        Rectangle btnBounds;
        int btnState;
        bool btnAction;

        int is_menu;
    } menu_t;

#endif //SUPERHEROES_MENU_H

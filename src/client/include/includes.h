/*
** EPITECH PROJECT, 2022
** kidiot.h
** File description:
** kidiot
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <ctype.h>
#include "raylib.h"
#include "raymath.h"

#include "linked_list.h"

#define MAX_COLUMNS 20

typedef struct bullet_s {
    Vector3 position;
    Vector3 direction;
    Vector3 target;
    Color colors;
    float speed;
    float size;
    struct bullet_s *next;
    struct bullet_s *head;
} bullet_t;

typedef struct cube_s {
    Vector3 position;
    float width;
    float height;
    float length;
    Color color;
} cube_t;

typedef struct sprite_s {
    Texture2D texture;
    Vector2 position;
    Vector2 origin;
    float scale;
    Color tint;
} sprite_t;


typedef struct {
    Camera camera;

} game_t;

/**
 * @brief Initialize the window
 *
 */
void initWindow(void);

/**
 * @brief Initialize the wall
 *
 * @param i
 * @param cube
 */
void initWall(int i, cube_t cube[MAX_COLUMNS]);

/**
 * @brief Initialize the camera
 *
 * @param camera
 */
void initCamera(Camera *camera);

/**
 * @brief
 *
 * @param speed
 * @param size
 * @param camera
 * @return bullet_t*
 */
bullet_t *initListBullet(float speed, float size, Camera *camera);

/**
 * @brief
 *
 * @param head
 */
void drawBullet(bullet_t *head);

/**
 * @brief
 *
 * @param camera
 * @param cube
 * @param head
 * @param sprite
 */
void drawObs(Camera *camera, cube_t cube[MAX_COLUMNS], bullet_t *head, sprite_t *sprite);

/**
 * @brief Create a Bullet object
 *
 * @param head
 * @param speed
 * @param size
 * @param camera
 */
void createBullet(bullet_t *head, float speed, float size, Camera *camera);

/**
 * @brief
 *
 * @param camera
 * @param cameraLastPosition
 * @param cube
 */
void checkCollision(Camera *camera, Vector3 cameraLastPosition, cube_t cube[MAX_COLUMNS]);

/**
 * @brief Main loop of the game
 *
 */
void mainLoop(void);

#endif /* !CLIENT_H_ */

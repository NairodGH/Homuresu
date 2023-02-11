/*
** EPITECH PROJECT, 2022
** kidiot.h
** File description:
** kidiot
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#define _GNU_SOURCE
#include "raylib.h"
#include "raymath.h"
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#include "list.h"

#define OBS_NBR 16
#define WALL_NBR 4
#define MAP_SIZE 46.0f

typedef enum {
  CROSSHAIR = 0,
} spriteName_t;

typedef struct {
  Vector3 position;
  Vector3 direction;
  Color colors;
  float speed;
  float size;
  bool isAlive;
} bullet_t;

typedef struct {
  Vector3 position;
  float width;
  float height;
  float length;
  Color color;
} cube_t;

typedef struct {
  Texture2D texture;
  Vector2 position;
  Vector2 origin;
  float scale;
  Color tint;
  char *name;
} sprite_t;

typedef struct {
  int score;
  int life;
  int ammo;
  int cooldownShoot;
  int lastShoot;
} stat_t;

typedef struct {
  Camera camera;
  Vector3 cameraLastPosition;

  list_t *cube;
  list_t *bullet;
  list_t *sprite;
  stat_t *stat;
} game_t;

/**
 * @brief
 *
 * @param screenWidth
 * @param screenHeight
 */
void initWindow(const int screenWidth, const int screenHeight);

/**
 * @brief
 *
 * @param game
 */
void initWall(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void initCube(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void initCamera(game_t *game);

/**
 * @brief
 *
 * @param speed
 * @param size
 * @param camera
 * @return bullet_t*
 */
void initBullet(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void initGame(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void initSprite(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void initStat(game_t *game);

// CREATE

/**
 * @brief Create a Bullet object
 *
 * @param game
 * @param speed
 * @param size
 */
void createBullet(game_t *game, float speed, float size);

// UPDATE

/**
 * @brief
 *
 * @param game
 */
void setupSprite(game_t *game, spriteName_t name, Vector2 position, Vector2 size, float scale, Color tint);

/**
 * @brief
 *
 * @param game
 */
void updateEnter(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void updateEvent(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void checkCollision(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void updateCollision(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void updateDeadBullet(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void updateGame(game_t *game);

// DRAW

/**
 * @brief
 *
 * @param game
 */
void drawGame(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void drawCube(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void drawBullet(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void drawSpriteTwoD(game_t *game);

// MAIN

/**
 * @brief
 *
 * @param game
 */
void mainLoop(game_t *game);

#endif /* !CLIENT_H_ */

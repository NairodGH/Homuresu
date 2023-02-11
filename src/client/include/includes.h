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

typedef struct bullet_s {
  Vector3 position;
  Vector3 direction;
  Color colors;
  float speed;
  float size;
  struct bullet_s *next;
  struct bullet_s *head;
  bool isAlive;
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


typedef enum {
  SOUND_WALK,
  SOUND_SHOOT,
} sound_e;

typedef struct {
  sound_e type;
  Sound sound;
} sound_t;

typedef struct {
  Camera camera;
  Vector3 cameraLastPosition;

  list_t *cube;
  list_t *bullet;
  list_t *sound;
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
void initSounds(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void initGame(game_t *game);

// MANAGE

/**
 * @brief Create a Bullet object
 *
 * @param game
 * @param speed
 * @param size
 */
void createBullet(game_t *game, float speed, float size);

/**
 * @brief Get the Sound object
 *
 * @param game
 * @param type
 * @return Sound*
 */
Sound *getSound(game_t *game, sound_e type);

/**
 * @brief
 *
 * @param game
 * @param type
 */
void playSound(game_t *game, sound_e type);

// UPDATE

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
void updateWalk(game_t *game);

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

// MAIN

/**
 * @brief
 *
 * @param game
 */
void mainLoop(game_t *game);

#endif /* !CLIENT_H_ */

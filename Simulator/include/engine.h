#ifndef ENGINE_FILE
#define ENGINE_FILE
#include <vector>
#include "rocket.h"
#include "init.h"

//Allegro
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

void UpdateObjects();
void RepositionSpaceShips();
void Redraw();
void DrawPoints();
void DrawLives();
void GameOver();

void DispatchKeys();
void KeyDown(ALLEGRO_EVENT);
bool KeyUp(ALLEGRO_EVENT);

bool GameContinues();
void PrintWinner();
void InitGame();

void CleanupAsteroids();
void CleanupBullets();
void CleanupSpaceships();
void Cleanup();

#endif
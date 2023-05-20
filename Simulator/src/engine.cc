#include "engine.h"
#include "config.h"
#include "spaceship.h"
#include "init.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


using namespace std;

Spaceship* spaceship;

enum MYKEYS {
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_ESCAPE, KEY_SPACE
};

bool pressedKeys[6] = { false, false, false, false, false, false };

void UpdateObjects() {
    bool restart = false;

    bool lives = spaceship->Update();
}

void RepositionSpaceships() {
    spaceship->x = 300;
    spaceship->y = 600;
    spaceship->speed = 0;
    spaceship->age = 0;
}

void Redraw() {
    al_clear_to_color(al_map_rgb(0,0,0));
    spaceship->Draw();
    DrawPoints();
    DrawLives();
    al_flip_display();
}

void DrawPoints() {
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform); 
    al_rotate_transform(&transform, 0); 
    al_translate_transform(&transform, 0, 0); 
    al_use_transform(&transform);
    al_draw_text(
                 font, 
                 al_map_rgb(0, 0, 255), 
                 SCREEN_W - 40, 20, ALLEGRO_ALIGN_RIGHT, 
                 "Hello"); 
    // In case of multiplayer, draw points here
}

void DrawLives() {
    int s = 0;
    ALLEGRO_COLOR color = al_map_rgb(0, 255, 0);
    ALLEGRO_TRANSFORM transform; 
    al_identity_transform(&transform); 
    al_rotate_transform(&transform, 0); 
    al_translate_transform(&transform, 20 * (1), 20); 
    al_use_transform(&transform);
    al_draw_line(-8, 9, 0, -11, color, 3.0f); 
    al_draw_line(0, -11, 8, 9, color, 3.0f); 
    al_draw_line(-6, 4, -1, 4, color, 3.0f); 
    al_draw_line(6, 4, 1, 4, color, 3.0f);
}

void InitGame() {
    Spaceship* spaceship = new Spaceship(300, 300, rocketStartSpeed);
    BOOST_LOG_TRIVIAL(info) << "engine.cc:160 Points " << spaceship->points;
}

bool GameContinues() {
    PrintWinner();
    return true;
}

void PrintWinner() {
    BOOST_LOG_TRIVIAL(info) << "engine.cc:169 Print Winner";
    al_clear_to_color(al_map_rgb(0, 0, 0 ));
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, 0);
    al_translate_transform(&transform, 0, 0);
    al_use_transform(&transform);
    BOOST_LOG_TRIVIAL(info) << "engine.cc:176 Transform";
    //int bufferSize = 40;
    //char buffer[bufferSize];
    BOOST_LOG_TRIVIAL(info) << "engine.cc:179 Points";
    //sprintf(buffer, "Total points: %d", spaceship->points);
    al_draw_text(
                 font,
                 al_map_rgb(120,120,120),
                 400, 200, ALLEGRO_ALIGN_RIGHT,
                 "A winner is you!");
    /*al_draw_text(
                 font,
                 al_map_rgb(120,120,120),
                 400, 250, ALLEGRO_ALIGN_RIGHT,
                 buffer);*/
    al_draw_text(
             font,
             al_map_rgb(0,255,0),
             120, 120, ALLEGRO_ALIGN_RIGHT,
             "very winner");
    al_draw_text(
             font,
             al_map_rgb(255,0,0),
             450, 450, ALLEGRO_ALIGN_RIGHT,
             "much points");
    al_draw_text(
             font,
             al_map_rgb(0,0,255),
             600, 120, ALLEGRO_ALIGN_RIGHT,
             "such asteroids");
    al_flip_display();
    al_rest(2.0);
};

void GameOver() {
    al_clear_to_color(al_map_rgb(0, 0, 0 ));
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, 0);
    al_translate_transform(&transform, 0, 0);
    al_use_transform(&transform);
    al_draw_text(
                 font,
                 al_map_rgb(120,120,120),
                 400, 200, ALLEGRO_ALIGN_RIGHT,
                 "Game Over!");
    al_flip_display();
    al_rest(2.0);
}
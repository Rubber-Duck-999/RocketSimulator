#include "engine.h"
#include "config.h"
#include "rocket.h"
#include "init.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


using namespace std;

Rocket* rocket;

enum MYKEYS {
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_ESCAPE, KEY_SPACE
};

bool pressedKeys[6] = { false, false, false, false, false, false };

void UpdateObjects() {
    bool restart = false;

    bool lives = rocket->Update();
}

void Repositionrockets() {
        rocket->x = 300;
        rocket->y = 600;
        rocket->speed = 0;
        rocket->age = 0;
}

void Redraw() {
    al_clear_to_color(al_map_rgb(0,0,0));
    rocket->Draw();
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
    int bufferSize = 40;
    char buffer[bufferSize];
    sprintf(buffer, "Points: %d", rocket->points);
    al_draw_text(
                 font, 
                 al_map_rgb(0, 0, 255), 
                 SCREEN_W - 40, 20, ALLEGRO_ALIGN_RIGHT, 
                 buffer); 
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

void DispatchKeys() {
    if(pressedKeys[KEY_UP]) {
        rocket->accelerate();
    }
 
    if(pressedKeys[KEY_DOWN]) {
        rocket->decelerate();
    }

    if(pressedKeys[KEY_LEFT]) {
        rocket->moveLeft();
    }

    if(pressedKeys[KEY_RIGHT]) {
        rocket->moveRight();
    }

    if(pressedKeys[KEY_SPACE]) {
        cout << "Move" << endl;
    }
}

void KeyDown(ALLEGRO_EVENT event) {
    switch(event.keyboard.keycode) {
        case ALLEGRO_KEY_UP:
            pressedKeys[KEY_UP] = true;
            break;

        case ALLEGRO_KEY_DOWN:
            pressedKeys[KEY_DOWN] = true;
            break;

        case ALLEGRO_KEY_LEFT: 
            pressedKeys[KEY_LEFT] = true;
            break;

        case ALLEGRO_KEY_RIGHT:
            pressedKeys[KEY_RIGHT] = true;
            break;

        case ALLEGRO_KEY_SPACE:
            pressedKeys[KEY_SPACE] = true;
            break;
    }
}


bool KeyUp(ALLEGRO_EVENT event) {
    switch(event.keyboard.keycode) {
        case ALLEGRO_KEY_UP:
            pressedKeys[KEY_UP] = false;
            rocket->acceleration = 0;
            return false;
            break;

        case ALLEGRO_KEY_DOWN:
            pressedKeys[KEY_DOWN] = false;
            return false;
            break;

        case ALLEGRO_KEY_LEFT: 
            pressedKeys[KEY_LEFT] = false;
            return false;
            break;

        case ALLEGRO_KEY_RIGHT:
            pressedKeys[KEY_RIGHT] = false;
            return false;
            break;

        case ALLEGRO_KEY_SPACE:
            pressedKeys[KEY_SPACE] = false;
            return false;
            break;

        case ALLEGRO_KEY_ESCAPE:
            return true;
            break;
    }
    return true;
}

void InitGame() {
    Rocket* rocket = new Rocket(300,300, rocketStartSpeed);
}

void PrintWinner() {
    al_clear_to_color(al_map_rgb(0, 0, 0 ));
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, 0);
    al_translate_transform(&transform, 0, 0);
    al_use_transform(&transform);
    int bufferSize = 40;
    char buffer[bufferSize];
    sprintf(buffer, "Total points: %d", rocket->points);
    al_draw_text(
                 font,
                 al_map_rgb(120,120,120),
                 400, 200, ALLEGRO_ALIGN_RIGHT,
                 "A winner is you!");
    al_draw_text(
                 font,
                 al_map_rgb(120,120,120),
                 400, 250, ALLEGRO_ALIGN_RIGHT,
                 buffer);

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
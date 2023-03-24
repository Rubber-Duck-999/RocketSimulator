#ifndef _OBJ_FILE_
#define _OBJ_FILE_

#include <stdio.h>
#include <allegro5/allegro.h>
#include "init.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/transformations.h>

const float deltaSpeed = .5;
const float deltaDegree = .09;

class Rocket {
public:
    Rocket(int x, int y, float speed);
    ~Rocket();
    void Draw();
    void moveLeft(const float delta = deltaDegree);
    void moveRight(const float delta = deltaDegree);
    void accelerate(const float delta = deltaSpeed);
    void decelerate(const float delta = deltaSpeed);
    bool Update();
    void DebugPrint();
    int x;
    int y;
    float dx;
    float dy;
    double direction; 
    float speed;
    int live; 
    ALLEGRO_COLOR color;
    int lives;
    int points;
    int age;
    float acceleration;
};

#endif
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/transformations.h>
#include "spaceship.h"
#include <iostream>
#include <math.h>
#include "init.h"
#include "config.h"
#include <cstdlib>

using namespace std;

void Spaceship::DebugPrint() {
	cout << "The follwing is a Spaceship!" << endl;
	cout << "X is :" << x << endl;
	cout << "Y is :" << y << endl;
	cout << "Direction is :" << direction << endl;
	cout << "Speed is :" << speed << endl;
}

Spaceship::Spaceship(int x, int y, float speed) {
	this->x = x;
	this->y = y;
	this->direction = 0;
	this->speed = speed;
	this->live = 1;
	this->color = al_map_rgb(0, 0, 0);
	this->color = al_map_rgb(255, 0, 0);
	this->direction = 0;
	this->lives = startingLives;
	this->age = 0;
}

Spaceship::~Spaceship() {

}

void Spaceship::Draw() {
	if (age > 120 || age % 2 == 0) {
		ALLEGRO_COLOR color = this->color;
		ALLEGRO_TRANSFORM transform; 
		al_identity_transform(&transform); 
		al_rotate_transform(&transform, direction); 
		al_translate_transform(&transform, x, y); 
		al_use_transform(&transform);
		al_draw_line(-8, 9, 0, -11, color, 3.0f); 
		al_draw_line(0, -11, 8, 9, color, 3.0f); 
		al_draw_line(-6, 4, -1, 4, color, 3.0f); 
		al_draw_line(6, 4, 1, 4, color, 3.0f);
	} else {
		ALLEGRO_COLOR color = al_map_rgb(0, 255, 0);
		ALLEGRO_TRANSFORM transform; 
		al_identity_transform(&transform); 
		al_rotate_transform(&transform, direction); 
		al_translate_transform(&transform, x, y); 
		al_use_transform(&transform);
		al_draw_line(-8, 9, 0, -11, color, 3.0f); 
		al_draw_line(0, -11, 8, 9, color, 3.0f); 
		al_draw_line(-6, 4, -1, 4, color, 3.0f); 
		al_draw_line(6, 4, 1, 4, color, 3.0f);
	}

}

void Spaceship::moveLeft(const float delta) {
	this->direction -= delta;
}

void Spaceship::moveRight(const float delta) {
	this->direction += delta;
}

void Spaceship::accelerate(const float delta) {
	acceleration += delta;
	if (acceleration > maxAcceleration) {
		acceleration = maxAcceleration;
	}
}

void Spaceship::decelerate(const float delta) {
	if (speed == 0) {
		return;
	}
	acceleration -= delta;
	if (acceleration < - maxAcceleration) {
		acceleration = - maxAcceleration;
	}
}

bool Spaceship::Update() {
	speed += acceleration;
	if (speed > maxSpeed) {
		speed = maxSpeed;
	}
	if (speed < 0) {
		speed = 0;
	}
	if (cylinder) {
		x = (x % SCREEN_W + SCREEN_W) % SCREEN_W;
	}
	if (torus) {
		y = (y % SCREEN_H + SCREEN_H) % SCREEN_H;
	}
	if (age <= secondsOfInvincibility * FPS) {
		age += 1;
	}
	// check for collisions is on engine.cpp
	return true;
}

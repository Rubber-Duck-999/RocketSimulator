#include <iostream>
#include "rocket.h"


Rocket::Rocket(float angle) {
	this->angle = angle;
}

Rocket::~Rocket() {

}

void Rocket::Draw() {
	std::cout << "Draw me!" << std::endl;
}
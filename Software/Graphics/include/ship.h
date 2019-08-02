#include "data_structure.h"
#include <string>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>

#ifndef SHIP_h
#define	SHIP_h

class Ship: public sf::Sprite
{
    float speed, accel;
    float x_vel, y_vel;
    float x_axis, y_axis;

    sf::Texture texture;
public:
    Ship()
    {
        texture.loadFromFile(rocket_simulator::kRocketImage);
        setTexture(texture);

        sf::Vector2f origin;
        origin.x = getTextureRect().width / 2;
        origin.y = getTextureRect().height / 2;
        setOrigin(origin);

        x_vel = 0.0;
        y_vel = 0.0;
        accel = 30;
        speed = 100;
    }

    void update(float x_axis, float y_axis, float angle_change)
    {

        setRotation(-1 * angle);

        setPosition(x_axis, y_axis);
    }
};

#endif
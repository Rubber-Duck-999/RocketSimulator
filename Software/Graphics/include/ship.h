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

        x_vel = 0;
        y_vel = 0;
        accel = 30;
        speed = 100;
    }

    void update(float dt, float angle_change)
    {
        sf::Vector2f position = getPosition();
        float angle = angle_change;

        setRotation(-1 * angle);

        x_vel = cos(angle) * speed;
        y_vel = sin(angle) * speed;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            move(x_vel * dt, y_vel * dt);
        }

        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            move(-x_vel * dt, -y_vel * dt);
        }
    }
};

#endif
#include "graphics.h"

class Game
{
public:
    void main(sf::RenderWindow& window, float launch_angle)
    {
        Ship rocket;
        rocket.setPosition(400, 400);

        sf::Clock clock;
        while (window.isOpen())
        {
            float dt = clock.restart().asSeconds();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }
            window.clear();

            sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(window));
            rocket.update(dt, launch_angle);

            window.draw(rocket);
            window.display();
        }
    }
};

void Graphics::RunRocket(double launch_angle)
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
    float angle = static_cast<float>(launch_angle);
    Game().main(window, angle);
}

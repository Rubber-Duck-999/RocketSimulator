#include "graphics.h"

class Game
{
public:
    void main(sf::RenderWindow& window, float launch_angle)
    {
        Ship rocket;
        rocket.setPosition(400, 400);

        float x_axis = 0.0;
        float y_axis = 0.0;

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
            rocket.update(x_axis, y_axis, launch_angle);
            x_axis = x_axis + 10;
            y_axis = y_axis + 10;
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

#include "graphics.h"

Graphics::Graphics()
{
    RunWindow();
}

void Graphics::RunWindow()
{
    BOOST_LOG_TRIVIAL(debug) << "Running Graphics ";
    namespace data = rocket_simulator;
    sf::RenderWindow window(sf::VideoMode(data::kWindowSizeHori, data::kWindowSizeVert), data::kWindowName, sf::Style::Close);
    /////////////////////////////////////////////
    // Texture
    sf::Texture rocket_texture;
    if(!rocket_texture.loadFromFile(data::kRocketImage, sf::IntRect(10, 10, 32, 32)))
    {
        BOOST_LOG_TRIVIAL(error) << "Error loading Rocket Image";
    }
    rocket_texture.setSmooth(true);
    /////////////////////////////////////////////

    /////////////////////////////////////////////
    // Entity
    sf::Sprite rocket_sprite;
    //rocket_sprite.setTexture(rocket_texture);
    rocket_sprite.setRotation(90.f); 
    // absolute angle
    //rocket_sprite.setOrigin(sf::Vector2f(400.f, 500.f));
    /////////////////////////////////////////////

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(rocket_sprite);
        window.display();
    }
}



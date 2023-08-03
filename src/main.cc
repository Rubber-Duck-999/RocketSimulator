#include "logging.h"
#include "interface.h"
#include "init.h"
#include "engine.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

void must_init(bool test, const char *description)
{
    if (test)
        return;

    BOOST_LOG_TRIVIAL(info) << "main.cc:10 couldn't initialize %s\n"
                            << description;
}

int main()
{
    init_log();
    Interface out;
    if (InitAllegro(60, 1920, 1080))
    {
        BOOST_LOG_TRIVIAL(info) << "main.cc:11 We have set up allegro correctly";
    }
    else
    {
        BOOST_LOG_TRIVIAL(info) << "main.cc:13 We have set up allegro incorrectly";
    }
    bool redraw = true;
    InitGame();

    al_flip_display();
    al_start_timer(timer);

    must_init(al_init_image_addon(), "image addon");
    ALLEGRO_BITMAP *milkyway = al_load_bitmap("/home/simon/Documents/RocketSimulator/milkyway.jpg");
    must_init(milkyway, "milkyway");
    ALLEGRO_BITMAP *spaceship = al_load_bitmap("/home/simon/Documents/RocketSimulator/spaceship.png");
    must_init(spaceship, "spaceship");
    must_init(al_init_primitives_addon(), "primitives");

    ALLEGRO_EVENT event;

    out.RunSimulation();
    std::map<double, double> coordinates = out.GetCoordinates();
    BOOST_LOG_TRIVIAL(info) << "main.cc: Coordinates: " << coordinates.size();
    if(coordinates.size() < 1)
    {
        return 0;
    }
    int index = 0;
    for(auto const &[key, val] : coordinates)
    {
        BOOST_LOG_TRIVIAL(trace) << "main.cc:24 Running through allegro loop";
        al_wait_for_event(event_queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            // game logic goes here.
            redraw = true;
            break;
        }

        if(redraw && al_is_event_queue_empty(event_queue))
        {
            if (index % 10 == 0) {
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_draw_text(font, al_map_rgb(0, 0, 0), 0, 0, 0, "Hello world!");

                al_draw_bitmap(milkyway, 0, 0, 0);
                al_draw_bitmap(spaceship, key, val, 45);
                BOOST_LOG_TRIVIAL(trace) << "main.cc:24 " << key << ", " << val;

                std::string x_string = std::to_string(key);
                al_draw_text(
                    font,
                    al_map_rgb(255, 255, 255),
                    100, 200, ALLEGRO_ALIGN_RIGHT,
                    x_string.c_str());

                al_flip_display();

                redraw = false;
            }
        }
        index++;
    }
    GameOver();
    return 0;
}

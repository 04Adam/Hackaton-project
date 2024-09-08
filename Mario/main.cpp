#include <SFML/Graphics.hpp>
#include "Objects.h"
using namespace std;
int main()
{
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");
    MarioClass Mario;
    while (app.isOpen())
    {

        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                app.close();
        }
        app.clear();
        Mario.draw(&app);
        app.display();
    }

    return EXIT_SUCCESS;
}

#include <SFML/Graphics.hpp>
#include "Objects.h"
#include <iostream>
using namespace std;

int main()
{
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");
    sf::RectangleShape Ground(sf::Vector2f(2000,50));
    Ground.setPosition(0,200);
    Ground.setFillColor(sf::Color::Green);
    KorwinClass Korwin;
    app.setKeyRepeatEnabled(true);
    while (app.isOpen())
    {

        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                app.close();
        }
        app.clear(sf::Color::White);
        Korwin.Move();
        Korwin.ChangeWeapon(event);
        Korwin.Walk(event);
       // Korwin.Gravity();
        app.draw(Ground);
        Korwin.draw(&app);
        Korwin.show();
        app.display();
    }

    return EXIT_SUCCESS;
}

#include <SFML/Graphics.hpp>
#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED
class MarioClass{
private:
    sf::Texture mario_t;
    sf::Sprite mario_s;
public:
    MarioClass();
    void draw(sf::RenderWindow *app){
        app->draw(mario_s);
    }
};


#endif // OBJECTS_H_INCLUDED

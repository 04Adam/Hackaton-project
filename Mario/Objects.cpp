#include <SFML/Graphics.hpp>
#include "Objects.h"
MarioClass::MarioClass(){
    mario_t.loadFromFile("mario1.png");
    mario_s.setTexture(mario_t);
    mario_s.setScale(.1,.1);
}

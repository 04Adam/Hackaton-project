#include <SFML/Graphics.hpp>
#include "Objects.h"
KorwinClass::KorwinClass(){
    JumpPower = -100;
    korwin1_t.loadFromFile("Korwin1.png");
    korwin2_t.loadFromFile("Korwin2.png");
    korwin_s.setTexture(korwin1_t);
    korwin_s.setScale(2.5,2.5);
    korwin_s.setPosition(0,150);
    Weapon = 0;
    WeaponCooldown = 0;
}
void KorwinClass::Move(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        this -> korwin_s.move(0.1,0);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        this -> korwin_s.move(-0.1,0);
    }
    if(this -> JumpPower == -100 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        JumpPower = 0.5;
    }
    if(JumpPower >= -0.5){
        this -> korwin_s.move(0,-JumpPower);
        this -> JumpPower -= 0.001;
        if(JumpPower <= -0.5)
            JumpPower = -100;
    }
}
void KorwinClass::draw(sf::RenderWindow *app){
    app->draw(korwin_s);
}
void KorwinClass::ChangeWeapon(sf::Event event){
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down && this -> WeaponCooldown == 0){
        if(this -> Weapon == 0){
            this -> korwin_s.setTexture(korwin2_t);
            this -> Weapon = 1;
            WeaponCooldown = 300;
        }
        else{
            this -> korwin_s.setTexture(korwin1_t);
            this -> Weapon = 0;
            WeaponCooldown = 300;
        }
    }
    if(this -> WeaponCooldown > 0)
        this -> WeaponCooldown--;
}
/*void KorwinClass::Gravity(){
    if(Jump && this -> korwin_s.getPosition().y < 50)
        this -> korwin_s.move(0,.4);
    if(this -> korwin_s.getPosition().y >= 50)
        Jump = 0;
} */

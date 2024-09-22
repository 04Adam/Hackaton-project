#include <SFML/Graphics.hpp>
#include "Objects.h"
#include <iostream>
KorwinClass::KorwinClass(){
    JumpPower = -100;
    korwin1_t.loadFromFile("Korwin1.png");
    korwin2_t.loadFromFile("Korwin2.png");
    korwinw1_t.loadFromFile("KorwinW1.png");
    korwinw2_t.loadFromFile("KorwinW2.png");
    korwinw3_t.loadFromFile("KorwinW3.png");
    korwin_s.setTexture(korwin1_t);
    korwin_s.setScale(2.5,2.5);
    korwin_s.setPosition(0,200);
    korwin_s.setOrigin({10,20});

    Weapon = false;
    Direction = true;
    isRolling = false;
    WeaponCooldown = 0;
    WalkAnimation = 0;
    RollingPhase = 0;
    RollDir = 0;
}
void KorwinClass::Move(){

    // Walk right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !isRolling){
        if(this -> Direction == 0){
            Direction = !Direction;
            korwin_s.move(-10,0);
        }
        this -> korwin_s.setScale(2.5,2.5);
        this -> korwin_s.move(0.3,0);
    }
    // Walk left
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !isRolling){
        if(this -> Direction){
            Direction = !Direction;
            korwin_s.move(10,0);
        }
        this -> korwin_s.setScale(-2.5,2.5);
        this -> korwin_s.move(-0.3,0);
    }

    // Jumping script

    if(this -> JumpPower == -100 && sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this -> JumpPower = 0.5;
    }
    if(JumpPower >= -0.5){
        this -> korwin_s.move(0,-JumpPower*1.75);
        this -> JumpPower -= 0.002;
        if(JumpPower <= -0.5){
            this -> Weapon == 0 ? this -> korwin_s.setTexture(this -> korwin1_t) : this -> korwin_s.setTexture(this -> korwin2_t);
            this -> JumpPower = -100;
            this -> korwin_s.move(0,0.75);
        }

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
void KorwinClass::Walk(sf::Event event){
    if(JumpPower == -100 && !isRolling){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) ){
            if(this -> WalkAnimation < 100)
                this -> korwin_s.setTexture(this -> korwinw1_t);
            else if(this -> WalkAnimation >= 100 && this -> WalkAnimation < 200)
                this -> korwin_s.setTexture(this -> korwinw2_t);
            else if(this -> WalkAnimation >= 200 && this -> WalkAnimation < 300)
                this -> korwin_s.setTexture(this -> korwinw3_t);
            this -> WalkAnimation++;
            this -> WalkAnimation %= 300;

        }
        else if(event.type == sf::Event::KeyReleased && (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::A)){
            this -> WalkAnimation = 0;
            this -> Weapon == 0 ? this -> korwin_s.setTexture(this -> korwin1_t) : this -> korwin_s.setTexture(this -> korwin2_t);
        }
    }
}
void KorwinClass::show(){
    std::cout << this -> korwin_s.getPosition().y << '\n';
}
void KorwinClass::Roll(sf::Event event){
    if(event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Left) && !isRolling && JumpPower == -100){
        isRolling = true;
        if(event.key.code == sf::Keyboard::Right)
            this -> RollDir = 1;
        else if(event.key.code == sf::Keyboard::Left)
            this -> RollDir = -1;
    }
    if(isRolling){
        RollingPhase++;
        this -> korwin_s.rotate(RollDir);
        this -> korwin_s.move(double(this -> RollDir)/2,0);
        if(RollingPhase >= 360){
            RollingPhase = 0;
            isRolling = false;
        }
    }
}
/*void KorwinClass::Gravity(){
    if(Jump && this -> korwin_s.getPosition().y < 50)
        this -> korwin_s.move(0,.4);
    if(this -> korwin_s.getPosition().y >= 50)
        Jump = 0;
} */

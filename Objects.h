#include <SFML/Graphics.hpp>
#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED
class KorwinClass{
private:
    sf::Texture korwin1_t, korwin2_t;
    sf::Sprite korwin_s;
    double JumpPower;
    bool Weapon;
    int WeaponCooldown;
public:
    KorwinClass();
    void draw(sf::RenderWindow *app);
    void Move();
    void Shot();
    void Gravity();
    void ChangeWeapon(sf::Event event);
};


#endif // OBJECTS_H_INCLUDED

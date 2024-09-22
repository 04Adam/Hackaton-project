#include <SFML/Graphics.hpp>
#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED
class KorwinClass{
private:
    sf::Texture korwin1_t, korwin2_t, korwinw1_t, korwinw2_t, korwinw3_t, korwinw4_t, korwinw5_t;
    sf::Sprite korwin_s;
    double JumpPower;
    double RollDir;
    bool Direction; // 1 - right, 0 - left
    bool Weapon;    // 1 - gun, 0 - nothing
    bool isRolling; // 1 - rolling, nothing
    int WeaponCooldown;
    int WalkAnimation;
    float RollingPhase;
public:
    KorwinClass();
    void draw(sf::RenderWindow *app);
    void Move();
    void Shot();
    void Gravity();
    void ChangeWeapon(sf::Event event);
    void Walk(sf::Event event);
    void show();
    void Roll(sf::Event event);

};


#endif // OBJECTS_H_INCLUDED

#ifndef E_ESTATICO_H
#define E_ESTATICO_H
#include "Bullet.h"
#include "Map.h"
#include "SFML/Graphics.hpp"
using namespace sf;
class E_estatico : public Map
{
public:
    E_estatico(Vector2f size, Vector2f tam);
    void setPos(sf::Vector2f newPos);
    int vidas = 900;
    int game_over = 0;
    bool estado = true;
    void checkColl(Bullet bullet);
    int get_X();
    int get_Y();
    Sprite soldier;
    void draw(RenderWindow &window);

private:
    Texture contra;
    RectangleShape enemy;
};

#endif // E_ESTATICO_H

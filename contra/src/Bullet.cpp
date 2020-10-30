#include "Bullet.h"
#include <SFML/Graphics.hpp>
using namespace sf;
Bullet::Bullet()
{

}
Bullet::Bullet(Vector2f size)
{
    bullet.setSize(size);
    bullet.setFillColor(Color::White);
}

 void Bullet::fire(float speed)
{
    bullet.move(speed,0);
}

int Bullet::getRight()
{
    return bullet.getPosition().x + bullet.getSize().x;
}
int Bullet::getLeft()
{
    return bullet.getPosition().y ;
}
int Bullet::getTop()
{
    return bullet.getPosition().y;
}
int Bullet::getBottom()
{
    return bullet.getPosition().y + bullet.getSize().y;
}

void Bullet::draw(RenderWindow &window)
{
    window.draw(bullet);
}

void Bullet::setPos(Vector2f newPos)
{
    bullet.setPosition(newPos);
}

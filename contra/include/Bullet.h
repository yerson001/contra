#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet {
public:

    Bullet();

    Bullet(Vector2f size);

    void fire(float speed);

    int getRight();

    int posX(){return bullet.getPosition().x;};

    int posY(){return bullet.getPosition().y;};

    int getLeft();

    int getTop();

    int getBottom();

    void draw(RenderWindow &window);

    void setPos(Vector2f newPos);

private:
    RectangleShape bullet;
};


#endif // BULLET_H

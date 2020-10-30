#include "E_estatico.h"
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <iostream>
using namespace sf;
using namespace std;

E_estatico::E_estatico(Vector2f size,Vector2f tam)
{
   enemy.setSize(size);
   soldier.setScale(tam);
   contra.loadFromFile("enemy.png");
   soldier.setTexture(contra);
   enemy.setFillColor(Color::Transparent); //////////////////////color
}

void E_estatico::setPos(Vector2f newPos) {
        enemy.setPosition(newPos);
        soldier.setPosition(newPos);
    }

void E_estatico::checkColl(Bullet bullet) {
        if (bullet.getRight() > enemy.getPosition().x && bullet.getTop() < enemy.getPosition().y + enemy.getSize().y && bullet.getBottom() > enemy.getPosition().y)
            {
            vidas = vidas - 1;
            enemy.setPosition(Vector2f(soldier.getPosition().x +5 , soldier.getPosition().y));
            soldier.setPosition(soldier.getPosition().x + 5 ,soldier.getPosition().y);

            if(vidas==0){
                    game_over  = game_over +1;
                    soldier.setColor(Color::Transparent);
                    enemy.setFillColor(Color::Transparent);
                    estado = false;
                    cout<<game_over<<endl;
            }

            }
    }

void E_estatico::draw(sf::RenderWindow &window) {
        window.draw(enemy);
        window.draw(soldier);
    }
int E_estatico::get_X() {
        this->enemy.getPosition().x;
    }

int E_estatico::get_Y() {
        this->enemy.getPosition().y;
    }

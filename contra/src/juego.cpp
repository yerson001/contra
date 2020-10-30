#include "juego.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

juego::juego()
{
    evento = new Event;
    division.x= 11;//devlaramos ento para las  11 imagnes que disponemos
    division.y = 3;//nustra imagentiene 3 x 11 imagenes
    frane_pos.x = 0; // va iniciar con el el primer sprite 00
    frane_pos.y = 0; // en y el sprite
    posvolteo = 1; // para poder voltear la imagen
    cargar_recurso();//para cargar los franes
}

void juego::eventos()
{
while(ventana->pollEvent(*evento))
    {
        switch(evento->type)
        {
            case Event::Closed:
                exit(1);
                break;
            case Event::KeyPressed:
            set_frane(*sprite1,{frane_pos});

            if(Keyboard::isKeyPressed(Keyboard::D))
                {
                sprite1->setPosition(sprite1->getPosition().x + 4,sprite1->getPosition().y);
                        if(frane_pos.x < division.x -7 )
                            frane_pos.x++;
                        else{
                            frane_pos.x = 0;
                            set_frane(*sprite1,frane_pos);
                        posvolteo = 1;
                        //set_frane(*sprite1,{0,0});

                        }
                   }
            else if(Keyboard::isKeyPressed(Keyboard::A))
                    {
                    sprite1->setPosition(sprite1->getPosition().x - 4,sprite1->getPosition().y);
                        if(frane_pos.x < division.x -4)
                            frane_pos.x++;
                        else
                            frane_pos.x = 2;
                            set_frane(*sprite1,frane_pos);
                        posvolteo = -1;
                    }
            else if(Keyboard::isKeyPressed(Keyboard::W))
            {
                set_frane(*sprite1,{8,0});
                if(posvolteo == -1)
                {
                    set_frane(*sprite1,{9,0});
                }
            }
             else if(Keyboard::isKeyPressed(Keyboard::S))
            {
                set_frane(*sprite1,{7,0});
                if(posvolteo == -1)
                {
                    set_frane(*sprite1,{8,0});
                }
            }
            break;
        }
    }
}

void juego::set_frane(Sprite &jugador, Vector2i numerof)
{
    IntRect posicion(numerof.x * (jugador.getTexture()->getSize().x / division.x)+2,numerof.y * (jugador.getTexture()->getSize().y / division.y)+4,jugador.getTexture()->getSize().x / division.x * posvolteo,jugador.getTexture()->getSize().y / division.y);
    jugador.setTextureRect(posicion);
}

void juego::cargar_recurso()
{
    textura1 = new Texture;
    textura1->loadFromFile("newsprite.png");
    sprite1 = new Sprite(*textura1);
    sprite1->setScale(0.6,0.6);
    sprite1->setPosition(100,50);

    textura2 = new Texture;
    textura2->loadFromFile("map.png");
    sprite2 = new Sprite(*textura2);
    sprite2->setScale(0.2,0.2);
    sprite2->setPosition(0,30);


    View vista(FloatRect(260 , 395 , 600 , 500));
    vista.setSize( 1120 , 1280 );
    vista.zoom(0.2);

    set_frane(*sprite1,{0,0});// el numero de frane (0,0)
}

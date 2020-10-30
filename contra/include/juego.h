#include <SFML/Graphics.hpp>
#include <iostream>
#ifndef JUEGO_H
#define JUEGO_H

using namespace sf;
using namespace std;

class juego
{
    public:
        juego();
        void dibujar();
        void gameloop();
        void cargar_recurso();
        void eventos();
        void set_frane(Sprite &jugador, Vector2i numerof);

    private:
        int fps;
        Event *evento;
        Vector2i division;
        Vector2i frane_pos;
        int posvolteo;

        Texture *textura1;
        Sprite *sprite1;

        Texture *textura2;
        Sprite *sprite2;
        View *vista;


};

#endif // JUEGO_H

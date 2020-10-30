#ifndef PERSONAJE_H
#define PERSONAJE_H


class personaje
{
    public:
        personaje();
        void cargar_recurso();
        void set_frane(Sprite &fulanito, Vector2i numerof);
        void eventos();
    private:
        Vector2i division;
        Vector2i frane_pos;
        int posvolteo;

        Texture *textura1;
        Sprite *sprite1;

        Texture *textura2;
        Sprite *sprite2;
        View *vista;
};

#endif // PERSONAJE_H

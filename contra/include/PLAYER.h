#ifndef PLAYER_H
#define PLAYER_H
#include "Bullet.h"
#include "Map.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
using namespace sf;
template<typename P , typename W>

class PLAYER : public Map {

public:

    P distanceX,distanceY; // distance
    int playervidas = 1000;
    FloatRect rect;
    bool onGround;
    Sprite sprite;
    Vector2f tamsprite;
    bool jum;
    P currentFrame;

        PLAYER(Texture &image)
       {
        sprite.setTexture(image);
        rect = FloatRect(32,32,25,40);

        distanceX = distanceY = 0.1;
        currentFrame = 0;
       }


       void update(P time,P offsetX_,P offsetY_, P down)
       {
         Vector2f tamsprite(38.7,40);
         rect.left = rect.left + distanceX * time;
         Collision(0);

         if (!onGround)
            {
            distanceY = distanceY+0.0005*time;
            rect.top = rect.top  + distanceY*time;
            }

         onGround=false;
         Collision(1);


         currentFrame += time * 0.005;
         if (currentFrame > 3) currentFrame -= 3;


        if (distanceX>0)
            sprite.setTextureRect(IntRect(40*W(currentFrame),0,tamsprite.x,tamsprite.y));
        if (distanceX<0)
            sprite.setTextureRect(IntRect(40*W(currentFrame)+40,0,tamsprite.x*-1,tamsprite.y));
//        if (down == 1)
//            sprite.setTextureRect(IntRect(40*W(currentFrame)+40,0,tamsprite.x*-1,tamsprite.y));


        if (jum == true)
           sprite.setTextureRect(IntRect(40*W(currentFrame),40,tamsprite.x,tamsprite.y));
         sprite.setPosition(rect.left - offsetX_ , rect.top - offsetY_);
         jum = false;
         distanceX=0;
       }


      void checkColli(Bullet bullet) {
        if (bullet.getRight() <= mypos.getPosition().x && bullet.getTop() < mypos.getPosition().y + mypos.getSize().y && bullet.getBottom() > mypos.getPosition().y)
            {
             playervidas = playervidas -1;
            mypos.setPosition(Vector2f(sprite.getPosition().x - 20 , mypos.getPosition().y));
            }
            if(playervidas == 0)
            {
                cout<<"persidte"<<endl;
            }

    }


       void Collision(W num)
    {

        for (int i = rect.top/cons ; i<(rect.top+rect.height)/cons; i++){
                for (int j = rect.left/cons; j<(rect.left+rect.width)/cons; j++)
                 {
                     if ((nivel[i][j]=='P') || (nivel[i][j]=='k') || (nivel[i][j]=='0') || (nivel[i][j]=='r') || (nivel[i][j]=='t'))
                            {
                                if (distanceY>0 && num == 1) // oliin en
                                { rect.top = i*cons -  rect.height;
                                  distanceY=0;
                                  onGround=true;
                                }
                                if (distanceY<0 && num==1)
                                    {
                                      rect.top = i*cons + cons;
                                      distanceY=0;
                                    }
                                if (distanceX>0 && num==0)
                                    {
                                      rect.left =  j*cons -  rect.width;
                                    }
                                if (distanceX<0 && num==0)
                                    {
                                     rect.left =  j*cons +cons;
                                     }
                            }

                     if (nivel[i][j]=='c') {
                                            nivel[i][j]=' ';
                                            playervidas = playervidas +50;
                                             }
                 }
                 }
    }

 void recta(Vector2f size)
{
   mypos.setSize(size);
   mypos.setFillColor(Color::Transparent);
}
void setPos_g(Vector2f newPos) {
        mypos.setPosition(newPos);
    }
void draw(RenderWindow &window) {
        window.draw(mypos);
    }

private:
    RectangleShape mypos;
    int cons = 16;


};


#endif // PLAYER_H

#ifndef ENEMY_H
#define ENEMY_H
#include "SFML/Graphics.hpp"
#include "Map.h"
using namespace sf;
template <typename T,typename M>
class ENEMY : public Map
{

public:
    T dx,dy;
    int con = 16;
    FloatRect rect;
    Sprite sprited;
    T currentFrame;
    bool life;
       void set(Texture &image, M x, M y)
       {
        sprited.setTexture(image);
        rect = FloatRect(x,y,10,10);

        dx=0.05;
        currentFrame = 0;
        life=true;
       }

       void update(T time,T _offsetX,T _offsetY)
       {
         rect.left += dx * time;

         Collision();


         currentFrame += time * 0.005;
         if (currentFrame > 2)
        {
            currentFrame = currentFrame - 2;
            sprited.setTextureRect(IntRect(30*M(currentFrame),0,30,40));
         }

        if (!life)
            {
            sprited.setTextureRect(IntRect(110,323,23,40));
            }

        sprited.setPosition(rect.left - _offsetX, rect.top - _offsetY);

       }


       void Collision()
      {

        for (int i = rect.top/con ; i<(rect.top+rect.height)/con; i++)
            for (int j = rect.left/con; j<(rect.left+rect.width)/con; j++)
                 if ((nivel[i][j]=='P') || (nivel[i][j]=='0'))
                                           {
                                            if (dx>0)
                                                {
                                                rect.left =  j*con - rect.width;
                                                dx*=-1;
                                                 }
                                            else if (dx<0)
                                                {
                                                rect.left =  j*con + con;
                                                dx*=-1;
                                                 }

                                            }
      }
};


#endif // ENEMY_H

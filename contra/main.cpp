#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdio>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include <iostream>
#include "Map.h"
#include "PLAYER.h"
#include "Enemy.h"
#include "E_estatico.h"
#include "Bullet.h"
#include <vector>
using namespace sf;
using namespace std;

float offsetX=0, offsetY=0;

Map mapa;
const int H = 19;
const int W = 300;

int ramdo(int can,int range)
{
	int ram;
	time_t t;
	srand((unsigned) time(&t));
	for(int i = 0 ; i <can; i++ ) {
		ram = (rand() % range);
	}
 return ram;
}


int main()
{

    RenderWindow window(VideoMode(600, 350), "contra 001");

	Texture tileSet; tileSet.loadFromFile("bloques_Tileset.png");
	Texture enemigos; enemigos.loadFromFile("new_enemy.png");
	Texture m_balas; m_balas.loadFromFile("m_arma.png"); Sprite vida(m_balas);
    Texture ladd; ladd.loadFromFile("ladrillo.png"); Sprite ladrillo(ladd); ladrillo.setScale(0.1,0.1);
	Texture c; c.loadFromFile("newsprite.png");
	Texture backg; backg.loadFromFile("background.jpg"); Sprite fondo(backg);fondo.setPosition(0,-140); fondo.setScale(0.5,0.4);
	Texture mem; mem.loadFromFile("menu.png"); Sprite menu(mem); menu.setOrigin(0,0); menu.setScale(1,0.8);
    Texture fil; fil.loadFromFile("final.png"); Sprite finall(fil);  finall.setScale(1.1,1.2);
    Texture toor; toor.loadFromFile("torreta2.png"); Sprite torreta(toor); torreta.setScale(1,1);
   // Texture _enemy; _enemy.loadFromFile("enemy.png"); Sprite sprite_ene(_enemy); sprite_ene.setScale(1.05,1.05);
    RectangleShape rectangulo( Vector2f(16,16));


	PLAYER<float,int> p(c);
	ENEMY<float,int>  enemy;
	ENEMY<float,int>  enemy2;
	ENEMY<float,int>  enemy3;
	E_estatico e_estatic(Vector2f(50, 50),Vector2f(1,1.1));
    E_estatico e_estatic2(Vector2f(50, 50),Vector2f(1,1.1));
    E_estatico e_estatic3(Vector2f(50, 50),Vector2f(1,1.1));
    enemy.set(enemigos,1080,199);  Sprite tile(tileSet);
    enemy2.set(enemigos,2000,199);  Sprite tile2(tileSet);
    enemy3.set(enemigos,2050,199);  Sprite tile23(tileSet);

	int score = p.playervidas;

    Font arial;
    arial.loadFromFile("start.ttf");
    std::ostringstream ssScore;
    ssScore << "Scorec: " << score;
    sf::Text Score1;
    Score1.setCharacterSize(15);
    Score1.setPosition({ 10, 10 });
    Score1.setFont(arial);
    Score1.setString(ssScore.str());


	SoundBuffer buffer;
	buffer.loadFromFile("pew.wav"); Sound sound(buffer);
	SoundBuffer extra;
	extra.loadFromFile("extra.wav"); Sound sonid(extra);
    Music somenu;
    somenu.openFromFile("son_menu.ogg"); somenu.play();
    Music music;
    music.openFromFile("music_contra.ogg");
    Music vic;
    vic.openFromFile("vic.ogg");


    vector<Bullet> bulletVec;//store the bullets
    vector<Bullet> bulletEne;
    vector<Bullet> bulletVecene;
    vector<Bullet> fin;
    vector<Bullet> torre_dis;

    bool disparo  = false;
    bool dis_enemy = false;
    bool dis_estatic = false;
    bool veryf = true;
    int vol_dis;
    bool very = false;
    bool fin_disparo = false;
    bool dis_torre = false;

	Clock clock;
	int abajo;
    while (window.isOpen())
    {


		float time2 = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time2 = time2/900;  // MAS LENTO

		if (time2 > 20) time2 = 20;


        int (*funcion)(int,int);
        funcion = &ramdo;
        int ale =(*funcion)(1,9);  // puntero a funcion

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed )
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::Space))
            {
	         very = true;
	         disparo = true;
	         sound.play();
            }
             if (ale == 1 || ale == 8 || ale == 5)//Keyboard::isKeyPressed(Keyboard::P)
            {
                dis_estatic = true;
            }

            if (ale == 6 || ale == 2)//Keyboard::isKeyPressed(Keyboard::X)
            {
	         dis_enemy = true;

            }
            if (ale == 2 || ale == 4 || ale == 3)//Keyboard::isKeyPressed(Keyboard::P)
            {
                fin_disparo = true;
            }
            if(ale == 6 || ale == 9 || ale == 10)
            {
                dis_torre = true;
            }
		}


		if (Keyboard::isKeyPressed(Keyboard::Enter))
            { menu.move(Vector2f(400,4000));somenu.stop(); music.play();}
		if (Keyboard::isKeyPressed(Keyboard::A))
            {
             p.distanceX=-0.1; vol_dis = -1;
            }
	    if (Keyboard::isKeyPressed(Keyboard::D))
            {
	         p.distanceX=0.1; vol_dis = 1;
            }

	    if (Keyboard::isKeyPressed(Keyboard::W))
	    {
	        p.jum = true;
            if (p.onGround) { p.distanceY=-0.27; p.onGround=false; }
        }

        if (Keyboard::isKeyPressed(Keyboard::S))
                    {
                   abajo = 1;
                    }


		 p.update(time2,offsetX,offsetY,abajo);
		 /////////////////////////////////////////
		 enemy.update(time2,offsetX,offsetY);
         enemy2.update(time2,offsetX,offsetY);
         enemy3.update(time2,offsetX,offsetY);

		 if  (p.rect.intersects( enemy.rect ) || p.rect.intersects(enemy2.rect) || p.rect.intersects(enemy3.rect))
		 {
			 if (enemy.life)
                {
                    if (p.distanceY>0)
                     {
                        enemy.dx=0;
                        p.distanceY=-0.2;
                        enemy.life=false;
                     }
                    else
                        p.sprite.setColor(Color::Red);
			    }
			    p.playervidas = p.playervidas -1;
		 }


		 if (p.rect.left>200)
               offsetX = p.rect.left-200;           //bacgrund
		 window.clear(Color::Black);
		 window.draw(fondo);

		 for (int i=0; i<H; i++)
			 for (int j=0; j<W; j++)
			  {
				if (mapa.nivel[i][j]=='P')  tile.setTextureRect( IntRect(143-16*3,112,16,16) );// piso

				if (mapa.nivel[i][j]=='k')  tile.setTextureRect( IntRect(143,112,16,16) ); // bloques

                if (mapa.nivel[i][j]=='v')  tile.setTextureRect( IntRect(143-16,112,16,16) );

				if (mapa.nivel[i][j]=='t')  tile.setTextureRect( IntRect(0,47,32,95-47) );

				if (mapa.nivel[i][j]=='g')  tile.setTextureRect( IntRect(0,16*9-5,3*16,16*2+5) );

				if (mapa.nivel[i][j]=='G')  tile.setTextureRect( IntRect(145,222,222-145,255-222) );

			    if (mapa.nivel[i][j]=='d')  tile.setTextureRect( IntRect(5,105,74,127-106) );

				if (mapa.nivel[i][j]=='w')  tile.setTextureRect( IntRect(99,224,140-99,255-224) );

				if (mapa.nivel[i][j]=='r')  tile.setTextureRect( IntRect(143-32,112,16,16) );

				if ((mapa.nivel[i][j]==' ') || (mapa.nivel[i][j]=='0')){ continue; }
                    tile.setPosition(j*16-offsetX,i*16 - offsetY) ;  window.draw(tile);

 		        if (mapa.nivel[i][j]=='1'){ e_estatic.setPos(Vector2f(j*16-offsetX, i*16 - offsetY)); }
 		        if (mapa.nivel[i][j]=='2'){ e_estatic2.setPos(Vector2f(j*16-offsetX, i*16 - offsetY)); }
                if (mapa.nivel[i][j]=='3'){ e_estatic3.setPos(Vector2f(j*16-offsetX, i*16 - offsetY)); }
                if (mapa.nivel[i][j]=='c') {vida.setPosition(Vector2f(j*16-offsetX,i*16 - offsetY)); window.draw(vida);}

                if (mapa.nivel[i][j]=='F') {finall.setPosition(Vector2f(j*16-offsetX,i*16 - offsetY)); window.draw(finall);}

                if (mapa.nivel[i][j]=='M'){ torreta.setPosition(Vector2f(j*16-offsetX,i*16 - offsetY)); window.draw(torreta);  }


		     }

		     p.recta(Vector2f(30,30));
		     p.setPos_g(Vector2f(p.sprite.getPosition().x,p.sprite.getPosition().y));



            if (disparo == true)
            {
            Bullet newBullet1(Vector2f(3,2));// tamanio de la bal
            newBullet1.setPos(Vector2f(p.sprite.getPosition().x + 13,p.sprite.getPosition().y + 10));
            bulletVec.push_back(newBullet1);
            disparo = false;
            }

             for (int i = 0; i < bulletVec.size(); i++) {  // principal
            bulletVec[i].draw(window);
            bulletVec[i].fire(vol_dis);
            if(bulletVec[i].posX()>=p.sprite.getPosition().x+ 250 || bulletVec[i].posX()<= p.sprite.getPosition().x - 150)
               {
                bulletVec[i].setPos(Vector2f(88888888,289875555));
               }
             }
        ////////////////////////////////////////////////////////////////////////////////////

            if(dis_enemy == true)
             {
            Bullet newBullet(Vector2f(3,3));// tamanio de la bal   move
            newBullet.setPos(Vector2f(enemy.sprited.getPosition().x,enemy.sprited.getPosition().y));
            bulletEne.push_back(newBullet);
            dis_enemy = false;
             }

          for (int i = 0; i < bulletEne.size(); i++) {
            bulletEne[i].draw(window);
            bulletEne[i].fire(-1);
            if(bulletEne[i].posX() <= enemy.sprited.getPosition().x - 250)
            {
                bulletEne[i].setPos(Vector2f(88888888,289875555));

            }
        }

            if(dis_estatic == true)
             {
            Bullet newBullet3(Vector2f(3,3));// tamanio de la bal   move
            newBullet3.setPos(Vector2f(e_estatic.soldier.getPosition().x,e_estatic.soldier.getPosition().y));
            if(e_estatic.estado == false){
            newBullet3.setPos(Vector2f(e_estatic2.soldier.getPosition().x,e_estatic2.soldier.getPosition().y));
            }
            if(p.sprite.getPosition().x > e_estatic2.soldier.getPosition().x)
            {
                 newBullet3.setPos(Vector2f(finall.getPosition().x + 13,finall.getPosition().y + 70));/////////////////////////////
            }

            bulletVecene.push_back(newBullet3);
            dis_estatic = false;
            }

         for (int i = 0; i < bulletVecene.size(); i++) {  //estatico
                    bulletVecene[i].draw(window);
                    bulletVecene[i].fire(-1);
                    if(bulletVecene[i].posX()<= e_estatic.soldier.getPosition().x - 200)
                    {
                        bulletVecene[i].setPos(Vector2f(9988833399,888838383838));
                    }
//                    else if(bulletVecene[i].posX()<= torreta.getPosition().x - 200 )
//                    {
//                         bulletVecene[i].setPos(Vector2f(9988833399,888838383838));
//                    }

                }

    if(p.sprite.getPosition().x >= torreta.getPosition().x -100){
        if (fin_disparo == true)
            {
            Bullet neww(Vector2f(5,5));// tamanio de la bal
            neww.setPos(Vector2f(finall.getPosition().x + 13,finall.getPosition().y + 40));
            fin.push_back(neww);
            fin_disparo = false;
            }

          for (int i = 0; i < fin.size(); i++) {  //estatico
                fin[i].draw(window);
                fin[i].fire(-1);
                if(fin[i].posX()<= finall.getPosition().x - 400)
                {
                    fin[i].setPos(Vector2f(9922224442222999,8888444438383838));
                }

            }
      }


        if(dis_torre == true)
            {
            Bullet newB(Vector2f(3,3));// tamanio de la bal   move
            newB.setPos(Vector2f(torreta.getPosition().x,torreta.getPosition().y)); // por el sprite
            torre_dis.push_back(newB);
            dis_torre = false;
            }

          for (int i = 0; i < torre_dis.size(); i++) {
            torre_dis[i].draw(window);
            torre_dis[i].fire(-1);
            if(torre_dis[i].posX() <= torreta.getPosition().x - 100)
            {
                torre_dis[i].setPos(Vector2f(88888888,289875555));

            }
        }






        for (int i = 0; i < bulletVec.size(); i++) { // principal
            e_estatic.checkColl(bulletVec[i]);
            e_estatic2.checkColl(bulletVec[i]);
            e_estatic3.checkColl(bulletVec[i]);

        }

        for(int i=0;  i< bulletVecene.size(); i++) // estatic con ene
        {
            p.checkColli(bulletVecene[i]);
        }

        ssScore.str("");
        ssScore << "Score : " << p.playervidas;
        Score1.setString(ssScore.str());
        if( e_estatic.game_over == 3)
        {
         vic.play();
          window.draw(menu);
          exit(1);
        }


		window.draw(p.sprite);
	    window.draw(enemy.sprited);
	    window.draw(enemy2.sprited);
        window.draw(enemy3.sprited);
	    e_estatic.draw(window);
	    e_estatic2.draw(window);
	    e_estatic3.draw(window);
	    p.draw(window);
	    window.draw(Score1);
	    window.draw(menu);
		window.display();
    }

    return 0;
}






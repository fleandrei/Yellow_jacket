#include <iostream>
#include <ctime>
#include "Game.hh"
#include "Ecran.hh"
#include "Gilet_joueur.hh"
#include "CRS.hh"
#include "Grenade.hh"
using namespace std;
using namespace sf;

float sizeblock=80;
uint16_t W=14*sizeblock, H=8*sizeblock; //Dimenssions de l'écran
float h_p=85, w_p=sizeblock;// Dimenssion des personnages
float h_g=10, w_g=10; //Dimenssions des grenades.

int main(int argc, char const *argv[])
{	
	Ecran ecran(W,H,sizeblock);
	Gilet_joueur J("Joueur", W-w_p, H-2*sizeblock+5, W-w_p, W, 0, H-30, w_p, h_p,ecran);
	Clock joueur_clock;
	//Gilet_joueur J("Joueur",  H/2,W-70,0, H-30, W-70, W, w_p, h_p,ecran);

	CRS crs("Benalla", 0, H-2*sizeblock+5, 0, w_p, 0, H-30, w_p, h_p,ecran);
	Clock crs_clock;

	Grenade gren(0,H-2*sizeblock+5, 0, W-w_p, 0, sizeblock, w_g, h_g, 1, ecran );



	float alea;
	srand (time(NULL));
	while(ecran.isOpen()){
		Event event;
		if (ecran.pollEvent(event))
		{
			if (event.type==sf::Event::Closed)
			{
				ecran.close();
			}

			if (event.type==Event::KeyPressed && joueur_clock.getElapsedTime()>= seconds(0.5))
			{
				if(sf::Keyboard::isKeyPressed(Keyboard::Up)){
                	J.move(0,-sizeblock);
                //sleep(seconds(0.3));
            	}else if(sf::Keyboard::isKeyPressed(Keyboard::Down)){
                	J.move(0,sizeblock);
                //sleep(seconds(0.3));
            }			}
			
		}
		
        

        if (crs_clock.getElapsedTime()>=seconds(1))
        {
        	alea=(float)rand()/RAND_MAX;
        	cout<<alea<<endl;
        	cout<<ecran.isOpen()<<endl;
        	if (alea<0.5-crs.get_love()/2)
        	{
        		crs.move(0,sizeblock);
        		//sleep(seconds(0.3));

        	}else if (alea>0.5+crs.get_love()/2)
        	{
        		crs.move(0,-sizeblock);
        		//sleep(seconds(0.3));

        	}else{
        		cout<<"ATTAQUE"<<endl;
        	}
        	crs_clock.restart();
        }
        

        crs.draw(ecran);
        gren.draw(ecran);
		J.draw(ecran);
		ecran.render();
		
	}
	return 0;
}



void draw_grille(Ecran &E){

}

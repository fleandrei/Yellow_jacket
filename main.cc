#include <iostream>
#include <ctime>
#include <list>
#include <queue>
#include "Game.hh"
#include "Ecran.hh"
#include "Gilet_joueur.hh"
#include "CRS.hh"
#include "Grenade.hh"
#include "Voiture.hh"
using namespace std;
using namespace sf;

float sizeblock=100;
uint16_t W=15*sizeblock, H=7*sizeblock; //Dimenssions de l'écran
float h_p=sizeblock+5, w_p=sizeblock;// Dimenssion des personnages
float h_g=10, w_g=10; //Dimenssions des grenades.

int main(int argc, char const *argv[])
{	
	bool damage(false); //true si le joueur s'est prit un dégat
	Clock degat_clock;// Pour gérer l'affichage de l'image de dégat du joueur.

	Ecran ecran(W,H,sizeblock);
	Gilet_joueur J("Joueur",W-w_p, H-2*sizeblock+5, W-w_p, W, 3*sizeblock, H-30, w_p, h_p,ecran);
	Clock joueur_clock;
	//Gilet_joueur J("Joueur",  H/2,W-70,0, H-30, W-70, W, w_p, h_p,ecran);

	CRS crs("Benalla", 0, H-2*sizeblock+5, 0, w_p, 3*sizeblock, H-30, w_p, h_p,ecran);
	Clock crs_clock;

	Voiture car(0,sizeblock, -2*sizeblock, 2*sizeblock, sizeblock,0, 2*sizeblock, sizeblock, ecran);
	/*Grenade gren(0,H-2*sizeblock+5, 0, W-w_p, H-2*sizeblock+5, sizeblock+10, w_g, h_g, 2, ecran );
	Clock gren_clock;
*/
	list<Grenade> gren;
	Clock gren_clock;

	queue<Voiture> file;

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
                }			
        	}
			
		}
		
        

        if (crs_clock.getElapsedTime()>=seconds(1))
        {
        	alea=(float)rand()/RAND_MAX;
        	//cout<<alea<<endl;
        	if (alea<0.5-crs.get_love()/2)
        	{
        		crs.move(0,sizeblock);

        	}else if (alea>0.5+crs.get_love()/2)
        	{
        		crs.move(0,-sizeblock);

        	}else{
        		//cout<<"ATTAQUE"<<endl;
        		float Y=crs.get_y();
        		gren.push_back(Grenade (w_p/2,Y, 0, W-w_p/2, Y, Y-sizeblock, w_g, h_g, 2, ecran ));
        	}
        	crs_clock.restart();
        }
        //cout<<"gren.get_temps= "<<seconds(gren.get_temps()).asSeconds()<<endl;
        /*if (gren_clock.getElapsedTime()<=seconds(gren.get_temps()))
        {

        	gren.update((float)gren_clock.getElapsedTime().asSeconds());
        }*/

        for (std::list<Grenade>::iterator i = gren.begin(); i != gren.end(); ++i)
        {
        	if (i->update(gren_clock.getElapsedTime().asSeconds()))
        	{
        		i->draw(ecran);
        		
        	}else{
        		if(J.colision_grenade(i->get_x(), i->get_y(), ecran)){ //renvoie true si il y a colision 
        			damage=true;
        			degat_clock.restart();//Réinitialisé à chaque fois qque le joueur se prend un dégat
        		}
        		i=gren.erase(i);


        	}

        	
        	
        	//sleep(seconds(1));
        }
        gren_clock.restart();
        





        crs.draw(ecran);		
		car.draw(ecran);
		ecran.draw_victoire();
		if (!damage && degat_clock.getElapsedTime().asSeconds()>=0.5) //Si le joueur s'est pris un dégat il y a moins de 0.5 seconde, on affiche l'image de dégat
		{
			J.draw(ecran);
		}else{
			ecran.draw_degat(J.get_x(), J.get_y(), J.get_w(), J.get_h());
			damage=false;
			//sleep(seconds(0.5));
		}
		ecran.render();

		
	}
	return 0;
}



void draw_grille(Ecran &E){

}

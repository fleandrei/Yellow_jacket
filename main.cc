#include <iostream>
#include <ctime>
#include <cstdlib>
#include <list>
#include <deque>
#include <vector>
#include "Game.hh"
#include "Ecran.hh"
#include "Gilet_joueur.hh"
#include "CRS.hh"
#include "Grenade.hh"
#include "Voiture.hh"
using namespace std;
using namespace sf;

float sizeblock=100;
uint16_t W=16*sizeblock, H=8*sizeblock; //Dimenssions de l'écran
float h_p=sizeblock+5, w_p=sizeblock;// Dimenssion des personnages
float h_g=10, w_g=10; //Dimenssions des grenades.

int main(int argc, char const *argv[])
{	
	bool damage(false); //true si le joueur s'est prit un dégat
	Clock degat_clock;// Pour gérer l'affichage de l'image de dégat du joueur.

	Ecran ecran(W,H,sizeblock);
	Gilet_joueur J("Joueur",W-w_p, H-2*sizeblock+5, W-w_p, W, 3*sizeblock-30, H-30, w_p, h_p,ecran);
	Clock joueur_clock;
	//Gilet_joueur J("Joueur",  H/2,W-70,0, H-30, W-70, W, w_p, h_p,ecran);

	CRS crs("Benalla", 0, H-2*sizeblock+5, 0, w_p, 3*sizeblock, H-30, w_p, h_p,ecran);
	Clock crs_clock;

	list<Grenade> gren;
	Clock gren_clock;

		/*Grenade gren(0,H-2*sizeblock+5, 0, W-w_p, H-2*sizeblock+5, sizeblock+10, w_g, h_g, 2, ecran );
	Clock gren_clock;
*/

	Voiture car(0,3*sizeblock, -2*sizeblock, 2*sizeblock, 3*sizeblock,2*sizeblock, 2*sizeblock, sizeblock, 15, ecran);
	vector<deque<Voiture>> file;
	file.push_back(deque<Voiture>());
	file.push_back(deque<Voiture>());
	file.push_back(deque<Voiture>());
	file.push_back(deque<Voiture>());
	file.push_back(deque<Voiture>());
	Clock car_clock_move;
	Clock car_clock_create;
	Clock car_clock_wait;
	

	

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
                	J.set_orientation(1);
                //sleep(seconds(0.3));
            	}else if(sf::Keyboard::isKeyPressed(Keyboard::Down)){
                	J.move(0,sizeblock);
                	J.set_orientation(0);
                //sleep(seconds(0.3));
                }			
        	}else{
        		J.set_orientation(2);
        	}
			
		}
		


        
        if (car_clock_create.getElapsedTime()>=seconds(2))
        {
        	int voie = rand()%5;
        	if (abs((voie+3)*sizeblock - crs.get_y())>30 && file[voie].size()<6)
        	{
        		file[voie].push_front(Voiture(-2*sizeblock, (3+voie)*sizeblock, -2*sizeblock, W, (3+voie)*sizeblock, (3+voie)*sizeblock, 2*sizeblock, sizeblock, 15, ecran ));
        		car_clock_create.restart();
        		//cout<<"file["<<voie<<"].size()"<<file[voie].size()<<endl;
        		//cout<<" numéro de voie: "<<voie<<endl;
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
        		gren.push_back(Grenade (w_p/2,Y+3*sizeblock/4, 0, W-w_p/2, Y+3*sizeblock/4, Y-sizeblock/4, w_g, h_g, 2, ecran ));
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
        

        //cout<<(car-J).x<<" "<<(car-J).y<<endl;
        if (car_clock_move.getElapsedTime()>=seconds(0.05))
        {
        	std::deque<Voiture>::iterator iter;
        	for (int i = 0; i < 5; ++i)
        	{
        		for ( iter = file[i].begin(); iter != file[i].end(); ++iter)
        		{
        			if (!iter->wait(car_clock_wait.getElapsedTime().asSeconds()))
        			{
        				if (iter !=  (file[i].end()-1) && *iter-*(iter+1) < 3*sizeblock)
        				{
        					(*iter)(*(iter+1));
        				}
        				iter->move();
        			}
        		}
        		
        		//cout<<"(file[0].end()-1)->get_time()=  "<<(file[0].end()-1)->get_time()<<" vitesse: "<<(file[0].end()-1)->get_vitesse()<<endl;
        		//cout<<"(file[1].end()-1)->get_time()=  "<<(file[1].end()-1)->get_time()<<" vitesse: "<<(file[1].end()-1)->get_vitesse()<<endl;
        		/*On travaille sur la tête de queu*/
        		if (!file[i].empty()) 
        		{


        			if ((*(file[i].end()-1))-J < 3*sizeblock ) 
        			{
        				(*(file[i].end()-1))(J);
        				//cout<<"J devant "<<i<<endl;

        			}else if((file[i].end()-1)->get_time() == 0){
        				//cout<<"restart voie "<<i<<endl;
        				(file[i].end()-1)->restart();
        			}
        			
        			if ( (file[i].end()-1)->fin())
        			{
        				file[i].pop_back();
        				//cout<<"file["<<i<<"].pop()"<<endl;
        			}
        			
        			
        			
        			
        		}
        	}
        	
        	car.move();
        	car_clock_move.restart();
        	car_clock_wait.restart();
        }
       // cout<<"nombre de voiture: "<<Voiture::get_nbr_voiture()<<endl;

       

		for (int i = 0; i < 5; ++i)
        		{
        			for (std::deque<Voiture>::iterator iter = file[i].begin(); iter != file[i].end(); ++iter)
        			{
        				//cout<<"file["<<i<<"].size()= "<<file[i].size()<<endl;
        				iter->draw(ecran);
        			
        			}
        		}
        crs.draw(ecran);		
		car.draw(ecran);
		//ecran.draw_victoire();
		if (!damage && degat_clock.getElapsedTime().asSeconds()>=0.5) //Si le joueur s'est pris un dégat il y a moins de 0.5 seconde, on affiche l'image de dégat
		{
			J.draw(ecran);
		}else{
			ecran.draw_degat(J.get_x(), J.get_y(), J.get_w(), J.get_h());
			damage=false;
			//sleep(seconds(0.5));
		}
		ecran.render();
		ecran.draw_Map();
		
	}
	return 0;
}



void draw_grille(Ecran &E){

}

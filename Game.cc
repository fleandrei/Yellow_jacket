#include "Game.hh"

using namespace std;
using namespace sf;


Game::Game(float sizeblock):_sizeblock(sizeblock), _W(sizeblock*16),_H(_sizeblock*8), _ecran(_W,_H,sizeblock), _damage(false), _intro(true)
							,_Joueur("Joueur",_W-_sizeblock, _H-2*sizeblock+5, _W-_sizeblock, _W, 3*sizeblock-30, _H-30, sizeblock, _sizeblock+5,_ecran)
							,_crs("Benalla", 0, _H-2*sizeblock+5, 0, sizeblock, 3*sizeblock, _H-30, sizeblock, sizeblock+5, _ecran)
							{}
  


  void Game::initGame(){
  	file.push_back(deque<Voiture>());
	file.push_back(deque<Voiture>());
	file.push_back(deque<Voiture>());
	file.push_back(deque<Voiture>());
	file.push_back(deque<Voiture>());
  }

  void Game::evenement_intro(){
  	_ecran.draw_intro();
  	Event event;
  	if (_ecran.pollEvent(event))
		{
			if(event.type==Event::KeyPressed){
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					cout<<"mouse press"<<endl;
					_intro=false;
				}
			}
  	}
  }


  void Game::evenement(){
  	Event event;
  	int ind_route;
		if (_ecran.pollEvent(event))
		{

			if (event.type==sf::Event::Closed)
			{
				_ecran.close();
			}

			if (event.type==Event::KeyPressed && joueur_clock.getElapsedTime()>= seconds(0.5))
			{
				cout<<"Key pressed"<<endl;
				if(sf::Keyboard::isKeyPressed(Keyboard::Up) ){
                	_Joueur.set_orientation(1);
                	ind_route= (int)((_Joueur.get_y()-_sizeblock+5)/_sizeblock)-3;
                	cout<<"ind_route: "<<ind_route<<endl;
                	if(ind_route >=0 && (file[ind_route].empty() || (file[ind_route].end()-1)->get_x() <= (_Joueur.get_Xi()-2*_sizeblock +5) || (file[ind_route].end()-1)->get_x() > _Joueur.get_Xf())){ 
                		_Joueur.move(-_sizeblock);
                	}
                	
                //sleep(seconds(0.3));
            	}else if(sf::Keyboard::isKeyPressed(Keyboard::Down)){
                	_Joueur.set_orientation(0);
					ind_route= (int)((_Joueur.get_y()+_sizeblock+5)/_sizeblock)-3;
					if(ind_route <=4 && (file[ind_route].empty() || (file[ind_route].end()-1)->get_x() <= (_Joueur.get_Xi()-2*_sizeblock +5) || (file[ind_route].end()-1)->get_x() > _Joueur.get_Xf())){ 
                		_Joueur.move(_sizeblock);
                	}
                //sleep(seconds(0.3));
                }			
        	}else{
        		_Joueur.set_orientation(2);
        	}
			
		}
	}
  


  void Game::creat_car(){
  	if (car_clock_create.getElapsedTime()>=seconds(2))
        {
        	int voie = rand()%5;
        	cout<<"voie "<<voie<<endl;
        	cout<<file[voie][0].get_x()<<endl;
        	if (abs((voie+3)*_sizeblock - _crs.get_y())>30 && (!file[voie].empty() && file[voie][0].get_x()>3*_sizeblock || file[voie].empty() ))
        	{
        		file[voie].push_front(Voiture(-2*_sizeblock, (3+voie)*_sizeblock, -2*_sizeblock, _W, (3+voie)*_sizeblock, (3+voie)*_sizeblock, 2*_sizeblock, _sizeblock, 15, _ecran ));
        		car_clock_create.restart();
        		//cout<<"file["<<voie<<"].size()"<<file[voie].size()<<endl;
        		//cout<<" numéro de voie: "<<voie<<endl;
        	}
        	
        	
        }
  }

void Game::car_act(){
	if (car_clock_move.getElapsedTime()>=seconds(0.05))
        {
        	std::deque<Voiture>::iterator iter;
        	for (int i = 0; i < 5; ++i)
        	{
        		for ( iter = file[i].begin(); iter != file[i].end(); ++iter)
        		{
        			if (!iter->wait(car_clock_wait.getElapsedTime().asSeconds()))
        			{
        				if (iter !=  (file[i].end()-1) && *iter-*(iter+1) < 3*_sizeblock)
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

        			if ((*(file[i].end()-1))-_Joueur < 3*_sizeblock ) 
        			{
        				(*(file[i].end()-1))(_Joueur);
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
        	
        	//car.move();
        	car_clock_move.restart();
        	car_clock_wait.restart();
        }
}

  void Game::crs_act(){
  	float alea;
  	int ind_route;
  	 if (crs_clock.getElapsedTime()>=seconds(1))
        {
        	alea=(float)rand()/RAND_MAX;
        	//cout<<alea<<endl;
        	if (alea<0.5-_crs.get_love()/2)
        	{
        		ind_route= (int)((_crs.get_y()+_sizeblock+5)/_sizeblock)-3;
        		cout<<"crs ind_route: "<<ind_route;
        		if ( ind_route <=4 && (file[ind_route].empty() || (file[ind_route].end()-1)->get_x() < (_crs.get_Xi()-2*_sizeblock) || (file[ind_route].end()-1)->get_x() > _crs.get_Xf()) )
        		{
        			_crs.move(_sizeblock);
        		}
        		

        	}else if (alea>0.5+_crs.get_love()/2)
        	{
        		ind_route= (int)((_crs.get_y()-_sizeblock+5)/_sizeblock)-3;
        		if (ind_route >=0 && (file[ind_route].empty() || (file[ind_route].end()-1)->get_x() < (_crs.get_Xi()-2*_sizeblock) || (file[ind_route].end()-1)->get_x() > _crs.get_Xf()))
        		{
        			_crs.move(-_sizeblock);
        		}
        		

        	}else{
        		//cout<<"ATTAQUE"<<endl;
        		float Y=_crs.get_y();
        		gren.push_back(Grenade (_sizeblock/2,Y+3*_sizeblock/4, 0, _W-_sizeblock/2, Y+3*_sizeblock/4, Y-_sizeblock/4, _sizeblock, _sizeblock+5, 2, _ecran ));
        	}
        	crs_clock.restart();
        }
  }



void Game::grenade_act(){
	for (std::list<Grenade>::iterator i = gren.begin(); i != gren.end(); ++i)
        {
        	if (i->update(gren_clock.getElapsedTime().asSeconds()))
        	{
        		i->draw(_ecran);
        		
        	}else{
        		if(_Joueur.colision_grenade(i->get_x(), i->get_y(), _ecran)){ //renvoie true si il y a colision 
        			_damage=true;
        			degat_clock.restart();//Réinitialisé à chaque fois qque le joueur se prend un dégat
        		}
        		i=gren.erase(i);
        	}
        }
        gren_clock.restart();
}



  bool Game::play(){
  	
  	initGame();
  	

  	while(_ecran.isOpen()){

  		while(_intro){

  		}

		evenement();
		creat_car();
		crs_act();
		grenade_act();
		car_act();

		for (int i = 0; i < 5; ++i)
        		{
        			for (std::deque<Voiture>::iterator iter = file[i].begin(); iter != file[i].end(); ++iter)
        			{
        				//cout<<"file["<<i<<"].size()= "<<file[i].size()<<endl;
        				iter->draw(_ecran);
        			
        			}
        		}

		if (!_damage && degat_clock.getElapsedTime().asSeconds()>=0.5) //Si le joueur s'est pris un dégat il y a moins de 0.5 seconde, on affiche l'image de dégat
		{
			_Joueur.draw(_ecran);
		}else{
			_ecran.draw_degat(_Joueur.get_x(), _Joueur.get_y(), _Joueur.get_w(), _Joueur.get_h());
			_damage=false;
		}
		_crs.draw(_ecran);
		_ecran.render();
		_ecran.draw_Map();

	}
  }

    

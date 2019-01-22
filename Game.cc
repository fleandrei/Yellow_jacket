#include "Game.hh"
#include "sstream"
using namespace std;
using namespace sf;


Game::Game(float sizeblock, int seuil_victoire):_sizeblock(sizeblock), _W(sizeblock*16),_H(_sizeblock*8), _ecran(_W,_H,sizeblock), _damage(false), _flash(false)
							,_Joueur("Joueur",_W-_sizeblock, _H-2*sizeblock+5, _W-_sizeblock, _W, 3*sizeblock-30, _H-30, sizeblock, _sizeblock+5,_ecran)
							,_crs("Benala", 0, _H-2*sizeblock+5, 0, sizeblock, 3*sizeblock, _H-30, sizeblock, sizeblock+5, _ecran), _seuil_victoire(seuil_victoire)
							{}
  

/*S'occupe d'réinitialiser les paramères du jeu*/
  void Game::initGame(){

  	if (file.empty())//Si c'est la première fois que le joueur joue:
  	{
  		
  		file.push_back(deque<Voiture>());
		file.push_back(deque<Voiture>());
		file.push_back(deque<Voiture>());
		file.push_back(deque<Voiture>());
		file.push_back(deque<Voiture>());
  	}else{             //Si le joueur déjà joué et qu'il a cliqué sur "try again", on réinitialise les paramètres qui ont besoin de l'être:
  		_damage=false;
  		_flash=false;
  		car_clock_create.restart();
  		car_clock_move.restart();
  		car_clock_wait.restart();
  		joueur_clock.restart();
  		crs_clock.restart();
  		crs_flash_clock.restart();
  		degat_clock.restart();
  		gren_clock.restart();
  		_Joueur.set_vie(3);
  		_crs.set_love(0.2);
  		Voiture::set_nbr_voiture_arret(0);

  	}
  	
  }


  void Game::evenement_intro(){
  	bool intro=true;

  	/*Création du texte que l'on affiche à l'écran*/
  	Text tex1=_ecran.creat_text_arial("Choose Your", 50, sf::Color::Red, 4*_sizeblock, 2*_sizeblock+40);
  	Text tex2=_ecran.creat_text_arial("Character :", 50, sf::Color::Red, 10*_sizeblock-30, 2*_sizeblock+40);
  	Text yellow_jaket=_ecran.creat_text_error("Yellow Jacket ", 100, sf::Color::Yellow, _W/2 , _sizeblock);
  	yellow_jaket.setPosition(_W/2 - yellow_jaket.getGlobalBounds().width/2, 10);
  	yellow_jaket.setStyle(Text::Bold);
  	yellow_jaket.setColor(Color::Yellow);


  	while(intro && _ecran.isOpen()){
  		/*Afichage des images et du texte*/
  		_ecran.draw_intro(); 
  		Event event;
  		_ecran.draw_text(tex1);
  		_ecran.draw_text(tex2);
  		_ecran.draw_text(yellow_jaket);

  		/*Partie évenementielle*/
  		if (_ecran.pollEvent(event))
			{
				if (event.type==sf::Event::Closed)
				{
					_ecran.close();
				}

				if(event.type==Event::MouseButtonPressed){
				
					if (Mouse::isButtonPressed(Mouse::Left))
					{
						/*Choix du personnage avec lequel on va jouer*/
						if (_ecran.mouse_guillaume())
						{
							_ecran.set_joueur("Guillaume");
							intro=false;
						}else if(_ecran.mouse_andrei()){
							_ecran.set_joueur("Andrei");
							intro=false;
						}
					
					
					}
				}
  		}
  		_ecran.render();
 	 }

 	 
  }

  /*Gère les évènements dans la partie principale du jeu*/
  void Game::evenement(){
  	Event event;
  	int ind_route; //Indice de la voie sur laquelle le personnage projette d'aller
		if (_ecran.pollEvent(event))
		{

			if (event.type==sf::Event::Closed)
			{
				_ecran.close();
			}

			/*Déplacement du joueur*/
			if (event.type==Event::KeyPressed && joueur_clock.getElapsedTime()>= seconds(0.5)) //Le joueur ne peut faire de mouvement que toutes les 0.5 secodes maximum
			{
				/*Si le joueur appuie sur la touche du haut*/
				if(sf::Keyboard::isKeyPressed(Keyboard::Up) ){
                	_Joueur.set_orientation(1);
                	ind_route= (int)((_Joueur.get_y()-_sizeblock+5)/_sizeblock)-3;

                	/*On s'assure que le personnage reste sur la route et qu'il n'y ait pas une voiture qui est entrain de passer à l'endoit où il veut aller*/
                	if(ind_route >=0 && (file[ind_route].empty() || (file[ind_route].end()-1)->get_x() <= (_Joueur.get_Xi()-2*_sizeblock +5) || (file[ind_route].end()-1)->get_x() > _Joueur.get_Xf())){ 
                		_Joueur.move(-_sizeblock);
                	}
                	
                /*Si le joueur appuie sur la touche du bas*/
            	}else if(sf::Keyboard::isKeyPressed(Keyboard::Down)){
                	_Joueur.set_orientation(0);
					ind_route= (int)((_Joueur.get_y()+_sizeblock+5)/_sizeblock)-3;

					 /*On s'assure que le personnage reste sur la route et qu'il n'y ait pas une voiture qui est entrain de passer à l'endoit où il veut aller*/
					if(ind_route <=4 && (file[ind_route].empty() || (file[ind_route].end()-1)->get_x() <= (_Joueur.get_Xi()-2*_sizeblock +5) || (file[ind_route].end()-1)->get_x() > _Joueur.get_Xf())){ 
                		_Joueur.move(_sizeblock);
                	}
                }	
                /*Si le joueur n'appuie ni sur haut ni sur bas: le personnage reste de profile*/		
        	}else{
        		_Joueur.set_orientation(2);
        	}
			
		}
	}
  
  bool Game::defaite(){
  	/*Création du texte à afficher*/
  	Text game_over=_ecran.creat_text_violent("GAME OVER", 50, sf::Color::Red, 6*_sizeblock, 1*_sizeblock);
  	Text try_again=_ecran.creat_text_adventure("TRY AGAIN", 50, sf::Color::Green, 6*_sizeblock+50, 6*_sizeblock);

  	bool continu=false;
  	while(_ecran.isOpen() && !continu){
  	Event event;

  	/*Affichage du texte et des images*/
  	_ecran.draw_defaite();
  	_ecran.draw_text(game_over);
  	_ecran.draw_text(try_again);

  	if (_ecran.pollEvent(event))
		{
			if (event.type==sf::Event::Closed)
			{
				_ecran.close();
			}

			if(event.type==Event::MouseButtonPressed){
				
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					if (_ecran.mouse_text(try_again)) //Si le joueur appuie sur 'try again', on renvoie true.
					{
						continu=true;
					}			
				}
			}
  	}
  	_ecran.render();
  }
  }
  

  bool Game::victoire(){
   	/*Création du texte à afficher*/
  	Text victoire=_ecran.creat_text_violent("VICTOIRE!", 50, sf::Color::Yellow, 6*_sizeblock, 1*_sizeblock);
  	Text try_again=_ecran.creat_text_adventure("TRY AGAIN", 50, sf::Color::Green, 6*_sizeblock+10, 6*_sizeblock);
  	bool continu=false;
  	while(_ecran.isOpen() && !continu){
  	Event event;

  	/*Affichage du texte et des images*/
  	_ecran.draw_victoire();
  	_ecran.draw_text(victoire);
  	_ecran.draw_text(try_again);

  	if (_ecran.pollEvent(event))
		{
			if (event.type==sf::Event::Closed)
			{
				_ecran.close();
			}

			if(event.type==Event::MouseButtonPressed){
				
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					if (_ecran.mouse_text(try_again))//Si le joueur appuie sur 'try again', on renvoie true.
					{
						continu=true;
					}			
				}
			}
  	}
  	_ecran.render();
  }
  return continu;
  }
  

  void Game::creat_car(){
  	if (car_clock_create.getElapsedTime()>=seconds(2)) //On crée une voiture toutes les 2 secondes minimum.
        {
        	int voie = rand()%5;
        	//cout<<"voie "<<voie<<endl;
        	//cout<<file[voie][0].get_x()<<endl;
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
        		/*On travaille sur l'ensemble des voitures d'une même file, sauf la tête de queue*/
        		for ( iter = file[i].begin(); iter != file[i].end(); ++iter)
        		{
        			if (!iter->wait(car_clock_wait.getElapsedTime().asSeconds()))
        			{
        				if (iter !=  (file[i].end()-1) && *iter-*(iter+1) < 3*_sizeblock)
        				{
        					(*iter)(*(iter+1));
        				}else if(iter !=  (file[i].end()-1)){
        					iter->restart();
        				}
        				iter->move();
        			}
        		}
        		
        		  
        		/*On travaille sur la tête de queu*/
        		if (!file[i].empty()) 
        		{

        			if ((*(file[i].end()-1))-_Joueur < 3*_sizeblock ) //Si le personnage est devant la voiture
        			{
        				(*(file[i].end()-1))(_Joueur);
        				//cout<<"J devant "<<i<<endl;

        			}else if((file[i].end()-1)->get_time() == 0){ 
        				//cout<<"restart voie "<<i<<endl;
        				(file[i].end()-1)->restart();
        			}
        			
        			if ( (file[i].end()-1)->fin())//Si la voiture a quittée la map, on la supprime
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
        	_crs.set_love(0.1+0.4*Voiture::get_nbr_voiture_arret()/_seuil_victoire);//L'aggressivité du crs augmente au fur et à mesure qu'on approche de la victoire
        	alea=(float)rand()/RAND_MAX;

        	/*Tire de Flashball:*/
        	if (abs(_crs.get_y() - _Joueur.get_y())<5 && !_flash && file[(int)(_crs.get_y()/_sizeblock) - 3].empty())//Si on est en face du crs et qu'il n'y a aucune voiture entre lui et nous, alors il tire une flashball
        	{
        		_flash=true;
        		projectile.push_back(new Flashball(_sizeblock/2, _crs.get_y()+30, _W-_sizeblock/2, 1500));
        		crs_flash_clock.restart();
        	}

        	/*Tire de grenade et déplacement:*/
        	if (Voiture::get_nbr_voiture_arret() >= (int)(_seuil_victoire/4))//Si on a arreté les 2/3 des voitures qu'on doit arreter, le crs commence à nous suivre
        	{
        		if (alea<_crs.get_love())//attaque
        		{
        			float Y=_crs.get_y();
        			projectile.push_back(new Grenade (_sizeblock/2,Y+3*_sizeblock/4, 0, _W-_sizeblock/2, Y+3*_sizeblock/4, Y-_sizeblock/4, _sizeblock, _sizeblock+5, 2, _ecran ));
        		}else{//Déplacement
        			if(_crs.get_y()<_Joueur.get_y()){//si le joueur est plus haut que le crs, ce dernier se déplace vers le haut
        				ind_route= (int)((_crs.get_y()+_sizeblock+5)/_sizeblock)-3;
        				if ( ind_route <=4 && (file[ind_route].empty() || (file[ind_route].end()-1)->get_x() < (_crs.get_Xi()-2*_sizeblock) || (file[ind_route].end()-1)->get_x() > _crs.get_Xf()) )
        				{
        					_crs.move(_sizeblock);
        				}
        			}else{//IDEM si le joueur est plus bas que le crs
        				
        				ind_route= (int)((_crs.get_y()-_sizeblock+5)/_sizeblock)-3;
        				if (ind_route >=0 && (file[ind_route].empty() || (file[ind_route].end()-1)->get_x() < (_crs.get_Xi()-2*_sizeblock) || (file[ind_route].end()-1)->get_x() > _crs.get_Xf()))
        				{
        					_crs.move(-_sizeblock);
        				}
        			}
        		}
        	}else{ //Si on est en dessous des 2/3 des voitures qu'on doit arreter, le crs se déplace au hasard.
        		if (alea<0.5-_crs.get_love()/2 && !_flash)//Déplace vers le bas
        		{
        			ind_route= (int)((_crs.get_y()+_sizeblock+5)/_sizeblock)-3;
        			if ( ind_route <=4 && (file[ind_route].empty() || (file[ind_route].end()-1)->get_x() < (_crs.get_Xi()-2*_sizeblock) || (file[ind_route].end()-1)->get_x() > _crs.get_Xf()) )
        			{
        				_crs.move(_sizeblock);
        			}
        		

        		}else if (alea>0.5+_crs.get_love()/2)//Déplace vers le bas
        		{
        			ind_route= (int)((_crs.get_y()-_sizeblock+5)/_sizeblock)-3;
        			if (ind_route >=0 && (file[ind_route].empty() || (file[ind_route].end()-1)->get_x() < (_crs.get_Xi()-2*_sizeblock) || (file[ind_route].end()-1)->get_x() > _crs.get_Xf()))
        			{
        				_crs.move(-_sizeblock);
        			}

        		}else{//Attaque
        			float Y=_crs.get_y();
        			projectile.push_back(new Grenade (_sizeblock/2,Y+3*_sizeblock/4, 0, _W-_sizeblock/2, Y+3*_sizeblock/4, Y-_sizeblock/4, _sizeblock, _sizeblock+5, 2, _ecran ));
        		}
        		
        	}
        	crs_clock.restart();
        }
  }



void Game::grenade_act(){
	for (std::list<Projectile*>::iterator i = projectile.begin(); i != projectile.end(); ++i)
        {
        	if ((*i)->update(gren_clock.getElapsedTime().asSeconds())) //update met à jour la position des projectiles et renvoie false si ils ont atteint l'autre éxtremitée de l'écran
        	{
        		(*i)->draw(_ecran);
        		
        	}else{
        		if(_Joueur.colision_grenade((*i)->get_x(), (*i)->get_y(), _ecran)){ //renvoie true si il y a colision avec le joueur
        			_damage=true;
        			degat_clock.restart();//Réinitialisé à chaque fois que le joueur se prend un dégat
        		}
        		delete (*i);
        		i=projectile.erase(i);
        	}
        }
        gren_clock.restart();
}


void Game::draw_jeu(){
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
		if (!_flash && crs_flash_clock.getElapsedTime().asSeconds()>=1)//Si le crs a tiré une flashball il y a moins de 1 seconde, on affiche l'affiche entrain de tirer.
		{
			_crs.draw(_ecran);
		}else{
			_ecran.draw_crs_flash(_crs.get_x(), _crs.get_y());
			_flash=false;
		}
		
		_ecran.render();
		_ecran.draw_Map(); //Dessine la map.
}

/*Affiche les points de vie qu'il nous reste*/
 bool Game::draw_my_life(Text life){
 	string temp=life.getString();
 	int vie=_Joueur.get_vie();
 	life.setString(temp+int2string(vie));
 	_ecran.draw_text(life);
 	if (vie>0)
 	{
 		return true;
 	}else{
 		return false;
 	}
 }

 /*Affiche le nombre de voitures qu'on a stopé ainsi que le nombre de voiture qu'il reste à stoper avant de gagner*/
 bool Game::draw_score(sf::Text score){
 	string temp=score.getString();
 	int voiture_arret = Voiture::get_nbr_voiture_arret();
 	score.setString(temp+int2string(voiture_arret)+"/"+int2string(_seuil_victoire));
 	_ecran.draw_text(score);
 	return (voiture_arret<_seuil_victoire);

 }



	/*Fonction principale*/
  bool Game::play(){
  	bool continu=true;
  	initGame();
  	/*Création des textes que l'on va afficher dans la partie principale*/
  	Text life=_ecran.creat_text_arial("Life: ", 30, sf::Color::Red, 12*_sizeblock, 0*_sizeblock);
  	Text score=_ecran.creat_text_arial("Voitures arretees: ", 30, sf::Color::Blue, 13*_sizeblock, 0*_sizeblock);
	
  	/*Ecran introductif*/
	evenement_intro();
  	
  	/*Boucle while dans laquelle se déroule le jeu: Partie interactive du jeu*/
  	while(_ecran.isOpen() && continu){
		evenement(); 
		creat_car(); //Création de voitures
		crs_act();// Action du crs
		grenade_act();//gestion des projectils
		car_act();//actins des voitures
		draw_jeu();//affichage du jeu
		continu=(draw_my_life(life) && draw_score(score)); //Si on a perdu toute ses vie ou qu'on a atteint le score qu'il fallait, on arrete la boucle
		//continu=true;
	}
	continu=false;
	erase_list(); // Vide les deux containers "file" et "gren" de notre classe afin de pouvoir être réutilisés au cas où le joueur souhaiterait refaire une partie
	
	if (_Joueur.get_vie()<=0)
	{
		continu=defaite();
	}else{
		continu=victoire();
	}
	
	return continu; //true: on refait une partie;  false: ons'arrète.
	
  }


    void Game::erase_list(){
    	for (std::list<Projectile*>::iterator i = projectile.begin(); i != projectile.end(); ++i)
    	{
    		delete (*i);
    		i=projectile.erase(i);
    	}
    	for(int i=0; i<5; i++){
    		while(!file[i].empty()){
    			file[i].pop_back();
    		}
    		/*for (std::deque<Voiture>::iterator iter = file[i].begin(); iter != file[i].end(); ++iter)
    		{
    			
    			iter=file[i].erase(iter);
    		}*/
    	}
    }

  std::string Game::int2string(int i)
  {
  	stringstream ss;
	ss << i;
	
	return ss.str();
  }


    

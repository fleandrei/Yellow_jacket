#ifndef _GAME_HH
#define _GAME_HH
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

/****************************************************/
/* Class that plays the game                       */
/* Initialized with a player and a number of goals */
/****************************************************/


class Game{
 public :
 Game(float sizeblock);
  //~Game();
  bool play();
 
 private:
  


 

 
 private:
  void initGame();
  void evenement_intro();
  void evenement();
  void creat_car();
  void car_act();
  void crs_act();
  void grenade_act();
  //void handleEvent (Screen& _s, Player & p, bool & move);
  float _sizeblock;
  float _W;
  float _H;

  bool _damage;
  bool _intro;

  sf::Clock car_clock_create;
  sf::Clock car_clock_move;
  sf::Clock car_clock_wait;
  sf::Clock joueur_clock;
  sf::Clock crs_clock;
  sf::Clock degat_clock;

  Gilet_joueur _Joueur;
  CRS _crs;
  Ecran _ecran;

  std::vector<std::deque<Voiture>> file;

  std::list<Grenade> gren;
  sf::Clock gren_clock;
  
};
#endif

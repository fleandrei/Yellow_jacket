#ifndef _GAME_HH
#define _GAME_HH
#include "Ecran.hh"
#include "Gilet_joueur.hh"
#include "CRS.hh"

/****************************************************/
/* Class that plays the game                       */
/* Initialized with a player and a number of goals */
/****************************************************/


class Game{
 public :
 Game(Gilet_joueur J);
  //~Game();
  bool play();
 
 private:
  Gilet_joueur joueur;
  CRS crs;

 

 
 private:
  void initGame();
  //void handleEvent (Screen& _s, Player & p, bool & move);
  
  
};
#endif

#ifndef _GAME_HH
#define _GAME_HH
#include <list>
#include "Ecran.hh"
#include "Gilet_joueur.hh"
#include "Grenade.hh"
#include "CRS.hh"

/****************************************************/
/* Class that plays the game                       */
/* Initialized with a player and a number of goals */
/****************************************************/


class Game{
 public :
 Game();
  //~Game();
  bool play();
 
 private:
  


 

 
 private:
  void initGame();
  //void handleEvent (Screen& _s, Player & p, bool & move);
  
  
};
#endif

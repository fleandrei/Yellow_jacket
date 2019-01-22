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
#include "Game.hh"
using namespace std;
using namespace sf;



void provisoir();

int main(int argc, char const *argv[])
{	
	float sizeblock=100;//Taille des blocs
	bool try_again(true);// vrai tantque le joueur souhaite jouer
	Game jeu(sizeblock, 5); 
	
	while(try_again){//Tant que le joueur souhaite jouer, on continue.
		try_again=jeu.play();
	}
	//provisoir();
	return 0;
}



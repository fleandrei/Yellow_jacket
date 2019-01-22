#ifndef _GAME_HH
#define _GAME_HH
#include <ctime>
#include <cstdlib>
#include <list>
#include <deque>
#include <vector>
#include "Ecran.hh"
#include "Gilet_joueur.hh"
#include "CRS.hh"
#include "Grenade.hh"
#include "Flashball.hh"
#include "Voiture.hh"

/****************************************************/
/* Class that plays the game                       */
/* Initialized with a player and a number of goals */
/****************************************************/


class Game{
 public :
 Game(float sizeblock, int seuil_victoire); //sizeblock: taille des blocs;   seuil_victoire: nombre de voitures qu'il faut stoper pour gagner
  //~Game();
  bool play(); //Fonction principale qui fait tourner le jeu.
  
 
 private:
  void initGame(); //initialise ou réinitialise les paramètres du jeu
  void evenement_intro(); //Gère la partie introductive du jeu dans laquelle il faut choisir son personnage.
  void evenement();//Gère les événements dans la partie principale et interactive du jeu.
  bool defaite();// gestion du game-over 
  bool victoire();// Gestion de la victoire
  void creat_car();// S'occupe de mettre en circulation des voitures sur les 5 voies de la map.
  void car_act();//Gère les actions de toutes les voitures: s'arreter, avancer, disparaitre...
  void crs_act();//Gère les actions du CRS.
  void grenade_act();// Gère l'ensemble des grenade ET des flashball.
  void draw_jeu(); //Affiche l'ensemble des éléments visuels de la partie principale du jeu
  bool draw_score(sf::Text score);//affiche le nombre de voitures arretées sur le nombre de voitures qu'il faut areter. Renvoie true si ce nombre est atteint
  bool draw_my_life(sf::Text life);//affiche les points de vie restants et renvoie false si il n'y a plus de vie.
  void erase_list();//libère les élèments de la list projectile
  std::string int2string(int i);

  float _sizeblock;
  float _W; //Largeur de l'écran
  float _H;//Hauteur de l'écran
  int _seuil_victoire; //Nombre de voitures qu'il faut arreter pour gagner.

  bool _damage; //true si le joueur s'est pris un dégat.
  bool _flash;//True si une flashball a été lancée
  
/*Gestion du temps avec sf::Clock*/
  sf::Clock car_clock_create; //temps relatif à la création de voitures
  sf::Clock car_clock_move;//temps relatif au deplacement des voitures
  sf::Clock car_clock_wait;//temps relatif à l'attente des voitures qui sont stopées.
  sf::Clock joueur_clock; //temps relatif au joueur
  sf::Clock crs_clock; //temps relatif au crs.
  sf::Clock crs_flash_clock;//temps relatif aux flashball
  sf::Clock degat_clock;//temps relatif aux degats



  Gilet_joueur _Joueur; 
  CRS _crs;
  Ecran _ecran;

  std::vector<std::deque<Voiture>> file; //Vecteur contenant 5 double files contenant chacune les voitures roullant sur la voie de circulation correspondant à son indice.

  std::list<Projectile*> projectile; //Liste hétérogène de poiteurs de la classe abstraite Projectile: Il s'agit des grenades et des flash ball
  sf::Clock gren_clock;//Temps relatif aux "projectiles".
  
};
#endif

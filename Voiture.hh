#ifndef VOITURE_HH_
#define VOITURE_HH_

#include <iostream>
#include <string>
#include "Mobile.hh"
#include "Gilet_joueur.hh"

class Voiture: public Mobile
{
public:
	Voiture(float x, float y, float Xi, float Xf, float Yi, float Yf, float w, float h, float vitesse_max, Ecran& E);
	
  
  virtual void draw(Ecran& e) const;
  
  virtual int operator-(Mobile const& M);//surcharge d'opérateur virtuelle renvoyant la distance entre la voiture et l'objet Mobile passé en paramètre 


  bool operator()(Voiture const& V);//Gère l'attitude à avoir (s'arreter, ralentir, rester à l'arret) par rapport à la voiture d'en face passée en paramètre. Renvoie true si la voiture vient de s'arreter
  bool operator()(Gilet_joueur const& J);//Gère l'attitude à avoir (s'arreter, ralentir, rester à l'arret) par rapport au joueur passée en paramètre. Renvoie true si la voiture vient de s'arreter

  bool wait(float t);// renvoie true si la voiture doit attendre encore avant de redémarer. Elle rajoute au temps d'attente déjà effectué
  					 // le temps t

  void restart(); //Permet de retrouver progressivement sa vitesse_max 
  
  void move();

  bool fin();// Renvoie true si la voiture est sortie de l'écran.

  static int get_nbr_voiture_arret(){return nbr_voiture_arret;}
  static int set_nbr_voiture_arret(int v){ nbr_voiture_arret=v;}
  float get_time()const{return _time;}
  float get_vitesse()const{ return _vitesse;}
private:
	float _vitesse; //vitesse actuelle de la voiture 
	float _vitesse_max;// vitesse que doit avoir la voiture quand rien ne se dresse sur se route
  	static unsigned int nbr_voiture_arret;
  	float _time; //=0: La voiture peut rouller librement.   >0: La voiture est à l'arret et _time est décrémenté progressivement pour réatteindre 0.
  	float _temps_redemare;//Temps que va mettre une voiture arrètée à réatteindre sa vitesse _max.
};

#endif

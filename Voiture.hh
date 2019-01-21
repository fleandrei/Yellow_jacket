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
	
  //virtual bool isInTheZone(const Player& p) const;  
  //virtual void interract(Mobile& m) = 0;
  virtual void draw(Ecran& e) const;
  //virtual bool operator> (Mobile const& M); // Renvoie un vecteur de deux dimenssions donnant les distance horizontales et
  // verticale entre la voiture et un autre élement de type Mobile (Gilet_joueur, Voiture,...).
  virtual int operator-(Mobile const& M);

  void operator()(Voiture const& V);
  void operator()(Gilet_joueur const& J);

  bool wait(float t);// renvoie true si la voiture doit attendre encore avant de redémarer. Elle rajoute au temps d'attente déjà effectué
  					 // le temps t

  void restart();
  
  void move();

  bool fin();

  static int get_nbr_voiture_arret(){return nbr_voiture_arret;}
  float get_time()const{return _time;}
  float get_vitesse()const{ return _vitesse;}
private:
	float _vitesse;
	float _vitesse_max;
  	static unsigned int nbr_voiture_arret;
  	float _time;
  	float _temps_redemare;
};

#endif

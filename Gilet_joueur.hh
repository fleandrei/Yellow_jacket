#ifndef GILET_JOUEUR_HH_
#define GILET_JOUEUR_HH_

#include <iostream>
#include "Personne.hh"

class Gilet_joueur: public Personne
{
public:
	Gilet_joueur(std::string nom, float x, float y, float Xi, float Xf, float Yi, float Yf, float w, float h, Ecran& E);

  //virtual bool isInTheZone(const Player& p) const;  
  //virtual void interract(Mobile& m) = 0;
  virtual void draw(Ecran& e) const;
  virtual void move(float x, float y);
  
protected:
 
};

#endif
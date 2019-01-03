#ifndef VOITURE_HH_
#define VOITURE_HH_

#include <iostream>
#include <string>
#include "Mobile.hh"

class Voiture: public Mobile
{
public:
	Voiture(float x, float y, float Xi, float Xf, float Yi, float Yf, float w, float h, Ecran& E);
  //virtual bool isInTheZone(const Player& p) const;  
  //virtual void interract(Mobile& m) = 0;
  virtual void draw(Ecran& e) const;
  
protected:
  
};

#endif

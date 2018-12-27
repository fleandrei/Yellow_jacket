#ifndef PERSONNE_HH_
#define PERSONNE_HH_

#include <iostream>
#include <string>
#include "Mobile.hh"

class Personne: public Mobile
{
public:
  //virtual bool isInTheZone(const Player& p) const;  
  //virtual void interract(Mobile& m) = 0;
  //virtual void draw(Ecran& e) const = 0;
  
protected:
  std::string name;
  float _Xi, _Xf;//Le personnage sera confiné sur l'axe des absisces entre Xi et Xf
  float _Yi, _Yf;//Le personnage sera confiné sur l'axe des ordonnées entre Yi et Yf
};

#endif

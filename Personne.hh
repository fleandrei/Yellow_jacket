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
virtual void move(float x,float y)/*{_x = _x+x; _y = _y+y;}*/=0;
  
protected:
  std::string name;
  
};

#endif

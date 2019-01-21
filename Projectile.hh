#ifndef PROJECTILE_HH_
#define PROJECTILE_HH_

#include <iostream>
#include <string>
#include "Mobile.hh"

class Projectile: public Mobile
{
public:
  //virtual bool isInTheZone(const Player& p) const;  
  //virtual void interract(Mobile& m) = 0;
  //virtual void draw(Ecran& e) const = 0;
//virtual void move(float y){_y=_y+y;}
virtual bool update(float time)=0;		
  
protected:
  std::string name;
  
};

#endif
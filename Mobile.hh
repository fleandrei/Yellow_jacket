#ifndef MOBILE_HH_
#define MOBILE_HH_

#include <iostream>
#include "Ecran.hh"

class Mobile
{
public:
  //virtual bool isInTheZone(const Player& p) const;  
  //virtual void interract(Mobile& m) = 0;
  virtual void draw(Ecran& e) const = 0;
  //void turnOn(){_active = true;}
  //bool active()const {return _active;}
  void set_position(float x,float y){_x = x; _y = y;}

  virtual void move(float x,float y)/*{_x = _x+x; _y = _y+y;}*/=0;

protected:
  float _h, _w;
  float _x, _y;
  //bool  _active;
};

#endif

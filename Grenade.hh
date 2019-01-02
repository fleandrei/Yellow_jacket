#ifndef GRENADE_HH_
#define GRENADE_HH_

#include <iostream>
#include <string>
#include "Mobile.hh"

class Grenade: public Mobile
{
public:
	Grenade(float x, float y, float Xi, float Xf, float Yi, float Yf, float w, float h,float temps, Ecran &E);

  virtual void draw(Ecran& e) const;
  void update(float time);
  
protected:
  
  //float cible_x, cible_y;
  bool _active;
  float _temps; //temps entre le moment où la grenade est lancée et où elle attérit. 
};

#endif

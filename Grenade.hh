#ifndef GRENADE_HH_
#define GRENADE_HH_

#include <iostream>
#include <string>
#include "Projectile.hh"

class Grenade: public Projectile
{
public:
	Grenade(float x, float y, float Xi, float Xf, float Yi, float Yf, float w, float h,float duree, Ecran &E);

  virtual void draw(Ecran& e) const;
  virtual bool update(float time); //Renvoie false si la grenade a attérit et doit être supprimer de la mêmoire. Renvoie true sinon

  float get_temps()const;
  float get_duree()const;

  
protected:
  
  //float cible_x, cible_y;
  //bool _active;
  float _duree; //temps entre le moment où la grenade est lancée et où elle est censsée attérir.
  float _temps; //temps entre le moment où la grenade a été lancée et le moment présent. 
};

#endif

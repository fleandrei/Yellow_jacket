#ifndef FLASHBALL_HH_
#define FLASHBALL_HH_

#include <iostream>
#include <string>
#include "Projectile.hh"

class Flashball: public Projectile
{
public:
	Flashball(float x, float y, float Xf, float vitesse);
  virtual void draw(Ecran& e) const;
  virtual bool update(float time); //Renvoie false si la grenade a attérit et doit être supprimer de la mêmoire. Renvoie true sinon

  

  
protected:
  
  float _vitesse;
};
#endif

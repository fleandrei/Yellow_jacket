#ifndef PROJECTILE_HH_
#define PROJECTILE_HH_

#include <iostream>
#include <string>
#include "Mobile.hh"


/*Classe abstraite pouvant être une grenadde ou une flashball*/
class Projectile: public Mobile
{
public:

virtual bool update(float time)=0;		
  
  
};

#endif
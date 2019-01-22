#ifndef PERSONNE_HH_
#define PERSONNE_HH_

#include <iostream>
#include <string>
#include "Mobile.hh"

class Personne: public Mobile
{
public:

virtual void move(float y){_y=_y+y;}
void set_name(std::string n){name=n;}
std::string get_name(){return name;}		
	
		
  
protected:
  std::string name; 
  
};

#endif

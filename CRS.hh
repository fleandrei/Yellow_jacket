#ifndef CRS_HH_
#define CRS_HH_

//#include <iostream>
#include "Personne.hh"

class CRS: public Personne
{
public:
	CRS(std::string nom, float x, float y, float Xi, float Xf, float Yi, float Yf, float w, float h, Ecran& E);

  //virtual bool isInTheZone(const Player& p) const;  
  //virtual void interract(Mobile& m) = 0;
  virtual void draw(Ecran& e) const;
  virtual void move(float x, float y);
  
  void act();

  float get_love()const;
private:
	float love; //Level Of ViolencE 
};

#endif
#ifndef CRS_HH_
#define CRS_HH_

//#include <iostream>
#include "Personne.hh"

class CRS: public Personne
{
public:
	CRS(std::string nom, float x, float y, float Xi, float Xf, float Yi, float Yf, float w, float h, Ecran& E);


  virtual void draw(Ecran& e) const;

  

  float get_love()const;
  
  void set_love(float l){love=l;}
  
private:
	float love; //Level Of ViolencE comprit entre 0.2 et 0.7
};

#endif
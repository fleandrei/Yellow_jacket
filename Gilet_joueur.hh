#ifndef GILET_JOUEUR_HH_
#define GILET_JOUEUR_HH_

//#include <iostream>
#include "Personne.hh"

enum Orientation{FACE, DOS, PROFILE};

class Gilet_joueur: public Personne
{
public:
	Gilet_joueur(std::string nom, float x, float y, float Xi, float Xf, float Yi, float Yf, float w, float h, Ecran& E);
	//Gilet_joueur(Gilet_joueur const& J);
  //virtual bool isInTheZone(const Player& p) const;  
  //virtual void interract(Mobile& m) = 0;
  virtual void draw(Ecran& e) const;
  virtual void move(float x, float y);
  bool colision_grenade(float x, float y, Ecran &e);

  int get_vie()const;
  void set_vie(int v);
  void set_orientation(int o){_dir= (Orientation) o;}
private:
	int _vie;
	Orientation _dir;
 
};

#endif

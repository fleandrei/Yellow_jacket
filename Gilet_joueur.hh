#ifndef GILET_JOUEUR_HH_
#define GILET_JOUEUR_HH_

//#include <iostream>
#include "Personne.hh"

enum Orientation{FACE, DOS, PROFILE};//orientation du personnage

class Gilet_joueur: public Personne
{
public:
	Gilet_joueur(std::string nom, float x, float y, float Xi, float Xf, float Yi, float Yf, float w, float h, Ecran& E);

  virtual void draw(Ecran& e) const;
  bool colision_grenade(float x, float y, Ecran &e); //Si la grenade de coordonnés(x,y) touche le joueur ce dernier perd une vie et la fonction renvoie true.

  int get_vie()const;
  void set_vie(int v);
  void set_orientation(int o){_dir= (Orientation) o;} //met à jour l'orientation du joueur.
private:
	int _vie;
	Orientation _dir; // -De dos  -De profile   - de face
 
};

#endif

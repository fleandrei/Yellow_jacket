#include "Voiture.hh"

using namespace std;



Voiture::Voiture(float x, float y, float Xi, float Xf, float Yi, float Yf, float w, float h, Ecran& E){
	_x=x;
	_y=y;
	_Xi=Xi;
	_Xf=Xf;
	_Yi=Yi;
	_Yf=Yf;
	_h=h;
	_w=w; 
	E.draw_Voiture(_x,_y,_h,_w);
}



void Voiture::draw(Ecran& e) const{
	e.draw_Voiture(_x,_y);
}
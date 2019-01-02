#include "Grenade.hh"
#include <cmath>
using namespace std;




Grenade::Grenade(float x, float y, float Xi, float Xf, float Yi, float Yf, float w, float h, float temps, Ecran &E){
	_x=x;
	_y=y;
	_Xi=Xi;
	_Xf=Xf;
	_Yi=Yi;
	_Yf=Yf;
	_h=h;
	_w=w; 
	_active=true;
	E.draw_Grenade(_x,_y,_h,_w);
}



void Grenade::update(float time){
	_x=_Xi+ time*(_Xf-_Xi)/_temps;
	_y=-9.81*pow(time,2)*0.5 + 0.5*9.81*_temps + _Yi;
}


void Grenade::draw(Ecran& e) const{
	e.draw_Grenade(_x, _y);
}

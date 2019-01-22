#include "Grenade.hh"
#include <cmath>
using namespace std;




Grenade::Grenade(float x, float y, float Xi, float Xf, float Yi, float Yf, float w, float h, float duree, Ecran &E){
	_x=x;
	_y=y;
	_Xi=Xi;
	_Xf=Xf;
	_Yi=Yi;
	_Yf=Yf;
	_h=h;
	_w=w; 
	_duree=duree;
	_temps=0;
	//_active=true;
	//E.draw_Grenade(_x,_y,_h,_w);
}



bool Grenade::update(float time){
	_temps=_temps+time;
	if (_temps>=_duree)//La grenade a atterit et explosée
	{
		return false;
	}else{

		/*Equations de x et de y en fonction du temps de manière à ce que la trajectoire de la grenadde forme une parabole*/
		_x=_Xi+ _temps*(_Xf-_Xi)/(_duree); 
		float k= -(_Yf-_Yi)*4/pow(_duree,2);
		_y=k*pow(_temps,2)-k*_duree*_temps+_Yi;
		
		return true;
	}
	
}


void Grenade::draw(Ecran& e) const{
	e.draw_Grenade(_x, _y);
}

float Grenade::get_temps()const{
	return _temps;
}

float Grenade::get_duree()const{
	return _duree;
}


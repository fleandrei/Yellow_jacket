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
	_active=true;
	E.draw_Grenade(_x,_y,_h,_w);
}



bool Grenade::update(float time){
	_temps=_temps+time;
	if (_temps>=_duree)
	{
		return false;
	}else{
		_x=_Xi+ _temps*(_Xf-_Xi)/(_duree);
		//_y=9.81*12*pow(_temps,2)*0.5 - 0.5*9.81*12*_duree *_temps + _Yi;
		float k= -(_Yf-_Yi)*4/pow(_duree,2);
		_y=k*pow(_temps,2)-k*_duree*_temps+_Yi;
		//cout<<"yi "<<_Yi<<endl;
		//cout<<"_temps "<<_temps<<" x= "<<_x<<" y= "<<_y<<endl;
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


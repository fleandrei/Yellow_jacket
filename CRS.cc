#include "CRS.hh"


using namespace std;


CRS::CRS(std::string nom, float x, float y, float Xi, float Xf, float Yi, float Yf, float w, float h, Ecran& E){
	name=nom;
	_x=x;
	_y=y;
	_Xi=Xi;
	_Xf=Xf;
	_Yi=Yi;
	_Yf=Yf;
	_h=h;
	_w=w; 
	love=0.2;
	//E.draw_CRS(x,y,h,w);
  
}



void CRS::draw(Ecran& e) const{
	e.draw_CRS(_x, _y);
}


float CRS::get_love()const{
	return love;
}

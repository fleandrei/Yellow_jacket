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
	love=0.4;
	//E.draw_CRS(x,y,h,w);
	cout<<"constructeur CRS"<<endl;
  
}

/*void CRS::move(float x, float y){
	if (_x+x >= _Xi && _x+x <= _Xf){
		_x=_x+x;
	}
	if (_y+y >= _Yi && _y+y <=_Yf)
	{
		_y=_y+y;
	}
}*/

void CRS::draw(Ecran& e) const{
	e.draw_CRS(_x, _y);
}


void CRS::act(){

}

float CRS::get_love()const{
	return love;
}

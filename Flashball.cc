#include"Flashball.hh"
using namespace std;




 Flashball::Flashball(float x, float y, float Xf, float vitesse){
 	_x=x;
 	_y=y;
 	_Xf=Xf;
 	_vitesse=vitesse;

 }
  
  void Flashball::draw(Ecran& e) const{
  	e.draw_flashball(_x,_y);
  	//cout<<"flash draw"<<endl;
  }

  bool Flashball::update(float time){
  	if (_x < _Xf)
  	{
  		_x=_x+ time*_vitesse;
  		//cout<<"flash update vitesse "<<_vitesse<<endl;
  		return true;
 	}else{
 		//cout<<"flash update false"<<endl;
 		return false;
 	}
  }
  	
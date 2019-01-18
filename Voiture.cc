#include "Voiture.hh"

using namespace std;



unsigned int Voiture::nbr_voiture = 0;

Voiture::Voiture(float x, float y, float Xi, float Xf, float Yi, float Yf, float w, float h, float vitesse_max, Ecran& E){
	_x=x;
	_y=y;
	_Xi=Xi;
	_Xf=Xf;
	_Yi=Yi;
	_Yf=Yf;
	_h=h;
	_w=w; 
	_vitesse=vitesse_max; 
	_vitesse_max=vitesse_max; 
	_temps_redemare=3;
	_time=0;       
	E.draw_Voiture(_x,_y,_h,_w);
	nbr_voiture++;
	cout<<"nbr_voiture= "<<nbr_voiture<<endl;
}


/*
bool Voiture::operator> (Mobile const& M){
	if (_y-M.get_y())
	{
		
	}
	return sf::Vector2f((M.get_x() - _x), (M.get_y()-_y) );
}
*/
void Voiture::move(){
	_x=_x+ _vitesse;

}

void Voiture::draw(Ecran& e) const{
	e.draw_Voiture(_x,_y);
}



bool Voiture::fin(){
	if (_x > _Xf)
	{
		return true;
	}else{
		//cout<<"_x "<<_x<<", _Xf"<<_Xf<<endl;
		return false;
	}
}



int Voiture::operator-(Mobile const& M){
	//if (M.get_y() > _y+_h || M.get_y() < _y-_h)
	if(abs(M.get_y() - _y) > 10)
	{
		return 1000;    // S'il s'agit du joueur et que ce dernier est loin de la voie sur laquelle se trouve la voiture alors, 
		                // on considère qu'il est très loin de la voiture et on renvoie 1000. 
	}else{
		return M.get_x()-_x; 
	}
}

 void Voiture::operator()(Voiture const& V){
 	unsigned int v_speed=V._vitesse; //vitesse de la voiture d'en face.
 	
 	
 		float Td=(V.get_x()-_x - _w)/_vitesse; //Temps dans lequel la voiture va atteindre la position à laquelle se trouve acctuelement la voiture d'en face 
 		_vitesse=_vitesse + (v_speed - _vitesse)/Td;
 		if (_vitesse<0.5)
 		{

 			_vitesse=0;
 			_time=_temps_redemare;
 		}
 	
 }


void Voiture::operator()(Gilet_joueur const& J){

		//if (J.get_y() < _y+10 && J.get_y() > _y-10)
		//{
			float Td=((J.get_x()-_x - _w )/_vitesse); //Temps dans lequel la voiture va atteindre la position à laquelle se trouve acctuelement le joueur. 
 			_vitesse=_vitesse - _vitesse/Td;
 			if (_vitesse<1) 
 			{
 				_vitesse=0;
 				_time=_temps_redemare;
 			}	
		//}
}

bool Voiture::wait(float t){
	if (_time > 0)
	{
		_time= _time - t;
		return true;
	}else{
		_time= 0;
		return false;
	}
}


void Voiture::restart(){
	_vitesse= _vitesse + (_vitesse_max - _vitesse)/(_temps_redemare - 0.5);
}

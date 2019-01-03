#include "Gilet_joueur.hh"

using namespace std;



Gilet_joueur::Gilet_joueur(string nom, float x, float y, float Xi, float Xf, float Yi, float Yf, float w, float h, Ecran& E)
{
	name=nom;
	_x=x;
	_y=y;
	_Xi=Xi;
	_Xf=Xf;
	_Yi=Yi;
	_Yf=Yf;
	_h=h;
	_w=w; 
	vie=3;
	E.draw_gilet(x,y,h,w);
}


void Gilet_joueur::move(float x, float y){
	
	if (_x+x >= _Xi && _x+x <= _Xf){
		_x=_x+x;
	}
	if (_y+y >= _Yi && _y+y <=_Yf)
	{
		_y=_y+y;
	}
	//cout<<"_x= "<<_x<<" _y= "<<_y<<endl;
}

bool Gilet_joueur::colision_grenade(float x, float y, Ecran &e){
	if (e.colision_joueur(sf::Vector2f(x,y)) || e.colision_joueur(sf::Vector2f(x,y+10)) || e.colision_joueur(sf::Vector2f(x+10,y)) || e.colision_joueur(sf::Vector2f(x+10,y+10)) )
	{
		vie--;
		cout<<"Aïe"<<endl;
		//e.draw_degat(_x, _y, _h, _w);
		return true;
	}else{
		return false;
	}
}

void Gilet_joueur::draw(Ecran& e) const{
	e.draw_gilet(_x, _y);

}

int Gilet_joueur::get_vie()const{
	return vie;
}
void Gilet_joueur::set_vie(int v){
	vie=v;
}


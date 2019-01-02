#include "Ecran.hh"

using namespace sf;
using namespace std;





Ecran::Ecran(uint16_t w, uint16_t h, uint16_t sizeblock): _h(h), _w(w), _sizeblock(sizeblock)
{
	_win = new sf::RenderWindow(sf::VideoMode(_w , _h+50), "NEW GAME: Yellow Jacket");
	
	//sf::Texture jaune;
	// On Charge la texture de gilet jaune et on crée le sprite correspondant
	if (!jaune.loadFromFile("jaune.png"))
	{
    	std::cout<<"Erreure l'image giletjaune n'est pas chargée"<<std::endl;
	}

	jaune.setSmooth(true);
	gilet_jaune.setTexture(jaune);
	gilet_jaune.setScale(0.25f, 0.25f);


	// On Charge la texture de CRS et on crée le sprite correspondant
	if (!CRS_tex.loadFromFile("CRS.png"))
	{
		cout<<"Erreure l'image CRS.png n'a pas pue être chargée"<<endl;
	}

	CRS_tex.setSmooth(true);
	CRS_spr.setTexture(CRS_tex);
	CRS_spr.setScale(0.25f, 0.25f);

	// On Charge la texture de La Grenade et on crée le sprite correspondant
	if (!Grenade_tex.loadFromFile("grenade.jpeg"))
	{
		cout<<"Erreure l'image Grenade.png n'a pas pue être chargée"<<endl;
	}

	Grenade_tex.setSmooth(true);
	Grenade_spr.setTexture(Grenade_tex);
	Grenade_spr.setScale(0.25f, 0.25f);

}

  

void Ecran::draw_gilet(float x, float y){
	//cout<<"x="<<x<<" y= "<<y<<endl;
	gilet_jaune.setPosition(x,y);
	_win->draw(gilet_jaune);
}

void Ecran::draw_gilet(float x, float y, float h, float w){
	//cout<<"h="<<h<<"w="<<w<<endl;
	gilet_jaune.setScale(w/gilet_jaune.getLocalBounds().height,h/gilet_jaune.getLocalBounds().width);
	//cout<<gilet_jaune.getScale().x<<" "<<gilet_jaune.getScale().y<<endl;
	gilet_jaune.setPosition(x,y);
	_win->draw(gilet_jaune);
}

void Ecran::draw_CRS(float x, float y){
	CRS_spr.setPosition(x,y);
	_win->draw(CRS_spr);
}

void Ecran::draw_CRS(float x, float y, float h, float w){
	CRS_spr.setScale(w/CRS_spr.getLocalBounds().height, h/CRS_spr.getLocalBounds().width);
	CRS_spr.setPosition(x,y);
	_win->draw(CRS_spr);
}

void Ecran::draw_Grenade(float x, float y){
	Grenade_spr.setPosition(x,y);
	_win->draw(Grenade_spr);
}

void Ecran::draw_Grenade(float x, float y, float h, float w){
	Grenade_spr.setScale(w/Grenade_spr.getLocalBounds().height, h/Grenade_spr.getLocalBounds().width);
	Grenade_spr.setPosition(x,y);
	cout<<"x= "<<x<<" y= "<<y<<endl;
	_win->draw(Grenade_spr);
}
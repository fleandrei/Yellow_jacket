#include "Ecran.hh"

using namespace sf;
using namespace std;





Ecran::Ecran(uint16_t w, uint16_t h): _h(h), _w(w)
{
	_win = new sf::RenderWindow(sf::VideoMode(_w , _h+50), "NEW GAME: Yellow Jacket");
	
	//sf::Texture jaune;
	
	if (!jaune.loadFromFile("jaune.png"))
	{
    	std::cout<<"Erreure l'image giletjaune n'est pas chargée"<<std::endl;
	}

	jaune.setSmooth(true);
	gilet_jaune.setTexture(jaune);
	gilet_jaune.setScale(0.25f, 0.25f);

}

    

void Ecran::draw_gilet(float x, float y){
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


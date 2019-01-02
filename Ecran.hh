#ifndef ECRAN_HH_
#define ECRAN_HH_
#include <iostream>
#include <SFML/Graphics.hpp>


class Ecran
{
public:
	Ecran(uint16_t w, uint16_t h, uint16_t sizeblock);
	~Ecran(){delete _win;}
	bool isOpen(){return _win->isOpen();}
    void close(){_win->close();}
    void render(){_win->display(); _win->clear();} //Affiche tous ce qu'il y a sur l'ecran; puis efface l'écran actuel.
    bool pollEvent(sf::Event& event){return _win->pollEvent(event);}
    void draw_gilet(float x, float y);
    void draw_gilet(float x, float y, float h, float w);
    void draw_CRS(float x, float y);
    void draw_CRS(float x, float y, float h, float w);
    void draw_Grenade(float x, float y);
    void draw_Grenade(float x, float y, float h, float w);



private:
	sf::RenderWindow *  _win;
  	uint16_t _w, _h, _sizeblock;

  	//texture et sprite Gilet jaune
  	sf::Texture jaune;
  	sf::Sprite gilet_jaune;

  	//Texture et Sprite CRS;
  	sf::Texture CRS_tex;
  	sf::Sprite CRS_spr;

  	//Texture et Sprite Grenade:
  	sf::Texture Grenade_tex;
  	sf::Sprite Grenade_spr;
	
};







#endif
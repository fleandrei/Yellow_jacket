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
    bool colision_joueur(sf::Vector2f point){return joueur_spr.getGlobalBounds().contains(point);}
    void draw_gilet(float x, float y);
    void draw_gilet(float x, float y, float h, float w);
    void draw_degat(float x, float y, float h, float w);
    void draw_CRS(float x, float y);
    void draw_CRS(float x, float y, float h, float w);
    void draw_Grenade(float x, float y);
    void draw_Grenade(float x, float y, float h, float w);
    void draw_Voiture(float x, float y);
    void draw_Voiture(float x, float y, float h, float w);
    void draw_victoire();


private:
	sf::RenderWindow *  _win;
  	uint16_t _w, _h, _sizeblock;

  	//texture et sprite Gilet jaune
  	sf::Texture Guillaume_tex;
  	sf::Texture Andrei_tex;
  	sf::Sprite joueur_spr;
  	sf::Texture Gui_degat;
  	sf::Texture And_degat;
  	sf::Sprite degat;
  	sf::Texture jaune_tex;
  	sf::Sprite jaune_spr;

  	//Texture et Sprite CRS;
  	sf::Texture CRS_tex;
  	sf::Sprite CRS_spr;

  	//Texture et Sprite Grenade:
  	sf::Texture Grenade_tex;
  	sf::Sprite Grenade_spr;

  	//Texture et Sprite voiture:
  	sf::Texture Voiture_tex;
  	sf::Sprite Voiture_spr;

	
  	//Texture et Sprite de l'image de victoire
  	sf::Texture Vic_tex;
  	sf::Sprite Vic_spr;

};







#endif
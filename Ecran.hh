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
    bool mouse_guillaume(){return Guillaume_spr.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*_win));}
    bool mouse_andrei(){return Andrei_spr.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*_win));}
    void set_joueur(std::string nom);
    void draw_intro();
    void draw_gilet(float x, float y, int O);
    void draw_gilet(float x, float y, float h, float w);
    void draw_degat(float x, float y, float h, float w);
    void draw_CRS(float x, float y);
    void draw_CRS(float x, float y, float h, float w);
    void draw_crs_flash(float x, float y);
    void draw_Grenade(float x, float y);
    void draw_flashball(float x, float y);
    //void draw_Grenade(float x, float y, float h, float w);
    void draw_Voiture(float x, float y);
    void draw_Voiture(float x, float y, float h, float w);
    void draw_Map();
    void draw_victoire();
    sf::Text creat_text_arial(std::string text, int size, sf::Color col, float x, float y);
    void draw_text(sf::Text text){_win->draw(text);}
    void clear();

private:
	sf::RenderWindow *  _win;
  	uint16_t _w, _h, _sizeblock;

  	void sprite_intro();
  	void sprite_projectile();
  	void sprite_crs();
  	void police_ecriture();



  	//texture et sprite Gilet jaune
  	sf::Texture Guillaume_tex;
  	sf::Texture Andrei_tex;
  	sf::Sprite Guillaume_spr;
  	sf::Sprite Andrei_spr;
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

   //Texture et Sprite de la map:
  	sf::Texture Map_tex;
  	sf::Sprite Map_spr;

  	//Texture et Sprite du backgroung
  	sf::Texture Background_tex;
  	sf::Sprite Background_spr;
    
    //Texture et Sprite du trotoire
  	sf::Texture Trotoire_tex;
  	sf::Sprite Trotoire_spr;

  	//Texture et Sprite du personnage de l'intro
  	sf::Texture intro_tex;
  	sf::Sprite intro_spr;

  	//Texture et Sprite du flashball;
  	sf::Texture flash_tex;
  	sf::Sprite flash_spr;

  	//Texture et Sprite du crs_flashball;
  	sf::Texture crs_flash_tex;
  	sf::Sprite crs_flash_spr;


  	sf::Font arial;
  };







#endif
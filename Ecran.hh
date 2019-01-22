#ifndef ECRAN_HH_
#define ECRAN_HH_
#include <iostream>
#include <SFML/Graphics.hpp>


class Ecran /*Intermédiaire permettant aux autres classes d'inter agir avec l'écran*/
{
public:
	Ecran(uint16_t w, uint16_t h, uint16_t sizeblock);
	~Ecran(){delete _win;}

	/*Fonctions qui permettent aux autre classes d'interagir avec l'écran*/
	bool isOpen(){return _win->isOpen();}
    void close(){_win->close();}
    void render(){_win->display(); _win->clear();} //Affiche tous ce qu'il y a sur l'ecran; puis efface l'écran actuel.
    bool pollEvent(sf::Event& event){return _win->pollEvent(event);}

    /*Renvoie true si le point passé en paramètre se trouve sur le sprite du joueur*/
    bool colision_joueur(sf::Vector2f point){return joueur_spr.getGlobalBounds().contains(point);}

    /*Renvoie true si la souris est sur le sprite du personnage*/ 
    bool mouse_guillaume(){return Guillaume_spr.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*_win));}
    bool mouse_andrei(){return Andrei_spr.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*_win));}

    /*Renvoie true si la souris est sur le texte passé en paramètre*/
    bool mouse_text(sf::Text tex){return tex.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*_win));}

    /*Permet de mettre en place les ressources graphiques liées au personnage dont le nom est passé en paramètre: C'est avec ce personnage que l'on jouera cette partie*/
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
    void draw_Voiture(float x, float y);
    void draw_Voiture(float x, float y, float h, float w);
    void draw_Map();
    void draw_defaite();
    void draw_victoire();

    /*Méthode permettant de créer en différentes polices, des texte affichables */
    sf::Text creat_text_arial(std::string text, int size, sf::Color col, float x, float y);
    sf::Text creat_text_adventure(std::string text, int size, sf::Color col, float x, float y);
    sf::Text creat_text_error(std::string text, int size, sf::Color col, float x, float y);
    sf::Text creat_text_violent(std::string text, int size, sf::Color col, float x, float y);

    void draw_text(sf::Text text){_win->draw(text); }// Permet d'afficher le text passé en paramètre à l'écran
    //void clear();

private:
	sf::RenderWindow *  _win; //Pointeur sur l'écran
  	uint16_t _w, _h, _sizeblock; // largeur, hauteur de l'écran ainsi que taille des blocks élémentaires.

  	/*Méthodes de chargement des textures, de création et d'ajustement de sprites */
  	void sprite_intro();
  	void sprite_projectile();
  	void sprite_crs();
  	void sprite_decor();
  	void sprite_fin();


	void police_ecriture();//Méthode chargée de charger les différentes polices d'écriture


  	//texture et sprite Gilet jaune
  	sf::Texture Guillaume_tex;
  	sf::Texture Andrei_tex;
  	sf::Texture Gui_intro_tex;//Pour les images sur fond blanc de l'introduction
  	sf::Texture And_intro_tex;
  	sf::Sprite Guillaume_spr;
  	sf::Sprite Andrei_spr;
  	sf::Sprite joueur_spr;
  	sf::Texture Gui_degat;//Image lorsque l'on prend des dégats
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

  	//Texture et Sprite de l'image de défaite;
  	sf::Texture Defaite_tex;
  	sf::Sprite Defaite_spr;

  	//Texture et Sprite de l'image de défaite;
  	sf::Texture macron_tex;
  	sf::Sprite macron_spr;
	
	//Texture et Sprite de l'image de défaite;
  	sf::Texture Dance_tex;
  	sf::Sprite Dance_spr;

  	//Police d'écriture:
  	sf::Font arial;
  	sf::Font error;
  	sf::Font violent;
  	sf::Font Adventure;
  };







#endif
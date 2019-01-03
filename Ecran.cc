#include "Ecran.hh"

using namespace sf;
using namespace std;





Ecran::Ecran(uint16_t w, uint16_t h, uint16_t sizeblock): _h(h), _w(w), _sizeblock(sizeblock)
{
	_win = new sf::RenderWindow(sf::VideoMode(_w , _h+50), "NEW GAME: Yellow Jacket");
	
	//sf::Texture jaune;
	// On Charge la texture de gilet jaune et on crée le sprite correspondant
	if (!Guillaume_tex.loadFromFile("guillaume.jpg"))
	{
    	std::cout<<"Erreure l'image guillaume.jpg n'est pas chargée"<<std::endl;
	}

	if (!Gui_degat.loadFromFile("guillaumemal.png"))
	{
    	std::cout<<"Erreure l'image guillaumemal.gpng n'est pas chargée"<<std::endl;
	}

	if (!Andrei_tex.loadFromFile("andrei.jpg"))
	{
		std::cout<<"Erreure l'image andrei.jpg n'est pas chargée"<<std::endl;
	}

	Guillaume_tex.setSmooth(true);
	joueur_spr.setTexture(Guillaume_tex);
	joueur_spr.setScale(0.25f, 0.25f);

	Andrei_tex.setSmooth(true);
	//Andrei_spr.setTexture(Andrei_tex);
	//Andrei_spr.setScale(0.25f, 0.25f);

	degat.setTexture(Gui_degat);
	//degat.setScale(0.25f, 0.25f);

	if (!jaune_tex.loadFromFile("jaune.png"))
	{
    	std::cout<<"Erreure l'image jaune.png n'est pas chargée"<<std::endl;
	}

	jaune_tex.setSmooth(true);
	jaune_spr.setTexture(jaune_tex);
	jaune_spr.setScale(0.25f, 0.25f);

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

	// On Charge la texture de La Voiture et on crée le sprite correspondant
	if (!Voiture_tex.loadFromFile("voiture.jpeg"))
	{
		cout<<"Erreure l'image voiture.jpeg n'a pas pue être chargée"<<endl;
	}

	Voiture_tex.setSmooth(true);
	Voiture_spr.setTexture(Voiture_tex);
	Voiture_spr.setScale(0.25f, 0.25f);

	//On Charge la texture de La Grenade et on crée le sprite correspondant
	if (!Vic_tex.loadFromFile("victoire.png"))
	{
		cout<<"Erreure l'image victoire.png n'a pas pue être chargée"<<endl;
	}

	Vic_tex.setSmooth(true);
	Vic_spr.setTexture(Vic_tex);
	Vic_spr.setScale(0.25f, 0.25f);

}

  

void Ecran::draw_gilet(float x, float y){
	//cout<<"x="<<x<<" y= "<<y<<endl;
	//cout<<"Joueur globale bound"<<joueur_spr.getGlobalBounds().width<<" "<<joueur_spr.getGlobalBounds().height<<endl;
	joueur_spr.setPosition(x,y);
	_win->draw(joueur_spr);
	/*jaune_spr.setPosition(x,y);
	_win->draw(jaune_spr);*/
}

void Ecran::draw_gilet(float x, float y, float h, float w){
	//cout<<"h="<<h<<"w="<<w<<endl;
	joueur_spr.setTextureRect(IntRect(570, 60, 200, 270));

	joueur_spr.setScale(w/joueur_spr.getLocalBounds().width,h/joueur_spr.getLocalBounds().height);
	//cout<<gilet_jaune.getScale().x<<" "<<gilet_jaune.getScale().y<<endl;
	joueur_spr.setPosition(x,y);
	_win->draw(joueur_spr);
	/*jaune_spr.setScale(w/jaune_spr.getLocalBounds().height,h/jaune_spr.getLocalBounds().width);
	//cout<<gilet_jaune.getScale().x<<" "<<gilet_jaune.getScale().y<<endl;
	jaune_spr.setPosition(x,y);
	_win->draw(jaune_spr);*/
}

void Ecran::draw_CRS(float x, float y){
	CRS_spr.setPosition(x,y);
	_win->draw(CRS_spr);
}

void Ecran::draw_CRS(float x, float y, float h, float w){
	CRS_spr.setScale(w/CRS_spr.getLocalBounds().width, h/CRS_spr.getLocalBounds().height);
	CRS_spr.setPosition(x,y);
	_win->draw(CRS_spr);
}

void Ecran::draw_Grenade(float x, float y){
	Grenade_spr.setPosition(x,y);
	_win->draw(Grenade_spr);
}

void Ecran::draw_Grenade(float x, float y, float h, float w){
	Grenade_spr.setScale(w/Grenade_spr.getLocalBounds().width, h/Grenade_spr.getLocalBounds().height);
	Grenade_spr.setPosition(x,y);
	//cout<<"x= "<<x<<" y= "<<y<<endl;
	_win->draw(Grenade_spr);
}

void Ecran::draw_victoire(){
	//cout<<"victoire scale"<<Vic_spr.getScale().x<<" "<<Vic_spr.getScale().y<<endl;
	Vic_spr.setPosition(_w/2,_h/2);
	_win->draw(Vic_spr);
}

void Ecran::draw_degat(float x, float y, float h, float w){
	degat.setScale(w/degat.getLocalBounds().width, h/degat.getLocalBounds().height);
	//cout<<"degat scale"<<degat.getScale().x<<" "<<degat.getScale().y<<endl;
	degat.setPosition(x,y);
	_win->draw(degat);
	
}

void Ecran::draw_Voiture(float x, float y){
	Voiture_spr.setPosition(x,y);
	_win->draw(Voiture_spr);
}

void Ecran::draw_Voiture(float x, float y, float h, float w){
	Voiture_spr.setScale(w/Voiture_spr.getLocalBounds().width, h/Voiture_spr.getLocalBounds().height);
	Voiture_spr.setPosition(x,y);
	//cout<<"x= "<<x<<" y= "<<y<<endl;
	_win->draw(Voiture_spr);
}
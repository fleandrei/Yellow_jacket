#include "Ecran.hh"

using namespace sf;
using namespace std;





Ecran::Ecran(uint16_t w, uint16_t h, uint16_t sizeblock): _h(h), _w(w), _sizeblock(sizeblock)
{
	_win = new sf::RenderWindow(sf::VideoMode(_w , _h+50), "NEW GAME: Yellow Jacket");
	police_ecriture();
	sprite_intro();
	sprite_projectile();
	sprite_crs();
	sprite_decor();
	sprite_fin();





	// On Charge la texture de La Voiture et on crée le sprite correspondant
	if (!Voiture_tex.loadFromFile("Image/Voiture.png"))
	{
		cout<<"Erreure l'image Voiture.png n'a pas pue être chargée"<<endl;
	}

	Voiture_tex.setSmooth(true);
	Voiture_spr.setTexture(Voiture_tex);
	Voiture_spr.setTextureRect(IntRect(45, 50, 550,250));
}
	

void Ecran::sprite_intro(){
	// On Charge la texture de gilet jaune et on crée le sprite correspondant
	if (!Gui_intro_tex.loadFromFile("guillaume_fondblanc.jpg"))
	{
    	std::cout<<"Erreure l'image guillaume.jpg n'est pas chargée"<<std::endl;
	}

	if (!And_intro_tex.loadFromFile("andrei_fondblanc.jpg"))
	{
		std::cout<<"Erreure l'image andrei.jpg n'est pas chargée"<<std::endl;
	}

	Gui_intro_tex.setSmooth(true);
	Guillaume_spr.setTexture(Gui_intro_tex);
	Guillaume_spr.setTextureRect(IntRect(70, 30, 220,320));
	Guillaume_spr.setPosition(4*_sizeblock, 5*_sizeblock);
	
	And_intro_tex.setSmooth(true);
	Andrei_spr.setTexture(And_intro_tex);
	Andrei_spr.setTextureRect(IntRect(40, 30, 230,310));
	Andrei_spr.setPosition(10*_sizeblock, 5*_sizeblock);
	
	
	if (!intro_tex.loadFromFile("Image/monsieur_intro.png"))
	{
		cout<<"Erreure l'image monsieur_intro.png n'a pas pue être chargée"<<endl;
	}

	intro_tex.setSmooth(true);
	intro_spr.setTexture(intro_tex);
	intro_spr.setScale(2*_sizeblock/intro_spr.getLocalBounds().width, (3*_sizeblock+_sizeblock/2)/intro_spr.getLocalBounds().height);
	intro_spr.setPosition(8*_sizeblock-intro_spr.getGlobalBounds().width/2, _sizeblock);
}

void Ecran::sprite_crs(){
	// On Charge la texture de CRS et on crée le sprite correspondant
	if (!CRS_tex.loadFromFile("Image/CRS.png"))
	{
		cout<<"Erreure l'image CRS.png n'a pas pue être chargée"<<endl;
	}

	CRS_tex.setSmooth(true);
	CRS_spr.setTexture(CRS_tex);
	CRS_spr.setScale(_sizeblock/CRS_spr.getLocalBounds().width, _sizeblock/CRS_spr.getLocalBounds().height);

	if (!crs_flash_tex.loadFromFile("Image/crs_flash.png"))
	{
		cout<<"Erreure l'image crs_flash.png n'a pas pue être chargée"<<endl;
	}

	crs_flash_tex.setSmooth(true);
	crs_flash_spr.setTexture(crs_flash_tex);
	crs_flash_spr.setTextureRect(IntRect(50,0,500, 450));
	crs_flash_spr.setScale(_sizeblock/crs_flash_spr.getLocalBounds().width, _sizeblock/crs_flash_spr.getLocalBounds().height);


}
void Ecran::sprite_projectile(){
	// On Charge la texture de La Grenade et on crée le sprite correspondant
	if (!Grenade_tex.loadFromFile("Image/grenade.png"))
	{
		cout<<"Erreure l'image grenade.png n'a pas pue être chargée"<<endl;
	}

	Grenade_tex.setSmooth(true);
	Grenade_spr.setTexture(Grenade_tex);
	Grenade_spr.setTextureRect(IntRect(170,150, 270, 250));
	Grenade_spr.setScale(30/Grenade_spr.getLocalBounds().width, 50/Grenade_spr.getLocalBounds().height);

	if (!flash_tex.loadFromFile("Image/flashball.png"))
	{
		cout<<"Erreure l'image flashball.png n'a pas pue être chargée"<<endl;
	}

	flash_tex.setSmooth(true);
	flash_spr.setTexture(flash_tex);
	flash_spr.setTextureRect(IntRect(5,20, 115, 7));
	flash_spr.setScale(15/flash_spr.getLocalBounds().width, 10/flash_spr.getLocalBounds().height);
}
void Ecran::police_ecriture(){
	if(!arial.loadFromFile("Font/arial-narrow.ttf")){
		cout<<"Problème la police arial-narrow n'a pas été téléchargée"<<endl;
	}
	if(!Adventure.loadFromFile("Font/Adventure.ttf")){
		cout<<"Problème la police Adventure.ttf n'a pas été téléchargée"<<endl;
	}
	if(!violent.loadFromFile("Font/ultraviolent.ttf")){
		cout<<"Problème la police ultraviolent.ttf n'a pas été téléchargée"<<endl;
	}
	if(!error.loadFromFile("Font/Error.ttf")){
		cout<<"Problème la police Error.ttf n'a pas été téléchargée"<<endl;
	}
}

void Ecran::sprite_decor(){
	if (!Map_tex.loadFromFile("Image/Route.png"))
	{
		cout<<"Erreure l'image Route.png n'a pas pue être chargée"<<endl;
	}

	Map_tex.setSmooth(true);
	Map_spr.setTexture(Map_tex);
	Map_spr.setPosition(-40,3*_sizeblock+10);
	Map_spr.setScale((_w+70)/Map_spr.getLocalBounds().width, (20+5*_sizeblock)/Map_spr.getLocalBounds().height);


	if (!Background_tex.loadFromFile("Image/arriereplan.png"))
	{
		cout<<"Erreure l'image arriereplan.png n'a pas pue être chargée"<<endl;
	}

	Background_tex.setSmooth(true);
	Background_spr.setTexture(Background_tex);
	Background_spr.setPosition(-60,-7);
	Background_spr.setScale((_w+70)/Background_spr.getLocalBounds().width, (50+3*_sizeblock)/Background_spr.getLocalBounds().height);

	if (!Trotoire_tex.loadFromFile("Image/Trotoire.png"))
	{
		cout<<"Erreure l'image Trotoire.png n'a pas pue être chargée"<<endl;
	}

	Trotoire_tex.setSmooth(true);
	Trotoire_spr.setTexture(Trotoire_tex);
	Trotoire_spr.setTextureRect(IntRect(100, 200, 1500, 200));
	Trotoire_spr.setPosition(-40,8*_sizeblock);
	Trotoire_spr.setScale((_w+70)/Trotoire_spr.getLocalBounds().width, (50)/Trotoire_spr.getLocalBounds().height);
}


void Ecran::sprite_fin(){
	if (!Defaite_tex.loadFromFile("Image/defaite.png"))
	{
		cout<<"Erreure l'image defaite.png n'a pas pue être chargée"<<endl;
	}

	Defaite_tex.setSmooth(true);
	Defaite_spr.setTexture(Defaite_tex);
	Defaite_spr.setScale(1.3, 1.3);
	Defaite_spr.setPosition(8*_sizeblock-Defaite_spr.getGlobalBounds().width/2, 2*_sizeblock);

	if (!macron_tex.loadFromFile("Image/macron_dance.jpeg"))
	{
		cout<<"Erreure l'image macron_dance.jpeg n'a pas pue être chargée"<<endl;
	}

	macron_tex.setSmooth(true);
	macron_spr.setTexture(macron_tex);
	macron_spr.setScale(0.4, 0.3);
	macron_spr.setPosition(13*_sizeblock-macron_spr.getGlobalBounds().width/2, 2*_sizeblock);

	if (!Dance_tex.loadFromFile("Image/danse.jpeg"))
	{
		cout<<"Erreure l'image danse.jpeg n'a pas pue être chargée"<<endl;
	}

	Dance_tex.setSmooth(true);
	Dance_spr.setTexture(Dance_tex);
	Dance_spr.setScale(0.7, 0.7);
	Dance_spr.setPosition(3*_sizeblock-Dance_spr.getGlobalBounds().width/2, 2*_sizeblock);

	if (!Vic_tex.loadFromFile("Image/victoire.png"))
	{
		cout<<"Erreure l'image victoire.png n'a pas pue être chargée"<<endl;
	}

	Vic_tex.setSmooth(true);
	Vic_spr.setTexture(Vic_tex);
	Vic_spr.setScale(0.2f, 0.2f);
	Vic_spr.setPosition(8*_sizeblock - Vic_spr.getGlobalBounds().width/2 -40, 2 *_sizeblock);

	}



void Ecran::draw_intro(){
	_win->draw(intro_spr);
	_win->draw(Guillaume_spr);
	_win->draw(Andrei_spr);

}  

void Ecran::set_joueur(std::string nom){
	if (nom=="Andrei")
	{	
		if (!Andrei_tex.loadFromFile("Image/Andrei.png"))
		{
			std::cout<<"Erreure l'image andrei.jpg n'est pas chargée"<<std::endl;
		}
		joueur_spr.setTexture(Andrei_tex);
		joueur_spr.setTextureRect(IntRect(4037*2/3, 60, 4037/3, joueur_spr.getLocalBounds().height));
		joueur_spr.setScale(_sizeblock/joueur_spr.getLocalBounds().width,(_sizeblock+5)/joueur_spr.getLocalBounds().height);
		if (!And_degat.loadFromFile("Image/degat_and.png"))
		{
    		std::cout<<"Erreure l'image guillaumemal.gpng n'est pas chargée"<<std::endl;
		}
		degat.setTexture(And_degat);

	}else if(nom=="Guillaume"){
		if (!Guillaume_tex.loadFromFile("Image/Guillaume.png"))
		{
			std::cout<<"Erreure l'image andrei.jpg n'est pas chargée"<<std::endl;
		}
		joueur_spr.setTexture(Guillaume_tex);
		joueur_spr.setTextureRect(IntRect(4037*2/3, 60, 4037/3, joueur_spr.getLocalBounds().height));
		joueur_spr.setScale(_sizeblock/joueur_spr.getLocalBounds().width,(_sizeblock+5)/joueur_spr.getLocalBounds().height);
		if (!Gui_degat.loadFromFile("Image/degat_gui.png"))
		{
    		std::cout<<"Erreure l'image guillaumemal.gpng n'est pas chargée"<<std::endl;
		}
		degat.setTexture(Gui_degat);
	}else{
		cout<<"Problème le joueur n'a pas de nom conventionnel"<<endl;
	}
}

void Ecran::draw_gilet(float x, float y, int O){
	//cout<<"x="<<x<<" y= "<<y<<endl;
	//cout<<"Joueur globale bound"<<joueur_spr.getGlobalBounds().width<<" "<<joueur_spr.getGlobalBounds().height<<endl;

	if (O==0)
	{
		joueur_spr.setTextureRect(IntRect(0, 60, 4037/3,2797));
	}else if(O==1){
		joueur_spr.setTextureRect(IntRect(4037/3, 60, 4037/3, 2797));
	}else{
		joueur_spr.setTextureRect(IntRect(4037*2/3, 60, 4037/3, 2797));
	}

	joueur_spr.setPosition(x,y);
	_win->draw(joueur_spr);
	/*jaune_spr.setPosition(x,y);
	_win->draw(jaune_spr);*/
}

void Ecran::draw_gilet(float x, float y, float h, float w){
	//cout<<"h="<<h<<"w="<<w<<endl;
	joueur_spr.setTextureRect(IntRect(4037*2/3, 60, 4037/3, joueur_spr.getLocalBounds().height));

	joueur_spr.setScale(w/joueur_spr.getLocalBounds().width,h/joueur_spr.getLocalBounds().height);
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

void Ecran::draw_crs_flash(float x, float y){
	crs_flash_spr.setPosition(x,y);
	//cout<<"draw_crs_flash"<<endl;
	_win->draw(crs_flash_spr);
}

void Ecran::draw_Grenade(float x, float y){
	Grenade_spr.setPosition(x,y);
	_win->draw(Grenade_spr);
}

void Ecran::draw_flashball(float x, float y){
	flash_spr.setPosition(x,y);
	_win->draw(flash_spr);
}
/*void Ecran::draw_Grenade(float x, float y, float h, float w){
	Grenade_spr.setScale(w/Grenade_spr.getLocalBounds().width, h/Grenade_spr.getLocalBounds().height);
	Grenade_spr.setPosition(x,y);
	//cout<<"x= "<<x<<" y= "<<y<<endl;
	_win->draw(Grenade_spr);
}*/



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
	_win->draw(Voiture_spr);
}

void Ecran::draw_Map(){
	_win->draw(Map_spr);
	_win->draw(Background_spr);
	_win->draw(Trotoire_spr);

}
void Ecran::draw_defaite(){
	_win->draw(Defaite_spr);
}

void Ecran::draw_victoire(){
	_win->draw(macron_spr);
	_win->draw(Dance_spr);
	_win->draw(Vic_spr);
}

Text Ecran::creat_text_arial(std::string tex, int size, sf::Color col, float x, float y){
	Text text;
	text.setFont(arial);
	text.setString(tex);
	text.setCharacterSize(size);
	text.setColor(col);
	text.setPosition(x,y);
	return text;	

}

Text Ecran::creat_text_violent(std::string tex, int size, sf::Color col, float x, float y){
	Text text;
	text.setFont(violent);
	text.setString(tex);
	text.setCharacterSize(size);
	text.setColor(col);
	text.setPosition(x,y);
	return text;	

}

Text Ecran::creat_text_adventure(std::string tex, int size, sf::Color col, float x, float y){
	Text text;
	text.setFont(Adventure);
	text.setString(tex);
	text.setCharacterSize(size);
	text.setColor(col);
	text.setPosition(x,y);
	return text;	

}

Text Ecran::creat_text_error(std::string tex, int size, sf::Color col, float x, float y){
	Text text;
	text.setFont(error);
	text.setString(tex);
	text.setCharacterSize(size);
	text.setColor(col);
	text.setPosition(x,y);
	return text;	

}
/*
void Ecran::clear(){
	delete &Andrei_spr;
	delete &Guillaume_spr;
	delete &Guillaume_tex;
	delete &joueur_spr;
	delete &Andrei_tex;
	delete &Gui_degat;
	delete &And_degat;
	delete &degat;
	delete &CRS_spr;
	delete &CRS_tex;
	delete &Grenade_spr;
	delete &Guillaume_tex;
	delete &Voiture_spr;
	delete &Voiture_tex;
	delete &Vic_spr;
	delete &Vic_tex;
	delete &Map_spr;
	delete &Map_tex;
	delete &Background_spr;
	delete &Background_tex;
	delete &Trotoire_spr;
	delete &Trotoire_tex;
	delete &intro_spr;
	delete &intro_tex;


}*/
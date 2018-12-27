#include <iostream>
#include "Ecran.hh"
#include "Gilet_joueur.hh"
using namespace std;
using namespace sf;

uint16_t W=1000, H=900;

int main(int argc, char const *argv[])
{
	Ecran ecran(W,H);
	Gilet_joueur J("Joueur", W-70, H/2, W-70, W, 0, H-30, 70, 70,ecran);
	while(ecran.isOpen()){
		Event event;
		if (ecran.pollEvent(event))
		{
			if (event.type==sf::Event::Closed)
			{
				ecran.close();
			}
		}
		if(sf::Keyboard::isKeyPressed(Keyboard::Up)){
                J.move(0,-0.7);
            }else if(sf::Keyboard::isKeyPressed(Keyboard::Down)){
                J.move(0,0.7);
            }

		J.draw(ecran);
		ecran.render();
	}
	return 0;
}
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main(void){

std::cout<<"hello"<<std::endl;
//RenderWindow app(VideoMode(800, 600, 32), "Ma premiere fenetre SFML ! ");
/*sf::shape carre;
carre.enableoutline(true);
carre.addpoint(vector2f(200,200), color(255,0,0), color(0,0,255));
carre.addpoint(vector2f(400,200), color(255,0,0), color(0,0,255));
carre.addpoint(vector2f(200,400), color(255,0,0), color(0,0,255));
carre.addpoint(vector2f(400,400), color(255,0,0), color(0,0,255));
*/
 /*µwhile (app.isOpen())

    {

        Event event;


        while (app.waitEvent(event))

        {

            if (event.type == Event::Closed)

                app.close();

        }


        // Remplissage de l'écran (couleur noire par défaut)

        app.clear();


        // Affichage de la fenêtre à l'écran

        app.display();

    }*/
 sf::RenderWindow window(sf::VideoMode(800, 700), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Texture jaune;
if (!jaune.loadFromFile("jaune.png"))
{
    std::cout<<"Erreure l'image giletjaune n'est pas chargée"<<std::endl;
}
jaune.setSmooth(true);
Sprite sprjaune;
sprjaune.setTexture(jaune);
sprjaune.setScale(0.25f, 0.25f);
sprjaune.setPosition(400.f, 350.f);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            /*Gestion de Clavier*/
            if(sf::Keyboard::isKeyPressed(Keyboard::Up)){
                sprjaune.move(0,-10);
            }else if(sf::Keyboard::isKeyPressed(Keyboard::Down)){
                sprjaune.move(0,10);
            }else if(sf::Keyboard::isKeyPressed(Keyboard::Left)){
                sprjaune.move(-10,0);
            }else if(sf::Keyboard::isKeyPressed(Keyboard::Right)){
                sprjaune.move(10,0);
            }

            /*Gestion de la souris*/
            if(Mouse::isButtonPressed(Mouse::Left)){
                Vector2i positionsouris= Mouse::getPosition(window);
                shape.setPosition(positionsouris.x, positionsouris.y);
            }
        }

        window.clear();
        window.draw(shape);
        window.draw(sprjaune);
        window.display();
    }
	return 0;
}
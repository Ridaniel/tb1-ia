#include "CHud.h"



CObjeto* CHud::getVida()
{
	return this->vidaObj;
}

int CHud::getVidaIndice()
{
	return vida;
}

int CHud::getPuntaje()
{
	return this->puntaje;
}

void CHud::setVida(int vida)
{
	this->vida = vida;
}

void CHud::setPuntaje(int puntaje)
{
	this->puntaje = puntaje;
	puntajetxt->setString("Puntuación: " + std::to_string(puntaje));
	puntajetxt->setPosition(1280 / 2, 720 / 160);
}

void CHud::setPiso(int piso)
{
	this->pisos = piso;
	pisostxt->setString(std::to_string(pisos));
	pisostxt->setPosition((1280 / 3) - 2, 720 / 130);
}

void CHud::dibujar(sf::RenderWindow * uiwindow)
{
	uiwindow->draw(*pisosObj->getSprite());
	uiwindow->draw(*vidaObj->getSprite());
	uiwindow->draw(*puntajetxt);
	uiwindow->draw(*pisostxt);
	uiwindow->draw(*Arma->getSprite());
	uiwindow->draw(*Pechera->getSprite());
}

CHud::CHud(sf::RenderWindow *uiwindow)
{
	this->vida = 0;
	this->puntaje = 0;
	this->pisos = 1;
	vidaObj = new CObjeto("Imagenes/imagenesUi/barrasVida.png");
	pisosObj = new CObjeto("Imagenes/imagenesUi/escalera.png");
	Arma = new CObjeto("Imagenes/imagenesUi/cuadradito.png");
	Pechera = new CObjeto("Imagenes/imagenesUi/cuadradito.png");
	vidaObj->setAlto(vidaObj->getSprite()->getLocalBounds().height / 9);
	this->pisosObj->setPosition((uiwindow->getSize().x /3)+10 , uiwindow->getSize().y / 130);
	vidaObj->setPosition(0+1, uiwindow->getSize().y / 130);
	vidaObj->setSize(250, 50);
	pisosObj->setSize(50, 43);
	Arma->setSize(60, 60);
	Pechera->setSize(60, 60);
	Arma->setPosition(uiwindow->getSize().x -220 ,uiwindow->getSize().y / 130);
	Pechera->setPosition(uiwindow->getSize().x - 165, uiwindow->getSize().y / 130);
	fuente.loadFromFile("Fonts/fuente1.ttf");
	this->puntajetxt = new sf::Text;
	this->pisostxt = new sf::Text;
	puntajetxt->setFont(fuente);
	pisostxt->setFont(fuente);
	std::string puntos = "Puntuación: ";
	puntos += std::to_string(puntaje);
	pisostxt->setString(std::to_string(pisos));
	pisostxt->setPosition((uiwindow->getSize().x / 3) - 2, uiwindow->getSize().y / 130);
	puntajetxt->setString(puntos);
	puntajetxt->setPosition(sf::Vector2f(uiwindow->getSize().x / 2, uiwindow->getSize().y / 160));
}


CHud::~CHud()
{
}

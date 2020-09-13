#include "CPuerta.hpp"





CPuerta::CPuerta(int criterio,CCuarto *apunta)
{
	this->apunta = apunta;
	this->criterio = criterio;
	textura = new sf::Texture();
	sprite = new sf::Sprite();
	if (criterio == 1 )
	{
		textura->loadFromFile("Imagenes/PuertaArriba.png");
		nombreImagen = "Imagenes/PuertaArriba.png";
		posicion = new sf::Vector2f(1280 / 2-130,-5);
		sprite->setTexture(*this->textura);
		indice.x = 0;
		indice.y = 0;
		ancho = sprite->getTextureRect().width / 3;
		alto = sprite->getTextureRect().height / 4;
		sprite->setTextureRect(sf::IntRect(indice.x, indice.y, ancho, alto));
		
	
		
	}
	if (criterio == 3)
	{
		textura->loadFromFile("Imagenes/PuertaAbajo.png");
		nombreImagen = "Imagenes/PuertaAbajo.png";
		posicion = new sf::Vector2f(1280 / 2-50, 599);
		sprite->setTexture(*this->textura);
		indice.x = 0;
		indice.y = 0;
		ancho = sprite->getTextureRect().width / 3;
		alto = sprite->getTextureRect().height / 4;
		sprite->setTextureRect(sf::IntRect(indice.x, indice.y, ancho, alto));



	}
	if (criterio == 2) {
		posicion = new sf::Vector2f(1083, 300);
		textura->loadFromFile("Imagenes/PuertaDerecha.png");
		nombreImagen = "Imagenes/PuertaDerecha.png";
		sprite->setTexture(*this->textura);
		indice.x = ancho * 3;
		indice.y = 0;
		ancho = sprite->getTextureRect().width / 4;
		alto = sprite->getTextureRect().height / 3;
		sprite->setTextureRect(sf::IntRect(indice.x, indice.y, ancho, alto));
	
	
	}
	if (criterio == 4) {
		posicion = new sf::Vector2f(60, 300);
		textura->loadFromFile("Imagenes/PuertaIzquierda.png");
		nombreImagen = "Imagenes/PuertaIzquierda.png";
		sprite->setTexture(*this->textura);
		ancho = sprite->getTextureRect().width / 4;
		alto = sprite->getTextureRect().height / 3;
		indice.x = 0;
		indice.y = 2;
		sprite->setTextureRect(sf::IntRect(indice.x, indice.y, ancho, alto));

	
	}
	


	textura->setSmooth(false);



	
	sprite->setPosition(*posicion);
}

CPuerta::~CPuerta()
{
}

CCuarto * CPuerta::getCuarto()
{
	return apunta;
}

int CPuerta::getCriterio()
{
	return this->criterio;
}

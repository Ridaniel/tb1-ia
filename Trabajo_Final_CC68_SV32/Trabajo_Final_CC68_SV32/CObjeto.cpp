#include "CObjeto.hpp"
#include "string"

CObjeto::CObjeto()
{
	textura = new sf::Texture();
	sprite = new sf::Sprite();
	posicion = new sf::Vector2f(250.0f, 250.0f);

}
CObjeto::CObjeto(std::string nombre, sf::Vector2f *posicion, float ancho, float alto, sf::Vector2f *indice)
{
	textura = new sf::Texture();
	sprite = new sf::Sprite();
	this->posicion = posicion;
	textura->loadFromFile(nombre);
	textura->setSmooth(false);
	sprite->setTexture(*this->textura);
	nombreImagen = nombre;
	this->ancho = ancho;
	this->alto = alto;
	sprite->setTextureRect(sf::IntRect(this->indice.x=indice->x,this->indice.y= indice->y,ancho, alto));
	sprite->setPosition(*posicion);
}
CObjeto::CObjeto(std::string nombre)
{
	
	textura = new sf::Texture();
	sprite = new sf::Sprite();
	posicion = new sf::Vector2f(250.0f, 250.0f);
	textura->loadFromFile(nombre);
	textura->setSmooth(false);
	sprite->setTexture(*this->textura);
	nombreImagen = nombre;
	ancho = sprite->getTextureRect().width;
	alto = sprite->getTextureRect().height;
	sprite->setTextureRect(sf::IntRect(indice.x, indice.y, ancho, alto));
	sprite->setPosition(*posicion);
}

CObjeto::~CObjeto()
{
	delete textura;
	delete posicion;
	delete sprite;
}

void CObjeto::setIndiceX(int indiceX)
{
	this->indice.x = indiceX;
	sf::Vector2f scalatemp = sprite->getScale();
	sprite = new sf::Sprite(*textura, sf::IntRect(this->indice.x, indice.y, ancho, alto));
	sprite->setScale(scalatemp);
}

void CObjeto::setIndiceY(int indiceY)
{
	this->indice.y = indiceY;
	sf::Vector2f scalatemp = sprite->getScale();
	sprite = new sf::Sprite(*textura, sf::IntRect(indice.x, this->indice.y, ancho, alto));
	sprite->setScale(scalatemp);
}

void CObjeto::setAlto(float alto)
{
	sf::Vector2f scalatemp = sprite->getScale();
	this->alto = alto;
	sprite = new sf::Sprite(*textura, sf::IntRect(indice.x, indice.y, ancho, alto));
	sprite->setScale(scalatemp);
}

void CObjeto::setPosition(int posicionX, int posicionY)
{

	posicion = new sf::Vector2f(posicionX, posicionY);
	//posicion = new sf::Vector2f(window->getView().getSize().x * (posicionX * window->getView().getSize().x / sf::VideoMode::getDesktopMode().width) / window->getView().getSize().x, window->getView().getSize().y * (posicionY * window->getView().getSize().y / sf::VideoMode::getDesktopMode().height) / window->getView().getSize().y);
	//posicion = new sf::Vector2f(window->getSize().x/posicionX, window->getSize().y/ posicionY);
	sprite->setPosition(*posicion);
}

void CObjeto::setSize(int ancho, int alto)
{
	sprite->setScale(ancho / sprite->getGlobalBounds().width, alto / sprite->getGlobalBounds().height);
}

void CObjeto::setTextura(std::string nombre)
{
	nombreImagen = "";
	nombreImagen = nombre;
	textura->loadFromFile(nombre);
	sprite->setTexture(*this->textura);
	sprite->setTextureRect(sf::IntRect(indice.x, indice.y, ancho, alto));
	sprite->setPosition(*posicion);
	ancho = sprite->getTextureRect().width;
	alto = sprite->getTextureRect().height;
	sprite->setTextureRect(sf::IntRect(indice.x, indice.y, ancho, alto));
	//sprite->setTexture(*textura);
}

void CObjeto::moverIndice(sf::Vector2f movimiento)
{
	sprite->setTextureRect(sf::IntRect(indice.x + movimiento.x, indice.y + movimiento.y, ancho, alto));
}

void CObjeto::cargarTextura(std::string nombre,float x,float y)
{
	


	textura = new sf::Texture;
	textura->loadFromFile(nombre);
	posicion = new sf::Vector2f(x, y);
	sprite = new sf::Sprite;
	sprite->setTexture(*this->textura);
	sprite->setTextureRect(sf::IntRect(indice.x, indice.y, ancho, alto));
	sprite->setPosition(*posicion);
}

std::string CObjeto::getNombreImagen()
{
	return nombreImagen;
}

sf::Vector2f* CObjeto::getSize()
{
	float x = sprite->getGlobalBounds().width;
	float y = sprite->getGlobalBounds().height;
	sf::Vector2f *temp = new sf::Vector2f(x, y);
	return temp;
}

void CObjeto::setAncho(float ancho)
{
	this->ancho = ancho;
	sf::Vector2f scalatemp = sprite->getScale();
	sprite = new sf::Sprite(*textura, sf::IntRect(indice.x, indice.y, ancho, alto));
	sprite->setScale(scalatemp);
}

sf::Texture*  CObjeto::getTextura()
{
	return textura;
}


int CObjeto::getIndiceX()
{
	return indice.x;
}

int CObjeto::getIndiceY()
{
	return indice.y;
}

sf::Vector2f CObjeto::getPosicion()
{
	return sprite->getPosition();
}

float CObjeto::getAncho()
{
	return ancho;
}

float CObjeto::getAlto()
{
	return alto;
}

sf::Sprite* CObjeto::getSprite()
{
	return sprite;
}

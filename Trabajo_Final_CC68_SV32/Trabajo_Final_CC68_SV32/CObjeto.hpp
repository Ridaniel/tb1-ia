#ifndef COBJETO_HPP
#define COBJETO_HPP

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//Creanado la clase objeto
class CObjeto
{
protected:
	float alto;
	float ancho;
	std::string nombreImagen;
	sf::Texture *textura;
	sf::Sprite *sprite;
	sf::Vector2f indice;
	sf::Vector2f *posicion;
	

public:
	CObjeto();
	CObjeto(std::string nombre);
	CObjeto(std::string nombre, sf::Vector2f* posicion, float ancho, float alto, sf::Vector2f* indice);

	~CObjeto();
	// Setters
	void setIndiceX(int indiceX);
	void setIndiceY(int indicey);
	void setAncho(float ancho);
	void setAlto(float alto);
	void setPosition( int posicionX, int posicionY);
	void setSize(int ancho, int alto);
	void setTextura(std::string nombre);
	// Getters
	std::string getNombreImagen();
	sf::Vector2f* getSize();
	sf::Texture *getTextura();
	int getIndiceX();
	int getIndiceY();
	sf::Vector2f getPosicion();
	float getAncho();
	float getAlto();
	sf::Sprite* getSprite();
	void moverIndice(sf::Vector2f movimiento);
	void cargarTextura(std::string nombre,float x,float y);
};

#endif // COBJETO_HPP
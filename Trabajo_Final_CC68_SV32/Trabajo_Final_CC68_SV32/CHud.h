#pragma once
#include "SFML/Graphics.hpp"
#include "CObjeto.hpp"
#include <string>
class CHud
{
	int vida;
	int puntaje;
	int pisos;
	CObjeto *vidaObj;
	sf::Text *puntajetxt;
	sf::Text *pisostxt;
	CObjeto *pisosObj;
	CObjeto *Arma;
	CObjeto *Pechera;
	sf::Font fuente;

public:
	CObjeto* getVida();
	int getVidaIndice();
	int getPuntaje();
	void setVida(int vida);
	void setPuntaje(int puntaje);
	void setPiso(int piso);

	void dibujar(sf::RenderWindow *uiwindow);
	CHud(sf::RenderWindow *uiwindow);
	~CHud();
};


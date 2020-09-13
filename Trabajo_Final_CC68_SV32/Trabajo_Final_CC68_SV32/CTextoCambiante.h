#pragma once
#include "CObjeto.hpp"
class CTextoCambiante :public CObjeto
{
private:
	sf::SoundBuffer * sbuff;
	sf::Sound *sound;
	bool salio;

public:
	void dibujar(sf::Vector2f posicionMouse);
	void setSbuff(std::string nombre);

	CTextoCambiante(std::string nombreImagen) :CObjeto(nombreImagen)
	{
		sbuff = new sf::SoundBuffer;
		sound = new sf::Sound;
		sound->setBuffer(*sbuff);
		salio = true;
		sbuff->loadFromFile("Sonidos/espada.wav");
	};
	~CTextoCambiante();
};


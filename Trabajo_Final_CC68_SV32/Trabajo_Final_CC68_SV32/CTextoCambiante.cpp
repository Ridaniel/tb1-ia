#include "CTextoCambiante.h"

void CTextoCambiante::dibujar(sf::Vector2f posicionMouse)
{
	if (posicionMouse.x > sprite->getPosition().x && posicionMouse.x < sprite->getPosition().x + sprite->getGlobalBounds().width)
	{
		if (posicionMouse.y > sprite->getPosition().y && posicionMouse.y < sprite->getPosition().y + sprite->getGlobalBounds().height) {
			if (salio == true)
			{
				sound->play();
				salio = false;
			}
			if (nombreImagen.find("con") == -1)
			{
				int pos = nombreImagen.find("sin");
				std::string *temp = new std::string;
				for (int i = 0; i < nombreImagen.size(); ++i)
				{
					if (i == pos)
					{
						*temp += 'c';
						continue;
					}
					if (i == pos + 1)
					{
						*temp += 'o';
						continue;
					}
					if (i == pos + 2)
					{
						*temp += 'n';
						continue;
					}
					*temp += nombreImagen[i];
				}
				setTextura(*temp);
			}
		}
		else
		{
			salio = true;
			if (nombreImagen.find("sin") == -1)
			{
				int pos = nombreImagen.find("con");
				std::string *temp = new std::string;
				for (int i = 0; i < nombreImagen.size(); i++)
				{
					if (i == pos)
					{
						*temp += 's';
						continue;
					}
					if (i == pos + 1)
					{
						*temp += 'i';
						continue;
					}
					if (i == pos + 2)
					{
						*temp += 'n';
						continue;
					}
					*temp += nombreImagen[i];
				}
				setTextura(*temp);
			}
		}
	}
	else
	{
		salio = true;
		if (nombreImagen.find("sin") == -1)
		{
			int pos = nombreImagen.find("con");
			std::string *temp = new std::string;
			for (int i = 0; i < nombreImagen.size(); i++)
			{
				if (i == pos)
				{
					*temp += 's';
					continue;
				}
				if (i == pos + 1)
				{
					*temp += 'i';
					continue;
				}
				if (i == pos + 2)
				{
					*temp += 'n';
					continue;
				}
				*temp += nombreImagen[i];
			}
			setTextura(*temp);
		}
	}
}

void CTextoCambiante::setSbuff(std::string nombre)
{
	sbuff->loadFromFile(nombre);
}

CTextoCambiante::~CTextoCambiante()
{
	sound->stop();
	sound->~Sound();
	sbuff->~SoundBuffer();
}

#include "CProtagonista.hpp"

CProtagonista::CProtagonista()
{
	hambre = 0;
	vidaMaxima = 0;
	experiencia = 0;
	indiceXTemp = 0;
	indiceYTemp = 0;
	inventario = new CInventario();
	teclaPresionada = 'd';
	posicion->x = 200;
	posicion->y = 220 + getSize()->y;
}

CProtagonista::CProtagonista(int experiencia, int vidaMaxima, int hambre, CInventario* inventario, std::string nombreSprite) : CPersonaje(3000, 10, 1, 0, sf::Vector2i(3,3), 0, nombreSprite)
{
	this->hambre = hambre;
	this->vidaMaxima = vidaMaxima;
	this->inventario = inventario;
	this->experiencia = experiencia;
	setAncho(sprite->getLocalBounds().width / 7);
	setAlto(sprite->getLocalBounds().height / 2);
	setSize(getAncho() * 4, getAlto() * 4);
	atacarEfecto = new CObjeto("Imagenes/atacar.png");
	atacarEfecto->setSize(getAncho() * 4, getAlto() * 4);
	teclaPresionada = 'd';
	posicion->x = 200;
	posicion->y = 220 + getSize()->y;
}

CProtagonista::~CProtagonista()
{
}

int CProtagonista::getVidaMaxima()
{
	return vidaMaxima;
}

int CProtagonista::getHambre()
{
	return hambre;
}

CInventario *& CProtagonista::getinventario()
{
	return inventario;
}

void CProtagonista::setVidaMaxima(int vidaMaxima)
{
	this->vidaMaxima = vidaMaxima;
}

void CProtagonista::setHambre(int hambre)
{
	this->hambre = hambre;
}

void CProtagonista::matarEnemigo(CPersonaje enemigo)
{
	this->experiencia += enemigo.getExperiencia();
	this->dinero += enemigo.getDinero();
}

CObjeto* CProtagonista::getAtacarEfecto()
{
	return atacarEfecto;
}

bool CProtagonista::atacar()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{

			if (teclaPresionada == 'a')
			{
				atacarEfecto->setPosition(posicion->x - getSize()->x, posicion->y);
			}
			else if (teclaPresionada == 'd')
			{		
				atacarEfecto->setPosition(posicion->x + getSize()->x, posicion->y);
			}
			else if (teclaPresionada == 'w')
			{
				atacarEfecto->setPosition(posicion->x, posicion->y - getSize()->y);
			}
			else if (teclaPresionada == 's')
			{
				atacarEfecto->setPosition(posicion->x, posicion->y + getSize()->y);
			}
		
		return true;
	}
	atacarEfecto->setPosition(0, 0);
	return false;
}

char CProtagonista::getTeclaPresionada()
{
	return teclaPresionada;
}

void CProtagonista::movimiento()
{
	++contadorAnimacion;
	if (contadorAnimacion >= 3)
		contadorAnimacion = 0;
	if (contadorAnimacion == 2)
	{
		++indiceXTemp;
		moverIndice(sf::Vector2f(indiceXTemp * ancho, indiceYTemp));
	}
	if (indiceXTemp >= 6)
		indiceXTemp = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && posicion->x < 1050)
	{
		teclaPresionada = 'd';
		setPosition(posicion->x + velocidad.x, posicion->y);
		indiceYTemp = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && posicion->x > 170)
	{
		teclaPresionada = 'a';
		setPosition(posicion->x - velocidad.x, posicion->y);
		indiceYTemp = getAlto();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && posicion->y > 100)
	{
		teclaPresionada = 'w';
		setPosition(posicion->x, posicion->y - velocidad.y);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && posicion->y < 540)
	{
		teclaPresionada = 's';
		setPosition(posicion->x, posicion->y + velocidad.y);
	}
	else
		moverIndice(sf::Vector2f(0, indiceYTemp));
}

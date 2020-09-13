#include "CPersonaje.hpp"

CPersonaje::CPersonaje()
{
	vida				= 0;
	ataque				= 0;
	nivel				= 0;
	defensa				= 0;
	velocidad			= sf::Vector2i(0,0);
	experiencia			= 0;
	contadorAnimacion	= 0;
}

CPersonaje::CPersonaje(int vida, int ataque, int nivel, int defensa, sf::Vector2i velocidad, int experiencia, std::string nombreSprite) : CObjeto(nombreSprite)
{
	this->vida			= vida;
	this->ataque		= ataque;
	this->nivel			= nivel;
	this->defensa		= defensa;
	this->velocidad		= velocidad;
	this->experiencia	= experiencia;
}

CPersonaje::~CPersonaje()
{
}

int CPersonaje::getVida()
{
	return vida;
}

int CPersonaje::getAtaque()
{
	return ataque;
}

int CPersonaje::getNivel()
{
	return nivel;
}

int CPersonaje::getDefensa()
{
	return defensa;
}

sf::Vector2i CPersonaje::getVelocidad()
{
	return velocidad;
}

int CPersonaje::getDinero()
{
	return dinero;
}

int CPersonaje::getExperiencia()
{
	return experiencia;
}

void CPersonaje::setVida(int vida)
{
	this->vida = vida;
}

void CPersonaje::setAtaque(int ataque)
{
	this->ataque = ataque;
}

void CPersonaje::setNivel(int nivel)
{
	this->nivel = nivel;
}

void CPersonaje::setDefensa(int defensa)
{
	this->defensa = defensa;
}

void CPersonaje::setVelocidad(sf::Vector2i velocidad)
{
	this->velocidad = velocidad;
}

void CPersonaje::setDinero(int dinero)
{
	this->dinero = dinero;
}

void CPersonaje::setExperiencia(int experiencia)
{
	this->experiencia = experiencia;
}

void CPersonaje::atacar(CPersonaje &enemigo)
{
	enemigo.setVida(enemigo.getVida() - (ataque - enemigo.getDefensa()));
	if (enemigo.getVida() < 0)
		enemigo.setVida(0);
}
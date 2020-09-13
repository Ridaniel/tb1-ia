#ifndef CPERSONAJE_HPP
#define CPERSONAJE_HPP

#include "CObjeto.hpp"

enum Direccion {
	arriba,
	abajo,
	derecha,
	izquierda
};

//Se crea la clase CPersonaje que tiene herencia de la clase CObjeto
class CPersonaje : public CObjeto
{
protected:
	//Se declara los atributos de la clase
	Direccion direccion;
	int vida;
	int ataque;
	int nivel;
	int defensa;
	sf::Vector2i velocidad;
	int dinero;
	int experiencia;
	int contadorAnimacion;

public:
	//Se crea su constructor vacio
	CPersonaje();
	//Se crea el constructor sobrecargado
	CPersonaje(int vida, int ataque, int nivel, int defensa, sf::Vector2i velocidad, int experiencia, std::string nombreSprite);
	//Se crea el destructor
	~CPersonaje();
	//Se implementan los getters y setters
	int getVida();
	int getAtaque();
	int getNivel();
	int getDefensa();
	sf::Vector2i getVelocidad();
	int getDinero();
	int getExperiencia();
	void setVida(int vida);
	void setAtaque(int ataque);
	void setNivel(int nivel);
	void setDefensa(int defensa);
	void setVelocidad(sf::Vector2i velocidad);
	void setDinero(int dinero);
	void setExperiencia(int experiencia);
	//funciones de juego
	void atacar(CPersonaje &enemigo);
};

#endif // !CPERSONAJE_HPP
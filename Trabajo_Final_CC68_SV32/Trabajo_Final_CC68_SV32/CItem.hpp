#ifndef CITEM_HPP
#define CITEM_HPP

#include "CObjeto.hpp"

//Es el tipo de item
enum tipoItem
{
	arma,
	armadura,
	pocion
};

//Es el tipo de daño pasivo que puede hacer un item
enum passive {
	fuego,
	veneno,
	hielo,
	roboVida,
	nada
};

class CItem : public CObjeto
{
protected:
	//Se declara los atributos
	tipoItem tipo;
	passive	pasiva;
	int durabilidad;
	int damagePasiva;
	int poder;
	std::string nombre;
public:
	//Se crea el constructor vacio
	CItem();
	//Se declara el constructor sobrecargado
	CItem(tipoItem tipo, passive pasiva, int durabilidad, int damagePasiva, std::string nombre, std::string nombreSprite, int celda);
	//Se declara el destructor
	~CItem();
	//Se declara los getters y setters
	tipoItem getTipo();
	passive getPasiva();
	int getDurabilidad();
	int getDamagePasiva();
	int getPoder();
	std::string getNombre();
	void setTipo(tipoItem tipo);
	void setPasiva(passive pasiva);
	void setDurabilidad(int durabilidad);
	void getDamagePasiva(int damagePasiva);
	void setPoder(int poder);
};

#endif // !CITEM_HPP
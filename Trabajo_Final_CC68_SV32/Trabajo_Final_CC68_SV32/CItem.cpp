#include "CItem.hpp"

CItem::CItem()
{
}

CItem::CItem(tipoItem tipo, passive pasiva, int durabilidad, int damagePasiva, std::string nombre, std::string nombreSprite,int celda) : CObjeto(nombreSprite)
{
	this->tipo = tipo;
	this->nombre = nombre;
	this->pasiva = pasiva;
	this->durabilidad = durabilidad;
	this->damagePasiva = damagePasiva;
	if(tipo==tipoItem(0))
		setSize(getAncho() /4, getAlto() / 4);
	else
		setSize(getAncho() / 7, getAlto() / 7);
	setPosition((rand()%3+5)*celda, (rand() % 5 + 2)*celda);
	
}


CItem::~CItem()
{
}

tipoItem CItem::getTipo()
{
	return tipo;
}

passive CItem::getPasiva()
{
	return pasiva;
}

int CItem::getDurabilidad()
{
	return durabilidad;
}

int CItem::getDamagePasiva()
{
	return damagePasiva;
}

int CItem::getPoder()
{
	return poder;
}

std::string CItem::getNombre()
{
	return nombre;
}

void CItem::setTipo(tipoItem tipo)
{
	this->tipo = tipo;
}

void CItem::setPasiva(passive pasiva)
{
	this->pasiva = pasiva;
}

void CItem::setDurabilidad(int durabilidad)
{
	this->durabilidad = durabilidad;
}

void CItem::getDamagePasiva(int damagePasiva)
{
	this->damagePasiva = damagePasiva;
}

void CItem::setPoder(int poder)
{
	this->poder = poder;
}

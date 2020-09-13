#include "CSprite.hpp"



CSprite::CSprite()
{
	posicionX = 0;
	posicionY = 0;
	indiceX = 0;
	indiceY = 0;
}


CSprite::~CSprite()
{
	
}

void CSprite::setPosicionX(int posicionX)
{
	this->posicionX = posicionX;
}

void CSprite::setPosicionY(int posicionY)
{
	this->posicionY = posicionY;
}

void CSprite::setIndiceX(int indiceX)
{
	this->indiceX = indiceX;
}

void CSprite::setIndiceY(int indiceY)
{
	this->indiceY = indiceY;
}

int CSprite::getPosicionX()
{
	return posicionX;
}

int CSprite::getPosicionY()
{
	return posicionY;
}

int CSprite::getIndiceX()
{
	return indiceX;
}

int CSprite::getIndiceY()
{
	return indiceY;
}

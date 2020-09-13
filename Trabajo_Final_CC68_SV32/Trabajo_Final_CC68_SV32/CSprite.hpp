#pragma once
#include "CObjeto.hpp"
class CSprite :
	public CObjeto
{protected:
	int posicionX;
	int posicionY;
	int indiceX;
	int indiceY;


public:
	CSprite();
	~CSprite();

	void setPosicionX(int posicionX );
	void setPosicionY(int posicionY);
	void setIndiceX(int indiceX);
	void setIndiceY(int indiceY);
	int getPosicionX();
	int getPosicionY();
	int getIndiceX();
	int getIndiceY();


};



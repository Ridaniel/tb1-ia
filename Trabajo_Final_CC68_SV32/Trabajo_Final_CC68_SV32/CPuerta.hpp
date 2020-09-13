#pragma once
#include "CObjeto.hpp"
#include "CCuarto.hpp"
class CPuerta :
	public CObjeto
	
{
private:
	int criterio;
	CCuarto *apunta;

public:
	CPuerta(int criterio,CCuarto *apunta) ;
	~CPuerta();
	CCuarto* getCuarto();
	int getCriterio();
};


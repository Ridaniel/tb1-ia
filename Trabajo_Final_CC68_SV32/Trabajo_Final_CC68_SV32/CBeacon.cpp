#include "CBeacon.hpp"
#include <cstdlib>
CBeacon::CBeacon(bool crearTodo )
{
	if (crearTodo) {
		crearPiso();
		actual = &cuartos->getCuartos()[0];
	}
	else {
		actual = nullptr;
		cuartos = nullptr;
	}
}

CBeacon::CBeacon(bool crearTodo,std::vector<int> *valAg)
{
	if (crearTodo) {
		crearPiso(valAg);
		actual = &cuartos->getCuartos()[0];
	}
	else {
		actual = nullptr;
		cuartos = nullptr;
	}
}

 CBeacon::CBeacon(int cantCuartos,int Beacon,std::vector<int> *valAg)
{
	auto comparar = [](Par<int, CCuarto*> a, Par<int, CCuarto*> b) {
		if (a.prime == b.prime && a.secun == b.secun)
			return true;
		else return false;
	};
	cuartos = new CListaAdyacencia<CCuarto>(cantCuartos, comparar, beacon, false,valAg);
}



CBeacon::~CBeacon()
{
}

CCuarto *& CBeacon::CuartoActual()
{
	return *&actual;
}

void CBeacon::crearPiso(std::vector<int> *valAg)
{
	srand(time(NULL));
	int cantcuartos = rand()%10+5;
	auto comparar = [](Par<int, CCuarto*> a, Par<int, CCuarto*> b) {
		if (a.prime == b.prime && a.secun == b.secun)
			return true;
		else return false;
	};
	beacon = rand() % cantcuartos;
	cuartos = new CListaAdyacencia<CCuarto>(cantcuartos,comparar,beacon,true,valAg);
	
}

void CBeacon::crearPiso()
{
	srand(time(NULL));
	int cantcuartos = rand() % 10 + 5;
	auto comparar = [](Par<int, CCuarto*> a, Par<int, CCuarto*> b) {
		if (a.prime == b.prime && a.secun == b.secun)
			return true;
		else return false;
	};
	beacon = rand() % cantcuartos;
	cuartos = new CListaAdyacencia<CCuarto>(cantcuartos, comparar, beacon, true);

}


int &CBeacon::getNumero()
{
	return numero;
}

void CBeacon::setNumero(int numero)
{	
	this->numero = numero;
}

CListaAdyacencia<CCuarto>* CBeacon::getLista()
{
	return cuartos;
}

bool CBeacon::inicialiar()
{
	if (cuartos == nullptr) {
		crearPiso();
		actual = &cuartos->getCuartos()[0];
		return true;
	}
	return false;
}

void CBeacon::setActual(CCuarto * actual)
{
	this->actual = actual;
}

int& CBeacon::getCuartoConBeacon()
{
	return beacon;
}


  

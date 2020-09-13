#ifndef __CBEACON__HPP__
#define __CBEACON__HPP__
#include "CListaAdyacencia.hpp"
#include"Par.hpp"
#include"CCuarto.hpp"
class CBeacon
{
private:
	CListaAdyacencia<CCuarto> *cuartos;
	int numero;	
	CCuarto* actual;
	int beacon;
public:
	CBeacon(bool crearTodo);
	CBeacon(bool crearTodo,std::vector<int> *valAg);
	CBeacon(int cantCuartos, int Beaco,std::vector<int> *valAg);
	~CBeacon();
	CCuarto*& CuartoActual();
	void crearPiso(std::vector<int>* valAg);
	void crearPiso();
	int& getNumero();
	void setNumero(int numero);
	CListaAdyacencia<CCuarto>* getLista();
	bool inicialiar();
	void setActual(CCuarto* actual);
	int &getCuartoConBeacon();
};

#endif // !__CBEACON__HPP__


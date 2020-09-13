#ifndef __CCUARTO__HPP__
#define __CCUARTO__HPP__

#include "CObjeto.hpp"
#include "CEnemigo.hpp"
#include "CListaCircular.hpp"
#include "CItem.hpp"
#include <Windows.h>

class CCuarto
{
private:
	int numero;
	int x;
	int y;
	CListaCircular<CEnemigo*>* listaEnemigos;
	CListaCircular<CItem*>*listaItems;
	CObjeto *fondo;
	CObjeto *escalera;
	CObjeto *teletransportador;
public:
	CCuarto();
	CCuarto(bool crear);
	~CCuarto();
	void setSize();
	int& getNumero();
	void setNumero(int numero);
	int& getX();
	int& getY();
	CListaCircular<CEnemigo*>* getListaEnemigos();
	CListaCircular<CItem*>* getListaItems();
	void setCoordenadas(int x, int y);
	void dibujarCuarto(sf::RenderWindow *ventana);
	void crearEscalera(int tipo);
	bool existeEscalera();
	bool existeTeletransportador();
	void crearTeletransportador();
	CObjeto* getTeletransportador();
	CObjeto* getEscalera();
	CObjeto* getFondo();
	void setTeletransportador(CObjeto* teletransportador);
	void setEscalera(CObjeto* Escalera);
	void setFondo(CObjeto*Fondo);
	void inicializarCuarto();
	void inicializarCuartoConAg(std::vector<int> *valAg);
};

#endif // !__CCUARTO__HPP__



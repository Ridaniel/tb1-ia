#ifndef __CMAPA__HPP__
#define __CMAPA__HPP__
#include"CArbolAVL.hpp"
#include"CBeacon.hpp"
#include"CListaDoble.hpp"
#include "SFML/Graphics.hpp"

class CMapa
{
private:
	CArbolAVL<int,CNodo<CBeacon*>*>* mapa;
	CBeacon* actual;
	CListaDoble<CBeacon*>* pisos;
	int cant;
public:
	CMapa();
	CMapa(int cantidad);
	~CMapa();
	void crearPisoSiguiente(std::vector<int> *valAg);
	void crearPisoSiguiente();
	void teletransportarse(int numeroPiso);
	CBeacon*& PisoActual();
	bool cambiarPiso(CCuarto*& cuarto,int criterio,sf::RenderWindow *ventana,std::vector<int> *valAg);
	void generarpisos(int i = 0);
	void setActual(CBeacon *actual);
	int& getCant();
	CListaDoble<CBeacon*>* getPisos();
};
#endif // !__CMAPA__HPP__



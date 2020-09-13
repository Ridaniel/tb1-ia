#ifndef CLISTA_ADYACENCIA_HPP
#define CLISTA_ADYACENCIA_HPP
#include <cstdlib>
#include "CListaCircular.hpp"
#include "Par.hpp"
#include <iostream>
#include <vector>
template<typename tipoDato>
class CListaAdyacencia
{
private:	
	CListaCircular< Par<int, tipoDato*> > *listas;
	tipoDato *cuartos;
	int tamanio;
	bool (*ptr)(Par<int, tipoDato*> a, Par<int, tipoDato*> b);
	bool asignarPosicion(int cuarto, int conexion) {
		bool seguir = true;
		int pos;
		int repeticiones = 0;
		while (seguir) {
			repeticiones++;
			seguir = false;
			pos = rand() % 3 + 1;
			listas[cuarto].iniciarIterator();
			for (int i = 0; i < listas[cuarto].size(); ++i) {
				if (pos == listas[cuarto].iterator->getValor().prime)
				{
					seguir = true;
					break;
				}
				else if (listas[cuarto].iterator->getValor().secun == &cuartos[conexion])
					return false;
				listas[cuarto].moverIterator(1);
				if (repeticiones > 10)
					return false;
			}
		}
		switch (pos)
		{
		case 1:
			cuartos[conexion].setCoordenadas(cuartos[cuarto].getX(), cuartos[cuarto].getY() + 1);
			break;
		case 2:
			cuartos[conexion].setCoordenadas(cuartos[cuarto].getX() + 1, cuartos[cuarto].getY());
			break;
		case 3:
			cuartos[conexion].setCoordenadas(cuartos[cuarto].getX(), cuartos[cuarto].getY() - 1);
			break;
		case 4:
			cuartos[conexion].setCoordenadas(cuartos[cuarto].getX() - 1, cuartos[cuarto].getY());
			break;
		default:
			break;
		}
		asignarConexion(cuarto, conexion, pos);
		return true;
	}
	void asignarConexion(int cuarto, int conexion, int pos) {
		tipoDato* ptr = &cuartos[conexion];
		Par<int, tipoDato*>  cp(pos, ptr);
		listas[cuarto].push_back(cp);
		ptr = &cuartos[cuarto];
		if (pos < 3)
			pos += 2;
		else
			pos -= 2;
		cp.prime = pos;
		cp.secun = ptr;
		listas[conexion].push_back(cp);
	}
	bool asignarConexionb(int cuarto, int conexion, int pos) {
		Par<int, tipoDato*> temp(pos, &cuartos[conexion]);
		if (listas[cuarto].find(temp, ptr))
			return false;
		tipoDato* ptr = &cuartos[conexion];
		Par<int, tipoDato*>  cp(pos, ptr);
		listas[cuarto].push_back(cp);
		ptr = &cuartos[cuarto];
		if (pos < 3)
			pos += 2;
		else
			pos -= 2;
		cp.prime = pos;
		cp.secun = ptr;
		listas[conexion].push_back(cp);
		return true;
	}
public:

CListaAdyacencia(int tamanio, bool  (*ptr2)(Par<int, tipoDato*> a, Par<int, tipoDato*> b),int pos,bool lleno) {
		ptr = ptr2;
		this->tamanio = tamanio;
		listas = new CListaCircular< Par<int, tipoDato*> >[tamanio];
		cuartos = new tipoDato[tamanio]();
		if (lleno) {
			int puertas;
			cuartos[0].setCoordenadas(rand() % 1000 + 50 + tamanio, rand() % 1000 + 50 + tamanio);
			cuartos[0].crearEscalera(2);
			cuartos[tamanio - 1].crearEscalera(1);
			cuartos[pos].crearTeletransportador();
			for (int inicio = 0; inicio < tamanio; ++inicio)
			{
				cuartos[inicio].inicializarCuarto();
				cuartos[inicio].setNumero(inicio);
				if (inicio == tamanio - 1 && cuartos[inicio].getX() == 0)
				{
					for (int i = 0; i < tamanio; ++i) {
						if (listas[i].size() < 4) {
							asignarPosicion(i, inicio);
							break;
						}
					}
				}
				puertas = rand() % 3 + 1;
				puertas -= listas[inicio].size();

				for (int i = 1; i <= puertas; i++) {
					int repe = 0;
					int cuartoconectado;
					bool seguir = true;
					while (seguir && repe < tamanio) {
						repe++;
						cuartoconectado = rand() % tamanio + 1;
						if (cuartoconectado >= tamanio)
							cuartoconectado = tamanio - 1;
						if (listas[cuartoconectado].size() < 4) {

							if (cuartos[inicio].getX() == 0 && cuartos[inicio].getY() == 0) {
								if (cuartos[cuartoconectado].getX() != 0 && cuartos[cuartoconectado].getY() != 0) {
									if (asignarPosicion(cuartoconectado, inicio))
										seguir = false;
								}
							}
							else if (cuartos[cuartoconectado].getX() == 0 && cuartos[cuartoconectado].getY() == 0) {
								if (asignarPosicion(inicio, cuartoconectado))
									seguir = false;
							}
							else {
								if (cuartos[inicio].getX() == cuartos[cuartoconectado].getX()) {
									if (cuartos[inicio].getY() - cuartos[cuartoconectado].getY() == 1) {
										if (asignarConexionb(inicio, cuartoconectado, 3))
											seguir = false;
									}
									else if (cuartos[inicio].getY() - cuartos[cuartoconectado].getY() == -1) {
										if (asignarConexionb(inicio, cuartoconectado, 1))
											seguir = false;
									}
								}
								else if (cuartos[inicio].getY() == cuartos[cuartoconectado].getY()) {
									if (cuartos[inicio].getX() - cuartos[cuartoconectado].getX() == 1) {
										if (asignarConexionb(inicio, cuartoconectado, 4))
											seguir = false;
									}
									else if (cuartos[inicio].getX() - cuartos[cuartoconectado].getX() == -1) {
										if (asignarConexionb(inicio, cuartoconectado, 2))
											seguir = false;
									}
								}
							}
						}
					}
				}
			}
		}
	}


CListaAdyacencia(int tamanio, bool  (*ptr2)(Par<int, tipoDato*> a, Par<int, tipoDato*> b), int pos, bool lleno, std::vector<int>* valAg) {
	ptr = ptr2;
	this->tamanio = tamanio;
	listas = new CListaCircular< Par<int, tipoDato*> >[tamanio];
	cuartos = new tipoDato[tamanio]();
	if (lleno) {
		int puertas;
		cuartos[0].setCoordenadas(rand() % 1000 + 50 + tamanio, rand() % 1000 + 50 + tamanio);
		cuartos[0].crearEscalera(2);
		cuartos[tamanio - 1].crearEscalera(1);
		cuartos[pos].crearTeletransportador();
		for (int inicio = 0; inicio < tamanio; ++inicio)
		{
			cuartos[inicio].inicializarCuartoConAg(valAg);
			cuartos[inicio].setNumero(inicio);
			if (inicio == tamanio - 1 && cuartos[inicio].getX() == 0)
			{
				for (int i = 0; i < tamanio; ++i) {
					if (listas[i].size() < 4) {
						asignarPosicion(i, inicio);
						break;
					}
				}
			}
			puertas = rand() % 3 + 1;
			puertas -= listas[inicio].size();

			for (int i = 1; i <= puertas; i++) {
				int repe = 0;
				int cuartoconectado;
				bool seguir = true;
				while (seguir && repe < tamanio) {
					repe++;
					cuartoconectado = rand() % tamanio + 1;
					if (cuartoconectado >= tamanio)
						cuartoconectado = tamanio - 1;
					if (listas[cuartoconectado].size() < 4) {

						if (cuartos[inicio].getX() == 0 && cuartos[inicio].getY() == 0) {
							if (cuartos[cuartoconectado].getX() != 0 && cuartos[cuartoconectado].getY() != 0) {
								if (asignarPosicion(cuartoconectado, inicio))
									seguir = false;
							}
						}
						else if (cuartos[cuartoconectado].getX() == 0 && cuartos[cuartoconectado].getY() == 0) {
							if (asignarPosicion(inicio, cuartoconectado))
								seguir = false;
						}
						else {
							if (cuartos[inicio].getX() == cuartos[cuartoconectado].getX()) {
								if (cuartos[inicio].getY() - cuartos[cuartoconectado].getY() == 1) {
									if (asignarConexionb(inicio, cuartoconectado, 3))
										seguir = false;
								}
								else if (cuartos[inicio].getY() - cuartos[cuartoconectado].getY() == -1) {
									if (asignarConexionb(inicio, cuartoconectado, 1))
										seguir = false;
								}
							}
							else if (cuartos[inicio].getY() == cuartos[cuartoconectado].getY()) {
								if (cuartos[inicio].getX() - cuartos[cuartoconectado].getX() == 1) {
									if (asignarConexionb(inicio, cuartoconectado, 4))
										seguir = false;
								}
								else if (cuartos[inicio].getX() - cuartos[cuartoconectado].getX() == -1) {
									if (asignarConexionb(inicio, cuartoconectado, 2))
										seguir = false;
								}
							}
						}
					}
				}
			}
		}
	}
}

	~CListaAdyacencia()
	{
	}

	void mostrar()
	{
		
			
			for (int i = 0; i < listas[0].size(); ++i) {
				std::cout << listas[0].at(i).prime << "------";
			}
			
		
	}
	CListaCircular< Par<int, tipoDato*> > * getlista() {
		return listas;
	}
	tipoDato* getCuartos() {
		return cuartos;
	}
	int &getTamanio() {
		return tamanio;
	}
};

#endif // !CLISTA_ADYACENCIA_HPP

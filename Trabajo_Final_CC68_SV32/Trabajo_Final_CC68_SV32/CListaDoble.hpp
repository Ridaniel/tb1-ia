#ifndef CListaDoble_HPP
#define CListaDoble_HPP
#include "CNodo.hpp"

template<typename tipoDato>
class CListaDoble {
private:
	CNodo<tipoDato>* inicio;
	CNodo<tipoDato>* fin;
	int tamanio;
	
public:
	CNodo<tipoDato>* iterator;
	bool iniciarIterator() {
		if (tamanio == 0)
			return false;
		iterator = inicio;
		return true;
	}
	bool moverIterator(int cantidad = 1) {
		if (tamanio == 0 || iterator==nullptr)
			return false;
		if (cantidad>0)
			while (cantidad-->0 && iterator!=nullptr)
				iterator = iterator->getSiguiente();
		else
			while (cantidad++<0 && iterator!=nullptr)
				iterator = iterator->getAnterior();
		return true;
	}
	CListaDoble()
	{
		inicio = nullptr;
		fin = nullptr;
		tamanio = 0;
		iterator = nullptr;
	}
	~CListaDoble()
	{
		delete inicio;
		delete fin;
	}

	void push_back(tipoDato valor)
	{
		CNodo<tipoDato>* nuevo = new CNodo<tipoDato>(valor);
		std::cout << valor->getNumero()<<std::endl;
		if (tamanio == 0) {
			inicio = nuevo;
			fin = nuevo;
		}
		else {
			nuevo->setAnterior(fin);
			fin->setSiguiente(nuevo);
			fin = nuevo;
		}
		++tamanio;
	}
	tipoDato front()
	{
		if (tamanio <= 0) throw "ERROR: NO HAY ELEMENTOS EN LA LISTA!";
		else return inicio->getValor();
	}
	tipoDato back()
	{
		if (tamanio <= 0) throw "ERROR: NO HAY ELEMENTOS EN LA LISTA!";
		else return fin->getValor();
	}
	CNodo<tipoDato>* begin()
	{
		return inicio;
	}
	CNodo<tipoDato>* end()
	{
		return fin;
	}
	bool empty()
	{
		if (tamanio == 0) return true;
		else return false;
	}
	int size()
	{
		return tamanio;
	}
	void clear()
	{
		CNodo<tipoDato>* iterador = inicio;
		for (int i = 0; i < tamanio; ++i) {
			CNodo<tipoDato>* borrador = iterador;
			iterador = iterador->getSiguiente();
			delete borrador;
		}
		inicio = nullptr;
		fin = nullptr;
		tamanio = 0;
	}
	void insert(int posicion, tipoDato valor)
	{
		if (posicion >= 0 && posicion < tamanio) {
			CNodo<tipoDato>* nuevo = new CNodo<tipoDato>(valor);
			if (tamanio == 0) {
				inicio = nuevo;
				fin = nuevo;
				++tamanio;
			}
			else {
				CNodo<tipoDato>* iterador = nullptr;
				if (tamanio - posicion + 1 < posicion) {
					iterador = fin;
					for (int i = tamanio - 1; i > posicion; --i) iterador = iterador->getAnterior();
				}
				else {
					iterador = inicio;
					for (int i = 0; i < posicion; ++i) iterador = iterador->getSiguiente();
				}
				if (posicion == 0) {
					nuevo->setSiguiente(inicio);
					inicio->setAnterior(nuevo);
					inicio = nuevo;
				}
				else if (posicion == tamanio - 1) {
					nuevo->setAnterior(fin);
					fin->setSiguiente(nuevo);
				}
				else {
					nuevo->setAnterior(iterador->getAnterior());
					nuevo->setSiguiente(iterador->getSiguiente());
					nuevo->getAnterior()->setSiguiente(nuevo);
					nuevo->getSiguiente()->setAnterior(nuevo);
				}
			}
			++tamanio;
		}
		else throw "ERROR: POSICION NO VALIDA!";
	}
	void erase(int posicion)
	{
		if (posicion >= 0 && posicion < tamanio) {
			if (tamanio == 0) throw "ERROR: NO HAY ELEMENTOS EN LA LISTA!";
			else {
				CNodo<tipoDato>* iterador = nullptr;
				if (tamanio - posicion + 1 < posicion) {
					iterador = fin;
					for (int i = tamanio - 1; i > posicion; --i) iterador = iterador->getAnterior();
				}
				else {
					iterador = inicio;
					for (int i = 0; i < posicion; ++i) iterador = iterador->getSiguiente();
				}
				CNodo<tipoDato>* borrador = iterador;
				if (posicion == 0) inicio = iterador->getSiguiente();
				else if (posicion == tamanio - 1) fin = iterador->getAnterior();
				else {
					iterador->getAnterior()->setSiguiente(iterador->getSiguiente());
					iterador->getSiguiente()->setAnterior(iterador->getAnterior());
				}
				delete borrador;
			}
			--tamanio;
		}
		else throw "ERROR: POSICION NO VALIDA!";
	}
	void pop_back()
	{
		if (tamanio > 0) {
			CNodo<tipoDato>* borrador = fin;
			fin = fin->getAnterior();
			delete borrador;
			--tamanio;
		}
		else throw "ERROR: NO HAY ELEMENTOS";
	}
	void push_front(tipoDato valor)
	{
		if (tamanio >= 0) {
			CNodo<tipoDato>* nuevo = new CNodo<tipoDato>(valor);
			nuevo->setSiguiente(inicio);
			inicio->setAnterior(nuevo);
			inicio = nuevo;
			++tamanio;
		}
		else throw "ERROR: NO HAY ELEMENTOS";
	}
	void pop_front()
	{
		if (tamanio > 0) {
			CNodo<tipoDato>* borrador = inicio;
			inicio = inicio->getSiguiente();
			delete borrador;
			--tamanio;
		}
		else throw "ERROR: NO HAY ELEMENTOS";
	}
	tipoDato at(int pos)
	{
		if (pos >= 0 && pos < tamanio)
		{
			CNodo<tipoDato> *iterador = nullptr;
			if (tamanio - pos + 1 < pos)
			{
				iterador = fin;
				for (int i = tamanio - 1; i > pos; --i)
					iterador = iterador->getAnterior();
			}
			else
			{
				iterador = inicio;
				for (int i = 0; i < pos; ++i)
					iterador = iterador->getSiguiente();
			}
			return iterador->getValor();
		}
		else
			throw "ERROR: POSICION NO VALIDA!";
	}
};

#endif // !CListaDoble_HPP

#ifndef CLISTACIRCULAR_HPP
#define CLISTACIRCULAR_HPP
#include "CNodo.hpp"

template<typename tipoDato>
class CListaCircular
{
private:
	CNodo<tipoDato> *inicio;
	int cantidadElementos;

public:
	CNodo<tipoDato> *iterator;
	bool iniciarIterator() {
		if (cantidadElementos == 0)
			return false;
		iterator = inicio;
		return true;
	}
	bool moverIterator(int cantidad=1) {
		if (cantidadElementos == 0)
			return false;
		if(cantidad>0)
			while(cantidad-->0)
				iterator = iterator->getSiguiente();
		else
			while (cantidad++<0)
				iterator = iterator->getAnterior();
		return true;
	}

	CListaCircular()
	{
		iterator = nullptr;
		inicio = nullptr;
		cantidadElementos = 0;
	}

	~CListaCircular()
	{
		delete inicio;
	}

	int size()
	{
		return cantidadElementos;
	}

	tipoDato front()
	{
		if (cantidadElementos == 0)
			throw "ERROR: NO HAY ELEMENTOS EN LA LISTA!";
		else
			return inicio->getValor();
	}

	tipoDato back()
	{
		if (cantidadElementos == 0)
			throw "ERROR: NO HAY ELEMENTOS EN LA LISTA!";
		else
			return inicio->getAnterior()->getValor();
	}

	bool empty()
	{
		if (cantidadElementos == 0)
			return true;
		else
			return false;
	}

	void clear()
	{
		CNodo<tipoDato> *iterador = inicio;
		for (int i = 0; i < cantidadElementos; ++i)
		{
			CNodo<tipoDato> *borrador = iterador;
			iterador = iterador->getSiguiente();
			delete borrador;
		}
		inicio->setSiguiente(nullptr);
		inicio->setAnterior(nullptr);
		inicio = nullptr;
		cantidadElementos = 0;
	}

	void insert(int pos, tipoDato valor)
	{
		if (pos >= 0 && pos < cantidadElementos)
		{
			CNodo<tipoDato> *nuevo = new CNodo<tipoDato>(valor);
			if (cantidadElementos == 0)
			{
				inicio = nuevo;
				inicio->setSiguiente(nuevo);
				inicio->setAnterior(nuevo);
				++cantidadElementos;
			}
			else
			{
				CNodo<tipoDato> *iterador = nullptr;
				if (cantidadElementos - pos + 1 < pos)
				{
					iterador = inicio->getAnterior();
					for (int i = cantidadElementos - 1; i > pos; --i)
						iterador = iterador->getAnterior();
				}
				else
				{
					iterador = inicio;
					for (int i = 0; i < pos; ++i)
						iterador = iterador->getSiguiente();
				}
				nuevo->setAnterior(iterador->getAnterior());
				nuevo->setSiguiente(iterador);
				nuevo->getAnterior()->setSiguiente(nuevo);
				nuevo->getSiguiente()->setAnterior(nuevo);
				if (pos == 0)
					inicio = nuevo;
			}
			++cantidadElementos;
		}
		else
			throw "ERROR: POSICION NO VALIDA!";
	}

	void erase(int pos)
	{
		if (pos >= 0 && pos < cantidadElementos)
		{
			if (cantidadElementos == 0)
				throw "ERROR: NO HAY ELEMENTOS EN LA LISTA!";
			else
			{
				CNodo<tipoDato> *iterador = nullptr;
				if (cantidadElementos - pos + 1 < pos)
				{
					iterador = inicio->getAnterior();
					for (int i = cantidadElementos - 1; i > pos; --i)
						iterador = iterador->getAnterior();
				}
				else
				{
					iterador = inicio;
					for (int i = 0; i < pos; ++i)
						iterador = iterador->getSiguiente();
				}
				CNodo<tipoDato> *borrador = iterador;
				iterador->getAnterior()->setSiguiente(iterador->getSiguiente());
				iterador->getSiguiente()->setAnterior(iterador->getAnterior());
				if (pos == 0)
					inicio = iterador->getSiguiente();
				delete borrador;
			}
			--cantidadElementos;
		}
		else
			throw "ERROR: POSICION NO VALIDA!";
	}

	void push_back(tipoDato valor)
	{
		CNodo<tipoDato> *nuevo = new CNodo<tipoDato>(valor);
		if (cantidadElementos == 0)
		{
			inicio = nuevo;
			inicio->setSiguiente(nuevo);
			inicio->setAnterior(nuevo);
		}
		else
		{
			nuevo->setAnterior(inicio->getAnterior());
			nuevo->setSiguiente(inicio);
			inicio->getAnterior()->setSiguiente(nuevo);
			inicio->setAnterior(nuevo);
		}
		++cantidadElementos;
	}

	void pop_back()
	{
		CNodo<tipoDato> *borrador = inicio->getAnterior();
		inicio->getAnterior()->getAnterior()->setSiguiente(inicio);
		inicio->setAnterior(inicio->getAnterior()->getAnterior());
		delete borrador;
		--cantidadElementos;
	}

	void push_front(tipoDato valor)
	{
		CNodo<tipoDato> *nuevo = new CNodo<tipoDato>(valor);
		if (cantidadElementos == 0)
		{
			inicio = nuevo;
			inicio->setSiguiente(nuevo);
			inicio->setAnterior(nuevo);
		}
		else
		{
			nuevo->setAnterior(inicio->getAnterior());
			nuevo->setSiguiente(inicio);
			inicio->getAnterior()->setSiguiente(nuevo);
		}
		inicio->setAnterior(nuevo);
		inicio = nuevo;
		++cantidadElementos;
	}

	void pop_front()
	{
		CNodo<tipoDato> *borrador = inicio;
		inicio->getAnterior()->setSiguiente(inicio->getSiguiente());
		inicio->getSiguiente()->setAnterior(inicio->getAnterior());
		inicio = inicio->getSiguiente();
		delete borrador;
		--cantidadElementos;
	}

	bool find(tipoDato valor,bool (*ptr)(tipoDato ,tipoDato ))
	{
		CNodo<tipoDato> *iterador = inicio;
		for (int i = 0; i < cantidadElementos; ++i)
		{
			if (ptr(valor, iterador->getValor()))
				return true;
			iterador = iterador->getSiguiente();
		}
		return false;
	}

	tipoDato& at(int pos)
	{
		if (pos >= 0 && pos < cantidadElementos)
		{
			CNodo<tipoDato> *iterador = nullptr;
			if (cantidadElementos - pos + 1 < pos)
			{
				iterador = inicio->getAnterior();
				for (int i = cantidadElementos - 1; i > pos; --i)
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
	

	void swap(CNodo<tipoDato> *nodo1, CNodo<tipoDato> *nodo2)
	{
		tipoDato copia = nodo1->getValor();
		nodo1->setValor(nodo2->getValor());
		nodo2->setValor(copia);
		if (nodo1 == nullptr || nodo2 == nullptr)
			throw "ERROR: NO EXISTE NODO SELECCIONADO!";
	}
};

#endif // !CLISTACIRCULAR_HPP
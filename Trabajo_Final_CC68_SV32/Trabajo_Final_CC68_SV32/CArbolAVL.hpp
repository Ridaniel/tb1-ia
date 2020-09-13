#ifndef __CArbolAVL__HPP__
#define __CArbolAVL__HPP__
#include"CNodo.hpp"
#include<iostream>

using namespace std;
template<class key, class T>
class CArbolAVL
{
private:
	//Es la raiz del árbol
	CNodoAVL<key, T> *raiz;
	//Indica la cantidad de elementos
	int cantidadElementos;
	//Función que sirve para ver como lo va a ordenar
	bool(*ptrfn)(key &, key &);
	void insertarNodo(CNodoAVL<key, T> *nodo, key &llave, T &elemento) {
		if (nodo->getLlave()<llave) {
			if (nodo->getSiguiente() != nullptr)
				insertarNodo(nodo->getSiguiente(), llave, elemento);
			else {
				nodo->setSiguiente(new CNodoAVL<key, T>(llave, elemento));
				nodo->getSiguiente()->setPadre(nodo);
				if (nodo->getAltura()<2)
					nodo->setAltura(2);
				equilibrar(nodo->getSiguiente());
			}
		}
		else {
			if (nodo->getAnterior() != nullptr)
				insertarNodo(nodo->getAnterior(), llave, elemento);
			else {
				nodo->setAnterior(new CNodoAVL<key, T>(llave, elemento));
				nodo->getAnterior()->setPadre(nodo);
				if (nodo->getAltura()<2)
					nodo->setAltura(2);
				equilibrar(nodo->getAnterior());
			}
		}
	}
	//Sirve para equilibrar el árbol
	void equilibrar(CNodoAVL<key, T>*nodo) {
		//Si el nodo llega a ser a nullptr o si hubo alguna rotación ya estará equilibrado
		while (nodo != nullptr) {
			//Se asigna el factor de equilibrio según la altura de los hijos
			if (nodo->getSiguiente() != nullptr) {
				nodo->setFE(nodo->getSiguiente()->getAltura());
				nodo->setAltura(nodo->getSiguiente()->getAltura() + 1);
				if (nodo->getAnterior() != nullptr) {
					nodo->setFE(nodo->getFE() - nodo->getAnterior()->getAltura());
					if (nodo->getAnterior()->getAltura() > nodo->getSiguiente()->getAltura())
						nodo->setAltura(nodo->getAnterior()->getAltura() + 1);
					else
						nodo->setAltura(nodo->getSiguiente()->getAltura() + 1);
				}
			}
			else {
				if (nodo->getAnterior() != nullptr) {
					nodo->setFE(-nodo->getAnterior()->getAltura());
					nodo->setAltura(nodo->getAnterior()->getAltura() + 1);
				}
			}
			//Se analiza si esta desequilibrado para hacer una rotaci�n
			if (nodo->getFE() == -2) {
				if (nodo->getAnterior()->getFE() == 1)
					rotacionDobleDerecha(nodo);
				else
					rotacionSimpleDerecha(nodo);
			}
			else {
				if (nodo->getFE() == 2) {
					if (nodo->getSiguiente()->getFE() == -1)
						rotacionDobleIzquierda(nodo);
					else
						rotacionSimpleIzquierda(nodo);
				}
			}
			//Se pasa a analizar el padre
			nodo = nodo->getPadre();
		}
	}
	void rotacionSimpleDerecha(CNodoAVL<key, T>*nodo) {
		//Los factores de equlibrio de los nodos que participan en la rotación se vuelven 0
		nodo->setFE(0);
		nodo->getAnterior()->setFE(0);
		//Se asigna la nueva altura del anterior(izquierda)
		if (nodo->getSiguiente() != nullptr)
			nodo->getAnterior()->setAltura(nodo->getAltura());
		//Se asigna la nueva altura del nodo
		if (nodo->getSiguiente() != nullptr)
			nodo->setAltura(nodo->getSiguiente()->getAltura() + 1);
		else
			nodo->setAltura(1);
		//Si el nodo tiene padre, la posicion donde se encuentra el nodo, por el anterior del nodo
		if (nodo->getPadre() != nullptr) {
			if (nodo->getPadre()->getSiguiente() == nodo)
				nodo->getPadre()->setSiguiente(nodo->getAnterior());
			else
				nodo->getPadre()->setAnterior(nodo->getAnterior());
			nodo->getAnterior()->setPadre(nodo->getPadre());
		}
		else {
			//En caso no tenga el anterior del nodo se vuelve la raiz
			nodo->getAnterior()->setPadre(nullptr);
			raiz = nodo->getAnterior();
		}
		//Se le asigna el nuevo padre al nodo
		nodo->setPadre(nodo->getAnterior());
		if (nodo->getAnterior()->getSiguiente() != nullptr)
			nodo->getAnterior()->getSiguiente()->setPadre(nodo);
		nodo->setAnterior(nodo->getAnterior()->getSiguiente());
		//Se le asigna el nuevo hijo a su nuevo padre del nodo
		nodo->getPadre()->setSiguiente(nodo);
	}
	void rotacionSimpleIzquierda(CNodoAVL<key, T>*nodo) {
		//cout << "RSI ->" << nodo->
		//<< " FE= " << nodo->getFE() << endl;
		nodo->setFE(0);
		nodo->getSiguiente()->setFE(0);
		/*if (nodo->getAnterior() != nullptr)
		nodo->getSiguiente()->setAltura(nodo->getAltura());*/
		if (nodo->getAnterior() != nullptr)
			nodo->setAltura(nodo->getAnterior()->getAltura() + 1);
		else
			nodo->setAltura(1);
		if (nodo->getPadre() != nullptr) {
			if (nodo->getPadre()->getSiguiente() == nodo)
				nodo->getPadre()->setSiguiente(nodo->getSiguiente());
			else
				nodo->getPadre()->setAnterior(nodo->getSiguiente());
			nodo->getSiguiente()->setPadre(nodo->getPadre());
		}
		else {
			nodo->getSiguiente()->setPadre(nullptr);
			raiz = nodo->getSiguiente();
		}
		nodo->setPadre(nodo->getSiguiente());
		if (nodo->getSiguiente()->getAnterior() != nullptr)
			nodo->getSiguiente()->getAnterior()->setPadre(nodo);
		nodo->setSiguiente(nodo->getSiguiente()->getAnterior());
		nodo->getPadre()->setAnterior(nodo);
	}
	void rotacionDobleDerecha(CNodoAVL<key, T>*nodo) {
		//	std:cout << "RDD" << endl;
		rotacionSimpleIzquierda(nodo->getAnterior());
		rotacionSimpleDerecha(nodo);

	}
	void rotacionDobleIzquierda(CNodoAVL<key, T>*nodo) {
		//	std::cout << "RDI" << endl;
		rotacionSimpleDerecha(nodo->getSiguiente());
		rotacionSimpleIzquierda(nodo);
	}

public:

	CArbolAVL(bool(*ptrfn)(key&, key &)) {
		raiz = nullptr;
		cantidadElementos = 0;
		this->ptrfn = ptrfn;
	}

	void insertar(key llave, T elemento) {
		if (cantidadElementos == 0) {
			CNodoAVL<key, T>*nuevo = new CNodoAVL<key, T>(llave, elemento);
			raiz = nuevo;
		}
		else {
			insertarNodo(raiz, llave, elemento);
		}
		cantidadElementos++;
	}
	~CArbolAVL() { delete raiz; };
	void imprimirPreOrde(CNodoAVL<key, T>*nodo, void(*ptr)(T dato)) {
		ptr(nodo->getValor());
		cout << " tiene Fe=" << nodo->getFE() << " y altura=" << nodo->getAltura() << endl;
		if (nodo->getAnterior() != nullptr)
			imprimirPreOrde(nodo->getAnterior(), ptr);
		if (nodo->getSiguiente() != nullptr)
			imprimirPreOrde(nodo->getSiguiente(), ptr);
	}
	void imprimirEntreOrde(CNodoAVL<key, T>*&nodo, void(*ptr)(T dato)) {
		if (nodo->getAnterior() != nullptr)
			imprimirPreOrde(nodo->getAnterior(), ptr);
		ptr(nodo->getValor());
		//cout << " tiene Fe=" << nodo->getFE() << " y altura=" << nodo->getAltura() << endl;
		if (nodo->getSiguiente() != nullptr)
			imprimirPreOrde(nodo->getSiguiente(), ptr);
	}
	CNodoAVL<key, T>*& getRaiz() {
		return raiz;
	}
	CNodoAVL<key, T>* buscar(key llave) {
		CNodoAVL<key, T>*temp = raiz;
		while (temp != nullptr) {
			if (temp->getLlave() < llave)
				temp = temp->getSiguiente();
			else if (temp->getLlave() > llave)
				temp = temp->getAnterior();
			else
				return temp;
		}
		return nullptr;
	}
	bool borrar(key llave) {
		CNodoAVL<key, T>*temp = buscar(llave);
		if (temp == nullptr)
			return false;
		CNodoAVL<key, T>*nuevo = temp;
		if (nuevo->getSiguiente() != nullptr) {
			nuevo = nuevo->getSiguiente();
			while (nuevo->getAnterior() != nullptr)
				nuevo = nuevo->getAnterior();
			if (nuevo->getSiguiente() != nullptr)
				nuevo->getSiguiente()->setPadre(nuevo->getPadre());
			nuevo->getPadre()->setAnterior(nuevo->getSiguiente());
			nuevo->setSiguiente(nullptr);
		}
		else {
			if (nuevo->getAnterior() != nullptr) {
				nuevo = nuevo->getAnterior();
				while (nuevo->getSiguiente() != nullptr)
					nuevo = nuevo->getSiguiente();
			}
			else {
				if (nuevo->getPadre()->getAnterior() == nuevo)
					nuevo->getPadre()->setAnterior(nullptr);
				else
					nuevo->getPadre()->setSiguiente(nullptr);
			}

		}
		temp->setValor(nuevo->getValor());
		temp->setLlave(nuevo->getLlave());
		equilibrar(nuevo->getPadre());
		delete nuevo;
		return true;
	}

};
#endif
#ifndef CNODO_HPP
#define CNODO_HPP

template<typename tipoDato>
class CNodo
{
private:
	tipoDato valor;
	CNodo<tipoDato> *siguiente;
	CNodo<tipoDato> *anterior;
public:
	CNodo()
	{
		siguiente = nullptr;
		anterior = nullptr;
	}

	CNodo(tipoDato valor)
	{
		this->valor = valor;
		siguiente = nullptr;
		anterior = nullptr;
	}

	~CNodo()
	{
	}

	tipoDato& getValor()
	{
		return valor;
	}

	void setValor(tipoDato valor)
	{
		this->valor = valor;
	}

	CNodo<tipoDato>* getAnterior()
	{
		return anterior;
	}

	CNodo<tipoDato>* getSiguiente()
	{
		return siguiente;
	}

	void setSiguiente(CNodo<tipoDato> *siguiente)
	{
		this->siguiente = siguiente;
	}

	void setAnterior(CNodo<tipoDato> *anterior)
	{
		this->anterior = anterior;
	}
};

template<class key, class tipoDato>
class CNodoAVL
{
private:
	//Factor de equilibrio
	int FE;
	//Es el mayor espacio que hay entre el nodo actual y el nodo hoja (nodo sin hijos)
	int altura;
	tipoDato valor;
	key llave;
	CNodoAVL<key, tipoDato> *siguiente;
	CNodoAVL<key, tipoDato> *anterior;
	CNodoAVL<key, tipoDato> *padre;
public:
	CNodoAVL()
	{
		siguiente = nullptr;
		anterior = nullptr;
		padre = nullptr;
		FE = 0;
		altura = 1;
	}

	CNodoAVL(key llave, tipoDato &valor)
	{
		this->llave = llave;
		this->valor = valor;
		siguiente = nullptr;
		anterior = nullptr;
		padre = nullptr;
		FE = 0;
		altura = 1;
	}

	~CNodoAVL()
	{
		delete siguiente;
		delete anterior;
	}

	key& getLlave()
	{
		return llave;
	}

	tipoDato getValor()
	{
		return valor;
	}

	CNodoAVL<key, tipoDato>* getPadre()
	{
		return padre;
	}
	int getFE()
	{
		return FE;
	}
	int getAltura()
	{
		return altura;
	}
	void setValor(tipoDato valor)
	{
		this->valor = valor;
	}

	CNodoAVL<key, tipoDato>* getAnterior()
	{
		return anterior;
	}

	CNodoAVL<key, tipoDato>* getSiguiente()
	{
		return siguiente;
	}

	void setSiguiente(CNodoAVL<key, tipoDato> *siguiente)
	{
		this->siguiente = siguiente;
	}

	void setAnterior(CNodoAVL<key, tipoDato> *anterior)
	{
		this->anterior = anterior;
	}

	void setPadre(CNodoAVL<key, tipoDato> *padre)
	{
		this->padre = padre;
	}

	void setFE(int FE)
	{
		this->FE = FE;
	}

	void setAltura(int altura)
	{
		this->altura = altura;
	}

	void setLlave(key llave)
	{
		this->llave = llave;
	}
};

#endif // !CNODO_HPP


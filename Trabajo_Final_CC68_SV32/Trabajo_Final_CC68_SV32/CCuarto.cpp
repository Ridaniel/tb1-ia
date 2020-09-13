#include "CCuarto.hpp"

CCuarto::CCuarto()
{
	this->numero = 0;
	x = 0;
	y = 0;
	fondo = new CObjeto("Imagenes/fondoCuarto.png");
	fondo->setPosition(0, 0);
	listaEnemigos = new CListaCircular<CEnemigo*>();
	listaItems = new CListaCircular<CItem*>();
	escalera = nullptr;
	teletransportador = nullptr;
	fondo->setSize(1280, 720);
}

CCuarto::CCuarto(bool crear)
{
	this->numero = 0;
	this->x = 0;
	this->y = 0;
	fondo = new CObjeto("Imagenes/fondoCuarto.png");
	fondo->setPosition(0, 0);
	listaEnemigos = new CListaCircular<CEnemigo*>();
	listaItems = new CListaCircular<CItem*>();
	srand(time(NULL));
	int cant = rand() % 5;
	for (int i = 0; i < cant; ++i)
	{
		int tipo = rand() % 2;
		switch (tipo)
		{
		case 0:
			listaItems->push_back(new CItem(static_cast<tipoItem>(tipo), static_cast<passive>(rand() % 2), 100, 5, "nombre", "Imagenes/espada.png", 80));
			break;
		case 1:
			listaItems->push_back(new CItem(static_cast<tipoItem>(tipo), static_cast<passive>(rand() % 2), 100, 5, "nombre", "Imagenes/armadura.png", 80));
			break;
		}
	}
	std::string spritesEnemigos[9];
	spritesEnemigos[0] = "Imagenes/bat.png";
	spritesEnemigos[1] = "Imagenes/bee.png";
	spritesEnemigos[2] = "Imagenes/blacksmith.png";
	spritesEnemigos[3] = "Imagenes/brute.png";
	spritesEnemigos[4] = "Imagenes/crab.png";
	spritesEnemigos[5] = "Imagenes/demon.png";
	spritesEnemigos[6] = "Imagenes/eye.png";
	spritesEnemigos[7] = "Imagenes/ghost.png";
	spritesEnemigos[8] = "Imagenes/gnoll.png";


	for (int i = 0; i < 4; ++i)
	{
		Sleep(100);
		listaEnemigos->push_back(new CEnemigo(i, spritesEnemigos[rand() % 9]));
	}
	escalera = nullptr;
	teletransportador = nullptr;
	fondo->setSize(1280, 720);
}


CCuarto::~CCuarto()
{

}
void CCuarto::crearEscalera(int tipo)
{

	if (tipo == 1)
		escalera = new CObjeto("Imagenes/escalera_abajo.png");
	else
		escalera = new CObjeto("Imagenes/escalera_arriba.png");
	escalera->setPosition(200, 200);
	escalera->setSize(70, 70);


}
bool CCuarto::existeEscalera()
{
	if (escalera == nullptr)
		return false;
	return true;
}
bool CCuarto::existeTeletransportador()
{
	return teletransportador != nullptr;
}
void CCuarto::crearTeletransportador()
{
	teletransportador = new CObjeto("Imagenes/teletransportador.png");
	teletransportador->setPosition(1020, 80);
	teletransportador->setSize(70, 100);
}
CObjeto * CCuarto::getTeletransportador()
{
	return teletransportador;
}
CObjeto * CCuarto::getEscalera()
{
	return escalera;
}
CObjeto * CCuarto::getFondo()
{
	return fondo;
}
void CCuarto::setTeletransportador(CObjeto * teletransportador)
{
	this->teletransportador = teletransportador;
}
void CCuarto::setEscalera(CObjeto * Escalera)
{
	this->escalera = new CObjeto;
	this->escalera = Escalera;
}
void CCuarto::setFondo(CObjeto * Fondo)
{
	this->fondo = Fondo;
}

void CCuarto::inicializarCuartoConAg(std::vector<int> *valAg) {

	listaItems = new CListaCircular<CItem*>();
	srand(time(NULL));
	int cant = rand() % 5;
	for (int i = 0; i < cant; ++i)
	{
		int tipo = rand() % 2;
		switch (tipo)
		{
		case 0:
			listaItems->push_back(new CItem(static_cast<tipoItem>(tipo), static_cast<passive>(rand() % 2), 100, 5, "nombre", "Imagenes/espada.png", 80));
			break;
		case 1:
			listaItems->push_back(new CItem(static_cast<tipoItem>(tipo), static_cast<passive>(rand() % 2), 100, 5, "nombre", "Imagenes/armadura.png", 80));
			break;
		}
	}
	std::string spritesEnemigos[9];
	spritesEnemigos[0] = "Imagenes/bat.png";
	spritesEnemigos[1] = "Imagenes/bee.png";
	spritesEnemigos[2] = "Imagenes/blacksmith.png";
	spritesEnemigos[3] = "Imagenes/brute.png";
	spritesEnemigos[4] = "Imagenes/crab.png";
	spritesEnemigos[5] = "Imagenes/demon.png";
	spritesEnemigos[6] = "Imagenes/eye.png";
	spritesEnemigos[7] = "Imagenes/ghost.png";
	spritesEnemigos[8] = "Imagenes/gnoll.png";
	std::vector<int> *temp=new std::vector<int>;

	std::vector<int> resultado= alg_gen(valAg);
	for (int i = 0;i < resultado.size();i++)
	{
		temp->push_back(resultado[i]);
	}
	valAg = temp;
	for (int i = 0; i < 4; ++i)
	{
		Sleep(100);
		listaEnemigos->push_back(new CEnemigo(i, spritesEnemigos[rand() % 9],valAg->at(i)));
	}

}
void CCuarto::inicializarCuarto()
{
	listaItems = new CListaCircular<CItem*>();
	srand(time(NULL));
	int cant = rand() % 5;
	for (int i = 0; i < cant; ++i)
	{
		int tipo = rand() % 2;
		switch (tipo)
		{
		case 0:
			listaItems->push_back(new CItem(static_cast<tipoItem>(tipo), static_cast<passive>(rand() % 2), 100, 5, "nombre", "Imagenes/espada.png", 80));
			break;
		case 1:
			listaItems->push_back(new CItem(static_cast<tipoItem>(tipo), static_cast<passive>(rand() % 2), 100, 5, "nombre", "Imagenes/armadura.png", 80));
			break;
		}
	}
	std::string spritesEnemigos[9];
	spritesEnemigos[0] = "Imagenes/bat.png";
	spritesEnemigos[1] = "Imagenes/bee.png";
	spritesEnemigos[2] = "Imagenes/blacksmith.png";
	spritesEnemigos[3] = "Imagenes/brute.png";
	spritesEnemigos[4] = "Imagenes/crab.png";
	spritesEnemigos[5] = "Imagenes/demon.png";
	spritesEnemigos[6] = "Imagenes/eye.png";
	spritesEnemigos[7] = "Imagenes/ghost.png";
	spritesEnemigos[8] = "Imagenes/gnoll.png";

	for (int i = 0; i < rand() % 3 + 2; ++i)
	{
		Sleep(100);
		listaEnemigos->push_back(new CEnemigo(i, spritesEnemigos[rand() % 9]));
	}
}
void CCuarto::setSize()
{
	fondo->setSize(1280, 720);
}

int& CCuarto::getNumero()
{
	return numero;
}

void CCuarto::setNumero(int numero)
{
	this->numero = numero;
}

int& CCuarto::getX()
{
	return x;
}

int& CCuarto::getY()
{
	return y;
}

CListaCircular<CEnemigo*>* CCuarto::getListaEnemigos()
{
	return listaEnemigos;
}

CListaCircular<CItem*>* CCuarto::getListaItems()
{
	return listaItems;
}

void CCuarto::setCoordenadas(int x, int y)
{
	this->x = x;
	this->y = y;
}

void CCuarto::dibujarCuarto(sf::RenderWindow *ventana)
{

	ventana->draw(*fondo->getSprite());
}

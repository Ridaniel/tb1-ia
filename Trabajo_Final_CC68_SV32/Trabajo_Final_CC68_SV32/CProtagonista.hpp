#ifndef CPROTAGONISTA_HPP
#define CPROTAGONISTA_HPP

#include "CInventario.hpp"
#include "CPersonaje.hpp"
#include "CListaCircular.hpp"

// Se crea la clase CProtagonista que tiene herencia de la clase CPersonaje
class CProtagonista : public CPersonaje
{
private:
	// Se declara sus atributos
	int vidaMaxima;
	int hambre;
	int experienciaMaxima;
	CInventario* inventario;
	CObjeto* atacarEfecto;
	char teclaPresionada;
	// Variables para el cambio de sprites durante la animacion
	int indiceXTemp;
	int indiceYTemp;

public:
	// Se crea el constructor vacio
	CProtagonista();
	// Constructor Sobrecargado
	CProtagonista(int experiencia, int vidaMaxima, int hambre, CInventario* inventario, std::string nombreSprite);
	// Se crea el destructor
	~CProtagonista();
	// Se crea los getters y setters
	int getVidaMaxima();
	int getHambre();
	CInventario*& getinventario();
	void setVidaMaxima(int vidaMaxima);
	void setHambre(int hambre);
	// Funciones de juego
	void matarEnemigo(CPersonaje enemigo);
	CObjeto* getAtacarEfecto();
	bool atacar();
	char getTeclaPresionada();
	void movimiento();
};
#endif // !CPROTAGONISTA_HPP


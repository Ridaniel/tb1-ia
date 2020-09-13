#ifndef CJUEGO_HPP
#define CJUEGO_HPP
#include <SFML/Audio.hpp>
#include "CProtagonista.hpp"
#include "CHud.h"
#include "CCuarto.hpp"
#include "CItem.hpp"
#include "CMapa.hpp"
#include "CPuerta.hpp"
#include<fstream>
#include <sstream>

class CJuego
{
private:
	CProtagonista *jugador;
	bool puntaje = 1;
	bool ataqueval;
	CHud *hud;
	CCuarto *cuarto;
	CMapa *map;
	CListaCircular<CPuerta*> *Puertas;
	sf::Music *musicafondo;
	bool musicaBool;
	std::vector<int> *valoresIniciales;
	
public:
	CJuego(sf::RenderWindow *ventana);
	~CJuego();
	// Loop principal del juego para la logica
	void update(sf::RenderWindow *ventana);
	// Loop principal del juego para el dibujo de texturas
	void dibujar(sf::RenderWindow *ventana);
	void puertas();
	void guardar();
	/*void leerPuntajes();*/
	void cargar(sf::RenderWindow *ventana);

	CProtagonista* getJugador();

};

#endif // !CJUEGO_HPP
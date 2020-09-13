#ifndef CENEMIGO__HPP
#define CENEMIGO__HPP

#include "CProtagonista.hpp"
#include "CListaCircular.hpp"
#include "Algoritmo.hpp"
enum tipoEnemigo {
	tanque,
	asesino
};

class CEnemigo :public CPersonaje {
private:
	sf::RectangleShape* campoVision;
	bool colisiona[4];
	sf::Vector2f dimImagenOriginal;

public:
	CEnemigo();
	CEnemigo(int sector, std::string nombreSprite);
	CEnemigo(int sector, std::string nombreSprite,int valAg);
	~CEnemigo();
	void movimiento(CProtagonista* jugador, CListaCircular<CEnemigo*>* enemigos, int& indice);
	sf::RectangleShape* getCampoVision();
};

#endif // !CENEMIGO_HPP
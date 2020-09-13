#include "CEnemigo.hpp"

CEnemigo::CEnemigo()
{
}

CEnemigo::CEnemigo(int sector, std::string nombreSprite) :CPersonaje(200, 10, 1, 0, sf::Vector2i(2, 2), 0, nombreSprite)
{

	/*std::vector<int> StatsEnemigo;
	
	alg_gen(StatsEnemigo);
	this->vida = StatsEnemigo[0];
	
	this->ataque = StatsEnemigo[1];
	this->defensa = StatsEnemigo[2];
	this->velocidad = sf::Vector2i(StatsEnemigo[3], StatsEnemigo[3]);
	*/
	dimImagenOriginal.x = sprite->getLocalBounds().width;
	dimImagenOriginal.y = sprite->getLocalBounds().height;
	if (nombreSprite == "Imagenes/bat.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/bee.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/blacksmith.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/brute.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/crab.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/demon.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/eye.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/ghost.png")
		setAncho(sprite->getLocalBounds().width / 2);
	else if (nombreSprite == "Imagenes/gnoll.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/goo.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/king.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/rat.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/scorpio.png")
		setAncho(sprite->getLocalBounds().width / 4);
	if (nombreSprite != "Imagenes/ghost.png")
		setAlto(sprite->getLocalBounds().height / 2);
	else
		setAlto(sprite->getLocalBounds().height);

	indice.x = 0;
	indice.y = 0;

	setSize(getAncho() * 4, getAlto() * 4);

	// Posicion de IA
	switch (sector)
	{
	case 0:
		setPosition(300, 150);
		break;
	case 1:
		setPosition(400, 450);
		break;
	case 2:
		setPosition(900, 150);
		break;
	case 3:
		setPosition(900, 450);
		break;
	}

	// Inicializar campo de vision de IA
	campoVision = new sf::RectangleShape();
	campoVision->setOutlineThickness(2.0f);
	campoVision->setOutlineColor(sf::Color::Red);
	campoVision->setFillColor(sf::Color::Transparent);
	campoVision->setPosition(*(posicion));
	campoVision->setSize(*(getSize()));
	// Posicion del campo de vision
	campoVision->setPosition(campoVision->getPosition().x - campoVision->getSize().x * 3,
		campoVision->getPosition().y - campoVision->getSize().y * 2);
	// Tamanio del campo de vision
	campoVision->setSize(sf::Vector2f(campoVision->getSize().x * 8,
		campoVision->getSize().y * 5));
	for (int i = 0; i < 4; ++i)
		colisiona[i] = false;
	contadorAnimacion = 0;
}
CEnemigo::CEnemigo(int sector, std::string nombreSprite,int valAg):CPersonaje(valAg*10, valAg, 1, valAg, sf::Vector2i(2, 2), 0, nombreSprite)
{

	/*std::vector<int> StatsEnemigo;

	alg_gen(StatsEnemigo);
	this->vida = StatsEnemigo[0];

	this->ataque = StatsEnemigo[1];
	this->defensa = StatsEnemigo[2];
	this->velocidad = sf::Vector2i(StatsEnemigo[3], StatsEnemigo[3]);
	*/
	dimImagenOriginal.x = sprite->getLocalBounds().width;
	dimImagenOriginal.y = sprite->getLocalBounds().height;
	if (nombreSprite == "Imagenes/bat.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/bee.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/blacksmith.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/brute.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/crab.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/demon.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/eye.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/ghost.png")
		setAncho(sprite->getLocalBounds().width / 2);
	else if (nombreSprite == "Imagenes/gnoll.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/goo.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/king.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/rat.png")
		setAncho(sprite->getLocalBounds().width / 4);
	else if (nombreSprite == "Imagenes/scorpio.png")
		setAncho(sprite->getLocalBounds().width / 4);
	if (nombreSprite != "Imagenes/ghost.png")
		setAlto(sprite->getLocalBounds().height / 2);
	else
		setAlto(sprite->getLocalBounds().height);

	indice.x = 0;
	indice.y = 0;

	setSize(getAncho() * 4, getAlto() * 4);

	// Posicion de IA
	switch (sector)
	{
	case 0:
		setPosition(300, 150);
		break;
	case 1:
		setPosition(400, 450);
		break;
	case 2:
		setPosition(900, 150);
		break;
	case 3:
		setPosition(900, 450);
		break;
	}

	// Inicializar campo de vision de IA
	campoVision = new sf::RectangleShape();
	campoVision->setOutlineThickness(2.0f);
	campoVision->setOutlineColor(sf::Color::Red);
	campoVision->setFillColor(sf::Color::Transparent);
	campoVision->setPosition(*(posicion));
	campoVision->setSize(*(getSize()));
	// Posicion del campo de vision
	campoVision->setPosition(campoVision->getPosition().x - campoVision->getSize().x * 3,
		campoVision->getPosition().y - campoVision->getSize().y * 2);
	// Tamanio del campo de vision
	campoVision->setSize(sf::Vector2f(campoVision->getSize().x * 8,
		campoVision->getSize().y * 5));
	for (int i = 0; i < 4; ++i)
		colisiona[i] = false;
	contadorAnimacion = 0;
}



CEnemigo::~CEnemigo()
{
	delete campoVision;
}

void CEnemigo::movimiento(CProtagonista* jugador, CListaCircular<CEnemigo*>* enemigos, int& indice)
{
	for (int i = 0; i < 4; ++i)
		colisiona[i] = false;
	for (int i = 0; i < enemigos->size(); ++i)
	{
		if (i != indice)
		{
			if (sprite->getGlobalBounds().intersects(enemigos->at(i)->getSprite()->getGlobalBounds()))
			{
				if (posicion->x <= enemigos->at(i)->getPosicion().x + enemigos->at(i)->getSize()->x &&
					posicion->x + getSize()->x >= enemigos->at(i)->getPosicion().x + enemigos->at(i)->getSize()->x)
					colisiona[izquierda] = true;
				if (posicion->x + getSize()->x >= enemigos->at(i)->getPosicion().x &&
					posicion->x <= enemigos->at(i)->getPosicion().x)
					colisiona[derecha] = true;
				if (posicion->y <= enemigos->at(i)->getPosicion().y + enemigos->at(i)->getSize()->y &&
					posicion->y + getSize()->y >= enemigos->at(i)->getPosicion().y + enemigos->at(i)->getSize()->y)
					colisiona[arriba] = true;
				if (posicion->y + getSize()->y >= enemigos->at(i)->getPosicion().y &&
					posicion->y <= enemigos->at(i)->getPosicion().y)
					colisiona[abajo] = true;
			}
		}
	}

	if (sprite->getGlobalBounds().intersects(jugador->getSprite()->getGlobalBounds()))
	{
		if (posicion->x <= jugador->getPosicion().x + jugador->getSize()->x &&
			posicion->x + getSize()->x >= jugador->getPosicion().x + jugador->getSize()->x)
			colisiona[izquierda] = true;
		if (posicion->x + getSize()->x >= jugador->getPosicion().x &&
			posicion->x <= jugador->getPosicion().x)
			colisiona[derecha] = true;
		if (posicion->y <= jugador->getPosicion().y + jugador->getSize()->y &&
			posicion->y + getSize()->y >= jugador->getPosicion().y + jugador->getSize()->y)
			colisiona[arriba] = true;
		if (posicion->y + getSize()->y >= jugador->getPosicion().y &&
			posicion->y <= jugador->getPosicion().y)
			colisiona[abajo] = true;
	}

	if (campoVision->getGlobalBounds().intersects(jugador->getSprite()->getGlobalBounds()))
	{
		++contadorAnimacion;
		if (contadorAnimacion >= 5)
			contadorAnimacion = 0;
		if (contadorAnimacion == 4)
		{
			++this->indice.x;
			moverIndice(sf::Vector2f(this->indice.x * ancho, this->indice.y * alto));
		}

		if (this->indice.x >= (dimImagenOriginal.x / ancho) - 1)
			this->indice.x = 0;

		if (jugador->getPosicion().x > posicion->x && colisiona[derecha] == false)
		{
			setPosition(posicion->x + velocidad.x, posicion->y);
			campoVision->setPosition(campoVision->getPosition().x + velocidad.x,
				campoVision->getPosition().y);
			this->indice.y = 0;
		}
		if (jugador->getPosicion().x < posicion->x && colisiona[izquierda] == false)
		{
			setPosition(posicion->x - velocidad.x, posicion->y);
			campoVision->setPosition(campoVision->getPosition().x - velocidad.x,
				campoVision->getPosition().y);
			if (nombreImagen != "Imagenes/ghost.png")
				this->indice.y = 1;
		}
		if (jugador->getPosicion().y > posicion->y && colisiona[abajo] == false)
		{
			setPosition(posicion->x, posicion->y + velocidad.y);
			campoVision->setPosition(campoVision->getPosition().x,
				campoVision->getPosition().y + velocidad.y);
		}
		if (jugador->getPosicion().y < posicion->y && colisiona[arriba] == false)
		{
			setPosition(posicion->x, posicion->y - velocidad.y);
			campoVision->setPosition(campoVision->getPosition().x,
				campoVision->getPosition().y - velocidad.y);
		}
		if (sprite->getGlobalBounds().intersects(jugador->getSprite()->getGlobalBounds()))
		{
			if (jugador->getinventario()->getItem(1)!= nullptr) {
				jugador->getinventario()->getItem(1)->setDurabilidad(jugador->getinventario()->getItem(1)->getDurabilidad() - 11);
				if (jugador->getinventario()->getItem(1)->getDurabilidad() <= 0)
				{
					jugador->getinventario()->anular(1);

				}
			}
			if (jugador->getDefensa() != 0)
				jugador->setVida(jugador->getVida() - ataque * jugador->getDefensa() / 100);
			else
					jugador->setVida(jugador->getVida() - ataque);
		}
	}
}

sf::RectangleShape* CEnemigo::getCampoVision()
{
	return campoVision;
}

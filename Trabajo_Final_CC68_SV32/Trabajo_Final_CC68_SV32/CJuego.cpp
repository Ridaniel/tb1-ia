#include "CJuego.hpp"
#include "Par.hpp"
CJuego::CJuego(sf::RenderWindow *ventana)
{
	musicafondo = new sf::Music;
	musicafondo->openFromFile("Sonidos/fondoJuego.wav");
	musicaBool = 1;
	jugador = new CProtagonista(0, 3000, 0, new CInventario(), "Imagenes/jugador.png");
	jugador->getSprite()->setPosition(250, 300);
	hud = new CHud(ventana);
	map = new CMapa(1);
	cuarto = map->PisoActual()->CuartoActual();
	map->PisoActual()->CuartoActual();
	//cargar(ventana);
	//cuarto = map->PisoActual()->CuartoActual();
	Puertas = new CListaCircular<CPuerta*>;
	puertas();
	valoresIniciales = new vector<int>;
	//map->PisoActual()->getLista()->mostrar();
	valoresIniciales->push_back(8);
	valoresIniciales->push_back(10);
	valoresIniciales->push_back(12);
	valoresIniciales->push_back(14);

}

CJuego::~CJuego()
{
	musicafondo->stop();
	delete jugador;
}

void CJuego::update(sf::RenderWindow *ventana)
{
	if (hud->getVidaIndice() <= 8)
	{
		if (jugador->getVida() % 340 == 0)
		{
			hud->getVida()->moverIndice(sf::Vector2f(0, hud->getVidaIndice()*hud->getVida()->getAlto()));
			hud->setVida(hud->getVidaIndice() + 1);
		}
	}

	if (jugador->getinventario()->getItem(0) != nullptr)
		jugador->setAtaque(20);
	if (jugador->getinventario()->getItem(1) != nullptr)
	{
		jugador->setDefensa(50);
		if (jugador->getNombreImagen() != "Imagenes/jugador_armadura.png")
		{
			jugador->setTextura("Imagenes/jugador_armadura.png");
		}
	}
	else
	{
		if (jugador->getNombreImagen() == "Imagenes/jugador_armadura.png")
		{
			jugador->setTextura("Imagenes/jugador.png");
		}

	}

	jugador->movimiento();
	for (int i = 0; i < cuarto->getListaEnemigos()->size(); i++)
	{
		cuarto->getListaEnemigos()->at(i)->movimiento(jugador, cuarto->getListaEnemigos(), i);
		if (jugador->getAtacarEfecto()->getSprite()->getGlobalBounds().intersects(cuarto->getListaEnemigos()->at(i)->getSprite()->getGlobalBounds()))
		{
			if (jugador->getinventario()->getItem(0) != nullptr)
			{
				jugador->getinventario()->getItem(0)->setDurabilidad(jugador->getinventario()->getItem(0)->getDurabilidad() - 9);
				if (jugador->getinventario()->getItem(0)->getDurabilidad() <= 0)
				{
					jugador->getinventario()->anular(0);

				}
			}
			//TODO:
			//std::cout << cuarto->getListaEnemigos()->at(i)->getVida() << '\n';
			cuarto->getListaEnemigos()->at(i)->setVida(cuarto->getListaEnemigos()->at(i)->getVida() - jugador->getAtaque()+ cuarto->getListaEnemigos()->at(i)->getDefensa());
		}
		if (cuarto->getListaEnemigos()->at(i)->getVida() <= 0)
		{
			cuarto->getListaEnemigos()->erase(i);
			hud->setPuntaje(hud->getPuntaje() + 1);
		}
	}
}

void CJuego::dibujar(sf::RenderWindow *ventana)
{

	if (musicaBool == true)
	{
		musicafondo->play();
		musicaBool = false;
		musicafondo->setLoop(1);
	}

	cuarto->dibujarCuarto(ventana);
	hud->dibujar(ventana);

	if (jugador->getVida() <= 0)

	{
		sf::Texture gameOverText;
		gameOverText.loadFromFile("Imagenes/game_over.png");
		sf::Sprite gameOverSprite;
		gameOverSprite.setTexture(gameOverText);
		gameOverSprite.setScale(0.7, 0.7);
		ventana->draw(gameOverSprite);
	/**	if (puntaje == 1)
		{
			std::ifstream archivo("puntajes.txt");
			std::string puntos, temp;
			std::string nombres[3];
			std::string puntajes[3];
			int contador = 0;

			while (std::getline(archivo, puntos))
			{
				std::stringstream buffer(puntos);
				std::getline(buffer, temp, ',');
				nombres[contador] = temp;
				std::getline(buffer, temp, ',');
				puntajes[contador] = temp;
				contador++;
			}
			archivo.close();
			if (hud->getPuntaje() > std::stoi(puntajes[2]))
			{


				
				sf::RectangleShape rectangulo(sf::Vector2f(600, 250));
				rectangulo.setFillColor(sf::Color::Black);
				std::string nombre;
				rectangulo.setPosition(400, 300);
				sf::Font fuente;
				sf::String codigo;
				sf::Text texcodigo;
				fuente.loadFromFile("Fonts/arial.ttf");
				codigo += "INGRESE NOMBRE \n ";
				texcodigo.setString(codigo);
				texcodigo.setFont(fuente);
				texcodigo.setCharacterSize(20);

				texcodigo.setPosition(450, 320);

				sf::Event evento;
				while (1) {
					while (ventana->pollEvent(evento))
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && codigo.getSize() > 0) {
							if (codigo.getSize() > 17)
							{
								codigo.erase(codigo.getSize() - 1);
								nombre.erase(nombre.size() - 1);
							}

						}
						if (evento.type == sf::Event::TextEntered) {
							if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) {
							
									nombre += evento.text.unicode;
									codigo += evento.text.unicode;
								
							}

						}
						

					}
					texcodigo.setString(codigo);
					if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
					{
						break;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
						break;

					}
					texcodigo.setFillColor(sf::Color::White);
					ventana->draw(rectangulo);
					ventana->draw(texcodigo);
					ventana->display();

				}
				if (hud->getPuntaje() > std::stoi(puntajes[0]))
				{
					puntajes[2] = puntajes[1];
					nombres[2] = nombres[1];
					puntajes[1] = puntajes[0];
					nombres[1] = nombres[0];
					nombres[0] = nombre;
					puntajes[0] = std::to_string(hud->getPuntaje());

				}
				else
				{
					if (hud->getPuntaje() > std::stoi(puntajes[1])) {
						puntajes[2] = puntajes[1];
						nombres[2] = nombres[1];
						nombres[1] = nombre;
						puntajes[1] = std::to_string(hud->getPuntaje());
					}
					else
					{
						nombres[2] = nombre;
						puntajes[2] = std::to_string(hud->getPuntaje());
					}
				}
				std::ofstream leer("puntajes.txt");
					leer << nombres[0] << "," << puntajes[0] <<std::endl << nombres[1] << "," << puntajes[1] << "\n" << nombres[2] << "," << puntajes[2] << "\n ";
				
				leer.close();
			}

			puntaje = 0;
		}**/


	}
	else
	{
		cuarto->dibujarCuarto(ventana);
		hud->dibujar(ventana);
		if (cuarto->existeEscalera())
		{
			ventana->draw(*(cuarto->getEscalera()->getSprite()));
			if (jugador->getSprite()->getGlobalBounds().intersects(cuarto->getEscalera()->getSprite()->getGlobalBounds()))
			{
				if (map->cambiarPiso(cuarto, 1, ventana,valoresIniciales))
				{
					jugador->setPosition(jugador->getPosicion().x + 20, jugador->getPosicion().y);
					hud->setPiso(map->PisoActual()->getNumero());
					cuarto = map->PisoActual()->CuartoActual();
					puertas();
				}
			}
		}

		if (cuarto->existeTeletransportador())
		{
			ventana->draw(*(cuarto->getTeletransportador()->getSprite()));
			if (jugador->getSprite()->getGlobalBounds().intersects(cuarto->getTeletransportador()->getSprite()->getGlobalBounds()))
			{
				if (map->cambiarPiso(cuarto, 2, ventana,valoresIniciales))
				{
					jugador->setPosition(500, 300);
					hud->setPiso(map->PisoActual()->getNumero());
					cuarto = map->PisoActual()->CuartoActual();
					puertas();
				}
			}
		}

		for (int i = 0; i < Puertas->size(); i++)
			ventana->draw(*Puertas->at(i)->getSprite());

		for (int i = 0; i < cuarto->getListaItems()->size(); ++i)
		{
			ventana->draw(*(cuarto->getListaItems()->at(i)->getSprite()));
			if (jugador->getSprite()->getGlobalBounds().intersects(cuarto->getListaItems()->at(i)->getSprite()->getGlobalBounds()))
			{
				if (jugador->getinventario()->agregarItem(cuarto->getListaItems()->at(i)))
					cuarto->getListaItems()->erase(i);
			}
		}
		for (int i = 0; i < cuarto->getListaEnemigos()->size(); ++i)
		{
			ventana->draw(*(cuarto->getListaEnemigos()->at(i)->getSprite()));
		}

		for (int i = 0; i < Puertas->size(); i++)
		{
			if (jugador->getSprite()->getGlobalBounds().intersects(Puertas->at(i)->getSprite()->getGlobalBounds()))
			{
				int temp;
				map->PisoActual()->setActual(Puertas->at(i)->getCuarto());
				temp = Puertas->at(i)->getCriterio();
				map->PisoActual()->CuartoActual()->setSize();
				cuarto = map->PisoActual()->CuartoActual();
				cuarto->setSize();
				puertas();
				if (temp == 1)
					jugador->setPosition(1280 / 2, 529);
				if (temp == 2)
					jugador->setPosition(230, 314);
				if (temp == 3)
					jugador->setPosition(1280 / 2 - 90, 125);
				if (temp == 4)
					jugador->setPosition(1033, 314);
			}
		}
		for (int i = 0; i < 2; ++i)
		{
			if (jugador->getinventario()->getItem(i) != nullptr)
				ventana->draw(*(jugador->getinventario()->getItem(i)->getSprite()));
		}
		ventana->draw(*(jugador->getSprite()));
		if (jugador->atacar())
			ventana->draw(*(jugador->getAtacarEfecto()->getSprite()));
	}
}


void CJuego::puertas()
{
	if (Puertas != nullptr)
		delete Puertas;
	Puertas = new CListaCircular<CPuerta*>;
	for (int i = 0; i < map->PisoActual()->getLista()->getlista()[cuarto->getNumero()].size(); i++)
		Puertas->push_back(new CPuerta(map->PisoActual()->getLista()->getlista()[cuarto->getNumero()].at(i).prime, map->PisoActual()->getLista()->getlista()[cuarto->getNumero()].at(i).secun));
}

void CJuego::guardar()
{
	std::ofstream docNor("GuardarNorm.txt");
	std::ofstream docBin("GuardarBin.bin", std::ios::binary);
	docNor << map->getCant() << std::endl;
	map->getPisos()->iniciarIterator();
	for (int i = 0; i < map->getPisos()->size(); ++i)
	{

		if (map->getPisos()->iterator->getValor()->getLista() != nullptr) {
			docNor << "1" << std::endl;

			docNor << map->getPisos()->iterator->getValor()->getLista()->getTamanio() << std::endl;
			docNor << map->getPisos()->iterator->getValor()->getCuartoConBeacon() << std::endl;
			for (int j = 0; j < map->getPisos()->iterator->getValor()->getLista()->getTamanio(); ++j)
			{
				/*docBin.write(reinterpret_cast<char*>(&map->getPisos()->at(i)->getLista()->getCuartos()[j].getNumero()), sizeof(int));
				docBin.write(reinterpret_cast<char*>(&map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getX()), sizeof(int));
				docBin.write(reinterpret_cast<char*>(&map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getY()), sizeof(int));*/
				if (map->getPisos()->at(i)->getLista()->getCuartos()[j].getTeletransportador() != nullptr) {

					/*docBin.write(reinterpret_cast<char*>(&*map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getTeletransportador()), sizeof(CObjeto));*/
					docNor << "1" << std::endl;
					docNor << map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getTeletransportador()->getNombreImagen() << std::endl;
					docNor << map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getTeletransportador()->getPosicion().x << std::endl;
					docNor << map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getTeletransportador()->getPosicion().y << std::endl;
					/*docBin.write(reinterpret_cast<char*>(map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getTeletransportador()->getIndiceX()));*/
				}
				else
					docNor << "0" << std::endl;
				if (map->getPisos()->at(i)->getLista()->getCuartos()[j].getEscalera() != nullptr) {

					docBin.write(reinterpret_cast<char*>(&*map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getEscalera()), sizeof(CObjeto));
					docNor << "1" << std::endl;
					docNor << map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getEscalera()->getNombreImagen() << std::endl;
					docNor << map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getEscalera()->getPosicion().x << std::endl;
					docNor << map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getEscalera()->getPosicion().y << std::endl;
				}
				else
					docNor << "0" << std::endl;
				docNor << map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getListaEnemigos()->size() << std::endl;
				for (int k = 0; k < map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getListaEnemigos()->size(); k++)
				{
					docBin.write(reinterpret_cast<char*>(&*map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getListaEnemigos()->at(k)), sizeof(CEnemigo));
					docNor << map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getListaEnemigos()->at(k)->getNombreImagen() << std::endl;
					docNor << map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getListaEnemigos()->at(k)->getPosicion().x << std::endl;
					docNor << map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getListaEnemigos()->at(k)->getPosicion().y << std::endl;
				}
				docNor << map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getListaItems()->size() << std::endl;
				for (int k = 0; k < map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getListaItems()->size(); k++)
				{
					docBin.write(reinterpret_cast<char*>(&*map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getListaItems()->at(k)), sizeof(CItem));
					docNor << map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getListaItems()->at(k)->getNombreImagen() << std::endl;
					docNor << map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getListaItems()->at(k)->getPosicion().x << std::endl;
					docNor << map->getPisos()->iterator->getValor()->getLista()->getCuartos()[j].getListaItems()->at(k)->getPosicion().y << std::endl;
				}
				docNor << map->getPisos()->iterator->getValor()->getLista()->getlista()[j].size() << std::endl;
				for (int k = 0; k < map->getPisos()->iterator->getValor()->getLista()->getlista()[j].size(); k++)
				{
					docBin.write(reinterpret_cast<char*>(&map->getPisos()->iterator->getValor()->getLista()->getlista()[j].at(k).prime), sizeof(int));
					docBin.write(reinterpret_cast<char*>(&*map->getPisos()->iterator->getValor()->getLista()->getlista()[j].at(k).secun), sizeof(CCuarto));
				}
			}
			docBin.write(reinterpret_cast<char*>(map->getPisos()->iterator->getValor()->CuartoActual()), sizeof(CCuarto));
		}
		else
			docNor << "0" << std::endl;
		//docBin.write(reinterpret_cast<char*>(&map->getPisos()->iterator->getValor()->getNumero()), sizeof(int));
		map->getPisos()->moverIterator();
	}
	//docBin.write(reinterpret_cast<char*>(&map->getCant()), sizeof(int));
	docBin.write(reinterpret_cast<char*>(map->PisoActual()), sizeof(CBeacon));
	//docBin.write(reinterpret_cast<char*>(&hud), sizeof(CHud));
	if (jugador->getinventario()->getItem(0) != nullptr) {
		docBin.write(reinterpret_cast<char*>(&*jugador->getinventario()->getItem(0)), sizeof(CItem));
		docNor << "1" << std::endl;
	}
	else
		docNor << "0" << std::endl;
	if (jugador->getinventario()->getItem(1) != nullptr) {
		docBin.write(reinterpret_cast<char*>(&*jugador->getinventario()->getItem(1)), sizeof(CItem));
		docNor << "1" << std::endl;
	}
	else
		docNor << "0" << std::endl;
	//docBin.write(reinterpret_cast<char*>(&jugador), sizeof(CProtagonista));
	docBin.close();
	docNor.close();

}

void CJuego::cargar(sf::RenderWindow *ventana)
{

	std::ifstream docNor("GuardarNorm.txt");
	std::ifstream docBin("GuardarBin.bin", std::ios::binary);
	std::string temp;
	int cantPisos;
	int cantCuartos;
	int cantEnemigos;
	int cantItems;
	int cantConexiones;
	int tempN;
	getline(docNor, temp);
	cantPisos = std::stoi(temp);
	for (int i = 0; i < cantPisos; i++)
	{
		getline(docNor, temp);
		if (temp == "1") {
			getline(docNor, temp);
			cantCuartos = std::stoi(temp);
			getline(docNor, temp);
			int beacon = stoi(temp);
			for (int j = 0; j < cantCuartos; ++j)
			{
				getline(docNor, temp);
				if (temp == "1")
				{
					getline(docNor, temp);
					std::string nombreTeletransportador = temp;
					getline(docNor, temp);
					int posx = stoi(temp);
					getline(docNor, temp);
					int posy = stoi(temp);
					getline(docNor, temp);
					int alto = stoi(temp);
					getline(docNor, temp);
					int ancho = stoi(temp);

				}
				else
					getline(docNor, temp);
				getline(docNor, temp);
				cantEnemigos = std::stoi(temp);


			}
		}
	}

}

CProtagonista* CJuego::getJugador()
{
	return jugador;
}


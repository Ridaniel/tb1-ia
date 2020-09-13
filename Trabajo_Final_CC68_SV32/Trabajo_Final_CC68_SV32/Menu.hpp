#ifndef MENU_HPP
#define MENU_HPP


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "CTextoCambiante.h"
#include <ctime>
#include <fstream>
#include <sstream>

class Menu
{
private:
	//creando textures,sprite y window

	sf::SoundBuffer buff;
	sf::Sound sound;
	int contador = 1000;
	sf::Music *music;
	sf::Time *time;
	sf::Font fuente;
	CObjeto *background;
	CObjeto *Nombre;
	CTextoCambiante *Start;
	CTextoCambiante *HighScores;
	CTextoCambiante *LoadGame;
	CTextoCambiante *NewGame;
	CObjeto *Atras;
	sf::Text *puntajes;
	sf::Text *puntajespuntos;
	CObjeto*metal;
	sf::Clock *tiempo;
	std::string puntajetxt;
	bool startb;
	bool highscoresb;
	bool principal;
	bool juegonb;
	bool juegolb;
	int contadorCambio;
	bool estab;
	float backgroundx;
	int mov;

public:
	Menu(sf::RenderWindow *uiwindow, sf::VideoMode desktop)
	{
		contador = 0;
		juegolb = 0;
		juegonb = 0;
		std::ifstream archivo;
		archivo.open("puntajes.txt");
		archivo.close();
		startb = 0;
		highscoresb = 0;
		principal = 1;
		background = new CObjeto("Imagenes/imagenesUi/background1.jpg");
		Start = new CTextoCambiante("Imagenes/imagenesUi/startsinhover.png");
		HighScores = new CTextoCambiante("Imagenes/imagenesUi/highscoresconhover.png");
		NewGame = new CTextoCambiante("Imagenes/imagenesUi/newgamesinhover.png");
		LoadGame = new CTextoCambiante("Imagenes/imagenesUi/loadgamesinhover.png");
		Nombre = new CObjeto("Imagenes/imagenesUi/nombreconhover.png");
		Atras = new CObjeto("Imagenes/imagenesUi/atras.png");
		metal = new CObjeto("Imagenes/imagenesUi/bb.png");
		tiempo = new sf::Clock;
		time = new sf::Time;
		music = new sf::Music;
		puntajes = new sf::Text;
		puntajespuntos = new sf::Text;
		music->openFromFile("Sonidos/cancioninicial.wav");
		music->play();
		fuente.loadFromFile("Fonts/fuente1.ttf");
		puntajes->setFont(fuente);
		puntajespuntos->setFont(fuente);
		music->setLoop(1);
		contadorCambio = 0;
		estab = 0;
		backgroundx = 0;
		mov = 1;
		background->setPosition(0, 0);
		Nombre->setSize(380, 220);
		Nombre->setPosition(uiwindow->getSize().x / 2 - 180, uiwindow->getSize().y / 70-25);
		Start->setSize(160, 110);
		Start->setPosition(uiwindow->getSize().x / 2 - 160, uiwindow->getSize().y / 2 - 150);
		HighScores->setPosition(uiwindow->getSize().x / 2 - 160, uiwindow->getSize().y / 2 - 40);
		HighScores->setSize(220, 150);
		background->setAncho(900);
		background->setAlto(700);
		background->setSize(desktop.width, desktop.height);
		puntajes->setPosition(uiwindow->getSize().x / 2 - 160, uiwindow->getSize().y / 2 - 150);
		puntajespuntos->setPosition(uiwindow->getSize().x / 2 + 50, uiwindow->getSize().y / 2 - 150);
		Atras->setSize(160, 290);
		Atras->setPosition(uiwindow->getSize().x - 250, uiwindow->getSize().y - 240);
		Atras->getSprite()->setColor(sf::Color::Yellow);
		NewGame->setSize(190, 150);
		NewGame->setPosition(uiwindow->getSize().x / 2 - 150, uiwindow->getSize().y / 2 - 150);
		LoadGame->setSize(190, 150);
		LoadGame->setPosition(uiwindow->getSize().x / 2 - 150, uiwindow->getSize().y / 2 - 40);
		this->puntajes->setFillColor(sf::Color::Yellow);
		this->puntajespuntos->setFillColor(sf::Color::Yellow);
		buff.loadFromFile("Sonidos/atras.wav");
		sound.setBuffer(buff);
	}

	~Menu()
	{
		music->stop();
		delete music;
		delete time;
		delete background;
		delete Start;
		delete HighScores;
		delete metal;
		delete tiempo;
		delete LoadGame;
		delete NewGame;
		delete Atras;
		delete puntajes;
		delete puntajespuntos;
	}

	void backgroudnmov(sf::RenderWindow *uiwindow, sf::VideoMode *desktop)
	{
		backgroundx += 1 * mov;
		background->setIndiceX(backgroundx);
		*time = tiempo->getElapsedTime();
		if (background->getSize()->x + background->getIndiceX() >= 1024)
			mov = -1;
		if (backgroundx <= 0)
			mov = 1;
		long long int val = time->asSeconds();
		if (val == 15)
		{
			background->setTextura("Imagenes/imagenesUi/background1.jpg");
			Atras->getSprite()->setColor(sf::Color::Yellow);
			this->puntajes->setFillColor(sf::Color::Yellow);
			this->puntajespuntos->setFillColor(sf::Color::Yellow);
		}
		if (val == 25)
		{
			background->setTextura("Imagenes/imagenesUi/background2.png");
			Atras->getSprite()->setColor(sf::Color::Blue);
			puntajes->setFillColor(sf::Color::Blue);
			puntajespuntos->setFillColor(sf::Color::Blue);
		}
		if (val == 35)
		{
			tiempo->restart();
			background->setTextura("Imagenes/imagenesUi/background3.png");
			puntajes->setFillColor(sf::Color::Cyan);
			puntajespuntos->setFillColor(sf::Color::Cyan);
			Atras->getSprite()->setColor(sf::Color::Cyan);
		}
	}

	void click(sf::Vector2f *posicionMouse)
	{

		if (startb == 0 && principal == 1)
			if (Start->getSprite()->getGlobalBounds().contains(*posicionMouse))
			{
				contador = 0;
				startb = 1;
				principal = 0;
				highscoresb = 0;
			}
		if (highscoresb == 0 && principal == 1)
			if (HighScores->getSprite()->getGlobalBounds().contains(*posicionMouse))
			{
				contador = 0;
				highscoresb = 1;
				principal = 0;
				startb = 0;
			}
		if (Atras->getSprite()->getGlobalBounds().contains(*posicionMouse) && principal == 0)
		{

			sound.play();
			if (highscoresb == 1)
			{
				highscoresb = 0;
				startb = 0;
				principal = 1;
			}
			if (startb == 1)
			{
				highscoresb = 0;
				startb = 0;
				principal = 1;
			}
		}

		if (LoadGame->getSprite()->getGlobalBounds().contains(*posicionMouse) && principal == 0 && contador >1)
		{
			music->stop();
			highscoresb = 0;
			juegolb = 1;
			contador = 0;
			juegonb = 0;
			startb = 0;


		}
		if (juegolb == 0)
			if (NewGame->getSprite()->getGlobalBounds().contains(*posicionMouse) && principal == 0 && contador >1)
			{
				music->stop();
				juegonb = 1;
				contador = 0;
				startb = 0;
				highscoresb = 0;
				juegolb = 0;

			}

	}
	int nuevoLoad()
	{
		if (juegolb == 1)return 2;
		if (juegonb == 1)return 1;
		return 0;

	}
	void leerPuntajes() {
		std::ifstream archivos("puntajes.txt");
		std::string puntos, temp;
		std::string nombres[100];
		std::string puntajes[100];
		int contador = 0;

		while (std::getline(archivos, puntos))
		{
			std::stringstream buffer(puntos);
			std::getline(buffer, temp, ',');
			nombres[contador] = temp;
			std::getline(buffer, temp, ',');
			puntajes[contador] = temp;
			contador++;
		}
		puntajetxt = "";
		for (int i = 0; i < 100; i++)
		{
			puntajetxt += nombres[i];
			puntajetxt += '\n';
		}
		this->puntajes->setString(puntajetxt);
		puntajetxt = "";
		for (int i = 0; i < 100; i++)
		{
			puntajetxt += puntajes[i];
			puntajetxt += '\n';

		}
		this->puntajespuntos->setString(puntajetxt);
		this->puntajes->setCharacterSize(20);
		this->puntajespuntos->setCharacterSize(20);
	}
	void dibujarMenu(sf::RenderWindow *uiwindow, sf::VideoMode *desktop, sf::Vector2f *posicionMouse)
	{
		if (juegolb == 0 && juegonb == 0) {
			contador++;

			backgroudnmov(uiwindow, desktop);
			uiwindow->draw(*background->getSprite());
			if (principal == 1)
			{
				startb = 0;
				highscoresb = 0;
				Start->dibujar(*posicionMouse);
				HighScores->dibujar(*posicionMouse);
				Start->setPosition(Start->getPosicion().x, Start->getPosicion().y);
				uiwindow->draw(*Start->getSprite());
				uiwindow->draw(*HighScores->getSprite());

			}
			if (startb == 1)
			{
				NewGame->dibujar(*posicionMouse);
				LoadGame->dibujar(*posicionMouse);
				uiwindow->draw(*NewGame->getSprite());
				uiwindow->draw(*LoadGame->getSprite());
				uiwindow->draw(*Atras->getSprite());


			}
			if (highscoresb == 1)
			{
				contador = 0;
				leerPuntajes();
				uiwindow->draw(*puntajes);
				uiwindow->draw(*puntajespuntos);
				startb = 0;
				principal = 0;
				uiwindow->draw(*Atras->getSprite());
				uiwindow->draw(*Atras->getSprite());
			}
		}
		uiwindow->draw(*Nombre->getSprite());
	}
};

#endif // !MENU_HPP
#include "CControlador.hpp"
#include "iostream"
CControlador::CControlador()
{
	desktop = new sf::VideoMode;
	*desktop = sf::VideoMode::getDesktopMode();
	view = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_SIZE, VIEW_SIZE));
	uiwindow = new sf::RenderWindow(sf::VideoMode(1280, 720, desktop->bitsPerPixel), "Dungeon Nightmare", sf::Style::Titlebar | sf::Style::Close);
	uiwindow->setPosition(sf::Vector2i(uiwindow->getPosition().x, 0));
	posicionMouse = new sf::Vector2f;
	menu = new Menu(uiwindow, *desktop);
	bolMenu = true;
	uiwindow->setFramerateLimit(60);
	breakb = 0;
	juego = new CJuego(uiwindow);
	//esqueleto=new CObjeto()
	//principal = new CPrincipal(uiwindow, desktop, posicionMouse);
}

void CControlador::dibujar()
{
	if (bolMenu == true)
		dibujarMenu();
	else
	{
		juego->update(uiwindow);
		juego->dibujar(uiwindow);
	}
}

void CControlador::dibujarMenu()
{
	if (bolMenu == true)
		menu->dibujarMenu(uiwindow, desktop, posicionMouse);
	if (bolMenu == true)
		if (menu->nuevoLoad() == 1)
		{	//juego nuevo
			delete menu;
			std::cout << "Nuevo" << std::endl;
			bolMenu = false;

		}
	if (bolMenu == true)
		if (menu->nuevoLoad() == 2)
		{	//cargar juego guardado
			delete menu;
			std::cout << "Cargado" << std::endl;

			bolMenu = false;
		}
}

void CControlador::Start()
{
	while (uiwindow->isOpen())
	{
		sf::Event event;
		if (pause == 0)
			uiwindow->clear(sf::Color::Black);
		while (uiwindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{

				//////////////if (juego != nullptr)
				///////////////*	juego->guardar();*/

				if (bolMenu == true)
					delete menu;
				uiwindow->close();
				breakb = 1;
				break;

			}
			if (event.type == sf::Event::MouseMoved)
				*posicionMouse = uiwindow->mapPixelToCoords(sf::Mouse::getPosition(*uiwindow));
			if (event.type == sf::Event::Resized)
				ReziseView();
			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
					onClick();
			}
			
		}



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{

			pause == 1;
		}
		if (breakb == 1)break;
		if (pause == 0)
		{
			dibujar();
		}
		uiwindow->display();

	}
}

void CControlador::ReziseView()
{
	aspectratio = float(uiwindow->getSize().x / float(uiwindow->getSize().y));
	view->setSize(VIEW_SIZE*aspectratio, VIEW_SIZE);
}

void CControlador::onClick()
{
	if (bolMenu == true)
		menu->click(posicionMouse);
}

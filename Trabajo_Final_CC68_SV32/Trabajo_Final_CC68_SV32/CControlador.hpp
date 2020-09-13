#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP

#include "Menu.hpp"
#include "CJuego.hpp"

const float VIEW_SIZE = 1000.0f;

class CControlador
{
protected:
	bool pause = 0;
	sf::RenderWindow *uiwindow;
	sf::Vector2f *posicionMouse;
	sf::View *view;
	sf::VideoMode *desktop;
	CJuego *juego;
	bool bolMenu;
	Menu*menu;
	bool breakb;
	float aspectratio;

public:
	CControlador();
	void dibujar();
	void dibujarMenu();
	void Start();
	void ReziseView();
	void onClick();
};
#endif // !CONTROLADOR_HPP
#include "CPrincipal.h"

void CPrincipal::dibujarJuegos()
{

}

void CPrincipal::dibujarMenu()
{
	menu->dibujarMenu(window, desktop, posicionMouse);
}

void CPrincipal::dibujar()
{
	dibujarMenu();
}

CPrincipal::CPrincipal(sf::RenderWindow *window, sf::VideoMode *desktop, sf::Vector2f *posicionMouse)
{
	menuDisplay = 1;
	juegoDisplay= 0;
	this->window = window;
	this->desktop = desktop;
	this->posicionMouse = posicionMouse;
	menu = new Menu(window, *desktop);
}

CPrincipal::~CPrincipal()
{
}

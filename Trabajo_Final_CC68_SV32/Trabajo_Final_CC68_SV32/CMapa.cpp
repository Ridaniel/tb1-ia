#include "CMapa.hpp"

CMapa::CMapa()
{
	auto criterio = [](int &elemento1, int &elemento2) {
		return elemento1 < elemento2;
	};
	mapa = new CArbolAVL<int, CNodo<CBeacon*>*>(criterio);
	pisos = new CListaDoble<CBeacon*>;
	cant = 0;
	crearPisoSiguiente();
}

CMapa::CMapa(int cantidad)
{
	auto criterio = [](int &elemento1, int &elemento2) {
		return elemento1 < elemento2;
	};
	mapa = new CArbolAVL<int, CNodo<CBeacon*>*>(criterio);
	pisos = new CListaDoble<CBeacon*>;
	cant = 0;
	generarpisos(cantidad);
	pisos->iniciarIterator();
	actual = pisos->iterator->getValor();
}


CMapa::~CMapa()
{
	delete mapa;
	delete pisos;
	delete actual;
}

void CMapa::crearPisoSiguiente()
{


	CBeacon* ptr = new CBeacon(true);
	ptr->setNumero(++cant);
	pisos->push_back(ptr);
	if (pisos->iterator == nullptr)
		pisos->iniciarIterator();
	else
		pisos->moverIterator();
	mapa->insertar(cant, pisos->iterator);
	actual = ptr;


}

void CMapa::crearPisoSiguiente(std::vector<int> *valAg)
{
	CBeacon* ptr =new CBeacon(true,valAg);
	ptr->setNumero(++cant);
	pisos->push_back(ptr);
	if (pisos->iterator == nullptr)
		pisos->iniciarIterator();
	else
		pisos->moverIterator();
	mapa->insertar(cant, pisos->iterator);
	actual = ptr;


}

void CMapa::teletransportarse(int numeroPiso)
{

}

CBeacon *& CMapa::PisoActual()
{
	return actual;
}

bool CMapa::cambiarPiso(CCuarto *& cuarto, int criterio, sf::RenderWindow *ventana,vector<int> *valAg)//criterio 1 para escalera ,criterio 2 para teletransportador
{
	if (criterio == 1)
		if (cuarto->getEscalera()->getNombreImagen() == "Imagenes/escalera_abajo.png") {
			if (actual->getNumero() == cant)
				crearPisoSiguiente(valAg);
			else {
				pisos->moverIterator();
				pisos->iterator->getValor()->inicialiar();

				actual = pisos->iterator->getValor();
			}
		}
		else {
			if (actual->getNumero() > 1) {
				pisos->moverIterator(-1);
				actual = pisos->iterator->getValor();
			}
			else return false;

		}
	else
	{
		sf::RectangleShape rectangulo(sf::Vector2f(600, 250));
		rectangulo.setFillColor(sf::Color::Black);
		std::string piso;
		rectangulo.setPosition(400, 300);
		sf::Font fuente;
		sf::String codigo;
		sf::Text texcodigo;
		fuente.loadFromFile("Fonts/arial.ttf");
		codigo += "INGRESE PISO \n ";
		texcodigo.setString(codigo);
		texcodigo.setFont(fuente);
		texcodigo.setCharacterSize(20);

		texcodigo.setPosition(450, 320);

		sf::Event evento;
		while (1) {
			while (ventana->pollEvent(evento))
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && codigo.getSize() > 0) {
					if (codigo.getSize() > 15)
					{
						codigo.erase(codigo.getSize() - 1);
						piso.erase(piso.size() - 1);
					}

				}
				if (evento.type == sf::Event::TextEntered) {
					if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) {
						if (evento.text.unicode >= '0' && evento.text.unicode <= '9') {
							piso += evento.text.unicode;
							codigo += evento.text.unicode;
						}
					}

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
					if (piso.size() > 0)
					{
						auto it = mapa->buscar(std::stoi(piso))->getValor();
						if (it->getValor()->getLista() != nullptr)
						{
							it->getValor()->setActual(&it->getValor()->getLista()->getCuartos()[it->getValor()->getCuartoConBeacon()]);
							actual =it->getValor();
							pisos->iterator = it;
							return 1;
						}
						else
						{
							codigo += "\n Piso no Disponible";
							return 0;
						}
					}

				}

			}
			std::cout << piso << std::endl;
			texcodigo.setString(codigo);
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
			{
				break;
			}
			texcodigo.setFillColor(sf::Color::White);
			ventana->draw(rectangulo);
			ventana->draw(texcodigo);
			ventana->display();
		}
	}
	return true;
}

void CMapa::generarpisos(int i)
{
	while (i-- > 0) {
		CBeacon* ptr;
		if (pisos->size() == 0) 
			ptr = new CBeacon(true);
		else
			ptr = new CBeacon(false);
		ptr->setNumero(++cant); 
		//std::cout << cant << std::endl;
		pisos->push_back(ptr);
		if (pisos->iterator == nullptr)
			pisos->iniciarIterator();
		else
			pisos->moverIterator();
		mapa->insertar(cant, pisos->iterator);
	}
}

void CMapa::setActual(CBeacon * actual)
{
	this->actual = actual;
}

int &CMapa::getCant()
{
	return cant;
}

CListaDoble<CBeacon*>* CMapa::getPisos()
{
	return pisos;
}

#include <ctime>
#include <iostream>
#include <cstdlib>
#include "CControlador.hpp"
int main() {
	srand(time(NULL));
	CControlador *controlador = new CControlador();
	controlador->Start();
}

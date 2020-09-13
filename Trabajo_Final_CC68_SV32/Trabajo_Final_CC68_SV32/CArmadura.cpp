#include "CArmadura.hpp"

CArmadura::CArmadura(int defensa )
{
	this->defensa = defensa;
}


CArmadura::~CArmadura()
{
}

int CArmadura::getDefensa()
{
	return defensa;
}

void CArmadura::setDefensa(int defensa)
{
	this->defensa = defensa;
}

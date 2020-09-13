#ifndef CARMA_HPP
#define CARMA_HPP

#include "CItem.hpp"

class CArma :public CItem
{
private:
	int ataque;
	int durabilidad;

public:
	CArma();
	~CArma();
	int getAtaque(int ataque);
	void setAtaque(int ataque);
};

#endif // !CARMA_HPP




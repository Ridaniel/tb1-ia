#ifndef CARMADURA_HPP
#define CARMADURA_HPP

#include "CItem.hpp"

class CArmadura :public CItem
{
private:
	int defensa;

public:
	CArmadura(int defensa = 0);
	~CArmadura();
	int getDefensa();
	void setDefensa(int defensa);
};

#endif // !CARMADURA_HPP



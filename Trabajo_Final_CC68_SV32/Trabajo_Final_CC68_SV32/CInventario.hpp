#ifndef __CINVENTARIO__HPP__
#define __CINVENTARIO__CPP__
#include "CItem.hpp"
class CInventario
{
private:
	CItem **inventario;
public:

	CInventario();
	~CInventario();
	bool agregarItem(CItem* item);
	CItem* getItem(int pos);
	void anular(int pos);
};

#endif // !__CINVENTARIO__HPP__




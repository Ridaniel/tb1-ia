#include "CInventario.hpp"

CInventario::CInventario()
{
	inventario = new CItem*[2];
	inventario[0] = nullptr;
	inventario[1] = nullptr;
}


CInventario::~CInventario()
{
}

CItem * CInventario::getItem(int pos)
{
	if (pos<2 && pos>-1)
		return inventario[pos];
	else
		return nullptr;
}

void CInventario::anular(int pos)
{
	inventario[pos] = nullptr;
}

bool CInventario::agregarItem(CItem* item)
{
	if (item->getTipo() == tipoItem(0)) {
		if (inventario[0] == nullptr) {
			inventario[0] = item;
			item->setPosition(1060, 10);
			return true;
		}
		else
			return false;
	}
	else {
		if (inventario[1] == nullptr) {
			inventario[1] = item;
			item->setPosition(1118, 10);
			return true;
		}
		else
			return false;
	}
	return false;
}


#pragma once
#include <string>
#include "ArbolAVL.h"

using namespace std;

class Gestor
{
private:
	ArbolAVL arbol;
public:
	string insertarEnABB(int);
	string mostrarPreOrden();
	string mostrarInOrden();
	string mostrarPostOrden();
};


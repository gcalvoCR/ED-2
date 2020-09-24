#ifndef GESTOR_H
#define GESTOR_H
#include <string>
#include "ArbolABB.h"

using namespace std;

class Gestor
{
private:
	ArbolABB arbol;
public:
	string insertarEnABB(int);
	string mostrarPreOrden();
	string mostrarInOrden();
	string mostrarPostOrden();
};

#endif
#pragma once
#include <string>
#include "ArbolAVL.h"
#include "ArbolB.h"
#include "ArbolBPlus.h"

using namespace std;

class Gestor
{
private:
	ArbolAVL arbolAVL;
	ArbolB arbolB;
	ArbolBPlus arbolBPlus;

public:
	//1. Métodos para Árbol AVL
	string insertarEnAVL(int);
	string mostrarPreOrdenAVL();
	string mostrarInOrdenAVL();
	string mostrarPostOrdenAVL();
	//2. Métodos para Árbol B
	//3. Métodos para Árbol B+
	//4. Métodos para Árbol Rojo-Negro
};


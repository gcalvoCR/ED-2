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
	//1. M�todos para �rbol AVL
	string insertarEnAVL(int);
	string mostrarPreOrdenAVL();
	string mostrarInOrdenAVL();
	string mostrarPostOrdenAVL();
	//2. M�todos para �rbol B
	//3. M�todos para �rbol B+
	//4. M�todos para �rbol Rojo-Negro
};


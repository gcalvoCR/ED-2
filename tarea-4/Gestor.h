#pragma once
#include <string>
#include "ArbolAVL.h"
#include "ArbolB.h"
#include "ArbolBPlus.h"
#include "ArbolRN.h"

using namespace std;

class Gestor
{
private:
	ArbolAVL arbolAVL;
	ArbolB arbolB;
	ArbolBPlus arbolBPlus;
	ArbolRN arbolRN;

public:
	//1. Métodos para Árbol AVL
	string insertarEnAVL(int);
	string mostrarPreOrdenAVL();
	string mostrarInOrdenAVL();
	string mostrarPostOrdenAVL();
	//2. Métodos para Árbol B
	string insertarElementoEnArbolB(int);
	bool validarOrdenArbol();
	void insertarOrdenArbolB(int);
	string imprimirDatosArbolB();
	string imprimirEstadoArbolB();
	string buscarElementoEnArbolB(int);
	string eliminarElementoEnArbolB(int);
	//3. Métodos para Árbol B+
	//4. Métodos para Árbol Rojo-Negro
	string insertarEnRN(int);
	void eliminarEnRN(int);
	void imprimirRN();
	void mostrarPreOrdenRN();
	void mostrarInOrdenRN();
	void mostrarPostOrdenRN();
};


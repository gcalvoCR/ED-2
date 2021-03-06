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
	//1. M�todos para �rbol AVL
	string insertarEnAVL(int);
	string mostrarPreOrdenAVL();
	string mostrarInOrdenAVL();
	string mostrarPostOrdenAVL();
	string buscarEnAVL(int);
	string eliminarAVL(int);
	//2. M�todos para �rbol B
	string insertarElementoEnArbolB(int);
	bool validarOrdenArbol();
	void insertarOrdenArbolB(int);
	string imprimirDatosArbolB();
	string imprimirEstadoArbolB();
	string buscarElementoEnArbolB(int);
	string eliminarElementoEnArbolB(int);
	//3. M�todos para �rbol B+
	string insertarElementoEnArbolBPlus(int);
	void imprimirDatosArbolBPlus();
	bool validarOrdenArbolBPlus();
	void insertarOrdenArbolBPlus(int);
	//4. M�todos para �rbol Rojo-Negro
	string insertarEnRN(int);
	string eliminarEnRN(int);
	void imprimirRN();
	void mostrarPreOrdenRN();
	void mostrarInOrdenRN();
	void mostrarPostOrdenRN();
};


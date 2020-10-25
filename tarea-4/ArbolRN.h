#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "NodoRN.h"
using namespace std;

class ArbolRN {
private:
	NodoRN* raiz;
	NodoRN* TNULL;

	// Inicializa todos los nodos con los valores apropiados
	// todos los punteros apunta al puntero "NULL" TNULL
	void inicializaNodoNULL(NodoRN* nodo, NodoRN* padre);
	
	//Helpers
	void preOrdenHelper(NodoRN* nodo);
	void inOrdenHelper(NodoRN* nodo);
	void postOrdenHelper(NodoRN* nodo);
	NodoRN* buscarArbolHelper(NodoRN* nodo, int key);
	bool borrarNodoHelper(NodoRN* nodo, int key);
	void printHelper(NodoRN* raiz, string indent, bool last);

	// Arregla el Arbol modificado por la operacion de borrar
	void arreglarBorrado(NodoRN* x);
	void transplantarRN(NodoRN* u, NodoRN* v);
	
	// arregla la insercion
	void arreglarInsercion(NodoRN* k);

	// busca el arbol por llave k
	NodoRN* buscarArbol(int k);
	// encuentra el nodo con la llave minima
	NodoRN* minimo(NodoRN* nodo);
	// encuentra el nodo con la llave maxima
	NodoRN* maximo(NodoRN* nodo);
	// encuentra el sucesor del nodo dado
	NodoRN* sucesor(NodoRN* x);
	// encuentra el predecesor del nodo dado
	NodoRN* predecesor(NodoRN* x);
	// rotar nodo izquierdo de x
	void rotarIzq(NodoRN* x);
	// rotar nodo derecho de x
	void rotarDer(NodoRN* x);
	// Getter que se necesita
	NodoRN* getraiz();
	

public:
	ArbolRN();
	// RID
	void preOrden();
	// IRD
	void inOrden();
	// IDR
	void postOrden();
	// insertar dato y arrreglar el arbol
	bool insertar(int key);
	// borrar el nodo
	bool borrarNodo(int dato);
	// imprimir 
	void prettyPrint();

};



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

	// initializes the nodos with appropirate values
	// all the pointers are set to point to the null pointer
	void initializeNULLnodo(NodoRN* nodo, NodoRN* padre);
	void preOrderHelper(NodoRN* nodo);
	void inOrderHelper(NodoRN* nodo);
	void postOrderHelper(NodoRN* nodo);
	NodoRN* searchTreeHelper(NodoRN* nodo, int key);
	// fix the rb tree modified by the delete operation
	void fixDelete(NodoRN* x);
	void rbTransplant(NodoRN* u, NodoRN* v);
	void deletenodoHelper(NodoRN* nodo, int key);
	// fix the red-black tree
	void fixInsert(NodoRN* k);
	void printHelper(NodoRN* raiz, string indent, bool last);

public:
	ArbolRN();
	// RID
	void preOrden();
	// IRD
	void inOrden();
	// IDR
	void postOrden();
	// busca el arbol por llave k
	NodoRN* buscarArbol(int k);
	// encuentra el nodo con la llave minima
	NodoRN* minimum(NodoRN* nodo);
	// encuentra el nodo con la llave maxima
	NodoRN* maximum(NodoRN* nodo);
	// encuentra el sucesor del nodo dado
	NodoRN* successor(NodoRN* x);
	// find the predecessor of a given nodo
	NodoRN* predecessor(NodoRN* x);
	// rotate izq at nodo x
	void izqRotate(NodoRN* x);
	// rotate der at nodo x
	void derRotate(NodoRN* x);
	// insert the key to the tree in its appropriate position
	// and fix the tree
	void insert(int key);
	NodoRN* getraiz();
	// delete the nodo from the tree
	void deleteNodo(int dato);
	// print the tree structure on the screen
	void prettyPrint();

};



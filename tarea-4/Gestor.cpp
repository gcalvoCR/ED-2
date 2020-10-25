#include "Gestor.h"
//1. Métodos para Árbol AVL
string Gestor::insertarEnAVL(int pDato) {
	bool cond = arbolAVL.insertarElem(pDato);
	string msg;
	if (cond) {
		msg = "Numero entero agregado con exito.";
	}
	else {
		msg = "Numero entero se encuentra repetido. Intente de nuevo.";
	}
	return msg;
}
string Gestor::mostrarPreOrdenAVL() {
	return arbolAVL.preOrden();
}
string Gestor::mostrarInOrdenAVL() {
	return  arbolAVL.inOrden();
}
string Gestor::mostrarPostOrdenAVL() {
	return arbolAVL.postOrden();
}



//4. Metodos en Arbol RN
string Gestor::insertarEnRN(int pDato) {
	bool cond = arbolRN.insertar(pDato);
	string msg;
	if (cond) {
		msg = "Numero entero agregado con exito.";
	}
	else {
		msg = "Numero entero se encuentra repetido. Intente de nuevo.";
	}
	return msg;
}

string Gestor::eliminarEnRN(int pdato)
{
	bool cond = arbolRN.borrarNodo(pdato);
	string msg;
	if (cond) {
		msg = "Numero entero eliminado con exito.";
	}
	else {
		msg = "Numero entero no fue encontrado. Intente de nuevo.";
	}
	return msg;
	
}
void Gestor::imprimirRN()
{
	arbolRN.prettyPrint();
}
void Gestor::mostrarPreOrdenRN() {
	arbolRN.preOrden();
}
void Gestor::mostrarInOrdenRN() {
	arbolRN.inOrden();
}
void Gestor::mostrarPostOrdenRN() {
	arbolRN.postOrden();
}

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

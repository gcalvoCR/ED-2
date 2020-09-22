#include "Gestor.h"

void Gestor::insertarEnABB(int pDato) {
	arbol.insertarDato(arbol.getRaiz(), pDato);
}

string Gestor::mostrarPreOrden() {
	string msg = arbol.PreOrden(arbol.getRaiz());
	return msg;
}

string Gestor::mostrarInOrden() {
	return "";
}

string Gestor::mostrarPostOrden() {
	return "";
}

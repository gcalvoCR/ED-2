#include "Gestor.h"

void Gestor::insertarEnABB(int pDato) {
	arbol.insertarDato(pDato);
}

string Gestor::mostrarPreOrden() {
	return arbol.PreOrden(arbol.getRaiz());
}

string Gestor::mostrarInOrden() {
	return "";
}

string Gestor::mostrarPostOrden() {
	return "";
}

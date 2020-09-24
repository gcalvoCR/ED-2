#include "Gestor.h"

string Gestor::insertarEnABB(int pDato) {
	bool cond = arbol.insertarDato(pDato);
	string msg;
	if (cond) {
		msg = "Numero entero agregado con exito.";
	}
	else {
		msg = "Numero entero se encuentra repetido. Intente de nuevo.";
	}
	return msg;
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

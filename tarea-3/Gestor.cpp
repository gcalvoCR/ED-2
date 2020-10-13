#include "Gestor.h"

string Gestor::insertarEnABB(int pDato) {
	bool cond = arbol.insertarElem(pDato);
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
	return arbol.preOrden();
}

string Gestor::mostrarInOrden() {
	return  arbol.inOrden();
}

string Gestor::mostrarPostOrden() {
	return arbol.postOrden();
}


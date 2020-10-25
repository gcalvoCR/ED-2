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
	return arbol.preOrden();
}

string Gestor::mostrarInOrden() {
	return  arbol.inOrden();
}

string Gestor::mostrarPostOrden() {
	return arbol.postOrden();
}

string Gestor::buscarEnAVL(int pDato) {

	bool existe = arbol.buscarEnAVL(pDato);
	string msg;
	if (existe) 
	{
		msg = "El numero esta";
	}else 
	{
		msg = "El numero no esta";
	}

	return msg;
}

string Gestor::eliminarAVL(int pDato) {

	bool borrado = arbol.borrar(pDato);
	string msg;

	if (borrado)
	{
		msg = "Numero borrado";
	}
	else
	{
		msg = "Numero no borrado";
	}
	
	return msg;
}
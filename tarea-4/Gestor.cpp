#include "Gestor.h"
//1. M�todos para �rbol AVL
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



//4. Metods en Arbol RN
string Gestor::insertarEnRN(int pDato) {
	arbolRN.insert(pDato);
	string msg;
	return "Numero entero agregado con exito.";
	
}
void Gestor::eliminarEnRN(int pdato)
{
	arbolRN.deleteNodo(pdato);
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

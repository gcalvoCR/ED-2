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

//2. M�todos en Arbol B

string Gestor::insertarElementoEnArbolB(int pDato) {
	bool cond = arbolB.agregar(pDato);
	string msg;
	if (cond) {
		msg = "Numero entero agregado con exito.";
	}
	else {
		msg = "Numero entero se encuentra repetido. Intente de nuevo.";
	}
	return msg;
}
bool Gestor::validarOrdenArbol() {
	bool rslt = false;
	if (arbolB.getOrden() != 0) {
		rslt = true;
	}
	return rslt;
}
void Gestor::insertarOrdenArbolB(int pOrden) {
	arbolB.setOrden(pOrden);
}
string Gestor::imprimirDatosArbolB() {
	return arbolB.pintar();

}
string Gestor::imprimirEstadoArbolB() {
	return arbolB.pintarArbol();
}
string Gestor::buscarElementoEnArbolB(int pDato) {
	bool cond = arbolB.buscar(pDato);
	string msg;
	if (cond) {
		msg += "El dato " + to_string(pDato) + " SI se encuentra en el arbol B.";
	}
	else {
		msg = "El dato " + to_string(pDato) + " NO se encuentra en el arbol B.";
	}
	return msg;
}
string Gestor::eliminarElementoEnArbolB(int pDato) {
	bool cond = arbolB.borrar(pDato);
	string msg;
	if (cond) {
		msg = "Numero entero eliminar con exito.";
	}
	else {
		msg = "Numero no existe en el �rbol B. Intente de nuevo.";
	}
	return msg;
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

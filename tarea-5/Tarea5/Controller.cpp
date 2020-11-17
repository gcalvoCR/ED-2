
#include "Controller.h"

#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>
#include "Etiqueta.h"
#include "Grafo.h"

using namespace std;

Controller::Controller() {
    grafo = new Grafo();
}

Controller::~Controller() {
}

Grafo* Controller::getGrafo() {
    return grafo;
}

//1. Métodos para primer grafo (matriz de adyacencia)

bool Controller::insertarVerticeEnArreglo(int pPosicion, int pVertice) {
    return grafo->insertarVertice(pPosicion, pVertice);
}

string Controller::agregarArcoEnMatriz(int pFila, int pColumna, int pPeso) {
    Etiqueta etiqueta(pPeso);
    grafo->insertarEtiqueta(pFila, pColumna, etiqueta);
    return "Datos guardados";
}

int Controller::buscarVertice(int pVertice) {
    return getGrafo()->buscarVertice(pVertice);
}

int Controller::buscarEtiqueta(int pFila, int pColumna) {
    return getGrafo()->buscarDatosEtiqueta(pFila, pColumna);
}

string Controller::mostrarVertices() {
    return getGrafo()->mostrarVertices();
}

string Controller::mostrarEtiquetas() {
    return getGrafo()->mostrarArcos();
}

//2. Métodos para segundo grafo (lista de adyacencia)
string Controller::insertar_nodo_segundoGrafo(char pDato) {
	string rslt = segundoGrafo.insertar_nodo(pDato);
	return rslt;
}

string Controller::insertar_arista_segundoGrafo(char pInicio, char pFin) {
	bool cond = segundoGrafo.insertar_arista(pInicio, pFin);
	string msg;
	if (cond) {
		msg = "Arco agregada con exito.";
	}
	else {
		msg = "Arco no se pudo agregar. Intente de nuevo.";
	}
	return msg;
}

string Controller::eliminar_nodo_segundoGrafo(char pVar) {
	bool cond = segundoGrafo.eliminar_nodo(pVar);
	string msg;
	if (cond) {
		msg = "Vertice eliminado con exito.";
	}
	else {
		msg = "Vertice no se pudo eliminar. Intente de nuevo.";
	}
	return msg;
}

string Controller::eliminar_arista_segundoGrafo(char pInicio, char pFin) {
	bool cond = segundoGrafo.eliminar_arista(pInicio, pFin);
	string msg;
	if (cond) {
		msg = "Arco eliminado con exito.";
	}
	else {
		msg = "Arco no se pudo eliminar. Intente de nuevo.";
	}
	return msg;
}

string Controller::mostrar_grafo_segundoGrafo() {
	string rslt = segundoGrafo.mostrar_grafo();
	return rslt;
}

string Controller::mostrar_aristas_segundoGrafo(char pVar) {
	string rslt = segundoGrafo.mostrar_aristas(pVar);
	return rslt;
}

string Controller::imprimir_nodos_segundoGrafo() {
	string rslt = segundoGrafo.imprimirNodos();
	return rslt;

}

bool Controller::verificarExistenciaNodoSegundoGrafo(char pVar) {
	bool cond = segundoGrafo.verificarNodoExistente(pVar);
	return cond;
}

bool Controller::verificarSegundoGrafoVacio() {
	bool cond = segundoGrafo.verificarGrafoVacio();
	return cond;
}
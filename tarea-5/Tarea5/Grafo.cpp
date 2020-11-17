
#include "Grafo.h"
#include <iostream>

Grafo::Grafo() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Etiqueta aux;
            matriz[i][j] = aux;
        }
    }
}

Grafo::Grafo(const Grafo& orig) {
}

Grafo::~Grafo() {
}

Etiqueta* Grafo::getMatriz() {
    return *matriz;
}

bool Grafo::insertarEtiqueta(int pFila, int pColumna, Etiqueta pEtiqueta) {
    matriz[pFila][pColumna] = pEtiqueta;
    return true;
}

bool Grafo::insertarVertice(int pPosicion, int pVertice) {
    if (buscarVertice(pVertice) == -1) {
        referencia[pPosicion] = pVertice;
        return true;
    }
    else {
        return false;
    }
}

int Grafo::buscarVertice(int pVertice) {
    for (int i = 0; i < 8; i++) {
        if (referencia[i] == pVertice) {
            return i;
        }
    }
    return -1;
}

int Grafo::buscarDatosEtiqueta(int pFila, int pColumna) {
    return matriz[pFila][pColumna].getPeso();
}

string Grafo::mostrarVertices() {
    ostringstream s;
    for (int i = 0; i < 8; i++) {
        s << "Vertice # " << i << " " << referencia[i] << "\n";
    }
    return s.str();
}

string Grafo::mostrarArcos() {
    ostringstream s;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            s << i << " -> " << j << ": " << matriz[i][j].toString();
        }
    }
    return s.str();
}

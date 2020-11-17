
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

bool Grafo::insertarArreglo(int pPosicion, string pCiudad) {
    if (buscarCiudad(pCiudad) == -1) {
        referencia[pPosicion] = pCiudad;
        return true;
    }
    else {
        return false;
    }
}

int Grafo::buscarCiudad(string pCiudad) {
    for (int i = 0; i < 8; i++) {
        if (referencia[i] == pCiudad) {
            return i;
        }
    }
    return -1;
}

string Grafo::buscarDatosEtiqueta(int pFila, int pColumna) {
    return matriz[pFila][pColumna].toString();
}

string Grafo::mostrarArreglo() {
    ostringstream s;
    for (int i = 0; i < 8; i++) {
        s << "Ciudad # " << i << " " << referencia[i] << "\n";
    }
    return s.str();
}

string Grafo::mostrarEtiquetas() {
    ostringstream s;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            s << i << " -> " << j << ": " << matriz[i][j].toString();
        }
    }
    return s.str();
}

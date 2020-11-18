#pragma once

#ifndef GRAFO_H
#define GRAFO_H
#include "Etiqueta.h"
#include "Nodo.h"
#include "Arista.h"
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class Grafo {
public:
    Grafo();
    Grafo(const Grafo& orig);
    virtual ~Grafo();
    Etiqueta* getMatriz();
    //Metodos matriz de adyacencia
    bool insertarEtiqueta(int, int, Etiqueta);
    bool insertarVertice(int, int);
    int buscarVertice(int);
    int buscarDatosEtiqueta(int, int);
    string mostrarVertices();
    string mostrarArcos();
    //Metodos lista de adyacencia
    string insertar_nodo(char);
    void agrega_arista(Tnodo&, Tnodo&, Tarista&);
    bool insertar_arista(char, char);
    void vaciar_aristas(Tnodo&);
    bool eliminar_nodo(char);
    bool eliminar_arista(char, char);
    string mostrar_grafo();
    string mostrar_aristas(char);
    string imprimirNodos();
    bool verificarNodoExistente(char);
    bool verificarGrafoVacio();

private:
    Etiqueta matriz[8][8];
    int referencia[8];
    Tnodo p;//puntero cabeza

};

#endif /* GRAFO_H */


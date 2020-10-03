#ifndef ARBOLABB_H
#define ARBOLABB_H
#include <string>
#include <iostream>
#include <sstream>
#include "Nodo.h"
using namespace std;

class ArbolABB
{
private:
    Nodo* raiz;
    int altura;
    string PreOrdenRecursivo(Nodo*);
    string InOrdenRecursivo(Nodo*);
    string PostOrdenRecursivo(Nodo*);

public:
    //CONSTRUCTOR
    ArbolABB();

    //GETTERS & SETTERS
    Nodo* getRaiz() const;
    void setRaiz(Nodo*);

    //METODOS
    // Insertar en árbol ordenado:
    bool insertarDato(int);
    bool buscarPI(Nodo* nodo, int pDato);
    bool estaVacio();

    string preOrden();
    string inOrden();
    string postOrden();
   
};

#endif
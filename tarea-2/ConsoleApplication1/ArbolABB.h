#ifndef ARBOLABB_H
#define ARBOLABB_H
#include <string>
#include <iostream>
#include <sstream>
#include "Nodo.h"
using namespace std;

class ArbolABB
{
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
    string PreOrden(Nodo*);
    string InOrden(Nodo*);
    string PostOrden(Nodo*);
   

private:
    Nodo* raiz;
    int altura;
};

#endif
#ifndef ARBOLABB_H
#define ARBOLABB_H
#include <string>
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
    bool insertarDato(Nodo* const&, int);
    string PreOrden(Nodo*);
    string InOrden();
    string PostOrden();

private:
    Nodo* raiz;
    int altura;
};

#endif
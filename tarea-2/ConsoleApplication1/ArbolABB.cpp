#include "ArbolABB.h"

//CONSTRUCTOR
ArbolABB::ArbolABB()
{
    setRaiz(NULL);
}

//GETTERS & SETTERS
Nodo* ArbolABB::getRaiz() const {
    return raiz;
}
void ArbolABB::setRaiz(Nodo* raiz) {
    ArbolABB::raiz = raiz;
}

//METODOS

bool ArbolABB::insertarDato(Nodo* const & raiz, int pDato) {
    if (raiz == NULL) {
        Nodo* nuevo = new Nodo();
        nuevo->setDato(pDato);
        setRaiz(nuevo);
    }
    else {
        int valorRaiz = raiz->getDato();
        if (pDato < valorRaiz) {
            insertarDato(raiz->getIzq(), pDato);
        }
        else if (pDato > valorRaiz) {
            insertarDato(raiz->getDer(), pDato);
        }
        else {
            //Numero repetido. Los arboles ABB no deben tener numeros repetidos.
            return false;
        }
    }
    return true;
}

string ArbolABB::PreOrden(Nodo* raiz) {
    string rslt = "";
    if (raiz != NULL) {
        rslt += to_string(raiz->getDato()) + ", " + "\n";
        PreOrden(raiz->getIzq());
        PreOrden(raiz->getDer());
    }
    return rslt;
}

string ArbolABB::InOrden() {
    return "";
}

string ArbolABB::PostOrden() {
    return "";
}

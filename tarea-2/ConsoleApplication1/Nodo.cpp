#include "Nodo.h"
#include "stddef.h"

//CONSTRUCTORES
Nodo::Nodo()
{
    setDato(0);
    setDer(NULL);
    setIzq(NULL);
}
Nodo::Nodo(int pdato, Nodo* der, Nodo* izq) : dato(pdato), der(der), izq(izq)
{
}
Nodo::Nodo(int pdato) : dato(pdato), der(NULL), izq(NULL)
{
}

//GETTERS & SETTERS
int Nodo::getDato() const {
    return dato;
}
void Nodo::setDato(int pdato) {
    Nodo::dato = pdato;
}
Nodo* Nodo::getDer() const {
    return der;
}
void Nodo::setDer(Nodo* der) {
    Nodo::der = der;
}
Nodo* Nodo::getIzq() const {
    return izq;
}
void Nodo::setIzq(Nodo* izq) {
    Nodo::izq = izq;
}

//METODOS
bool Nodo::esHoja() {
    return izq == nullptr && der == nullptr;
}
bool Nodo::esInteriorUnHijo() {
    return (izq == nullptr && der != nullptr) || (izq != nullptr && der == nullptr);
}
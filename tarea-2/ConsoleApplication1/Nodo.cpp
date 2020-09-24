#include "Nodo.h"
#include "stddef.h"

//CONSTRUCTORES
Nodo::Nodo()
{
    setDato(0);
    setDer(NULL);
    setIzq(NULL);
}
Nodo::Nodo(int dato, Nodo* der, Nodo* izq) : dato(dato), der(der), izq(izq)
{
}
Nodo::Nodo(int dato) : dato(dato), der(NULL), izq(NULL)
{
}

//GETTERS & SETTERS
int Nodo::getDato() const {
    return dato;
}
void Nodo::setDato(int dato) {
    Nodo::dato = dato;
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
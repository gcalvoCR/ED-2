#include "Nodo.h"
#include "stddef.h"

//CONSTRUCTORES
Nodo::Nodo() : dato(0), padre(NULL), der(NULL), izq(NULL), fe(0)
{
}

Nodo::Nodo(int dato, Nodo* ppadre, Nodo* der, Nodo* izq) : dato(dato), padre(ppadre), der(der), izq(izq), fe(0)
{
}

Nodo::Nodo(int dato, Nodo* ppadre) : dato(dato), padre(ppadre), der(NULL), izq(NULL), fe(0)
{
}

Nodo::Nodo(int dato) : dato(dato), padre(NULL), der(NULL), izq(NULL), fe(0)
{
}

//GETTERS & SETTERS
int Nodo::getDato() {
    return dato;
}
void Nodo::setDato(int dato) {
    Nodo::dato = dato;
}
Nodo* Nodo::getDer() {
    return der;
}
void Nodo::setDer(Nodo* der) {
    Nodo::der = der;
}
Nodo* Nodo::getIzq() {
    return izq;
}
void Nodo::setIzq(Nodo* izq) {
    Nodo::izq = izq;
}

int Nodo::getFE()
{
    return this->fe;
}

void Nodo::setFE(int pfe)
{
    this->fe = pfe;
}

void Nodo::incrementarFE()
{
    this->fe++;
}

void Nodo::disminuirFE()
{
    this->fe--;
}

//METODOS
bool Nodo::esHoja() {
    return izq == nullptr && der == nullptr;
}
bool Nodo::esInteriorUnHijo() {
    return (izq == nullptr && der != nullptr) || (izq != nullptr && der == nullptr);
}

Nodo* Nodo::getPadre()
{
    return padre;
}

void Nodo::setPadre(Nodo* padre)
{
    this->padre = padre;
}


#include "ArbolABB.h"
#include "Helper.h"

//CONSTRUCTOR
ArbolABB::ArbolABB()
{
    setRaiz(NULL);
}

//GETTERS & SETTERS
Nodo* ArbolABB::getRaiz()
{
    return this->raiz;
}
void ArbolABB::setRaiz(Nodo* raiz) {
    ArbolABB::raiz = raiz;
}

int ArbolABB::getAltura()
{
    return this->altura;
}

void ArbolABB::setAltura(int paltura)
{
    this->altura = paltura;
}

//METODOS
bool ArbolABB::insertarElem(int pdato) {
    if (this->raiz == nullptr) {
        Nodo* nuevo = new Nodo(pdato);
        this->raiz = nuevo;
    }
    else {
        //Invoca metodo recursivo que posicionara el dato en la rama indicada.
        return buscarEinsertarOrdenado(this->raiz, pdato);
    }
    return true;
}

//PI : punto de insercion del dato en el arbol binario (metodo recursivo)
bool ArbolABB::buscarEinsertarOrdenado(Nodo* nodo, int pDato) {
    if (pDato < nodo->getDato() && nodo->getIzq() != nullptr) {
        return buscarEinsertarOrdenado(nodo->getIzq(), pDato);
    }
    else if (pDato < nodo->getDato() && nodo->getIzq() == nullptr) {
        nodo->setIzq(new Nodo(pDato));
    }
    else if (pDato > nodo->getDato() && nodo->getDer() != nullptr) {
        return buscarEinsertarOrdenado(nodo->getDer(), pDato);
    }
    else if (pDato > nodo->getDato() && nodo->getDer() == nullptr) {
        nodo->setDer(new Nodo(pDato));
    }
    else if (pDato == nodo->getDato()){
        //Else en caso que el valor sea repetido, retorna false, ya que un ABB no puede tener valores iguales. 
        return false;
    }
    return true;
}

bool ArbolABB::estaVacio() {
    if (getRaiz() == nullptr) {
        return true;
    }
    return false;
}

string ArbolABB::preOrden()
{
    return PreOrdenRecursivo(getRaiz());
}

string ArbolABB::inOrden()
{
    return InOrdenRecursivo(getRaiz());
}

string ArbolABB::postOrden()
{
    return PostOrdenRecursivo(getRaiz());
}

string  ArbolABB::PreOrdenRecursivo(Nodo* raiz) {
    string rslt = "";
    Helper helper;
    stringstream sstm;

    if (raiz != NULL) {
        // PREORDEN: RAIZ -- IZQUIERDA -- DERECHA (RID)
        sstm << raiz->getDato() << " " << PreOrdenRecursivo(raiz->getIzq()) << " " << PreOrdenRecursivo(raiz->getDer());
        rslt += sstm.str();

        // Paso para formatear un poco el string
        rslt = helper.ReplaceAll(rslt);
    }
    else if (estaVacio()) {
        return "Arbol binario de busqueda vacio.";
    }
    return rslt;
}

string ArbolABB::InOrdenRecursivo(Nodo* raiz) {
    string rslt = "";
    Helper helper;
    stringstream sstm;

    if (raiz != NULL) {
        // PREORDEN: IZQUIERDA -- RAIZ -- DERECHA (IRD)
        sstm << InOrdenRecursivo(raiz->getIzq())  << " " << raiz->getDato() << " " << InOrdenRecursivo(raiz->getDer());
        rslt += sstm.str();

        // Paso para formatear un poco el string
        rslt = helper.ReplaceAll(rslt);
    }
    else if (estaVacio()) {
        return "Arbol binario de busqueda vacio.";
    }
    return rslt;
}

string ArbolABB::PostOrdenRecursivo(Nodo* raiz) {
    string rslt = "";
    Helper helper;
    stringstream sstm;

    if (raiz != NULL) {
        // PREORDEN: IZQUIERDA -- DERECHA -- RAIZ (IDR)
        sstm << PostOrdenRecursivo(raiz->getIzq()) << " " << PostOrdenRecursivo(raiz->getDer()) << " " << raiz->getDato();
        rslt += sstm.str();

        // Paso para formatear un poco el string
        rslt = helper.ReplaceAll(rslt);
    }
    else if (estaVacio()) {
        return "Arbol binario de busqueda vacio.";
    }
    return rslt;
}

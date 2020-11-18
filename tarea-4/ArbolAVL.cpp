#include "ArbolAVL.h"
#include "Helper.h"

//CONSTRUCTOR
ArbolAVL::ArbolAVL()
{
    setRaiz(NULL);
}

ArbolAVL::~ArbolAVL()
{
    //En proceso
}

//METODOS
bool ArbolAVL::insertarElem(int pDato) {
    if (this->raiz == nullptr) {
        Nodo* nuevo = new Nodo(pDato);
        this->raiz = nuevo;
    }
    else {
        //Invoca metodo recursivo que posicionara el dato en la rama indicada.
        return buscarEinsertarOrdenado(this->raiz, pDato);
    }
    return true;
}

bool ArbolAVL::eliminarElem(int pdato)
{
    return false;
}

bool ArbolAVL::buscarEinsertarOrdenado(Nodo* nodo, int pdato) {

    if (pdato < nodo->getDato() && nodo->getIzq() != nullptr) {
        return buscarEinsertarOrdenado(nodo->getIzq(), pdato);
    }
    else if (pdato < nodo->getDato() && nodo->getIzq() == nullptr) {
        Nodo* padre = nodo;
        nodo->setIzq(new Nodo(pdato, padre));
        equilibrar(nodo, IZQUIERDO, true); //Despues de insertar llamamos a equilibrar
    }
    else if (pdato > nodo->getDato() && nodo->getDer() != nullptr) {
        return buscarEinsertarOrdenado(nodo->getDer(), pdato);
    }
    else if (pdato > nodo->getDato() && nodo->getDer() == nullptr) {
        Nodo* padre = nodo;
        nodo->setDer(new Nodo(pdato, padre));
        equilibrar(nodo, DERECHO, true); //Despues de insertar llamamos a equilibrar
    }
    else if (pdato == nodo->getDato()) {
        //Else en caso que el valor sea repetido, retorna false, ya que un ABB no puede tener valores iguales. 
        return false;
    }
    return true;
}

bool ArbolAVL::estaVacio() {
    if (getRaiz() == nullptr) {
        return true;
    }
    return false;
}

bool ArbolAVL::borrar(int pdato)
{
    Nodo* padre = NULL;
    Nodo* nodo;
    Nodo* actual;

    int aux;

    actual = raiz;
    // Mientras sea posible que el valor esté en el árbol
    while (!estaVacio(actual)) {
        if (pdato == actual->getDato()) { // Si el valor está en el nodo actual
            if (esHoja(actual)) { // Y si además es un nodo hoja: lo borramos
                if (padre) // Si tiene padre (no es el nodo raiz)
                   // Anulamos el puntero que le hace referencia
                    if (padre->getDer() == actual) padre->setDer(NULL);
                    else if (padre->getIzq() == actual) padre->setIzq(NULL);
                delete actual; // Borrar el nodo
                actual = NULL;
                // El nodo padre del actual puede ser ahora un nodo hoja, por lo tanto su
                // FE es cero, pero debemos seguir el camino a partir de su padre, si existe.
                if ((padre->getDer() == actual && padre->getFE() == 1) ||
                    (padre->getIzq() == actual && padre->getFE() == -1)) {
                    padre->setFE(0);
                    actual = padre;
                    padre = actual->getPadre();
                }
                if (padre)
                    if (padre->getDer() == actual) this->equilibrar(padre, DERECHO, false);
                    else                         this->equilibrar(padre, IZQUIERDO, false);
                return true;
            }
            else { // Si el valor está en el nodo actual, pero no es hoja
               // Buscar nodo
                padre = actual;
                // Buscar nodo más izquierdo de rama derecha
                if (actual->getDer()) {
                    nodo = actual->getDer();
                    while (nodo->getIzq()) {
                        padre = nodo;
                        nodo = nodo->getIzq();
                    }
                }
                // O buscar nodo más derecho de rama izquierda
                else {
                    nodo = actual->getIzq();
                    while (nodo->getDer()) {
                        padre = nodo;
                        nodo = nodo->getDer();
                    }
                }
                // Intercambiar valores de no a borrar u nodo encontrado
                // y continuar, cerrando el bucle. El nodo encontrado no tiene
                // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
                // de que sólo se eliminan nodos hoja.
                aux = actual->getDato();
                actual->setDato(nodo->getDato());
                nodo->setDato(aux);
                actual = nodo;
            }
        }
        else { // Todavía no hemos encontrado el valor, seguir buscándolo
            padre = actual;
            if (pdato > actual->getDato()) actual = actual->getDer();
            else if (pdato < actual->getDato()) actual = actual->getIzq();
        }

    }
    return false;
}
bool ArbolAVL::buscarEnAVL(int pDato)
{
    if (raiz == nullptr)
    {
        return false;
    }
    else
    {
        return buscar(getRaiz(), pDato);
    }
}

bool ArbolAVL::buscar(Nodo *nodo,int pdato)
{

    if (getRaiz() != nullptr && nodo->getDato() != NULL)
    {
        if (nodo->getDato() == pdato)
        {
            return true;
        }
        else if (pdato > nodo->getDato() && nodo->getDer() != nullptr) {
            return buscar(nodo->getDer(), pdato);
        }
        else if (pdato < nodo->getDato() && nodo->getIzq() != nullptr)
        {
            return buscar(nodo->getIzq(), pdato);
        }
        else
        {
            return false;
        }
    }
}

bool ArbolAVL::esHoja(Nodo* pnodo)
{
    return (pnodo->getDer() == NULL && pnodo->getIzq() == NULL);
}

int ArbolAVL::numHojas()
{
    // en proceso
    return 0;
}

int ArbolAVL::peso()
{
    //En proceso!
    return 0;
}

int ArbolAVL::altura()
{
    //En proceso
    return 0;
}

string ArbolAVL::preOrden()
{
    return PreOrdenRecursivo(getRaiz());
}

string ArbolAVL::inOrden()
{
    return InOrdenRecursivo(getRaiz());
}

string ArbolAVL::postOrden()
{
    return PostOrdenRecursivo(getRaiz());
}

string  ArbolAVL::PreOrdenRecursivo(Nodo* raiz) {
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

string ArbolAVL::InOrdenRecursivo(Nodo* raiz) {
    string rslt = "";
    Helper helper;
    stringstream sstm;

    if (raiz != NULL) {
        // PREORDEN: IZQUIERDA -- RAIZ -- DERECHA (IRD)
        sstm << InOrdenRecursivo(raiz->getIzq()) << " " << raiz->getDato() << " " << InOrdenRecursivo(raiz->getDer());
        rslt += sstm.str();

        // Paso para formatear un poco el string
        rslt = helper.ReplaceAll(rslt);
    }
    else if (estaVacio()) {
        return "Arbol binario de busqueda vacio.";
    }
    return rslt;
}

string ArbolAVL::PostOrdenRecursivo(Nodo* raiz) {
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

/*
equilibrado con estructura iterativa

void ArbolAVL::equilibrar(Nodo* pnodo, int rama, bool nuevo)
{
    bool salir = false;

    // Recorrer camino inverso actualizando valores de FE
    while (pnodo && !salir) {

        // Actualizamos el FE
        if (nuevo) {
            rama == IZQUIERDO ? pnodo->disminuirFE() : pnodo->incrementarFE();
        }
        else {
            rama == IZQUIERDO ? pnodo->incrementarFE() : pnodo->incrementarFE();
        }

        // Determinar tipo de rotacion y rotar
        if (pnodo->getFE() == 0) {
            salir = true;                                                       //Si el nodo esta equilibrado, no hay nada que hacer
        }
        else if (pnodo->getFE() == -2) {                                        // Rotar a derecha y salir
            if (pnodo->getIzq()->getFE() == 1) rotacionDobleDerecha(pnodo);     // Rotación doble
            else rotacionSimpleDerecha(pnodo);                                  // Rotación simple
            salir = true;
        }
        else if (pnodo->getFE() == 2) {                                         // Rotar a izquierda y salir
            if (pnodo->getDer()->getFE() == -1) rotacionDobleIzquierda(pnodo);  // Rotación doble
            else rotacionSimpleIzquierda(pnodo);                                // Rotación simple
            salir = true;
        }

        // Asignamos el padre
        if (pnodo->getPadre()) {
            pnodo->getPadre()->getDer() == pnodo ? rama = DERECHO : rama = IZQUIERDO;
        }

        pnodo = pnodo->getPadre(); // Calcular FE, siguiente nodo del camino.
    }

}
*/

/* Equilibrado recursivo*/
void ArbolAVL::equilibrar(Nodo* pnodo, int rama, bool nuevo)
{
    if (nuevo) {
        rama == IZQUIERDO ? pnodo->disminuirFE() : pnodo->incrementarFE();
    }
    else {
        rama == IZQUIERDO ? pnodo->incrementarFE() : pnodo->incrementarFE();
    }

    // Rotamos y salimos
    if (pnodo->getFE() == 0) {
        return;
    }
    else if (pnodo->getFE() == -2) {                                        // Rotar a derecha y salir
        if (pnodo->getIzq()->getFE() == 1) rotacionDobleDerecha(pnodo);     // Rotación doble
        else rotacionSimpleDerecha(pnodo);                                  // Rotación simple
        return;
    }
    else if (pnodo->getFE() == 2) {                                         // Rotar a izquierda y salir
        if (pnodo->getDer()->getFE() == -1) rotacionDobleIzquierda(pnodo);  // Rotación doble
        else rotacionSimpleIzquierda(pnodo);                                // Rotación simple
        return;
    }

    if (pnodo->getPadre()) {
        pnodo->getPadre()->getDer() == pnodo ? rama = DERECHO : rama = IZQUIERDO;
    }

    pnodo = pnodo->getPadre();

    if (pnodo) {
        equilibrar(pnodo, rama, nuevo);
    }

}

void ArbolAVL::rotacionSimpleDerecha(Nodo* pnodo)
{
    //P es nodo desequilibrado
    //Q es nodo raiz del subarbol derecho en P

    Nodo* Padre = pnodo->getPadre();
    Nodo* P = pnodo;
    Nodo* Q = P->getIzq();
    Nodo* B = Q->getDer();

    if (Padre) {
        Padre->getDer() == P ? Padre->setDer(Q) : Padre->setIzq(Q);
    }
    else { setRaiz(Q); }

    // Reconstruir árbol:
    P->setIzq(B);
    Q->setDer(P);

    // Reasignar padres:
    P->setPadre(Q);

    (B) ? B->setPadre(P) : Q->setPadre(Padre);

    // Ajustar valores de FE:
    P->setFE(0);
    Q->setFE(0);
}

void ArbolAVL::rotacionSimpleIzquierda(Nodo* pnodo)
{
    //P es nodo desequilibrado
    //Q es nodo raiz del subarbol derecho en P

    Nodo* Padre = pnodo->getPadre();
    Nodo* P = pnodo;
    Nodo* Q = P->getDer();
    Nodo* B = Q->getIzq();

    if (Padre) {
        Padre->getIzq() == P ? Padre->setIzq(Q) : Padre->setDer(Q);
    }
    else { setRaiz(Q); }

    // Reconstruir árbol:
    P->setDer(B);
    Q->setIzq(P);

    // Reasignar padres:
    P->setPadre(Q);

    B ? B->setPadre(P) : Q->setPadre(Padre);

    // Ajustar valores de FE:
    P->setFE(0);
    Q->setFE(0);
}

void ArbolAVL::rotacionDobleDerecha(Nodo* pnodo)
{
    Nodo* Padre = pnodo->getPadre();
    Nodo* P = pnodo;
    Nodo* Q = P->getIzq();
    Nodo* R = Q->getDer();
    Nodo* B = R->getIzq();
    Nodo* C = R->getDer();

    if (Padre)
    {
        if (Padre->getDer() == pnodo) Padre->setDer(R);
        else Padre->setIzq(R);
    }
    else setRaiz(R);

    // Reconstruir árbol:
    Q->setDer(B);
    P->setIzq(C);
    R->setIzq(Q);
    R->setDer(P);

    // Reasignar padres:
    R->setPadre(Padre);
    P->setPadre(R);
    Q->setPadre(R);
    if (B) B->setPadre(Q);
    if (C) C->setPadre(P);

    // Ajustar valores de FE:
    switch (R->getFE()) {
    case -1:
        Q->setFE(0);
        P->setFE(1);
        break;
    case 0:
        Q->setFE(0);
        P->setFE(0);
        break;
    case 1:
        Q->setFE(-1);
        P->setFE(0);
        break;
    }
    R->setFE(0);

}

void ArbolAVL::rotacionDobleIzquierda(Nodo* pnodo)
{
    Nodo* Padre = pnodo->getPadre();
    Nodo* P = pnodo;
    Nodo* Q = P->getDer();
    Nodo* R = Q->getIzq();
    Nodo* B = R->getIzq();
    Nodo* C = R->getDer();

    if (Padre)
    {
        if (Padre->getDer() == pnodo) Padre->setDer(R);
        else Padre->setIzq(R);
    }
    else setRaiz(R);

    // Reconstruir árbol:
    P->setDer(C);
    Q->setIzq(B);
    R->setIzq(P);
    R->setDer(Q);

    // Reasignar padres:
    R->setPadre(Padre);
    P->setPadre(R);
    Q->setPadre(R);
    if (B) B->setPadre(Q);
    if (C) C->setPadre(P);

    //// Ajustar valores de FE:
    switch (R->getFE()) {
    case -1:
        P->setFE(0);
        Q->setFE(1);
        break;
    case 0:
        P->setFE(0);
        Q->setFE(0);

        break;
    case 1:
        P->setFE(0);
        Q->setFE(-1);
        break;
    }
    R->setFE(0);
}

//GETTERS & SETTERS
Nodo* ArbolAVL::getRaiz()
{
    return this->raiz;
}

void ArbolAVL::setRaiz(Nodo* praiz)
{
    this->raiz = praiz;
}


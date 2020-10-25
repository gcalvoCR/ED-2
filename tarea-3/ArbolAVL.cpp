#include "ArbolAVL.h"
#include "Helper.h"

//CONSTRUCTOR
ArbolAVL::ArbolAVL()
{
    setRaiz(NULL);
}

//METODOS
bool ArbolAVL::insertarDato(int pDato) {
    if (this->raiz == nullptr) {
        Nodo* nuevo = new Nodo(pDato);
        this->raiz = nuevo;
    }   
    else {
        //Invoca metodo recursivo que posicionara el dato en la rama indicada.
        return buscarPI(this->raiz, pDato);
    }
    return true;
}
//PI : punto de insercion del dato en el arbol binario (metodo recursivo)
bool ArbolAVL::buscarPI(Nodo* nodo, int pDato) {
    

    if (pDato < nodo->getDato() && nodo->getIzq() != nullptr) {
        return buscarPI(nodo->getIzq(), pDato);
    }
    else if (pDato < nodo->getDato() && nodo->getIzq() == nullptr) {
        Nodo* padre = nodo;
        nodo->setIzq(new Nodo(pDato, padre));
        equilibrar(nodo, IZQUIERDO, true); //Despues llamamos a la funcion equilibrar, el true es para e
    }
    else if (pDato > nodo->getDato() && nodo->getDer() != nullptr) {
        return buscarPI(nodo->getDer(), pDato);
    }
    else if (pDato > nodo->getDato() && nodo->getDer() == nullptr) {
        Nodo* padre = nodo;
        nodo->setDer(new Nodo(pDato, padre));
        equilibrar(nodo, DERECHO, true); //Despues llamamos a la funcion equilibrar
    }
    else if (pDato == nodo->getDato()) {
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
                if ((padre->getDer() == actual && padre->getFactorEquilibrio() == 1) ||
                    (padre->getIzq() == actual && padre->getFactorEquilibrio() == -1)) {
                    padre->setFactorEquilibrio(0);
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
        else if (pdato < nodo->getDato() && nodo->getIzq()!= nullptr)
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
    return (pnodo->getDer()==NULL && pnodo->getIzq()==NULL);
}

int ArbolAVL::numeroNodos()
{
    //En proceso!
    return 0;
}

int ArbolAVL::alturaArbol()
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

int ArbolAVL::max(int a, int b)
{
    return (a>b)? a : b;
}

void ArbolAVL::equilibrar(Nodo* pnodo, int rama, bool nuevo)
{
    bool salir = false;

    // Recorrer camino inverso actualizando valores de FE:
    while (pnodo && !salir) {
        if (nuevo)
            if (rama == IZQUIERDO) pnodo->disminuirFE(); // Depende de si añadimos ...
            else                   pnodo->incrementarFE();
        else
            if (rama == IZQUIERDO) pnodo->incrementarFE(); // ... o borramos
            else                   pnodo->incrementarFE();
        if (pnodo->getFactorEquilibrio() == 0) salir = true; //Si el nodo esta equilibrado, no hay nada que hacer
                                        
        else if (pnodo->getFactorEquilibrio() == -2) { // Rotar a derecha y salir:
            if (pnodo->getIzq()->getFactorEquilibrio() == 1) rotacionDobleDerecha(pnodo); // Rotación doble
            else rotacionSimpleDerecha(pnodo);                         // Rotación simple
            salir = true;
        }
        else if (pnodo->getFactorEquilibrio() == 2) {  // Rotar a izquierda y salir:
            if (pnodo->getDer()->getFactorEquilibrio() == -1) rotacionDobleIzquierda(pnodo); // Rotación doble
            else rotacionSimpleIzquierda(pnodo);                        // Rotación simple
            salir = true;
        }
        if (pnodo->getPadre())
            if (pnodo->getPadre()->getDer() == pnodo) rama = DERECHO; else rama = IZQUIERDO;
        pnodo = pnodo->getPadre(); // Calcular FE, siguiente nodo del camino.
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

    if (Padre)
        if (Padre->getDer() == P) Padre->setDer(Q);
        else Padre->setIzq(Q);
    else setRaiz(Q);

    // Reconstruir árbol:
    P->setIzq(B);
    Q->setDer(P);

    // Reasignar padres:
    P->setPadre(Q);

    if (B) B->setPadre(P);
    Q->setPadre(Padre);

    // Ajustar valores de FE:
    P->setFactorEquilibrio(0);
    Q->setFactorEquilibrio(0);
}

void ArbolAVL::rotacionSimpleIzquierda(Nodo* pnodo)
{
    //P es nodo desequilibrado
    //Q es nodo raiz del subarbol derecho en P

    Nodo* Padre = pnodo->getPadre();
    Nodo* P = pnodo;
    Nodo* Q = P->getDer();
    Nodo* B = Q->getIzq();

    if (Padre)
        if (Padre->getIzq() == P) Padre->setIzq(Q);
        else Padre->setDer(Q);
    else setRaiz(Q);

    // Reconstruir árbol:
    P->setDer(B);
    Q->setIzq(P);

    // Reasignar padres:
    P->setPadre(Q);

    if (B) B->setPadre(P);
    Q->setPadre(Padre);

    // Ajustar valores de FE:
    P->setFactorEquilibrio(0);
    Q->setFactorEquilibrio(0);
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
    switch (R->getFactorEquilibrio()) {
        case -1: 
            Q->setFactorEquilibrio(0); 
            P->setFactorEquilibrio(1);
            break;
        case 0:  
            Q->setFactorEquilibrio(0); 
            P->setFactorEquilibrio(0);
            break;
        case 1:  
            Q->setFactorEquilibrio(-1); 
            P->setFactorEquilibrio(0);
            break;
    }
    R->setFactorEquilibrio(0);

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
    switch (R->getFactorEquilibrio()) {
    case -1:
        P->setFactorEquilibrio(0);
        Q->setFactorEquilibrio(1);
        break;
    case 0:
        P->setFactorEquilibrio(0);
        Q->setFactorEquilibrio(0);
        
        break;
    case 1:
        P->setFactorEquilibrio(0);
        Q->setFactorEquilibrio(-1);
        break;
    }
    R->setFactorEquilibrio(0);
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

Nodo* ArbolAVL::getActual()
{
    return actual;
}

void ArbolAVL::setActual(Nodo* actual)
{
    this->actual = actual;
}

int ArbolAVL::getAltura()
{
    return this->altura;
}

void ArbolAVL::setAltura(int altura)
{
    this->altura = altura;
}



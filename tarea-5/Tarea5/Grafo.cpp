
#include "Grafo.h"
#include <iostream>

Grafo::Grafo() : p(NULL)  {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Etiqueta aux;
            matriz[i][j] = aux;
        }
    }
}

Grafo::Grafo(const Grafo& orig) {
}

Grafo::~Grafo() {
}

Etiqueta* Grafo::getMatriz() {
    return *matriz;
}

bool Grafo::insertarEtiqueta(int pFila, int pColumna, Etiqueta pEtiqueta) {
    matriz[pFila][pColumna] = pEtiqueta;
    return true;
}

bool Grafo::insertarVertice(int pPosicion, int pVertice) {
    if (buscarVertice(pVertice) == -1) {
        referencia[pPosicion] = pVertice;
        return true;
    }
    else {
        return false;
    }
}

int Grafo::buscarVertice(int pVertice) {
    for (int i = 0; i < 8; i++) {
        if (referencia[i] == pVertice) {
            return i;
        }
    }
    return -1;
}

int Grafo::buscarDatosEtiqueta(int pFila, int pColumna) {
    return matriz[pFila][pColumna].getPeso();
}

string Grafo::mostrarVertices() {
    ostringstream s;
    for (int i = 0; i < 8; i++) {
        s << "Vertice # " << i << " " << referencia[i] << "\n";
    }
    return s.str();
}

string Grafo::mostrarArcos() {
    ostringstream s;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            s << i << " -> " << j << ": " << matriz[i][j].toString();
        }
    }
    return s.str();
}


/*                      INSERTAR NODO AL GRAFO
---------------------------------------------------------------------*/
string Grafo::insertar_nodo(char pDato)
{
    Tnodo t, nuevo = new struct nodo;
    bool repetido = false;
    nuevo->nombre = pDato;
    nuevo->sgte = NULL;
    nuevo->ady = NULL;
    string rslt;

    if (p == NULL)
    {
        p = nuevo;
        rslt = "Primer nodo insertado.";
    }
    else
    {
        t = p;

        if (t->nombre == nuevo->nombre) {
            rslt = "No se puede insertar. Nodo repetido";
            repetido = true;
        }
        else {
            while (t->sgte != NULL)
            {
                if (t->sgte->nombre == nuevo->nombre) {
                    rslt = "No se puede insertar. Nodo repetido";
                    repetido = true;
                    break;
                }
                else {
                    t = t->sgte;
                }
            }
        }
        if (!repetido) {
            t->sgte = nuevo;
            rslt = "Nodo ingresado correctamente";
        }

    }
    return rslt;
}

/*                      AGREGAR ARISTA
    funcion que utilizada para agregar la arista a dos nodos
---------------------------------------------------------------------*/
void Grafo::agrega_arista(Tnodo& aux, Tnodo& aux2, Tarista& nuevo)
{
    Tarista q;
    if (aux->ady == NULL)
    {
        aux->ady = nuevo;
        nuevo->destino = aux2;
        cout << "PRIMERA ARISTA....!";
    }
    else
    {
        q = aux->ady;
        while (q->sgte != NULL)
            q = q->sgte;
        nuevo->destino = aux2;
        q->sgte = nuevo;
        cout << "ARISTA AGREGADA...!!!!";
    }

}
/*                      INSERTAR ARISTA
    funcion que busca las posiciones de memoria de los nodos
    y hace llamado a agregar_arista para insertar la arista
---------------------------------------------------------------------*/
bool Grafo::insertar_arista(char ini, char fin)
{
    Tarista nuevo = new struct arista;
    Tnodo aux, aux2;

    if (p == NULL)
    {
        return false;
    }
    nuevo->sgte = NULL;
    aux = p;
    aux2 = p;
    while (aux2 != NULL)
    {
        if (aux2->nombre == fin)
        {
            break;
        }

        aux2 = aux2->sgte;
    }
    while (aux != NULL)
    {
        if (aux->nombre == ini)
        {
            agrega_arista(aux, aux2, nuevo);
            return true;
        }

        aux = aux->sgte;
    }
    return true;
}

/*          FUNCION PARA BORRAR TODAS LAS ARISTAS DE UN NODO
    esta funcion es utilizada al borrar un nodo pues si tiene aristas
    es nesesario borrarlas tambien y dejar libre la memoria
---------------------------------------------------------------------*/
void Grafo::vaciar_aristas(Tnodo& aux)
{
    Tarista q, r;
    q = aux->ady;
    while (q->sgte != NULL)
    {
        r = q;
        q = q->sgte;
        delete(r);
    }
}
/*                      ELIMINAR NODO
    funcion utilizada para eliminar un nodo del grafo
    pero para eso tambien tiene que eliminar sus aristas por lo cual
    llama a la funcion vaciar_aristas para borrarlas
---------------------------------------------------------------------*/
bool Grafo::eliminar_nodo(char var)
{
    Tnodo aux, ant = NULL;
    aux = p;
    if (p == NULL)
    {
        return false;
    }

    while (aux != NULL)
    {
        if (aux->nombre == var)
        {
            if (aux->ady != NULL)
                vaciar_aristas(aux);

            if (aux == p)
            {

                p = p->sgte;
                delete(aux);
                return true;



            }
            else
            {
                ant->sgte = aux->sgte;
                delete(aux);
                return true;
            }
        }
        else
        {
            ant = aux;
            aux = aux->sgte;
        }
    }

}

/*                      ELIMINAR ARISTA
    funcion utilizada para eliminar una arista
---------------------------------------------------------------------*/
bool Grafo::eliminar_arista(char ini, char fin)
{
    Tnodo aux, aux2;
    Tarista q, r1 = NULL;
    aux = p;
    aux2 = p;
    while (aux2 != NULL)
    {
        if (aux2->nombre == fin)
        {
            break;
        }
        else
            aux2 = aux2->sgte;
    }
    while (aux != NULL)
    {
        if (aux->nombre == ini)
        {
            q = aux->ady;
            while (q != NULL)
            {
                if (q->destino == aux2)
                {
                    if (q == aux->ady)
                        aux->ady = aux->ady->sgte;
                    else
                        r1->sgte = q->sgte;
                    delete(q);
                    return true;
                }
            }
            r1 = q;
            q = q->sgte;
        }
        aux = aux->sgte;
    }
}
/*                      MOSTRAR GRAFO
    funcion que imprime un grafo en su forma enlazada
---------------------------------------------------------------------*/
string Grafo::mostrar_grafo()
{
    Tnodo ptr;
    Tarista ar;
    ptr = p;
    string rslt = "";
    rslt += "NODO|LISTA DE ADYACENCIA\n";

    while (ptr != NULL)
    {
        rslt += "  ";
        rslt += ptr->nombre;
        rslt += " |";
        if (ptr->ady != NULL)
        {
            ar = ptr->ady;
            while (ar != NULL)
            {
                rslt += "  ";
                rslt += ar->destino->nombre;
                ar = ar->sgte;
            }

        }
        ptr = ptr->sgte;
        rslt += "\n";
    }
    return rslt;
}

/*                      MOSTRAR ARISTAS
    funcion que muestra todas las aristas de un nodo seleccionado
---------------------------------------------------------------------*/
string Grafo::mostrar_aristas(char var)
{
    Tnodo aux;
    Tarista ar;
    aux = p;
    string rslt;
    while (aux != NULL)
    {
        if (aux->nombre == var)
        {
            if (aux->ady == NULL)
            {
                rslt += "El nodo no tiene aristas";
                return rslt;
            }
            else
            {
                rslt += "NODO|LISTA DE ADYACENCIA\n";
                rslt += "   ";
                rslt += aux->nombre;
                rslt += "|";
                ar = aux->ady;

                while (ar != NULL)
                {

                    rslt += ar->destino->nombre;
                    rslt += " ";
                    ar = ar->sgte;
                }
                rslt += "\n";
                break;
            }
        }
        else
            aux = aux->sgte;
    }
    return rslt;
}

string Grafo::imprimirNodos() {
    Tnodo ptr;
    Tarista ar;
    ptr = p;
    string rslt = "";
    rslt += "Lista de nodos en el grafo:\n";

    while (ptr != NULL)
    {
        rslt += "  ";
        rslt += ptr->nombre;
        rslt += " | ";
        ptr = ptr->sgte;
    }
    return rslt;
}

bool Grafo::verificarNodoExistente(char var) {
    Tnodo ptr;
    Tarista ar;
    ptr = p;
    bool cond = false;
    while (ptr != NULL)
    {
        if (ptr->nombre == var) {
            cond = true;
        }
        ptr = ptr->sgte;
    }
    return cond;
}

bool Grafo::verificarGrafoVacio() {
    bool vacio = false;
    if (p == NULL)
    {
        return true;
    }
    return vacio;
}
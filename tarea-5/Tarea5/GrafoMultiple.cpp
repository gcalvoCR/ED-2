#include "GrafoMultiple.h"


GrafoMultiple::GrafoMultiple() : p(NULL) {
}


/*                      INSERTAR NODO AL GRAFO
---------------------------------------------------------------------*/
string GrafoMultiple::insertar_nodo(char pDato, int pValor)
{
    TnodoMultiple t, nuevo = new struct nodoMultiple;
    bool repetido = false;
    nuevo->nombre = pDato;
    nuevo->valor = pValor;
    nuevo->sgte = NULL;
    nuevo->pdr = NULL;
    nuevo->scr = NULL;
    string rslt;

    if (p == NULL)
    {
        p = nuevo;
        rslt = "Primer vertice insertado.";
    }
    else
    {
        t = p;

        if (t->nombre == nuevo->nombre) {
            rslt = "No se puede insertar. Vertice repetido";
            repetido = true;
        }
        else {
            while (t->sgte != NULL)
            {
                if (t->sgte->nombre == nuevo->nombre) {
                    rslt = "No se puede insertar. Vertice repetido";
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
            rslt = "Vertice ingresado correctamente";
        }

    }
    return rslt;
}

/*                      AGREGAR ARISTA
    funcion que utilizada para agregar la arista a dos nodos
---------------------------------------------------------------------*/
void GrafoMultiple::agrega_arista(TnodoMultiple& aux, TnodoMultiple& aux2, TaristaMultiple& nuevo)
{

    TaristaMultiple q;
    if (aux->scr == NULL)
    {
        aux->scr = nuevo;
        nuevo->destino = aux2;
        nuevo->sgte = NULL;
        cout << "Arco agregado.";
    }
    else
    {
        q = aux->scr;
        while (q->sgte != NULL)
            q = q->sgte;
        nuevo->destino = aux2;
        q->sgte = nuevo;
        nuevo->sgte = NULL;
        cout << "Arco agregado.";
    }

    if (aux2->pdr == NULL)
    {
        aux2->pdr = nuevo;
        nuevo->predecesor = aux;
        nuevo->sgte = NULL;
        cout << "Arco agregado.";
    }
    else
    {
        q = aux2->pdr;
        while (q->sgte != NULL)
            q = q->sgte;
        nuevo->predecesor = aux;
        q->sgte = nuevo;
        nuevo->sgte = NULL;
        cout << "Arco agregado.";
    }

}
/*                      INSERTAR ARISTA
    funcion que busca las posiciones de memoria de los nodos
    y hace llamado a agregar_arista para insertar la arista
---------------------------------------------------------------------*/
bool GrafoMultiple::insertar_arista(char ini, char fin, int pValor)
{
    TaristaMultiple nuevo = new struct aristaMultiple;
    TnodoMultiple aux, aux2;

    if (p == NULL)
    {
        return false;
    }
    nuevo->sgte = NULL;
    nuevo->valor = pValor;
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

/*                      MOSTRAR GRAFO
    funcion que imprime un grafo en su forma enlazada
---------------------------------------------------------------------*/
string GrafoMultiple::mostrar_grafo()
{
    TnodoMultiple ptr;
    TaristaMultiple ar;
    ptr = p;
    string rslt = "";
    rslt += " PREDECESORES | NODO  |  SUCESORES\n";

    while (ptr != NULL)
    {
      
        if (ptr->pdr != NULL)
        {
            ar = ptr->pdr;
            while (ar != NULL)
            {
                rslt += "  ";
                rslt += to_string(ar->valor);
                ar = ar->sgte;
            }

        }
        rslt += " | ";
        rslt += ptr->nombre;
        rslt += "(" + to_string(ptr->valor);
        rslt += ") |";
        if (ptr->scr != NULL)
        {
            ar = ptr->scr;
            while (ar != NULL)
            {
                rslt += "  ";
                rslt += to_string(ar->valor);
                ar = ar->sgte;
            }

        }
        ptr = ptr->sgte;
        rslt += "\n";
    }
    return rslt;
}

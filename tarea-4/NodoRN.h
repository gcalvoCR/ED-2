#pragma once
struct NodoRN
{
    int dato;       // dato
    NodoRN* padre;    // nodo padre
    NodoRN* der;      // hijo derecho
    NodoRN* izq;      // hijo izquierdo
    int color;     //0 o negro, 1 o rojo

};


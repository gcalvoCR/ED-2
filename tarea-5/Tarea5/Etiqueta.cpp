#include "Etiqueta.h"

#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>


Etiqueta::Etiqueta() {
    setDistancia(0);
    setMinutos(0);
}

Etiqueta::Etiqueta(int pDistancia, int pMinutos) {
    setDistancia(pDistancia);
    setMinutos(pMinutos);
}


int Etiqueta::getDistancia() {
    return distancia;
}

void Etiqueta::setDistancia(int pDistancia) {
    distancia = pDistancia;
}

int Etiqueta::getMinutos() {
    return minutos;
}

void Etiqueta::setMinutos(int pMinutos) {
    minutos = pMinutos;
}

string Etiqueta::toString() {
    ostringstream s;
    s << distancia << " metros y " << minutos << " minutos \n";
    return s.str();
}

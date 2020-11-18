#include "Etiqueta.h"

#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>


Etiqueta::Etiqueta() {
    setPeso(0);
}

Etiqueta::Etiqueta(int pPeso) {
    setPeso(pPeso);
}


int Etiqueta::getPeso() {
    return peso;
}

void Etiqueta::setPeso(int pPeso) {
    peso = pPeso;
}

string Etiqueta::toString() {
    ostringstream s;
    s << peso << " peso \n";
    return s.str();
}

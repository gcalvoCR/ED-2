#include "ArbolRN.h"
#include "ArbolRN.h"

void ArbolRN::inicializaNodoNULL(NodoRN* nodo, NodoRN* padre)
{
	nodo->dato = 0;
	nodo->padre = padre;
	nodo->izq = nullptr;
	nodo->der = nullptr;
	nodo->color = 0;
}

void ArbolRN::preOrdenHelper(NodoRN* nodo)
{
	if (nodo != TNULL) {
		cout << nodo->dato << " ";
		preOrdenHelper(nodo->izq);
		preOrdenHelper(nodo->der);
	}
}

void ArbolRN::inOrdenHelper(NodoRN* nodo)
{
	if (nodo != TNULL) {
		inOrdenHelper(nodo->izq);
		cout << nodo->dato << " ";
		inOrdenHelper(nodo->der);
	}
}

void ArbolRN::postOrdenHelper(NodoRN* nodo)
{
	if (nodo != TNULL) {
		postOrdenHelper(nodo->izq);
		postOrdenHelper(nodo->der);
		cout << nodo->dato << " ";
	}
}

NodoRN* ArbolRN::buscarArbolHelper(NodoRN* nodo, int key)
{
	if (nodo == TNULL || key == nodo->dato) {
		return nodo;
	}

	if (key < nodo->dato) {
		return buscarArbolHelper(nodo->izq, key);
	}
	return buscarArbolHelper(nodo->der, key);
}

void ArbolRN::arreglarBorrado(NodoRN* x)
{
	NodoRN* s;
	while (x != raiz && x->color == 0) {
		if (x == x->padre->izq) {
			s = x->padre->der;
			if (s->color == 1) {
				// caso 3.1
				s->color = 0;
				x->padre->color = 1;
				rotarIzq(x->padre);
				s = x->padre->der;
			}

			if (s->izq->color == 0 && s->der->color == 0) {
				// caso 3.2
				s->color = 1;
				x = x->padre;
			}
			else {
				if (s->der->color == 0) {
					// caso 3.3
					s->izq->color = 0;
					s->color = 1;
					rotarDer(s);
					s = x->padre->der;
				}

				// caso 3.4
				s->color = x->padre->color;
				x->padre->color = 0;
				s->der->color = 0;
				rotarIzq(x->padre);
				x = raiz;
			}
		}
		else {
			s = x->padre->izq;
			if (s->color == 1) {
				// caso 3.1
				s->color = 0;
				x->padre->color = 1;
				rotarDer(x->padre);
				s = x->padre->izq;
			}

			if (s->der->color == 0 && s->der->color == 0) {
				// caso 3.2
				s->color = 1;
				x = x->padre;
			}
			else {
				if (s->izq->color == 0) {
					// caso 3.3
					s->der->color = 0;
					s->color = 1;
					rotarIzq(s);
					s = x->padre->izq;
				}

				// caso 3.4
				s->color = x->padre->color;
				x->padre->color = 0;
				s->izq->color = 0;
				rotarDer(x->padre);
				x = raiz;
			}
		}
	}
	x->color = 0;
}

void ArbolRN::transplantarRN(NodoRN* u, NodoRN* v)
{
	if (u->padre == nullptr) {
		raiz = v;
	}
	else if (u == u->padre->izq) {
		u->padre->izq = v;
	}
	else {
		u->padre->der = v;
	}
	v->padre = u->padre;
}

bool ArbolRN::borrarNodoHelper(NodoRN* nodo, int key)
{
	// encuentra el nodo que contenga la llave --> key
	NodoRN* z = TNULL;
	NodoRN* x;
	NodoRN* y;
	while (nodo != TNULL) {
		if (nodo->dato == key) {
			z = nodo;
		}

		if (nodo->dato <= key) {
			nodo = nodo->der;
		}
		else {
			nodo = nodo->izq;
		}
	}

	if (z == TNULL) {
		cout << "Couldn't find key in the tree" << endl;
		return false;
	}

	y = z;

	int y_original_color = y->color;
	if (z->izq == TNULL) {
		x = z->der;
		transplantarRN(z, z->der);
	}
	else if (z->der == TNULL) {
		x = z->izq;
		transplantarRN(z, z->izq);
	}
	else {
		y = minimo(z->der);
		y_original_color = y->color;
		x = y->der;
		if (y->padre == z) {
			x->padre = y;
		}
		else {
			transplantarRN(y, y->der);
			y->der = z->der;
			y->der->padre = y;
		}

		transplantarRN(z, y);
		y->izq = z->izq;
		y->izq->padre = y;
		y->color = z->color;
	}
	delete z;
	if (y_original_color == 0) {
		arreglarBorrado(x);
	}

	return true;
}

void ArbolRN::arreglarInsercion(NodoRN* k)
{
	NodoRN* u;
	while (k->padre->color == 1) {
		if (k->padre == k->padre->padre->der) {
			u = k->padre->padre->izq; // tio
			if (u->color == 1) {
				// caso 3.1
				u->color = 0;
				k->padre->color = 0;
				k->padre->padre->color = 1;
				k = k->padre->padre;
			}
			else {
				if (k == k->padre->izq) {
					// caso 3.2.2
					k = k->padre;
					rotarDer(k);
				}
				// caso 3.2.1
				k->padre->color = 0;
				k->padre->padre->color = 1;
				rotarIzq(k->padre->padre);
			}
		}
		else {
			u = k->padre->padre->der; // tio

			if (u->color == 1) {
				// espejo de caso 3.1
				u->color = 0;
				k->padre->color = 0;
				k->padre->padre->color = 1;
				k = k->padre->padre;
			}
			else {
				if (k == k->padre->der) {
					// espejo de caso 3.2.2
					k = k->padre;
					rotarIzq(k);
				}
				// espejo de caso 3.2.1
				k->padre->color = 0;
				k->padre->padre->color = 1;
				rotarDer(k->padre->padre);
			}
		}
		if (k == raiz) {
			break;
		}
	}
	raiz->color = 0;
}

void ArbolRN::printHelper(NodoRN* raiz, string indent, bool last)
{
	// imprimir la estructura del arbol en pantalla
	if (raiz != TNULL) {
		cout << indent;
		if (last) {
			cout << "R----";
			indent += "     ";
		}
		else {
			cout << "L----";
			indent += "|    ";
		}

		string sColor = raiz->color ? "ROJO" : "NEGRO";
		cout << raiz->dato << "(" << sColor << ")" << endl;
		printHelper(raiz->izq, indent, false);
		printHelper(raiz->der, indent, true);
	}
	// cout<<raiz->izq->dato<<endl;
}

ArbolRN::ArbolRN()
{
	TNULL = new NodoRN();
	TNULL->color = 0;
	TNULL->izq = nullptr;
	TNULL->der = nullptr;
	raiz = TNULL;
}

void ArbolRN::preOrden()
{
	preOrdenHelper(this->raiz);
}

void ArbolRN::inOrden()
{
	inOrdenHelper(this->raiz);
}

void ArbolRN::postOrden()
{
	postOrdenHelper(this->raiz);
}

NodoRN* ArbolRN::buscarArbol(int k)
{
	return buscarArbolHelper(this->raiz, k);
}

NodoRN* ArbolRN::minimo(NodoRN* nodo)
{
	while (nodo->izq != TNULL) {
		nodo = nodo->izq;
	}
	return nodo;
}

NodoRN* ArbolRN::maximo(NodoRN* nodo)
{
	while (nodo->der != TNULL) {
		nodo = nodo->der;
	}
	return nodo;
}

NodoRN* ArbolRN::sucesor(NodoRN* x)
{
	// Si el subarbol derecho no es null
	// el sucesor es el nodo mas a la izquierda en el subarbol derecho
	if (x->der != TNULL) {
		return minimo(x->der);
	}

	// caso contrario es el ancestro menor de x, el cual su hijo izquierdo es tambien el ancestro de x
	NodoRN* y = x->padre;
	while (y != TNULL && x == y->der) {
		x = y;
		y = y->padre;
	}
	return y;
}

NodoRN* ArbolRN::predecesor(NodoRN* x)
{
	// Si el subarbol izquierdo no es null
	// el predecesor es el nodo mas a la derecha in el subarbol izquierdo
	if (x->izq != TNULL) {
		return maximo(x->izq);
	}

	NodoRN* y = x->padre;
	while (y != TNULL && x == y->izq) {
		x = y;
		y = y->padre;
	}

	return y;
}

void ArbolRN::rotarIzq(NodoRN* x)
{
	NodoRN* y = x->der;
	x->der = y->izq;
	if (y->izq != TNULL) {
		y->izq->padre = x;
	}
	y->padre = x->padre;
	if (x->padre == nullptr) {
		this->raiz = y;
	}
	else if (x == x->padre->izq) {
		x->padre->izq = y;
	}
	else {
		x->padre->der = y;
	}
	y->izq = x;
	x->padre = y;
}

void ArbolRN::rotarDer(NodoRN* x)
{
	NodoRN* y = x->izq;
	x->izq = y->der;
	if (y->der != TNULL) {
		y->der->padre = x;
	}
	y->padre = x->padre;
	if (x->padre == nullptr) {
		this->raiz = y;
	}
	else if (x == x->padre->der) {
		x->padre->der = y;
	}
	else {
		x->padre->izq = y;
	}
	y->der = x;
	x->padre = y;
}

bool ArbolRN::insertar(int key)
{
	// Insercion binaria ordinaria
	NodoRN* nodo = new NodoRN();
	nodo->padre = nullptr;
	nodo->dato = key;
	nodo->izq = TNULL;
	nodo->der = TNULL;
	nodo->color = 1; // todo nodo insertado tiene que ser rojo

	NodoRN* y = nullptr;
	NodoRN* x = this->raiz;

	while (x != TNULL) {
		y = x;
		if (nodo->dato == x->dato) {
			return false;
		}
		else {
			if (nodo->dato < x->dato) {
				x = x->izq;
			}
			else {
				x = x->der;
			}
		}
	}

	// y es padre de x
	nodo->padre = y;
	if (y == nullptr) {
		raiz = nodo;
	}
	else if (nodo->dato < y->dato) {
		y->izq = nodo;
	}
	else {
		y->der = nodo;
	}

	// si el nuevo nodo es la raiz, simplemente retorna
	if (nodo->padre == nullptr) {
		nodo->color = 0;
		return true;
	}

	// si el abuelo es null, simplemente retorna
	if (nodo->padre->padre == nullptr) {
		return true;
	}

	// Se llama a arreglar insercion
	arreglarInsercion(nodo);
	return true;
}

NodoRN* ArbolRN::getraiz()
{
	return this->raiz;
}

bool ArbolRN::borrarNodo(int dato)
{
	return borrarNodoHelper(this->raiz, dato);
}

void ArbolRN::prettyPrint()
{
	if (raiz) {
		printHelper(this->raiz, "", true);
	}
}


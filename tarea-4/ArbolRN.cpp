#include "ArbolRN.h"
#include "ArbolRN.h"

void ArbolRN::initializeNULLnodo(NodoRN* nodo, NodoRN* padre)
{
	nodo->dato = 0;
	nodo->padre = padre;
	nodo->izq = nullptr;
	nodo->der = nullptr;
	nodo->color = 0;
}

void ArbolRN::preOrderHelper(NodoRN* nodo)
{
	if (nodo != TNULL) {
		cout << nodo->dato << " ";
		preOrderHelper(nodo->izq);
		preOrderHelper(nodo->der);
	}
}

void ArbolRN::inOrderHelper(NodoRN* nodo)
{
	if (nodo != TNULL) {
		inOrderHelper(nodo->izq);
		cout << nodo->dato << " ";
		inOrderHelper(nodo->der);
	}
}

void ArbolRN::postOrderHelper(NodoRN* nodo)
{
	if (nodo != TNULL) {
		postOrderHelper(nodo->izq);
		postOrderHelper(nodo->der);
		cout << nodo->dato << " ";
	}
}

NodoRN* ArbolRN::searchTreeHelper(NodoRN* nodo, int key)
{
	if (nodo == TNULL || key == nodo->dato) {
		return nodo;
	}

	if (key < nodo->dato) {
		return searchTreeHelper(nodo->izq, key);
	}
	return searchTreeHelper(nodo->der, key);
}

void ArbolRN::fixDelete(NodoRN* x)
{
	NodoRN* s;
	while (x != raiz && x->color == 0) {
		if (x == x->padre->izq) {
			s = x->padre->der;
			if (s->color == 1) {
				// case 3.1
				s->color = 0;
				x->padre->color = 1;
				izqRotate(x->padre);
				s = x->padre->der;
			}

			if (s->izq->color == 0 && s->der->color == 0) {
				// case 3.2
				s->color = 1;
				x = x->padre;
			}
			else {
				if (s->der->color == 0) {
					// case 3.3
					s->izq->color = 0;
					s->color = 1;
					derRotate(s);
					s = x->padre->der;
				}

				// case 3.4
				s->color = x->padre->color;
				x->padre->color = 0;
				s->der->color = 0;
				izqRotate(x->padre);
				x = raiz;
			}
		}
		else {
			s = x->padre->izq;
			if (s->color == 1) {
				// case 3.1
				s->color = 0;
				x->padre->color = 1;
				derRotate(x->padre);
				s = x->padre->izq;
			}

			if (s->der->color == 0 && s->der->color == 0) {
				// case 3.2
				s->color = 1;
				x = x->padre;
			}
			else {
				if (s->izq->color == 0) {
					// case 3.3
					s->der->color = 0;
					s->color = 1;
					izqRotate(s);
					s = x->padre->izq;
				}

				// case 3.4
				s->color = x->padre->color;
				x->padre->color = 0;
				s->izq->color = 0;
				derRotate(x->padre);
				x = raiz;
			}
		}
	}
	x->color = 0;
}

void ArbolRN::rbTransplant(NodoRN* u, NodoRN* v)
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

void ArbolRN::deletenodoHelper(NodoRN* nodo, int key)
{
	// find the nodo containing key
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
		return;
	}

	y = z;

	int y_original_color = y->color;
	if (z->izq == TNULL) {
		x = z->der;
		rbTransplant(z, z->der);
	}
	else if (z->der == TNULL) {
		x = z->izq;
		rbTransplant(z, z->izq);
	}
	else {
		y = minimum(z->der);
		y_original_color = y->color;
		x = y->der;
		if (y->padre == z) {
			x->padre = y;
		}
		else {
			rbTransplant(y, y->der);
			y->der = z->der;
			y->der->padre = y;
		}

		rbTransplant(z, y);
		y->izq = z->izq;
		y->izq->padre = y;
		y->color = z->color;
	}
	delete z;
	if (y_original_color == 0) {
		fixDelete(x);
	}
}

void ArbolRN::fixInsert(NodoRN* k)
{
	NodoRN* u;
	while (k->padre->color == 1) {
		if (k->padre == k->padre->padre->der) {
			u = k->padre->padre->izq; // uncle
			if (u->color == 1) {
				// case 3.1
				u->color = 0;
				k->padre->color = 0;
				k->padre->padre->color = 1;
				k = k->padre->padre;
			}
			else {
				if (k == k->padre->izq) {
					// case 3.2.2
					k = k->padre;
					derRotate(k);
				}
				// case 3.2.1
				k->padre->color = 0;
				k->padre->padre->color = 1;
				izqRotate(k->padre->padre);
			}
		}
		else {
			u = k->padre->padre->der; // uncle

			if (u->color == 1) {
				// mirror case 3.1
				u->color = 0;
				k->padre->color = 0;
				k->padre->padre->color = 1;
				k = k->padre->padre;
			}
			else {
				if (k == k->padre->der) {
					// mirror case 3.2.2
					k = k->padre;
					izqRotate(k);
				}
				// mirror case 3.2.1
				k->padre->color = 0;
				k->padre->padre->color = 1;
				derRotate(k->padre->padre);
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
	// print the tree structure on the screen
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
	preOrderHelper(this->raiz);
}

void ArbolRN::inOrden()
{
	inOrderHelper(this->raiz);
}

void ArbolRN::postOrden()
{
	postOrderHelper(this->raiz);
}

NodoRN* ArbolRN::buscarArbol(int k)
{
	return searchTreeHelper(this->raiz, k);
}

NodoRN* ArbolRN::minimum(NodoRN* nodo)
{
	while (nodo->izq != TNULL) {
		nodo = nodo->izq;
	}
	return nodo;
}

NodoRN* ArbolRN::maximum(NodoRN* nodo)
{
	while (nodo->der != TNULL) {
		nodo = nodo->der;
	}
	return nodo;
}

NodoRN* ArbolRN::successor(NodoRN* x)
{
	// if the der subtree is not null,
	// the successor is the izqmost nodo in the
	// der subtree
	if (x->der != TNULL) {
		return minimum(x->der);
	}

	// else it is the lowest ancestor of x whose
	// izq child is also an ancestor of x.
	NodoRN* y = x->padre;
	while (y != TNULL && x == y->der) {
		x = y;
		y = y->padre;
	}
	return y;
}

NodoRN* ArbolRN::predecessor(NodoRN* x)
{
	// if the izq subtree is not null,
	// the predecessor is the dermost nodo in the 
	// izq subtree
	if (x->izq != TNULL) {
		return maximum(x->izq);
	}

	NodoRN* y = x->padre;
	while (y != TNULL && x == y->izq) {
		x = y;
		y = y->padre;
	}

	return y;
}

void ArbolRN::izqRotate(NodoRN* x)
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

void ArbolRN::derRotate(NodoRN* x)
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

void ArbolRN::insert(int key)
{
	// Ordinary Binary Search Insertion
	NodoRN* nodo = new NodoRN();
	nodo->padre = nullptr;
	nodo->dato = key;
	nodo->izq = TNULL;
	nodo->der = TNULL;
	nodo->color = 1; // new nodo must be red

	NodoRN* y = nullptr;
	NodoRN* x = this->raiz;

	while (x != TNULL) {
		y = x;
		if (nodo->dato < x->dato) {
			x = x->izq;
		}
		else {
			x = x->der;
		}
	}

	// y is padre of x
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

	// if new nodo is a raiz nodo, simply return
	if (nodo->padre == nullptr) {
		nodo->color = 0;
		return;
	}

	// if the grandpadre is null, simply return
	if (nodo->padre->padre == nullptr) {
		return;
	}

	// Fix the tree
	fixInsert(nodo);
}

NodoRN* ArbolRN::getraiz()
{
	return this->raiz;
}

void ArbolRN::deleteNodo(int dato)
{
	deletenodoHelper(this->raiz, dato);
}

void ArbolRN::prettyPrint()
{
	if (raiz) {
		printHelper(this->raiz, "", true);
	}
}


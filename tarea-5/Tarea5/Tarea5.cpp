//A.Programar la simulación de dos grafos(solamente agregar y mostrar).
//
//1. Primer grafo : Este se debe realizar mediante una matriz de adyacencia en la cual se agregarán 8 vertices y arcos según lo decida el usuario.
//
//2. Segundo grafo : Este se debe realizar mediante una lista de adyacencia en la cual se agregarán los vertices y arcos según lo decida el usuario.
//
//B.Programar la simulación de una lista encadenada múltiple de adyacencia(solamente agregar y mostrar)

#include <cstdlib>

#include "Controller.h"

static Controller* controller = new Controller();
//Metodos de menus
int menuPrincipal(int answer);
void menuGrafoMatriz();
int menuGrafoMatrizImp(int answer);
void menuGrafoLista();
int menuGrafoListaImp(int answer);
//Metodos de matriz de adyacencia
void insertarVertice();
void mostrarVertices();
void insertarArco();
void mostrarEtiquetas();
//Metodos lista de adyacencia
void insertarNodoSegundoGrafo();
void insertarAristaSegundoGrafo();
void eliminarNodoSegundoGrafo();
void eliminarAristaSegundoGrafo();
void mostrarGrafoSegundoGrafo();
void mostrarAristasSegundoGrafo();
bool verificarExistenciaNodoSegundoGrafo(char);
//Metodos lista multiple
void menuGrafoListaMultiple();
int menuGrafoListaMultipleImp(int answer);
void insertarNodoListaMultiple();
void insertarAristaListaMultiple();
void mostrarListaMultiple();

using namespace std;

int main()
{
    int answer;
    bool keepLooping = true;

    system("CLS");
    do
    {
        cout << "-------------------------------------" << endl;
        cout << "Favor digite una opcion:" << endl;
        cout << "1. Primer grafo: matriz de adyacencia." << endl;
        cout << "2. Segundo grafo: lista de adyacencia." << endl;
        cout << "3. Lista encadenada multiple de adyacencia." << endl;
        cout << "0. Salir del sistema." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;
        system("CLS");

        keepLooping = menuPrincipal(answer);

        if (answer == 0)
        {
            keepLooping = false;
        }
        else
        {
            keepLooping = true;
        }
    } while (keepLooping);

}

//MENÚ PRINCIPAL
int menuPrincipal(int answer)
{
    switch (answer)
    {
    case 1:
        menuGrafoMatriz();
        break;
    case 2:
        menuGrafoLista();
        break;
    case 3:
        menuGrafoListaMultiple();
        break;
    case 0:
        cout << "Gracias por usar el sistema." << endl;
        break;
    default:
        cout << "Opcion incorrecta. Favor digite de nuevo." << endl;
    }
    return answer;
}

//1. Menú para grafo con matriz de adyacencia
void menuGrafoMatriz()
{
    int answer;
    bool keepLooping = true;

    system("CLS");
    do
    {
        system("CLS");
        cout << "-------------------------------------" << endl;
        cout << "Ejercicio usando matrices de adyacencia" << endl;
        cout << "-------------------------------------" << endl;
        cout << " " << endl;
        cout << "Favor digite la opcion que desea insertar:" << endl;
        cout << "1. Insertar vertices (8 numeros positivos)" << endl;
        cout << "2. Mostrar vertices" << endl;
        cout << "3. Insertar informacion de arco (peso) " << endl;
        cout << "4. Mostrar informacion de arcos (pesos)" << endl;
        cout << "5. Volver al menu principal." << endl;
        cout << "------------------------------------------------" << endl;
        cin >> answer;
        system("CLS");

        menuGrafoMatrizImp(answer);

        if (answer == 7)
        {
            keepLooping = false;
        }
        else
        {
            keepLooping = true;
        }
    } while (keepLooping);
}

int menuGrafoMatrizImp(int answer)
{
    switch (answer) {
    case 1:
        insertarVertice();
        system("PAUSE");
        break;
    case 2:
        mostrarVertices();
        system("PAUSE");
        break;
    case 3:
        insertarArco();
        system("PAUSE");
        break;
    case 4:
        mostrarEtiquetas();
        system("PAUSE");
        break;
    case 5:
        main();
        break;
    default:
        cout << "OPCION INVALIDA";
    }

    return answer;
}

void insertarVertice() {
    int numero;

    for (int i = 0; i < 8; i++) {
        bool bandera = true;
        do {
            cout << "Digitar numero #" << i << ": ";
            cin >> numero;
            if (controller->insertarVerticeEnArreglo(i, numero)) {
                cout << "Numero agregado\n";
                bandera = false;
            }
            else {
                cout << "El numero ya existe, agregar otro\n";
            }
        } while (bandera);

    }
}

void mostrarVertices() {
    cout << controller->mostrarVertices();
}

void insertarArco() {
    int numero, numero2, peso;
    cout << "Digitar el 1er numero: ";
    cin >> numero;
    cout << "Digitar el 2ndo numero: ";
    cin >> numero2;
    cout << "Peso entre el 1er y 2ndo numero: ";
    cin >> peso;
    cout << controller->agregarArcoEnMatriz(controller->buscarVertice(numero), controller->buscarVertice(numero2), peso);

}

void mostrarEtiquetas() {
    cout << controller->mostrarEtiquetas();
}

//2. Menú para grafo con lista de adyacencia

void menuGrafoLista()
{
    int answer;
    bool keepLooping = true;

    system("CLS");
    do
    {
        system("CLS");
        cout << "-------------------------------------" << endl;
        cout << "Grafos dirigidos: lista de adyacencia" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Favor digite una opcion:" << endl;
        cout << "1. Insertar un nuevo vertice." << endl;
        cout << "2. Insertar un arco." << endl;
        cout << "3. Eliminar un vertice." << endl;
        cout << "4. Eliminar un arco." << endl;
        cout << "5. Mostrar grafo." << endl;
        cout << "6. Mostrar arcos de un vertice." << endl;
        cout << "7. Volver al menu principal." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;
        system("CLS");

        menuGrafoListaImp(answer);

        if (answer == 7)
        {
            keepLooping = false;
        }
        else
        {
            keepLooping = true;
        }
    } while (keepLooping);
}

int menuGrafoListaImp(int answer)
{
    switch (answer)
    {
    case 1:
        insertarNodoSegundoGrafo();
        system("PAUSE");
        break;
    case 2:
        insertarAristaSegundoGrafo();
        system("PAUSE");
        break;
    case 3:
        eliminarNodoSegundoGrafo();
        system("PAUSE");
        break;
    case 4:
        eliminarAristaSegundoGrafo();
        system("PAUSE");
        break;
    case 5:
        mostrarGrafoSegundoGrafo();
        system("PAUSE");
        break;
    case 6:
        mostrarAristasSegundoGrafo();
        system("PAUSE");
        break;
    case 7:
        main();
        break;
    default:
        cout << "Opcion incorrecta. Favor digite de nuevo." << endl;
    }

    return answer;
}

void insertarNodoSegundoGrafo() {
    char input;
    cout << "Favor insertar vertice a agregar: " << flush;
    cin >> input;
    cout << controller->insertar_nodo_segundoGrafo(input) << endl;
}

void insertarAristaSegundoGrafo() {
    if (!controller->verificarSegundoGrafoVacio()) {
        cout << controller->imprimir_nodos_segundoGrafo() << endl;
        char ini, fin;
        do
        {
            cout << "Ingrese vertice de inicio de la lista de vertices:";
            cin >> ini;
        } while (!verificarExistenciaNodoSegundoGrafo(ini));

        do
        {
            cout << "Ingrese vertice de final de la lista de vertices:";
            cin >> fin;
        } while (!verificarExistenciaNodoSegundoGrafo(fin));
        cout << controller->insertar_arista_segundoGrafo(ini, fin) << endl;
    }
    else {
        cout << "Grafo vacio. No se puede insertar arcos." << endl;
    }
}

void eliminarNodoSegundoGrafo() {
    if (!controller->verificarSegundoGrafoVacio()) {
        cout << controller->imprimir_nodos_segundoGrafo() << endl;
        char input;
        do
        {
            cout << "Favor insertar vertice a eliminar: " << flush;
            cin >> input;
        } while (!verificarExistenciaNodoSegundoGrafo(input));
        cout << controller->eliminar_nodo_segundoGrafo(input) << endl;
    }
    else {
        cout << "Grafo vacio. No se puede eliminar vertices." << endl;
    }

}

void eliminarAristaSegundoGrafo() {
    if (!controller->verificarSegundoGrafoVacio()) {
        cout << controller->imprimir_nodos_segundoGrafo() << endl;
        char ini, fin;
        do
        {
            cout << "Ingrese vertice de inicio de la lista de vertices:";
            cin >> ini;
        } while (!verificarExistenciaNodoSegundoGrafo(ini));

        do
        {
            cout << "Ingrese vertice de final de la lista de vertices:";
            cin >> fin;
        } while (!verificarExistenciaNodoSegundoGrafo(fin));

        cout << controller->eliminar_arista_segundoGrafo(ini, fin) << endl;
    }
    else {
        cout << "Grafo vacio. No se puede eliminar arcos." << endl;
    }

}

void mostrarGrafoSegundoGrafo() {
    if (!controller->verificarSegundoGrafoVacio()) {
        cout << controller->mostrar_grafo_segundoGrafo() << endl;
    }
    else {
        cout << "Grafo vacio." << endl;
    }
}

void mostrarAristasSegundoGrafo() {
    if (!controller->verificarSegundoGrafoVacio()) {
        cout << controller->imprimir_nodos_segundoGrafo() << endl;
        char input;
        do
        {
            cout << "Mostrar arcos de vertice: " << flush;
            cin >> input;
        } while (!verificarExistenciaNodoSegundoGrafo(input));

        cout << controller->mostrar_aristas_segundoGrafo(input) << endl;
    }
    else {
        cout << "Grafo vacio. No se puede mostrar arcos." << endl;
    }
}

bool verificarExistenciaNodoSegundoGrafo(char pVar) {
    bool cond = controller->verificarExistenciaNodoSegundoGrafo(pVar);
    return cond;
}

//3. Menú para lista de adyacencia multiple

void menuGrafoListaMultiple()
{
    int answer;
    bool keepLooping = true;

    system("CLS");
    do
    {
        system("CLS");
        cout << "-------------------------------------" << endl;
        cout << "Lista encadenada multiple de adyacencia" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Favor digite una opcion:" << endl;
        cout << "1. Insertar un nuevo vertice." << endl;
        cout << "2. Insertar un arco." << endl;
        cout << "3. Mostrar grafo." << endl;
        cout << "4. Volver al menu principal." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;
        system("CLS");

        menuGrafoListaMultipleImp(answer);

        if (answer == 7)
        {
            keepLooping = false;
        }
        else
        {
            keepLooping = true;
        }
    } while (keepLooping);
}

int menuGrafoListaMultipleImp(int answer)
{
    switch (answer)
    {
    case 1:
        insertarNodoListaMultiple();
        system("PAUSE");
        break;
    case 2:
        insertarAristaListaMultiple();
        system("PAUSE");
        break;
    case 3:
        mostrarListaMultiple();
        system("PAUSE");
        break;
    case 4:
        main();
        break;
    default:
        cout << "Opcion incorrecta. Favor digite de nuevo." << endl;
    }

    return answer;
}

void insertarNodoListaMultiple() {
    char nombreNodo;
    int valorNodo;
    cout << "Favor insertar nombre de nodo: " << flush;
    cin >> nombreNodo;
    cout << "Favor valor de nodo a agregar: " << flush;
    cin >> valorNodo;
    cout << controller->insertar_nodo_multiple(nombreNodo, valorNodo) << endl;
}

void insertarAristaListaMultiple() {
   
    char ini, fin;
    int valorArco;
    cout << "Ingrese nodo de inicio de la lista de vertices:";
    cin >> ini;
    cout << "Ingrese nodo de final de la lista de vertices:";
    cin >> fin;
    cout << "Ingrese valor del arco:";
    cin >> valorArco;
        
    cout << controller->insertar_arista_multiple(ini, fin, valorArco) << endl;
  
}

void mostrarListaMultiple() {
 
    cout << controller->mostrar_grafo_multiple() << endl;
    
}
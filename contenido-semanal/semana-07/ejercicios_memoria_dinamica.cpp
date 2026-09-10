// ============================================================
// SEMANA 07 - Memoria Dinamica
// ============================================================
// ENUNCIADOS
// ------------------------------------------------------------
// Ejercicio 1 - Arreglo unidimensional dinamico:
//    Solicite al usuario el tamanio de un arreglo, asigne la
//    memoria con new int[] y llene los valores por consola.
//    Calcule el promedio y libere la memoria con delete[].
//
// Ejercicio 2 - Matriz dinamica (arreglo multidimensional):
//    Solicite el numero de filas y columnas, asigne una matriz
//    con new int*[filas] y new int[columnas] para cada fila.
//    Llene la matriz, calcule la suma de todos sus elementos y
//    libere la memoria en orden inverso (delete[] filas y luego
//    delete[] matriz).
//
// Ejercicio 3 - Apuntador a estructura:
//    Defina una estructura Alumno con nombre (char[30]) y nota
//    (float). Asigne un objeto alumno con new, solicite sus
//    datos mediante el apuntador (operador ->), muestrelos y
//    libere la memoria con delete.
//
// Ejercicio 4 - Encadenamiento de estructuras (lista enlazada):
//    Defina un Nodo que contenga un dato entero y un apuntador
//    al siguiente nodo (Nodo* siguiente). Cree una lista
//    enlazada simple con 3 nodos usando new, recorrala para
//    imprimir sus valores y libere la memoria de cada nodo
//    con delete.
// ============================================================

#include <iostream>
#include <cstring>
using namespace std;

// Estructuras usadas en los ejercicios 3 y 4
struct Alumno {
    char nombre[30];
    float nota;
};

struct Nodo {
    int dato;
    Nodo* siguiente;
};

// ============================================================
// EJERCICIO 1 - Arreglo unidimensional dinamico
// ============================================================
void ejercicio1() {
    int tamanio;

    cout << "Ejercicio 1 - Arreglo unidimensional dinamico:" << endl;
    cout << "Ingrese el tamanio del arreglo: ";
    cin >> tamanio;

    int* arreglo = new int[tamanio]; // Asignacion de memoria dinamica

    for (int i = 0; i < tamanio; i++) {
        cout << "Valor " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    int suma = 0;
    for (int i = 0; i < tamanio; i++) {
        suma = suma + arreglo[i];
    }

    cout << "Suma: " << suma << endl;
    cout << "Promedio: " << (float)suma / tamanio << endl;

    delete[] arreglo; // Liberacion de memoria
    cout << endl;
}

// ============================================================
// EJERCICIO 2 - Matriz dinamica
// ============================================================
void ejercicio2() {
    int filas, columnas;

    cout << "Ejercicio 2 - Matriz dinamica:" << endl;
    cout << "Ingrese el numero de filas: ";
    cin >> filas;
    cout << "Ingrese el numero de columnas: ";
    cin >> columnas;

    // Se asigna el arreglo de apuntadores a filas
    int** matriz = new int*[filas];

    // Se asigna cada fila
    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Valor [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    int suma = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            suma = suma + matriz[i][j];
        }
    }

    cout << "La suma de todos los elementos es: " << suma << endl;

    // Liberacion de memoria en orden inverso
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
    cout << endl;
}

// ============================================================
// EJERCICIO 3 - Apuntador a estructura
// ============================================================
void ejercicio3() {
    Alumno* alumno = new Alumno; // Asignacion de una estructura con new

    cout << "Ejercicio 3 - Apuntador a estructura:" << endl;
    cout << "Ingrese el nombre: ";
    cin >> alumno->nombre;
    cout << "Ingrese la nota: ";
    cin >> alumno->nota;

    // Acceso a los campos con el operador ->
    cout << "Alumno: " << alumno->nombre << " | Nota: " << alumno->nota << endl;

    delete alumno; // Liberacion de memoria
    cout << endl;
}

// ============================================================
// EJERCICIO 4 - Encadenamiento de estructuras (lista enlazada)
// ============================================================
void ejercicio4() {
    cout << "Ejercicio 4 - Encadenamiento de estructuras (lista enlazada):" << endl;

    // Creacion de los nodos de la lista
    Nodo* nodo1 = new Nodo;
    Nodo* nodo2 = new Nodo;
    Nodo* nodo3 = new Nodo;

    nodo1->dato = 10;
    nodo1->siguiente = nodo2;

    nodo2->dato = 20;
    nodo2->siguiente = nodo3;

    nodo3->dato = 30;
    nodo3->siguiente = nullptr; // Fin de la lista

    // Recorrido de la lista para imprimir los valores
    Nodo* actual = nodo1;
    cout << "Valores de la lista: ";
    while (actual != nullptr) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;

    // Liberacion de memoria de cada nodo
    actual = nodo1;
    while (actual != nullptr) {
        Nodo* aBorrar = actual;
        actual = actual->siguiente;
        delete aBorrar;
    }
    cout << endl;
}

// ============================================================
// MAIN
// ============================================================
int main() {
    ejercicio1();
    ejercicio2();
    ejercicio3();
    ejercicio4();

    return 0;
}
#include <iostream>
using namespace std;


// ============================================================
// EJERCICIO 1 — Acceso mediante punteros
// ============================================================

void ejercicio1() {
    int numero = 10;
    int* puntero = &numero;

    cout << "Ejercicio 1:" << endl;
    cout << "Valor original: " << *puntero << endl;

    *puntero = 25;

    cout << "Valor modificado: " << *puntero << endl;
}


// ============================================================
// EJERCICIO 2 — Recorrer un arreglo con punteros
// ============================================================

void ejercicio2() {
    int numeros[5] = {10, 20, 30, 40, 50};

    int* puntero = numeros;

    cout << "\nEjercicio 2:" << endl;

    for (int i = 0; i < 5; i++) {
        cout << *puntero << endl;
        puntero++;
    }
}


// ============================================================
// EJERCICIO 3 — Intercambio de dos variables
// ============================================================

void intercambiar(int* a, int* b) {
    int temporal = *a;
    *a = *b;
    *b = temporal;
}


void ejercicio3() {
    int numero1 = 10;
    int numero2 = 20;

    cout << "\nEjercicio 3:" << endl;

    cout << "Antes del intercambio:" << endl;
    cout << "Numero 1: " << numero1 << endl;
    cout << "Numero 2: " << numero2 << endl;

    intercambiar(&numero1, &numero2);

    cout << "\nDespues del intercambio:" << endl;
    cout << "Numero 1: " << numero1 << endl;
    cout << "Numero 2: " << numero2 << endl;
}


// ============================================================
// EJERCICIO 4 — Mayor elemento de un arreglo
// ============================================================

int mayor(int* arreglo, int tamanio) {
    int mayorValor = *arreglo;

    for (int i = 1; i < tamanio; i++) {
        arreglo++;

        if (*arreglo > mayorValor) {
            mayorValor = *arreglo;
        }
    }

    return mayorValor;
}


void ejercicio4() {
    int numeros[6] = {15, 8, 42, 23, 7, 31};

    int resultado = mayor(numeros, 6);

    cout << "\nEjercicio 4:" << endl;
    cout << "El numero mayor es: " << resultado << endl;
}


// ============================================================
// EJERCICIO 5 — Memoria dinámica
// ============================================================

void ejercicio5() {
    int tamanio;

    cout << "\nEjercicio 5:" << endl;

    cout << "Ingrese el tamanio del arreglo: ";
    cin >> tamanio;

    int* arreglo = new int[tamanio];

    cout << "\nIngrese los valores:" << endl;

    for (int i = 0; i < tamanio; i++) {
        cout << "Valor " << i + 1 << ": ";
        cin >> *(arreglo + i);
    }

    int suma = 0;

    for (int i = 0; i < tamanio; i++) {
        suma = suma + *(arreglo + i);
    }

    float promedio = (float)suma / tamanio;

    cout << "\nPromedio: " << promedio << endl;

    delete[] arreglo;
}


// ============================================================
// MAIN
// ============================================================

int main() {

    ejercicio1();
    ejercicio2();
    ejercicio3();
    ejercicio4();
    ejercicio5();

    return 0;
}
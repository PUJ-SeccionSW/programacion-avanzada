// ============================================================
// SEMANA 05 - Apuntadores
// ============================================================
// ENUNCIADOS
// ------------------------------------------------------------
// Ejercicio 1 - Declaracion, inicializacion y acceso:
//    Declare una variable int, un apuntador a int e
//    inicialicelo con la direccion de la variable. Muestre el
//    valor de la variable, su direccion (&variable) y el valor
//    almacenado en el apuntador. Luego modifique el valor de
//    la variable a traves del apuntador (desreferenciacion)
//    y muestrelo de nuevo.
//
// Ejercicio 2 - Aritmetica de apuntadores:
//    Con un arreglo de enteros de 5 posiciones, recorra el
//    arreglo usando un apuntador con incrementos (puntero++)
//    y muestre cada valor y su direccion de memoria.
//
// Ejercicio 3 - Paso de parametros por referencia:
//    Realice una funcion que intercambie dos enteros usando
//    apuntadores como parametros. Muestre los valores antes y
//    despues del intercambio.
//
// Ejercicio 4 - Apuntador a apuntador:
//    Declare una variable int, un apuntador int* y un apuntador
//    a apuntador int**. Muestre el valor de la variable
//    desreferenciando p1 (*p1) y p2 (**p2), y modifiquelo a
//    traves de **p2.
//
// Ejercicio 5 - Arreglos y apuntadores:
//    Implemente una funcion que reciba un arreglo de enteros y
//    su tamanio mediante apuntadores y devuelva el mayor
//    elemento. Pruebela con un arreglo ingresado por el
//    usuario.
// ============================================================

#include <iostream>
using namespace std;

// ============================================================
// EJERCICIO 1 - Declaracion, inicializacion y acceso
// ============================================================
void ejercicio1() {
    int numero = 10;
    int* puntero = &numero;

    cout << "Ejercicio 1 - Declaracion, inicializacion y acceso:" << endl;
    cout << "Valor de la variable: " << numero << endl;
    cout << "Direccion de la variable (&numero): " << &numero << endl;
    cout << "Valor del apuntador (direccion): " << puntero << endl;
    cout << "Valor desreferenciado (*puntero): " << *puntero << endl;

    *puntero = 25; // Modificar la variable a traves del apuntador
    cout << "Nuevo valor de la variable: " << numero << endl;
    cout << endl;
}

// ============================================================
// EJERCICIO 2 - Aritmetica de apuntadores
// ============================================================
void ejercicio2() {
    int numeros[5] = {10, 20, 30, 40, 50};
    int* puntero = numeros;

    cout << "Ejercicio 2 - Aritmetica de apuntadores:" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "numeros[" << i << "] = " << *puntero
             << " | direccion: " << puntero << endl;
        puntero++; // Avanza al siguiente elemento del arreglo
    }

    cout << endl;
}

// ============================================================
// EJERCICIO 3 - Paso de parametros por referencia
// ============================================================
void intercambiar(int* a, int* b) {
    int temporal = *a;
    *a = *b;
    *b = temporal;
}

void ejercicio3() {
    int valor1 = 7;
    int valor2 = 15;

    cout << "Ejercicio 3 - Paso de parametros por referencia:" << endl;
    cout << "Antes: valor1 = " << valor1 << ", valor2 = " << valor2 << endl;

    intercambiar(&valor1, &valor2);

    cout << "Despues: valor1 = " << valor1 << ", valor2 = " << valor2 << endl;
    cout << endl;
}

// ============================================================
// EJERCICIO 4 - Apuntador a apuntador
// ============================================================
void ejercicio4() {
    int numero = 100;
    int* puntero = &numero;
    int** puntero2 = &puntero;

    cout << "Ejercicio 4 - Apuntador a apuntador:" << endl;
    cout << "Valor mediante *puntero: " << *puntero << endl;
    cout << "Valor mediante **puntero2: " << **puntero2 << endl;

    **puntero2 = 500; // Modifica la variable a traves del apuntador a apuntador
    cout << "Nuevo valor de la variable: " << numero << endl;
    cout << endl;
}

// ============================================================
// EJERCICIO 5 - Arreglos y apuntadores
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

void ejercicio5() {
    const int tamanio = 5;
    int numeros[tamanio];

    cout << "Ejercicio 5 - Arreglos y apuntadores:" << endl;

    for (int i = 0; i < tamanio; i++) {
        cout << "Ingrese el valor " << i + 1 << ": ";
        cin >> numeros[i];
    }

    cout << "El mayor elemento es: " << mayor(numeros, tamanio) << endl;
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
    ejercicio5();

    return 0;
}
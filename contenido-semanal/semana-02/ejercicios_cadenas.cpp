// ============================================================
// SEMANA 02 - Cadenas de Caracteres de tipo char[]
// ============================================================
// ENUNCIADOS
// ------------------------------------------------------------
// Ejercicio 1 - Longitud de una cadena:
//    Lea una palabra en una variable de tipo char[] y calcule
//    su longitud recorriendo la cadena caracter por caracter
//    hasta encontrar el caracter nulo '\0', sin usar strlen().
//
// Ejercicio 2 - Copia de cadenas:
//    Copie manualmente el contenido de una cadena char[] hacia
//    otra variable char[] caracter por caracter (incluya el
//    '\0'). Compare el resultado con la funcion strcpy() de la
//    biblioteca <cstring>.
//
// Ejercicio 3 - Comparacion de cadenas:
//    Compare dos cadenas char[] caracter por caracter y diga
//    si son iguales, o cual es mayor alfabeticamente. Use
//    tambien la funcion strcmp() y muestre su resultado.
//
// Ejercicio 4 - Concatenacion:
//    Una dos cadenas char[] en una tercera variable. Imprima
//    el resultado manualmente y luego con strcat().
//
// Ejercicio 5 - Invertir una cadena:
//    Lea una palabra en un arreglo char[] e imprimala al
//    reves, intercambiando sus caracteres de los extremos
//    hacia el centro.
//
// Ejercicio 6 - Nombre completo con getline:
//    Ingrese el nombre completo de una persona (puede tener
//    espacios) usando cin.getline() y luego cuente cuantas
//    vocales contiene.
// ============================================================

#include <iostream>
#include <cstring>
using namespace std;

// ============================================================
// EJERCICIO 1 - Longitud de una cadena (sin strlen)
// ============================================================
void ejercicio1() {
    char palabra[50];

    cout << "Ejercicio 1 - Longitud de una cadena:" << endl;
    cout << "Ingrese una palabra: ";
    cin >> palabra;

    int longitud = 0;
    while (palabra[longitud] != '\0') {
        longitud++;
    }

    cout << "La palabra '" << palabra << "' tiene " << longitud << " caracteres." << endl;
    cout << endl;
}

// ============================================================
// EJERCICIO 2 - Copia de cadenas
// ============================================================
void ejercicio2() {
    char origen[] = "hola mundo";
    char copiaManual[50];
    char copiaConStrcpy[50];

    cout << "Ejercicio 2 - Copia de cadenas:" << endl;

    // Copia manual caracter por caracter
    int i = 0;
    while (origen[i] != '\0') {
        copiaManual[i] = origen[i];
        i++;
    }
    copiaManual[i] = '\0';

    // Copia con la funcion de la biblioteca
    strcpy(copiaConStrcpy, origen);

    cout << "Original: " << origen << endl;
    cout << "Copia manual: " << copiaManual << endl;
    cout << "Copia con strcpy(): " << copiaConStrcpy << endl;
    cout << endl;
}

// ============================================================
// EJERCICIO 3 - Comparacion de cadenas
// ============================================================
void ejercicio3() {
    char cadena1[50];
    char cadena2[50];

    cout << "Ejercicio 3 - Comparacion de cadenas:" << endl;
    cout << "Ingrese la primera cadena: ";
    cin >> cadena1;
    cout << "Ingrese la segunda cadena: ";
    cin >> cadena2;

    // Comparacion manual caracter por caracter
    bool iguales = true;
    for (int j = 0; cadena1[j] != '\0' || cadena2[j] != '\0'; j++) {
        if (cadena1[j] != cadena2[j]) {
            iguales = false;
            break;
        }
    }

    if (iguales) {
        cout << "Manual: las cadenas son iguales." << endl;
    } else {
        cout << "Manual: las cadenas son diferentes." << endl;
    }

    // Comparacion con strcmp() (0 = iguales, <0 si cadena1 es menor, >0 si es mayor)
    int resultado = strcmp(cadena1, cadena2);
    cout << "Con strcmp(): " << resultado << " (0 iguales, <0 menor, >0 mayor)" << endl;
    cout << endl;
}

// ============================================================
// EJERCICIO 4 - Concatenacion
// ============================================================
void ejercicio4() {
    char primera[50];
    char segunda[50];
    char manual[100];
    char conStrcat[100];

    cout << "Ejercicio 4 - Concatenacion:" << endl;
    cout << "Ingrese la primera cadena: ";
    cin >> primera;
    cout << "Ingrese la segunda cadena: ";
    cin >> segunda;

    // Concatenacion manual
    int pos = 0;
    int k = 0;
    while (primera[k] != '\0') {
        manual[pos] = primera[k];
        pos++;
        k++;
    }
    k = 0;
    while (segunda[k] != '\0') {
        manual[pos] = segunda[k];
        pos++;
        k++;
    }
    manual[pos] = '\0';

    // Concatenacion con strcat()
    strcpy(conStrcat, primera);
    strcat(conStrcat, segunda);

    cout << "Manual: " << manual << endl;
    cout << "Con strcat(): " << conStrcat << endl;
    cout << endl;
}

// ============================================================
// EJERCICIO 5 - Invertir una cadena
// ============================================================
void ejercicio5() {
    char palabra[50];

    cout << "Ejercicio 5 - Invertir una cadena:" << endl;
    cout << "Ingrese una palabra: ";
    cin >> palabra;

    int longitud = strlen(palabra);

    for (int izq = 0, der = longitud - 1; izq < der; izq++, der--) {
        char temporal = palabra[izq];
        palabra[izq] = palabra[der];
        palabra[der] = temporal;
    }

    cout << "Palabra invertida: " << palabra << endl;
    cout << endl;
}

// ============================================================
// EJERCICIO 6 - Nombre completo con getline
// ============================================================
void ejercicio6() {
    char nombreCompleto[100];

    cout << "Ejercicio 6 - Nombre completo con getline:" << endl;
    cout << "Ingrese su nombre completo: ";
    cin.ignore(); // limpia el salto de linea dejado por cin >>
    cin.getline(nombreCompleto, 100);

    int vocales = 0;
    for (int i = 0; nombreCompleto[i] != '\0'; i++) {
        char letra = tolower(nombreCompleto[i]);
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
            vocales++;
        }
    }

    cout << "El nombre '" << nombreCompleto << "' tiene " << vocales << " vocales." << endl;
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
    ejercicio6();

    return 0;
}
// ============================================================
// SEMANA 01 - Estructuras y Tipos de Datos
// ============================================================
// ENUNCIADOS
// ------------------------------------------------------------
// Ejercicio 1 - Tipos de datos y tamanios:
//    Declare variables de tipo int, float, double, char, bool,
//    short y long. Asigneles un valor y muestre en consola el
//    valor y el tamanio en bytes de cada tipo usando sizeof().
//
// Ejercicio 2 - Modificadores y tamanios:
//    Compare los tamanios de int, short int, long int,
//    unsigned int y signed int usando sizeof(). Explique la
//    diferencia observada con un mensaje en consola.
//
// Ejercicio 3 - Conversion entre variables:
//    Declare un int y un float. Realice una conversion
//    implicita (int a float) y una conversion explicita
//    (casting de float a int y de double a int). Muestre por
//    consola los resultados y la perdida de precision cuando
//    corresponda.
//
// Ejercicio 4 - Estructura:
//    Defina una estructura Estudiante con los campos: nombre
//    (char[30]), edad (int) y promedio (float). Solicite los
//    datos por consola y muestrelos al final.
//
// Ejercicio 5 - Estructuras con funciones:
//    Use la estructura Estudiante para leer y almacenar los
//    datos de 5 estudiantes en un arreglo. Calcule con una
//    funcion el promedio general del grupo y con otra funcion
//    muestre el estudiante con el mayor promedio.
// ============================================================

#include <iostream>
#include <climits>
using namespace std;

// Estructura usada en los ejercicios 4 y 5
struct Estudiante {
    char nombre[30];
    int edad;
    float promedio;
};

// ============================================================
// EJERCICIO 1 - Tipos de datos y tamanios
// ============================================================
void ejercicio1() {
    int entero = 10;
    float flotante = 3.14;
    double doble = 2.71828;
    char caracter = 'A';
    bool booleano = true;
    short corto = 5;
    long largo = 100000;

    cout << "Ejercicio 1 - Tipos de datos y tamanios:" << endl;
    cout << "int    -> valor " << entero     << ", tamanio " << sizeof(int)     << " bytes" << endl;
    cout << "float  -> valor " << flotante   << ", tamanio " << sizeof(float)   << " bytes" << endl;
    cout << "double -> valor " << doble      << ", tamanio " << sizeof(double)  << " bytes" << endl;
    cout << "char   -> valor " << caracter   << ", tamanio " << sizeof(char)    << " bytes" << endl;
    cout << "bool   -> valor " << booleano   << ", tamanio " << sizeof(bool)    << " bytes" << endl;
    cout << "short  -> valor " << corto      << ", tamanio " << sizeof(short)   << " bytes" << endl;
    cout << "long   -> valor " << largo      << ", tamanio " << sizeof(long)    << " bytes" << endl;
    cout << endl;
}

// ============================================================
// EJERCICIO 2 - Modificadores y tamanios
// ============================================================
void ejercicio2() {
    cout << "Ejercicio 2 - Modificadores y tamanios:" << endl;
    cout << "int          -> " << sizeof(int)          << " bytes" << endl;
    cout << "short int    -> " << sizeof(short int)    << " bytes" << endl;
    cout << "long int     -> " << sizeof(long int)     << " bytes" << endl;
    cout << "unsigned int -> " << sizeof(unsigned int) << " bytes" << endl;
    cout << "signed int   -> " << sizeof(signed int)   << " bytes" << endl;

    cout << "Rango de int: " << INT_MIN << " a " << INT_MAX << endl;
    cout << "Rango de unsigned int: 0 a " << UINT_MAX << endl;

    cout << "Observacion: unsigned int solo almacena valores" << endl;
    cout << "positivos (alcanza un maximo mayor), mientras que" << endl;
    cout << "signed int reparte el rango entre positivos y negativos." << endl;
    cout << endl;
}

// ============================================================
// EJERCICIO 3 - Conversion entre variables
// ============================================================
void ejercicio3() {
    int entero = 9;

    cout << "Ejercicio 3 - Conversion entre variables:" << endl;

    // Conversion implicita: el int se convierte a float
    float flotante = entero;
    cout << "Implicita: int " << entero << " -> float " << flotante << endl;

    // Conversion explicita (casting)
    float decimal = 9.85f;
    int truncado = (int)decimal;
    cout << "Explicita: float " << decimal << " -> int " << truncado << " (se pierde la parte decimal)" << endl;

    double doble = 3.1415;
    int enteroDoble = int(doble);
    cout << "Explicita: double " << doble << " -> int " << enteroDoble << endl;
    cout << endl;
}

// ============================================================
// EJERCICIO 4 - Estructura
// ============================================================
void ejercicio4() {
    Estudiante estudiante;

    cout << "Ejercicio 4 - Estructura:" << endl;
    cout << "Ingrese el nombre: ";
    cin >> estudiante.nombre;
    cout << "Ingrese la edad: ";
    cin >> estudiante.edad;
    cout << "Ingrese el promedio: ";
    cin >> estudiante.promedio;

    cout << "Datos del estudiante:" << endl;
    cout << "Nombre: " << estudiante.nombre << endl;
    cout << "Edad: " << estudiante.edad << endl;
    cout << "Promedio: " << estudiante.promedio << endl;
    cout << endl;
}

// ============================================================
// EJERCICIO 5 - Estructuras con funciones
// ============================================================
float promedioGeneral(Estudiante estudiantes[], int cantidad) {
    float suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma = suma + estudiantes[i].promedio;
    }
    return suma / cantidad;
}

int indiceMejorEstudiante(Estudiante estudiantes[], int cantidad) {
    int mejor = 0;
    for (int i = 1; i < cantidad; i++) {
        if (estudiantes[i].promedio > estudiantes[mejor].promedio) {
            mejor = i;
        }
    }
    return mejor;
}

void ejercicio5() {
    const int cantidad = 5;
    Estudiante estudiantes[cantidad];

    cout << "Ejercicio 5 - Estructuras con funciones:" << endl;

    for (int i = 0; i < cantidad; i++) {
        cout << "Estudiante " << i + 1 << ":" << endl;
        cout << "  Nombre: ";
        cin >> estudiantes[i].nombre;
        cout << "  Edad: ";
        cin >> estudiantes[i].edad;
        cout << "  Promedio: ";
        cin >> estudiantes[i].promedio;
    }

    cout << "Promedio general del grupo: " << promedioGeneral(estudiantes, cantidad) << endl;

    int mejor = indiceMejorEstudiante(estudiantes, cantidad);
    cout << "Mejor estudiante: " << estudiantes[mejor].nombre << endl;
    cout << "Con promedio: " << estudiantes[mejor].promedio << endl;
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
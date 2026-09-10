// ============================================================
// SEMANA 03 - Archivos de Tipo Texto - Acceso Secuencial
// ============================================================
// ENUNCIADOS
// ------------------------------------------------------------
// Ejercicio 1 - Escribir un archivo de texto:
//    Cree una estructura Producto con los campos nombre
//    (char[40]), cantidad (int) y precio (float). Solicite los
//    datos de 3 productos y guardianos en un archivo de texto
//    "productos.txt" usando ofstream.
//
// Ejercicio 2 - Leer un archivo de texto:
//    Lea el archivo "productos.txt" con ifstream y muestre en
//    consola cada uno de los productos guardados, campo por
//    campo, usando el operador de extraccion >>.
//
// Ejercicio 3 - Agregar datos al final (append):
//    Solicite un nuevo producto y agreguelo al final del
//    archivo "productos.txt" sin borrar los existentes, usando
//    ofstream con el indicador ios::app.
//
// Ejercicio 4 - Leer linea por linea con getline():
//    Lea el archivo "productos.txt" linea por linea con
//    getline() y muestre el contenido completo de cada linea.
//
// Ejercicio 5 - Procesar datos estructurados con stringstream:
//    Lea el archivo "productos.txt" linea por linea, use
//    stringstream para separar cada campo y calcule el valor
//    total (cantidad * precio) de cada producto y el valor
//    total de toda la factura.
// ============================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

// Estructura usada en todos los ejercicios
struct Producto {
    char nombre[40];
    int cantidad;
    float precio;
};

// ============================================================
// EJERCICIO 1 - Escribir un archivo de texto
// ============================================================
void ejercicio1() {
    Producto productos[3];

    cout << "Ejercicio 1 - Escribir un archivo de texto:" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Producto " << i + 1 << ":" << endl;
        cout << "  Nombre: ";
        cin >> productos[i].nombre;
        cout << "  Cantidad: ";
        cin >> productos[i].cantidad;
        cout << "  Precio: ";
        cin >> productos[i].precio;
    }

    ofstream archivo("productos.txt");
    if (!archivo) {
        cout << "Error: no se pudo abrir el archivo para escritura." << endl;
        return;
    }

    for (int i = 0; i < 3; i++) {
        archivo << productos[i].nombre << " "
                << productos[i].cantidad << " "
                << productos[i].precio << endl;
    }

    archivo.close(); // Es importante cerrar el archivo
    cout << "Productos guardados correctamente en productos.txt" << endl;
    cout << endl;
}

// ============================================================
// EJERCICIO 2 - Leer un archivo de texto
// ============================================================
void ejercicio2() {
    Producto producto;

    cout << "Ejercicio 2 - Leer un archivo de texto:" << endl;

    ifstream archivo("productos.txt");
    if (!archivo) {
        cout << "Error: no se encontro el archivo productos.txt" << endl;
        return;
    }

    while (archivo >> producto.nombre >> producto.cantidad >> producto.precio) {
        cout << "Nombre: " << producto.nombre << endl;
        cout << "Cantidad: " << producto.cantidad << endl;
        cout << "Precio: " << producto.precio << endl;
        cout << endl;
    }

    archivo.close();
}

// ============================================================
// EJERCICIO 3 - Agregar datos al final (append)
// ============================================================
void ejercicio3() {
    Producto nuevo;

    cout << "Ejercicio 3 - Agregar datos al final (append):" << endl;
    cout << "Ingrese el nuevo producto:" << endl;
    cout << "  Nombre: ";
    cin >> nuevo.nombre;
    cout << "  Cantidad: ";
    cin >> nuevo.cantidad;
    cout << "  Precio: ";
    cin >> nuevo.precio;

    ofstream archivo("productos.txt", ios::app);
    if (!archivo) {
        cout << "Error: no se pudo abrir el archivo." << endl;
        return;
    }

    archivo << nuevo.nombre << " "
            << nuevo.cantidad << " "
            << nuevo.precio << endl;

    archivo.close();
    cout << "Producto agregado al final del archivo." << endl;
    cout << endl;
}

// ============================================================
// EJERCICIO 4 - Leer linea por linea con getline()
// ============================================================
void ejercicio4() {
    cout << "Ejercicio 4 - Leer linea por linea con getline():" << endl;

    ifstream archivo("productos.txt");
    if (!archivo) {
        cout << "Error: no se encontro el archivo productos.txt" << endl;
        return;
    }

    string linea;
    int numeroLinea = 1;

    while (getline(archivo, linea)) {
        cout << "Linea " << numeroLinea << ": " << linea << endl;
        numeroLinea++;
    }

    archivo.close();
    cout << endl;
}

// ============================================================
// EJERCICIO 5 - Procesar datos con stringstream
// ============================================================
void ejercicio5() {
    cout << "Ejercicio 5 - Procesar datos con stringstream:" << endl;

    ifstream archivo("productos.txt");
    if (!archivo) {
        cout << "Error: no se encontro el archivo productos.txt" << endl;
        return;
    }

    string linea;
    float valorTotal = 0;

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        char nombre[40];
        int cantidad;
        float precio;

        ss >> nombre >> cantidad >> precio;

        float subtotal = cantidad * precio;
        valorTotal = valorTotal + subtotal;

        cout << "Producto: " << nombre << endl;
        cout << "Subtotal: " << subtotal << endl;
        cout << endl;
    }

    archivo.close();
    cout << "Valor total de la factura: " << valorTotal << endl;
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
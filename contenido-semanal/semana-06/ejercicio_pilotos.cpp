#include <iostream>
#include <cstring>
using namespace std;

struct Piloto
{
    char nombre[20];
    char apellido[30];
    int edad;
    int puntos;
};


// Ejercicio 1 
void mostarPilotos(Piloto *pilotos, int cantidad)
{

    for (int i = 0; i < cantidad; i++)
    {
        char nombreCompleto[60];
        strcpy(nombreCompleto, (pilotos + i)->nombre);
        strcat(nombreCompleto, " ");
        strcat(nombreCompleto, (pilotos + i )->apellido);
        cout << "Memoria del objeto:" << (pilotos + i) << endl;
        cout << "nommbre Completo :" << nombreCompleto << endl;
        cout << "Edad:" << (pilotos + i)->edad << "-" << "Memoria:" << &(pilotos + i)->edad << endl;
        // otra manera de consultar el valor
        cout << "Puntos:" << (*(pilotos + i)).puntos << endl;
    }
}

//Ejercicio 2 
void actualizarPuntuacion(Piloto *pilotos, int cantidad, int indice, int puntos)
{
    (pilotos + indice)->puntos = puntos;
}
// Ejercicio 3 
void buscarLider(Piloto *pilotos, int cantidad)
{
    int mejorPuntuacion = 0;
    char lider[60];

    for (int i = 0; i < cantidad; i++)
    {
        char nombreCompleto[60];
        strcpy(nombreCompleto, (pilotos + i)->nombre);
        strcat(nombreCompleto, " ");
        strcat(nombreCompleto, (pilotos + i )->apellido);

        if ((pilotos + i)->puntos > mejorPuntuacion)
        {
            mejorPuntuacion = (pilotos + i)->puntos;
            strcpy(lider, nombreCompleto);
        }
    }
    cout << "El lider de la carrera es :" << lider << endl;
}
// Ejerccico 4 
void agregarPiloto(Piloto *pilotos, int &cantidad)
{
    cout << "Ingrese nombre: ";
    cin >> (pilotos + cantidad)->nombre;
    cout << "Ingrese apellido: ";
    cin >> (pilotos + cantidad)->apellido;
    cout << "Ingrese edad: ";
    cin >> (pilotos + cantidad)->edad;
    cout << "Ingrese puntos: ";
    cin >> (pilotos + cantidad)->puntos;

    cantidad++;

    cout << "Piloto agregado exitosamente." << endl;
}
// Ejerccio 5
void mostrarPodio(Piloto *pilotos, int cantidad)
{

    Piloto copia[100];
    for (int i = 0; i < cantidad; i++)
    {
        *(copia + i) = *(pilotos + i);
    }

    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = 0; j < cantidad - i - 1; j++)
        {
            if ((copia + j)->puntos < (copia + j + 1)->puntos)
            {
                Piloto temp = *(copia + j);
                *(copia + j) = *(copia + j + 1);
                *(copia + j + 1) = temp;
            }
        }
    }

    cout << "\n       PODIO DE LA CARRERA     " << endl;

    int limite = (cantidad < 3) ? cantidad : 3;

    for (int i = 0; i < limite; i++)
    {
        if (i == 0)
            cout << "1er Lugar: ";
        else if (i == 1)
            cout << "2do Lugar: ";
        else if (i == 2)
            cout << "3er Lugar: ";

        cout << (copia + i)->nombre << " " << (copia + i)->apellido << " - " << (copia + i)->puntos << " Puntos" << endl;
    }
}

int main()
{

    int cantidad = 5;

    

    Piloto listaPilotos[100] = {
        {"Carlos", "Rodriguez", 21, 150},
        {"Ana", "Martinez", 22, 180},
        {"Luis", "Gomez", 20, 120},
        {"Sofia", "Perez", 23, 200},
        {"Mateo", "Ramirez", 21, 170}
    };

    Piloto *pilotos = &listaPilotos[0];
    

    int opcion = 0;

    while (opcion != 6)
    {
        int numero = 0;
        int puntos = 0;
        cout << "--- MENU DE OPCIONES -" << endl;
        cout << "1. Mostrar pilotos" << endl;
        cout << "2. Actualizar puntuacion" << endl;
        cout << "3. Buscar lider" << endl;
        cout << "4. Agregar piloto" << endl;
        cout << "5. Mostrar podio" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            mostarPilotos(pilotos, cantidad);
            break;
        case 2:
            cout << "Seleccione el numero del piloto (el indice es el numero del piloto)" << endl;
            cin >> numero;
            cout << "A que numero quiere actualizar sus Puntos" << endl;
            cin >> puntos;
            actualizarPuntuacion(pilotos, cantidad, numero, puntos);
            break;

        case 3:
            buscarLider(pilotos, cantidad);
            break;

        case 4:
            agregarPiloto(pilotos, cantidad);
            break;

        case 5:
            mostrarPodio(pilotos, cantidad);

            break;

        case 6:
            cout << "Saliendo..." << endl;
            break;

        default:
            break;
        }
    }
}
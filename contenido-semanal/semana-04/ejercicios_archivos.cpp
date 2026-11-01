#include <iostream>
#include <string>
#include <fstream>


using namespace std;


struct Animales {
    char nombre[50];
    char especie [50];
    int edad ; 
    double peso ; 
    bool sano;
};


int leerAnimales (Animales animales []){
    string linea;
    int i=0;

    ifstream leer("Veterinaria.txt");
    if(!leer)
    {
        cout<<"no se encontro el archivo"<<endl;
        return 0;
    }
    getline(leer,linea); // saltarse la primera linea 
    while (leer >> animales[i].nombre >> animales[i].especie>> animales[i].edad>> animales[i].peso>> animales[i].sano)
{
    i++;
}
    return i;
}
// manera alternativa 

/* 
while(!leer.eof())
    {
        if (linea.empty()) continue; // seguir apesar de que existan lineas vacias 
        leer>>animales[i].nombre>>animales[i].especie>>animales[i].edad>>animales[i].peso>>animales[i].sano;
        i++;
    }
*/

void imprimirAnimales(Animales animales [], int cantidad ){
    for(int i = 0 ; i< cantidad ; i++ ){
        cout << "Animal " << i << ":" << endl;
        cout << "Nombre: " << animales[i].nombre << endl;
        cout << "Especie: " << animales[i].especie << endl;
        cout << "Edad: " << animales[i].edad << endl;
        cout << "Peso: " << animales[i].peso << " kg" << endl;
        cout << "Estado: " << (animales[i].sano ? "Sano" : "Grave") << endl;
        cout << endl;
    }
}

void animalesEnfermos(Animales animales[],int cantidad ){
ofstream ani("enfermos.bin", ios::binary); // se puede usar tambien fstream | ios::out 

    cout << "Animales enfermos guardado en enfermos.bin" << endl;
    cout<<endl<<endl;
    for (int i = 0; i < cantidad; i++)
    {
        if (animales[i].sano == false )
        {
            cout << "nombre:" << animales[i].nombre << endl;
            cout<<endl<< endl;

            ani.write((char *)&animales[i], sizeof(Animales));
        }
    }
    ani.close();
}


void agregarAnimalEnfermo()
{
    Animales nuevo;

    cout << "Ingrese el nombre: ";
    cin >> nuevo.nombre;

    cout << "Ingrese la especie: ";
    cin >> nuevo.especie;

    cout << "Ingrese la edad: ";
    cin >> nuevo.edad;

    cout << "Ingrese el peso: ";
    cin >> nuevo.peso;

    nuevo.sano = false;

    ofstream sos("enfermos.bin", ios::binary | ios::app);

    sos.write((char *)&nuevo, sizeof(Animales));

    cout << "Animal agregado correctamente" << endl;

    sos.close();
}


void leerAnimalesEnfermos()
{
    Animales animal;

    ifstream leer("enfermos.bin", ios::binary);

    if (!leer)
    {
        cout << "No se encontro el archivo" << endl;
        return;
    }

    cout << "ANIMALES ENFERMOS" << endl << endl;

    while (leer.read((char *)&animal, sizeof(Animales)))
    {
        cout << "Nombre: " << animal.nombre << endl;
        cout << "Especie: " << animal.especie << endl;
        cout << "Edad: " << animal.edad << endl;
        cout << "Peso: " << animal.peso << " kg" << endl;
        cout << "Estado: " << (animal.sano ? "Sano" : "Grave") << endl;
        cout << endl;
    }

    leer.close();
}


int main()
{
    Animales animales[10];
    int cantidad  = leerAnimales(animales);
    int opc = 0 ; 
    do
    {

        cout << "Ingrese la opcion que quiere hacer: " << endl;
        cout << "0. Para salir" << endl;
        cout << "1. Imprimir animales" << endl;
        cout << "2. Guardar Animales enfermos" << endl;
        cout << "3. Añadir Animal enfermo" << endl;
        cout << "4. Ver Animales enfermos" << endl;
        cin >> opc;
        cout << endl;
        switch (opc)
        {

        case 0:
            cout << "Saliendo del programa" << endl;
            break;

        case 1:
            imprimirAnimales(animales, cantidad);
            break;

        case 2:
            animalesEnfermos(animales,cantidad);
            break;
        case 3:
            agregarAnimalEnfermo();
            break;
        case 4:
            leerAnimalesEnfermos();
            break;
        }
    }
    while (opc != 0);

}



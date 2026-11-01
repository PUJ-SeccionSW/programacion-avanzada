#include<iostream>
using namespace std ;



void  mostrar_arreglo(int* arreglo,int tamanio){
    for (int i = 0 ; i < tamanio ; i ++ ){

    cout<<"["<<*(arreglo+i)<<"]";
}
}

void inicializar(){

     cout<<"--------Primera Parte ------------"<<endl;
    // 1 .
    int num = 25 ;
    cout<<num<<endl;

    // 2.
    int* apuntador_25 = &num;
     cout<<apuntador_25<<endl;

    //3.
    cout<<*apuntador_25<<endl;

    // respuesta: A

}


void duplicar(int* apuntador_10) {


    cout<<"--------Segunda Parte ------------"<<endl;
    cout<<"Valor Original: "<<*apuntador_10<<endl;

// Al pasar la dirección de numero mediante un apuntador,
// podemos modificar directamente la variable original.
// Por esta razón, duplicar() no necesita retornar el nuevo valor.


// Multiplica el valor de la variable * 2

    *apuntador_10 *=2;

// Impresion
    cout<<apuntador_10<<endl ;

    // Respuesta :  B

}

void contar_pares(int* arreglo, int tamanio) {


    // Una forma de recorrer un apuntador es con (nombre_del_puntero + i ) -> memoria
     // Una forma de recorrer un apuntador es con *(nombre_del_puntero + i ) -> valores
    int contador_pares = 0 ;

    cout<<"--------Tercera  Parte ------------"<<endl;


    for (int i = 0 ; i < tamanio ; i ++ ){
            if(*(arreglo+i)%2 == 0){
                cout<<"Numeros Pares: "<<*(arreglo+i)<<endl;
                contador_pares++;
            }
    }
    cout<<"Cantidad de numeros que son pares: "<<contador_pares<<endl;

    // Respuesta : B

}

void invertir (int* arreglo, int tamanio){
    int temporal = 0 ;

        cout<<"--------Cuarta  Parte ------------"<<endl;

        cout << "Estado original: ";
        mostrar_arreglo(arreglo, tamanio);
        cout << endl;


for (int i = 0 ; i < tamanio/2; i ++ ){
        temporal = *(arreglo + i);

        *(arreglo + i) = *(arreglo + tamanio - 1 - i);

        *(arreglo + tamanio - 1 - i) = temporal;

}
// Respuesta D .
}



void memoria_dinamica () {

    cout<<"--------5 parte  ------------"<<endl;



    int tamanio;

    cout << "Ingrese el tamaño del arreglo: ";
    cin >> tamanio;

    // Reservar memoria dinámicamente
    int* numeros = new int[tamanio];

    cout << "\nIngrese los valores:" << endl;

    // Llenar el arreglo
    for (int i = 0; i < tamanio; i++) {
        cout << "Valor " << i + 1 << ": ";
        cin >> *(numeros + i);
    }

    // Contar números positivos
    int contadorPositivos = 0;

    for (int i = 0; i < tamanio; i++) {

        if (*(numeros + i) > 0) {
            contadorPositivos++;
        }
    }

    cout << "\nCantidad de numeros positivos: "
         << contadorPositivos << endl;

    // Liberar memoria
    delete[] numeros;

    // sin pregunta

}


void analizar() {
    cout<<"--------6 parte  ------------"<<endl;
    int numero = 10;
    int* puntero = &numero;
    *puntero = 20;
    int numeros[3]= {5, 10, 15};
    int* arreglo = numeros;
    *(arreglo + 1) = *puntero;
    int* dinamico = new int;
    *dinamico = *(arreglo + 2) + *puntero;
    cout << numero << endl;
    cout << numeros[1] << endl;
    cout << *dinamico << endl; delete dinamico;

    // Respuestas :
    // 1. C
    // 2. D
    // 3. C
    // 4 .B

}



int main () {
    // conceptos para el taller con salida por consola

     cout<<"--------Conceptos para el taller  ------------"<<endl;
    int numero = 10;

    // valor de la variable
    cout<<numero<<endl;
    // direccion de memoria
    int* apuntador_10 = &numero;
    cout<<apuntador_10<<endl;


    inicializar();

    duplicar(apuntador_10);


    cout<<"Valor modificado: "<<numero<<endl;
    int numeros[6] = {4, 7, 10, 13, 20, 25};
    int* apunatdor_numeros = numeros;

    contar_pares(apunatdor_numeros,6);

    int numeros_invertir [5] = {5, 4, 7, 11, 12};

    invertir(numeros_invertir,5);
    cout << "Estado Modificado: ";
    mostrar_arreglo(numeros_invertir,5);
    cout << endl;
    memoria_dinamica();
    analizar();



}









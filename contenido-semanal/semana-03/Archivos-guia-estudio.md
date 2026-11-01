# Guía de Estudio: Archivos de Texto
# 1. Conceptos
   ## ¿Qué es un archivo?
   Fundamentalmente, es una colección de datos almacenados en un disco que un programa puede leer o en la que puede escribir. Actúa como un
   mecanismo de almacenamiento persistente, lo que significa que los datos que contiene permanecen intactos incluso después de que el programa 
   haya terminado de ejecutarse o el computador se haya apagado. Esto diferencia a los archivos de la memoria volátil (como la RAM), 
   que pierde su contenido cuando se interrumpe la energía.
   ## Propósito de los archivos
   El propósito principal de usar archivos en programación es garantizar el almacenamiento persistente de datos. Esto permite guardar, 
   recuperar y reutilizar información entre distintas ejecuciones de un programa, haciendo posible que las aplicaciones mantengan su estado, 
   almacenen preferencias del usuario, administren bases de datos y manejen conjuntos de datos grandes que exceden la memoria disponible.
   ## Archivos de texto
   * Contienen datos legibles por humanos, normalmente codificados mediante juegos de caracteres 
   como ASCII o UTF-8
   * Algunos ejemplos son los archivos .txt, .csv, .html y .log
   * Pueden ser menos eficientes en espacio y más lentos en procesar estructuras de datos complejas
   que otros tipos como los binarios
## Métodos de acceso
  En este curso, para manejar archivos de texto, se usará el **acceso secuencial**. Consiste
  en leer o escribir los datos en un orden lineal, recorriendo el archivo elemento por elemento, 
  desde el principio hasta el final. Se puede pensar como leer un libro desde la portada, procesando 
  página por página en secuencia, hasta llegar a la última.
  ## Flujos: Interacción con archivos
  En C++, los programas interactúan con los archivos mediante una abstracción potente denominada flujos 
  (streams). Los flujos proporcionan una interfaz uniforme para realizar operaciones de entrada y salida, 
  ya sea con la consola, con archivos o con otras fuentes de datos. En el contexto de la entrada/salida 
  (I/O) de archivos, un flujo es un canal abstracto a través del cual se transmiten datos entre un
  programa en C++ y un archivo.
 * Un flujo de **salida** se utiliza cuando el programa **escribe** datos en un archivo.

 * Un flujo de **entrada** se utiliza cuando el programa **lee** datos desde un archivo.

Los flujos abstraen los detalles de bajo nivel de las operaciones de disco, lo que permite utilizar
operadores conocidos (como << para salida y >> para entrada) para administrar datos de archivos 
de una forma más sencilla y consistente.
# 2. Operaciones con flujos de archivos
## Biblioteca fstream
fstream es el componente principal de la biblioteca estándar de C++ dedicado 
a la manipulación de archivos. Proporciona las herramientas necesarias, incluidas clases 
de flujo especializadas, para realizar operaciones de entrada y salida con archivos y 
permitir el almacenamiento y la recuperación persistentes de datos
## Clases de flujo
C++ ofrece distintas clases de flujo para administrar diferentes tipos de interacción con
archivos:
* ofstream (Output File Stream): se utiliza para escribir datos en archivos. Cuando un
  archivo se abre con ofstream y ya existe, su contenido se sobrescribe de forma predeterminada. Si el archivo no existe, se crea.
* ifstream (Input File Stream): se utiliza para leer datos desde archivos. Esta clase requiere
  que el archivo exista; intentar abrir para lectura un archivo inexistente producirá un error.
* fstream (File Stream): es una clase versátil que puede utilizarse tanto para leer como para
  escribir archivos. Ofrece flexibilidad al permitir especificar el modo de operación deseado.
## Abrir un archivo
Para abrir un archivo, primero se declara un objeto de flujo apropiado (ofstream, ifstream o 
fstream) y luego se utiliza su método `.open()` ; también es posible pasar el nombre del 
archivo directamente al constructor.

Ejemplo usando ofstream:
```C++
#include <fstream>  // Necesario para las operaciones con flujos de archivos
#include <iostream> // Necesario para mostrar mensajes de error

ofstream outputFile;
outputFile.open("data.txt"); // Abre el archivo "data.txt" para escritura
```
## Manejo de errores
Es fundamental comprobar que el archivo se haya abierto correctamente antes de 
intentar cualquier operación. Esto puede hacerse evaluando el propio objeto de 
flujo o utilizando el método `.is_open()`

Ejemplo de comprobación de errores:
```C++
if (!outputFile) { // Comprueba si el flujo está en un estado de error
    cout << "Error: no se pudo abrir el archivo 'data.txt' para escritura." << endl;
    // Anunciar el error
}

// O utilizando is_open():
if (outputFile.is_open()) {
    // El archivo se abrió correctamente; continuar con las operaciones
} else {
    cout << "Error: no se pudo abrir el archivo 'data.txt' para escritura." << endl;
}
```
## Cerrar un archivo
Después de terminar de leer o escribir un archivo, debe cerrarse mediante el método 
`.close()` . Esta acción vacía en el archivo cualquier dato que aún esté almacenado
en el buffer y libera los recursos del sistema asociados al identificador del archivo. 
No cerrar los archivos puede provocar escrituras incompletas o fugas de recursos.
Ejemplo:
```C++
outputFile.close(); // Cierra el archivo
```
## Escritura en archivo de texto
### Modo sobreescritura
Cuando se abre un objeto ofstream sin especificar indicadores adicionales, se utiliza 
de forma predeterminada el modo de sobrescritura. Esto significa que, si el archivo 
especificado ya existe, todo su contenido se elimina antes de escribir los nuevos datos. 
Si el archivo no existe, se crea.

Procedimiento básico de escritura:

1.  Incluir el encabezado `<fstream>`.

2.  Declarar un objeto ofstream.

3.  Abrir el archivo (por ejemplo, `ofstream outFile("output.txt");`).

4.  Utilizar el operador de inserción `<<` para escribir datos. Usar `endl` o `\n`
    para los saltos de línea.

6.  Cerrar el archivo mediante `.close()` .

Ejemplo:
```C++
#include <fstream>
#include <iostream>
#include <string>

int main() {
    // Abre el archivo para escritura. Se sobrescribirá si "output.txt" ya existe.
    ofstream outFile("output.txt");

    if (outFile.is_open()) {
        outFile << "Esta es la primera línea." << endl;
        outFile << "Esta es la segunda línea." << endl;
        int value = 123;
        outFile << "Un número: " << value << endl;
        outFile.close(); // Cierra el archivo
        cout << "Se escribió correctamente en output.txt (sobrescribiendo si ya existía)." <<endl;
    } else {
        cout << "Error: no se pudo abrir el archivo 'output.txt' para escritura." << endl;
    }
    return 0;
}
```
### Modo append: Agregar datos al final de un archivo
Para agregar datos al final de un archivo existente sin eliminar su contenido actual, 
se debe abrir el objeto ofstream con el indicador `ios::app`. Esto garantiza que todas 
las escrituras posteriores se agreguen al final de los datos ya existentes en el archivo.

Ejemplo:
```C++
#include <fstream>
#include <iostream>

int main() {
    // Abre el archivo en modo de anexado
    ofstream appendFile("output.txt", ios::app);

    if (appendFile.is_open()) {
        appendFile << "Esta línea se agrega al final." << endl;
        appendFile.close();
        cout << "Los datos se agregaron correctamente a output.txt." << endl;
    } else {
        cout << "Error: no se pudo abrir el archivo 'output.txt' para agregar datos."  << endl;
    }
    return 0;
}
```
### Buenas prácticas de escritura
* Formato consistente: mantener una estructura predecible para los datos que se escriben.
  Si se escriben pares de cadenas y números, deben conservar siempre el mismo orden

* Usar delimitadores: emplear separadores claros, como espacios, tabulaciones `\t` o comas,
  para separar elementos de datos individuales dentro de una misma línea. Esto es esencial
  para analizarlos posteriormente

* Saltos de línea: utilizar `endl` o `\n` para separar registros o líneas distintas y mantener
  el archivo organizado visualmente
## Lectura de archivos de texto
Leer datos desde archivos de texto consiste en recuperar contenido de un archivo y almacenarlo 
en variables dentro del programa.
### Procedimiento básico
1.  Incluir el encabezado `<fstream>`.

2.  Declarar un objeto ifstream.

3.  Abrir el archivo (por ejemplo, `ifstream inFile("input.txt");`)

4.  Comprobar que el archivo se haya abierto correctamente

5.  Utilizar el operador de extracción `>>` para leer datos y almacenarlos en variables.
   Este operador normalmente lee elementos separados por espacios en blanco

7.  Para leer líneas completas, incluyendo todos sus elementos aunque estén separados por
   espacios, utilizar `getline()`

9.  Cerrar el archivo mediante `.close()`

Ejemplo - Leer datos separados por espacios en blanco:

```C++
#include <fstream>
#include <iostream>
#include <string>

int main() {
    ifstream inFile("output.txt"); // Abre el archivo para lectura
    string lineContent;
    int numberValue;

    if (inFile.is_open()) {
        // Lee los datos elemento por elemento.
        // El ciclo lee un token sin espacios y lo guarda en lineContent;
        // después lee el siguiente token separado por espacios en numberValue.
        // Continúa mientras ambas lecturas sean correctas.
        while (inFile >> lineContent >> numberValue) {
            cout << "Leído: " << lineContent << " " << numberValue << endl;
        }

        inFile.close(); // Cierra el archivo
        cout << "Finalizó la lectura de output.txt." << endl;
    } else {
        cout << "Error: no se pudo abrir el archivo 'output.txt' para lectura." << endl;
    }
    return 0;
}
```

Ejemplo - Leer línea por línea: para leer una línea completa de texto, incluidos los espacios, 
se utiliza `getline()`.

```C++
#include <fstream>
#include <iostream>
#include <string>

int main() {
    ifstream inFile("output.txt"); // Abre el archivo para lectura
    string fullLine;

    if (inFile.is_open()) {
        // Lee el archivo línea por línea
        while (getline(inFile, fullLine)) {
            cout << "Línea: " << fullLine << endl;
        }
        inFile.close(); // Cierra el archivo
        cout << "Finalizó la lectura de las líneas de output.txt." << endl;
    } else {
        cout << "Error: no se pudo abrir el archivo 'output.txt' para lectura." << endl;
    }
    return 0;
}
```
### Lectura con fstream
Si es necesario leer y escribir en el mismo archivo, se declara un objeto `fstream` y se abre 
con los indicadores apropiados (por ejemplo, `ios::in | ios::out`).

## Leer datos estructurados con ss
Un método robusto para leer datos estructurados línea por línea desde un archivo en C++ 
contiene varios pasos:

1.  Leer línea por línea: utilizar `getline(archivo, linea);` para leer el contenido completo de
    una línea en una variable `string` llamada linea. Esto es esencial para procesar datos que
    contienen varios atributos en una misma línea.

3.  Procesar la línea con `stringstream`: para cada linea leída, crear un objeto `stringstream ss(linea);`.
    Esto permite tratar la cadena como un flujo de entrada y facilita la extracción de componentes individuales.

5.  Extraer atributos: desde el `stringstream`, extraer los atributos individuales (campos de
   datos) mediante los operadores de extracción de flujo `>>`.

7.  Limpieza opcional: si los datos contienen caracteres adicionales (como espacios al inicio o
   al final, delimitadores específicos que no se desea usar para separar, o comillas no deseadas),
 pueden utilizarse funciones de manipulación de cadenas como `substr`, `find` y `erase` para
limpiar los datos antes o después de la extracción.

Este patrón ofrece flexibilidad y permite controlar de forma detallada cómo se extrae y prepara 
cada elemento de información para utilizarlo posteriormente en el programa.

#### Stringstream
La clase `stringstream` es muy útil para manipular cadenas como si fueran flujos de 
entrada/salida. Sus usos principales incluyen:

* Dividir cadenas: separar fácilmente una única cadena en partes más pequeñas según
  distintos delimitadores (por ejemplo, comas en archivos CSV, guiones o espacios).

  Ejemplo:
  ```C++
  // Supongamos que en el archivo, los datos están escritos de la forma dato1*dato2*dato3"
  #include <fstream>
  #include <iostream>
  #include <string>

  int main() {
    ifstream inFile("output.txt");
    string linea;
    int numberValue;

    if (inFile.is_open()) {
      inFile >> linea;
        
        inFile.close();
    }
  stringstream ss(linea);
  string token;
  getline(ss, token, '*');
  cout >> token; // Muestra dato1

  return 0
  }

  ```

* Leer varios tipos de datos desde una línea: extraer números, palabras u otros tipos
  de datos de forma secuencial desde una sola línea de texto.

* Conversión de cadenas a enteros `stoi` o flotantes `stof`: la función `stoi()` convierte la
  representación de un número entero almacenada en un `string` en un valor real de tipo `int`, y
  la función `stof()` convierte de un `string` a un dato tipo `float`.

Uso: es especialmente útil cuando se ha extraído una cadena que se sabe o se espera 
que contenga un valor entero. Esta conversión es necesaria para realizar operaciones 
matemáticas o comparaciones con datos numéricos. 

Ejemplo: 

`int age = stoi(ageString);`
`float height = stoi(heightString);`






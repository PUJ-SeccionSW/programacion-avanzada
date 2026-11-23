# Semana 02: Cadenas de Caracteres de tipo `char[]`

## Autoría

Las diapositivas de esta semana son de autoría del **profesor Jimmy Alejandro Castro Sabogal**.

## Descripción

Material de práctica de la semana 02 de **Programación Avanzada**. Incluye la presentación del tema de cadenas de caracteres de tipo `char[]` y ejercicios resueltos con sus enunciados, junto con ejercicios de repaso de punteros que funcionan como taller de refuerzo.

## Archivos

```text
.
├── cadenas-caracteres.pdf
├── ejercicios_cadenas.cpp
├── ejercicios_punteros.cpp
├── ejercicios_punteros_cpp.pdf
├── solucion-taller-apuntadores.cpp
└── taller_punteros.pdf
```

* `ejercicios_punteros.cpp`: contiene la solución de los ejercicios en un solo archivo.
* `ejercicios_punteros_cpp.pdf`: versión en PDF de los enunciados.
* `solucion-taller-apuntadores.cpp`: contiene la solución de las preguntas y ejercicios planteados en el taller.
* `taller_punteros.pdf`: contiene las preguntas y los enunciados de los ejercicios que se deben realizar.


## Compilación

Con `g++`:

```bash
g++ ejercicios_punteros.cpp -o ejercicios

g++ solucion-taller-apuntadores.cpp -o taller
```

## Ejecución

En Linux o WSL:

```bash
./ejercicios
-/taller
```

En Windows:

```bash
ejercicios.exe
taller.exe
```

## Conceptos utilizados

* Cadenas de caracteres de tipo `char[]`.
* Carácter nulo `'\0'` como fin de cadena.
* Recorrido, copia, comparación, concatenación e inversión de cadenas.
* `cin.getline()`, `strlen()`, `strcpy()`, `strcmp()` y `strcat()`.
* Punteros, arreglos y memoria dinámica (repaso).

## Propósito

Reforzar el manejo de cadenas de caracteres de tipo `char[]` mediante ejercicios prácticos en C++, y consolidar con un taller de repaso de punteros.
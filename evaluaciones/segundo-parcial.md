# Segundo Parcial - JAVA
Este parcial integra todo lo aprendido sobre JAVA en la materia, enfocándose en que los estudiantes sepan hacer uso correcto de objetos para gestionar sistemas de información.
Cuenta con dos partes principales: 
* Preguntas teóricas de opción múltiple 
* Preguntas abiertas de código para resolver un problema
A continuación, hay un ejemplo de parcial con su respectiva solución explicada.

## Preguntas teóricas
**1) Sean dos objetos obj1 y obj2 de una clase ClaseA. Si se quisiera comparar los dos objetos para evaluar si son iguales, en cuanto a contenido, la instrucción que iría en el condicional sería:**

a. obj1 == obj2

**b. obj1.equals(obj2)**

c. ClaseA.equals(obj1, obj2)

d. obj1.equalsIgnoreCase(obj2)

**2) Suponga que existe una clase Mamifero, que hereda de la clase Animal. Seleccione la instrucción que es incorrecta.**

a. Animal A = new Mamifero();

**b. Mamifero A = new Animal();**

c. Animal A = new Animal();

d. Mamifero A = new Mamifero();

**3) ¿Qué palabra reservada se utiliza para impedir que una clase sea heredada por otras?**

a. static

b. abstract

**c. final**

d. protected

**4) ¿Cuál es el propósito del bloque finally en una estructura try-catch?**

a. Ejecutarse solo si ocurre una excepción.

b. Ejecutarse solo si NO ocurre una excepción.

**c. Ejecutarse siempre, independientemente de si hubo excepción o no.**

d. Capturar excepciones de tipo Error.

**5) ¿Qué es polimorfismo?**

a. Crear múltiples variables.

**b. Capacidad de un objeto de comportarse de diferentes maneras.**

c. Ocultar métodos.

d. Ejecutar ciclos múltiples.

**6) En Java, la clase Object es la única clase que no hereda de ninguna otra clase.**

**a. Verdadero**

b. Falso

**7) ¿Cuál de las siguientes opciones describe correctamente la sobrecarga de métodos en Java?**

a. Un método de la clase hija redefine el comportamiento de un método de la clase padre con la misma firma.

**b. Varios métodos en la misma clase comparten el mismo nombre pero difieren en el número o tipo de parámetros.**

c. Se utiliza la anotación @Override para indicar que el método fue sobrecargado.

d. Solo se pueden sobrecargar métodos declarados como static.

**8) ¿Cuál de los siguientes códigos usa un método estático?**

a.
Perro p = new Perro();
p.correr();


**b.
System.out.println("Potencia:" + Math.pow(2,3));**


c.
System.out.println("Metodo estatico");


d.
int a = 5;
int b = 3;
System.out.println("2+3=" + (2+3));

**9) ¿Qué imprime el siguiente código?**
String cadena = "Hola";
System.out.println(cadena.toUpperCase());


a. hola

**b. HOLA**

c. Hola

d. Error

**10) Una app de pagos tiene la clase padre Pago con el método public void procesar(). La clase hija PagoConTarjeta necesita redefinir ese comportamiento para incluir la validación del CVV. ¿Cuál de estas implementaciones en PagoConTarjeta sobrescribe correctamente el método?**

a.
public void procesar(String cvv) {
    ...
}


**b.
@Override
public void procesar() {
    /\* valida CVV \*/
}**


c.
public void procesarPago() { ... }


d.
@Override
public void procesarPago(String cvv) {
    /* valida CVV */
}

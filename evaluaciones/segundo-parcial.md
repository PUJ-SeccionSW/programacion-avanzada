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

## Enunciado principal

Una prestigiosa librería especializada lo ha contratado para crear un sistema que les permita manejar las compras que hacen sus clientes.

La librería maneja un catálogo de libros (una colección de Libros) que se almacena de forma permanente en un archivo libros.dat y que se carga en memoria al iniciar el sistema.

La clase Abstracta Libro tiene los atributos: código (entero), un título (cadena), un precioBase (double) y una cantidad existente llamada copias licenciadas (int) que corresponde con la cantidad de licencias del libro que se pueden vender.

La librería maneja también una colección de Compras. Cada Compra tiene un nombreCliente (cadena) y una colección de Líneas de compra, así como valor total de la compra (double). Cada Línea tiene el libro comprado, la cantidad de libros de la línea y el subtotal (calculado) de línea (double) que corresponde a la multiplicación de la cantidad de libros de la línea por el precio del libro. El valor total de la compra se calcula como: suma de los subtotales de líneas más el 19.
### Archivos usados
* libros.txt (texto, enviado por proveedor)
* libros.dat (binario, almacenamiento permanente de libros)
* compras.dat (binario, almacenamiento de compras)
* compraCliente.txt (archivo plano generado como recibo de compra)

### Funcionamiento del sistema
* El archivo libros.dat se crea a partir del archivo libros.txt.
* Al iniciar el programa, libros.dat debe cargarse en memoria.
* El usuario puede realizar una compra agregando múltiples líneas.
* En la línea de compra solo se pueden agregar libros que existan en el catálogo y tengan cantidad suficiente en copias licenciadas.
* Al agregar una línea de compra, en memoria debe descontarse el número de copias licenciadas del libro en el catálogo.
* Al finalizar la compra: se calcula el total, se genera compraCliente.txt y se guarda (al final) la compra en compras.dat.

  ### Diagrama de clases UML
<img width="946" height="466" alt="image" src="https://github.com/user-attachments/assets/8f1ba5a5-5b8c-426f-8743-affb20970078" />

### Preguntas abiertas
**1. (10 puntos)** Escriba un método en la clase Librería (buscarLibro) que busque un libro por título en el catálogo y retorne: un libro si existe o NULL si no existe. Llega como parámetro el título del libro. Suponga que el título de libro es único y NO se repite.

**2. (10 puntos)** Escriba un método (totalizarCompra que retorna double) en la clase Compra que permita calcular el total de una compra: el total se calcula como la suma de los subtotales de las líneas, incrementando la suma en un 19 % que corresponde al IVA, y, guardar el resultado en el total de la compra.

**3. (20 puntos)** Escriba en la clase Compra un método (agregarLinea que retorna la Linea creada) que permita agregar una nueva Línea a la Compra. El método recibe el título del libro y la cantidad de libros a comprar en esa línea. Si el libro existe en el catálogo de la librería y si la cantidad disponible es suficiente (comparada con la cantidad de copias licenciadas del libro), se crea la línea y se adiciona en las líneas de la Compra; igualmente, se debe disminuir (en la cantidad comprada) el número de copias licenciadas del libro en el catálogo (en la colección de libros). También, se debe calcular y modificar el subtotal de la línea que se agrega, el subtotal se calcula como la cantidad * precio – devuelto por el método calcularPrecio()-. Finalmente se debe actualizar el atributo total de la compra sumando el subtotal de la línea agregada. Si el libro no existe o la cantidad de copias licenciadas no es suficiente se debe lanzar una excepción personalizada (asuma que la clase personalizada de excepción ya existe con un mensaje de tipo cadena).

**4. (10 puntos)** Escriba en la clase Librería un método (comprasSuperanTope) que retorne una colección de Compras cuyo total supera un tope que llega como parámetro. Para ello, el método debe agregar a la lista de retorno las compras cuyo total, calculado como la suma de los subtotales de cada línea, sea mayor al parámetro que llega al método.

**5. (10 puntos)** Escriba en la clase Compra un método (removerLinea que no retorna nada) que permita remover una Línea de la Compra. El método recibe el título del libro y remueve la línea cuyo libro asociado tenga el título que llega como parámetro. Se debe actualizar el número de copias licenciadas del libro removido con la cantidad especificada de libros de la línea removida. Finalmente, se debe actualizar el total de la compra.

**6. (5 puntos)** Escriba un método GenerarReporteLibrosDigitales en la clase Librería que genera un reporte en un archivo cuyo formato usted elige: librosDigitales.txt (texto) o librosDigitales.dat (binario). Usted debe generar la lista de libros a guardar y posteriormente debe enviarlos al disco duro, es decir, a un archivo en memoria secundaria.

**7. (15 puntos)** Escriba un método (totalizarValorLibros) en la clase Librería que permita calcular de forma polimórfica el valor total de los libros del catálogo, para ello en cada libro del catálogo se deben sumar: el producto del número de copias licenciadas por el precio total de cada libro (devuelto en calcularPrecio()).

Escriba también el método calcularPrecio() en cada una de las clases que implementan el método abstracto en Libro teniendo en cuenta las siguientes reglas:
* Para un libro digital el precio se calcula como el precio base menos el descuento.
* Para un libro físico el precio se calcula como el precio base más el costo del envío.

### Restricciones
Para cualquiera de estos métodos puede usar métodos desarrollados en otros puntos del parcial. En caso de usar métodos adicionales o auxiliares que no estén incluidos en este enunciado, debe implementarlos completamente. Suponga también que cuenta con todos los getters y setters (puede usarlos) de todas las clases, a menos que se solicite para que sea(n) implementado(s) en alguno(s) de los puntos del parcial. No puede asumir –a menos que se le diga de forma explícita en el parcial– que existe código ya implementado.

# Solución
**1.** 
En primer lugar, el ejercicio solicita que se retorne un elemento de clase `Libro`, por eso la función debe ser de este tipo. Luego, se necesita recorrer todos los elementos presentes en `catalogo`, para esto se usa `libro l:catalogo` que genera un elemento de tipo libro al que le va asignando secuencialmente los datos de cada elemento existente en la lista. Teniendo este elemento temporal, se usa el getter que el parcial nos indica que ya existe para obtener su título, y así poder compararlo con el que se recibe como parámetro. En caso de encontrarlo, se retorna allí mismo el elemento temporal, que en esa iteración va a contener el dato buscado. Si usamos un `return` en medio de condicionales, aseguramos que la única manera de que llegue al final de la función es que nunca cumpla la condición, por eso podemos ubicar un `return: NULL` después de cerrar la iteración y el condicional.
```public Libro buscarLibro (string titulo){
    for (libro l: catalogo){
        if (l.getTitulo().equals(titulo)){
            return l;
        }
    }
    return NULL;
    }
```

**2.**
Esta función se desarrolla en la clase `Compra`, por lo que se cuenta con la lista `lineas` disponible. Entonces, para totalizar la compra, en primer lugar se deben sumar los subtotales de cada linea en esta lista. Para eso nuevamente se usa `Linea x:lineas` para recorrerlas. Al finalizar esta acción se multiplica el total por 1.19, para obtener un incremento del 19%.
```
public double totalizarCompra(){
    total=0;
    for (Linea x:lineas){
        total += x.getSubtotal();
    }
    total *=1.19;
    return total;
}
```
**3.**
Para este punto, es importante recordar que se necesitan excepciones, y por lo tanto se debe usar `throws` al declarar el método y `throw new` cuando se quiera aplicar. El método es de tipo `Linea` ya que debe retornar un dato de este tipo. También es importante denotar que la este método está en la clase `Compra`, la cual "conoce" a la clase `libreria`, por ello podemos usar funciones de esta última, como `buscarLibro`. Empezamos haciendo justamente esto y guardando el resultado en un objeto temporal, usamos el contenido de este para comprobar si fue encontrado y en caso de que no, aplicamos una excepción, lo que terminará el método. Si continua significa que sí fue encontrado, entonces pasa a evaluarse si hay copias disponibles usando el getter de `Libro`, de no haber suficientes arrojamos la misma excepción pero con un mensaje diferente. Finalmente se calcula el precio a pagar con el getter del precio y tenido todos los datos se llama al constructor de `Linea` con estos datos. Para terminar, se añade la nueva linea usando `.add` y se restan la cantidad de copias compradas en el catalogo usando nuevamente el objeto temporal, y se vuelve a totalizar la compra ya que se añadió un nuevo elemento a la lista de la que calcula el total.
```
public Linea agregarLinea (String titulo, int cant) throws LibroInvalidoException{
    Libro buscado = libreria.buscarLibro(titulo);
    if (buscado=NULL){
        throw new LibroInvalidoException ("El libro buscado no existe");
    }
    if (buscado.getCopias()<cant){
        throw new LibroInvalidoException ("No hay suficientes copias disponibles");
    }
    double calc = cant * (buscado.calcularPrecio());
    Linea nueva = new Linea(cant, calc);
    lineas.add(nueva);
    buscado.setCopias(buscado.getCopias()-cant);
    double nuevot = totalizarCompra();
    return nueva;
}
```
**4.**
Ya que el problema pide retornar una colección de compras, el método debe ser de tipo lista, es decir `Arraylist`, de elementos de la clase `Compra`. Se crea una lista vacía de esta clase para empezar. Luego se recorre la lista de compras existentes hasta el momento con una variable temporal usando `Compra c: compras`, y por cada una de ellas se obtiene el total con el método ya creado, este total se compara con el tope suministrado y en caso de superarlo, se añade la compra que se está revisando (c) a la lista creada. Al terminar las iteraciones se retorna la lista construída.
```
public Arraylist <Compra> comprasSuperanTope (double tope){
    Arraylist <Compra> superan = new Arraylist <>();
    double revisar;
    for (Compra c: compras){
        revisar = c.totalizarCompra();
        if (revisar > tope){
            superan.add(c);
        }
    }
    return superan;
}
```
**5.**
La dificultad de este punto está en el acceso a cada objeto y sus atributos, hay que ser muy cuidadosos con qué clases conocen a cada clase y cuando necesitamos getters y setters de acuerdo a esto. Empezamos recorriendo la colección de lineas que se encuentran en `Compra`, por cada linea que recorramos, usamos un getter para obtener el objeto `Libro` asociado a esta, y otro getter dentro de este objeto, para obtener el titulo de dicho libro. Una vez se tiene este valor se puede comprarar con el titulo indicado usando `.equals`. En caso de que la comparación sea positiva, antes de hacer la siguiente iteración se pasa a buscar dicho libro en el catalogo de libros, es decir en la colección que se encuentra en la clase `Libreria`. Ya que la clase `Compra` sí conoce al objeto `libreria`, no se requiere un getter, pero dado que los atributos de libreria son privados, sí se requiere un getter para obtener la lista de libros (catalogo). Teniendo esta lista, se recorre uno por uno y en cada uno se compara con el titulo con el indicado, de encontrarlo se pasa a realizar el ajuste de las copias antes de la siguiente iteración. Ya que en este punto del código están las dos condicionales abiertas, los objetos `x` y `l` corresponden al objeto `Libro` hallado en el catalogo y al objeto `Linea` en el que se realiza una compra de este libro. Entonces, para reestablecer el número de copias disponibles, se suman las copias que quedaban registradas en el catálogo (`x.getCopias()`) y las copias que se habían comprado (`l.getCantidad()`) y esta suma se fija con un setter como el nuevo número de copias en el catálogo. Finalmente, saliendo del repetidor que exploraba el catálogo pero no del que exploraba las lineas, se remueve la linea encontrada usando `.remove()` y se calcula el nuevo total de la compra.
```
public void removerLinea (String titulo){
    for (Linea l: lineas){
        if (l.getLibro().getTitulo().equals (titulo)){
            for (Libro x: libreria.getCatalogo()){
                if (x.getTitulo.equals (titulo)){
                    x.setCopias(x.getCopias() + l.getCantidad());
                }
            }
            lineas.remove(l);
            totalizarCompra();
        }
    }
}
```
**6.**
Para este punto, en primer lugar se genera la lista de libros digitales verificando el tipo de cada objeto en el catalogo, ya que es una lista polimórfica que puede tener libros digitales o en físico. Eso lo hacemos recorriendo el catalogo con `Libro l:catalogo` y en cada iteración evaluamos `instanceof LibroDigital`, esto es un método que comprueba si el objeto es del tipo indicado, así solo los que cumplan con esta condición serán añadidos a la lista con `.add()`. Una vez se tiene la lista completa, se hace la escritura, es importante recordar que siempre que se escriba un archivo se debe usar `try-catch` para evaluar excepciones por errores en lectura o escritura de datos (`IOException`), que es una clase ya establecida. Se abre un `try` y allí se crea el archivo con `new FlieOutputStream("")` y se escribe con un `ObjectOutputStream`. En este caso, se recorre la lista creada y se escribe cada uno de los elementos que la incluyen. Luego se incluye un `catch` con la excepción mencionada, para evitar que todo el programa se detenga si hay errores en el proceso de impresión.
```
public void generarReporteLibrosDigitales(){
    Arraylist <LibroDigital> digitales = new Arraylist <>();
    for (Libro l:catalogo){
        if (l instanceof LibroDigital){
            digitales.add(l);
        }
    }
    try (ObjectOutputStream salida = new ObjectOutputStream (new FileOutputStream ("librosdigitales.dat"))){
        for (LibroDigital d:digitales){
            salida.WriteObject(d);
        }
    } catch (IOException e){System.out.println ("Error" + e.getMessage())}
}
```

**7.**
Este punto evalúa principalmente que sepan usar polimorfismo y sobreescribir métodos de clases abstractas a clases hijas. Para sobreescribir un método, se debe escribir `@Override` antes del método y debe tener el mismo nombre que el de la clase padre. En las clases en las que se sobreescribe este método se usa el mismo tipo de atributo (`double`) pero se hace un cálculo de manera diferente. Para libros digitales, se usa `super` para llamar al getter de la clase padre y obtener el precio base y luego a este se le resta el valor que haya en el atributo `descuento` del objeto (libroDigital). Para los libros físicos, también se llama al getter del precio base de la clase padre, pero en este caso se le suma el valor de costo de envío que se encontraba en el atributo de este objeto. En ambos casos se retorna el total obtenido. En la clase libreria, se crea un método que llamará a una de las dos formas de `calcularPrecio`, dependiendo de a qué instancia pertenezca el objeto desde el que se llame, y al multiplicar este valor obtenido por la cantidad de copias para ese libro, y sumar esto con los totales para cada libro, se obtiene una valorización total del catálogo.
```
public double totalizarValorLibros (){
    double valor = 0, precio;
    for (Libro l:catalogo){
        precio = l.calcularPrecio();
        valor += precio * l.getCopias;
    }
    return valor;
}

//Libro Digital
@Override
public double calcularPrecio(){
    double precio = super.getPreciobase()- descuento;
    return precio;
}

//Libro Físico
@Override
public double calcularPrecio(){
    double precio = super.getPreciobase () + costoEnvio;
    return precio;
}
```

### Consejos
Estos parciales tienden a estar organizados para evaluar uno o dos conceptos clave en cada punto, como polimorfismo, excepciones, escritura de archivos, encapsulación y obtención de información, etc. Identifica el concepto que el punto trata de evaluar y sé lo más claro posible frente a ese tema en el código, si lo necesitas redacta comentarios para explicar tu lógica. No te desgastes escribiendo códigos muy extensos, te piden funciones puntuales. ¡Buena suerte!

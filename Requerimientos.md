# Requerimientos del Programa: Resolución del Acertijo de las Cajas

## Descripción General

Desarrollar un programa en lenguaje C capaz de resolver el clásico acertijo de las tres cajas.

Existen tres cajas que contienen los siguientes contenidos:

* Una caja contiene únicamente chocolates.
* Una caja contiene únicamente mentas.
* Una caja contiene una mezcla de chocolates y mentas.

Cada caja posee una etiqueta que indica su supuesto contenido; sin embargo, **todas las etiquetas son incorrectas**.

A partir de la extracción de un solo dulce de una de las cajas, es posible determinar el contenido real de cada una.

## Requerimientos Funcionales

1. El programa deberá solicitar al usuario la etiqueta de la caja de la que se extrajo el dulce. 
2. El programa deberá solicitar al usuario el tipo de dulce obtenido al realizar la extracción (chocolate o menta).
3. Con base en la información proporcionada, el programa deberá decirte *sigue intentando* si es que no adivine el contenido correcto(teniendo en cuenta que la caja con la etiqueta de mentas y la que tiene etiqueta de chocolate puede variar dependiendo de que elijo que haya en la caja mixta)
4. El programa deberá mostrar al usuario la distribución correcta de los contenidos en cada caja.
5. El programa deberá considerar que todas las etiquetas iniciales son incorrectas y resolver el acertijo respetando esta condición.
6. Tengo que implementar una funcion para seleccionar las opciones con las flechitas en la terminal.

## Entradas del Programa

* Etiqueta de la caja seleccionada:

  * Chocolates
  * Mentas
  * Chocolates y Mentas

* Dulce extraído:

  * Chocolate
  * Menta

## Salida Esperada

El programa deberá indicar el contenido real de cada una de las tres cajas, especificando cuál contiene:

* Solo chocolates.
* Solo mentas.
* Chocolates y mentas mezclados.

## Restricciones

* Solo se permite utilizar la información obtenida de una única extracción.
* Se debe asumir que ninguna etiqueta coincide con el contenido real de la caja.
* La solución debe implementarse en lenguaje C.



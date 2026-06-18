# Especificación de Requerimientos

## Simulador del Acertijo de las Cajas

### 1. Descripción

El programa consiste en un simulador interactivo del clásico acertijo de las tres cajas.

Existen tres cajas con las siguientes etiquetas:

* Chocolates
* Mentas
* Chocolates y Mentas

Sin embargo, todas las etiquetas son incorrectas. El usuario podrá extraer un único dulce de una caja y posteriormente deberá deducir el contenido real de cada una.

El programa deberá permitir verificar la solución y, al finalizar, ofrecer un modo de exploración libre para comprobar el comportamiento de las cajas.

---

# 2. Requerimientos Funcionales

## RF-1. Pantalla de bienvenida

Al iniciar el programa deberá mostrarse:

* Una breve explicación del acertijo.
* Las reglas de la simulación.
* La indicación de que el usuario debe presionar la tecla Enter para comenzar.

El programa permanecerá esperando hasta recibir la pulsación de Enter.

---

## RF-2. Generación aleatoria del escenario

Al comenzar la simulación:

* El programa deberá generar aleatoriamente una de las dos configuraciones posibles que cumplen las condiciones del acertijo.
* La configuración elegida permanecerá fija durante toda la partida.
* El usuario no deberá conocer la distribución seleccionada.

---

## RF-3. Selección de una caja

El usuario podrá seleccionar una única caja de la cual extraer un dulce.

La interfaz deberá cumplir las siguientes condiciones:

* Mostrar las tres cajas identificadas únicamente por sus etiquetas incorrectas.
* Permitir navegar entre ellas utilizando las flechas del teclado.
* Confirmar la selección mediante la tecla Enter.
* Solo podrá realizarse una extracción durante la partida.

---

## RF-4. Extracción del dulce

Una vez seleccionada la caja:

* El programa deberá mostrar el tipo de dulce obtenido.

Reglas:

* Si la caja contiene únicamente chocolates, siempre se obtendrá un chocolate.
* Si la caja contiene únicamente mentas, siempre se obtendrá una menta.
* Si la caja contiene una mezcla de ambos dulces, el programa deberá seleccionar aleatoriamente cuál entregar en cada extracción.

El contenido interno de las cajas no deberá modificarse.

---

## RF-5. Selección de la solución

Después de la extracción, el usuario deberá indicar cuál es el contenido real de cada caja.

El proceso deberá funcionar mediante dos niveles de menú.

### Primer menú

* Mostrar las tres cajas identificadas por sus etiquetas.
* Permitir navegar con las flechas del teclado.
* Confirmar la selección con Enter.

### Segundo menú

Una vez elegida una caja:

* Mostrar los contenidos disponibles:

  * Chocolates.
  * Mentas.
  * Chocolates y Mentas.
* Permitir navegar mediante las flechas del teclado.
* Confirmar la selección con Enter.

---

## RF-6. Restricción de contenidos

Cada contenido podrá asignarse únicamente a una caja.

Cuando un contenido haya sido asignado:

* Deberá eliminarse de las opciones disponibles para las cajas restantes.

Cuando únicamente quede:

* Una caja sin asignar.
* Un contenido disponible.

El programa deberá realizar la asignación automáticamente.

---

## RF-7. Validación

Al finalizar la asignación:

El programa deberá:

* Comparar la respuesta del usuario con la configuración generada al inicio.
* Informar claramente si la solución es correcta o incorrecta.
* Mostrar la distribución real de las cajas.

---

## RF-8. Modo de exploración libre

Después de mostrar el resultado:

El programa deberá conservar la configuración inicial de las cajas y permitir al usuario realizar extracciones ilimitadas.

El objetivo es comprobar experimentalmente el comportamiento de cada caja.

Durante este modo:

* El usuario podrá seleccionar cualquier caja.
* Extraer tantos dulces como desee.
* La caja con contenido mixto deberá entregar chocolates o mentas de forma aleatoria en cada extracción.
* Las cajas con contenido único deberán entregar siempre el mismo tipo de dulce.

El usuario podrá abandonar este modo cuando lo desee.

---

# 3. Requerimientos de Interfaz

## RI-1. Navegación

Todos los menús interactivos deberán utilizar:

* Flecha arriba.
* Flecha abajo.

La confirmación de cualquier selección deberá realizarse mediante la tecla Enter.

---

## RI-2. Presentación

El programa deberá ejecutarse completamente en modo consola.

La interfaz deberá:

* Ser clara.
* Mostrar siempre la opción actualmente seleccionada.
* Evitar solicitar entradas mediante números o texto libre cuando exista un menú navegable.

---

# 4. Requerimientos Técnicos

## RT-1

El programa deberá desarrollarse en lenguaje C.

---

## RT-2

Toda la interacción deberá realizarse mediante la consola.

---

## RT-3

La lógica del acertijo deberá garantizar que:

* Las tres etiquetas sean incorrectas.
* La distribución seleccionada pertenezca a uno de los dos escenarios válidos definidos para la simulación.

---

## RT-4

La generación aleatoria deberá utilizar una semilla apropiada para evitar obtener siempre el mismo escenario y los mismos resultados en las extracciones aleatorias de la caja mixta.

---

## RT-5

El proyecto deberá utilizar Git como sistema de control de versiones durante todo su desarrollo.

Se deberán cumplir las siguientes condiciones:

* El proyecto deberá inicializarse como un repositorio Git desde el inicio del desarrollo.
* Los avances deberán registrarse mediante commits descriptivos y periódicos.
* El repositorio deberá alojarse en una cuenta propia de GitHub.
* El código fuente deberá mantenerse respaldado y sincronizado con el repositorio remoto.
* El repositorio deberá incluir todos los archivos necesarios para compilar y ejecutar el proyecto.
* Se deberá incluir un archivo `README.md` con una descripción del proyecto y las instrucciones básicas para su compilación y ejecución.
* El historial de commits deberá reflejar las distintas etapas del desarrollo y la implementación de las principales funcionalidades del programa.

---

# 5. Flujo General del Programa

1. Mostrar la introducción y las reglas del acertijo.
2. Esperar a que el usuario presione Enter.
3. Generar aleatoriamente una configuración válida de las cajas.
4. Permitir al usuario seleccionar una caja para realizar una única extracción.
5. Mostrar el dulce obtenido.
6. Solicitar al usuario que determine el contenido real de cada caja mediante los menús interactivos.
7. Validar las respuestas del usuario.
8. Informar si la solución es correcta o incorrecta.
9. Mostrar la distribución real de las cajas.
10. Entrar en el modo de exploración libre.
11. Permitir extracciones ilimitadas de cualquier caja conservando la configuración inicial.
12. Finalizar cuando el usuario decida salir del programa.



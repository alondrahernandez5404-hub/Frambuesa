/*Aquí declararemos todo lo relacionado con el juego.
Enumeracion de contenido, 
estructura de cajas,
funciones publicas */

#ifndef GAME_H
#define GAME_H

/*
 * Tipos de contenido posibles dentro de una caja.
 */
typedef enum
{
    CHOCOLATES,
    MENTAS,
    MIXTO
} Contenido;

/*
 * Representa una caja del acertijo.
 */
typedef struct
{
    Contenido etiqueta;
    Contenido contenidoReal;
} Caja;

/*
 * Genera aleatoriamente uno de los escenarios válidos.
 */
void generarEscenario(Caja cajas[]);

/*
 * Realiza una extracción de una caja.
 */
Contenido extraerDulce(Caja caja);

/*
 * Convierte un contenido a texto.
 */
const char *contenidoATexto(Contenido contenido);

/*
 * Compara la solución propuesta por el usuario
 * con la solución real.
 *
 * Regresa:
 * 1 -> Correcta
 * 0 -> Incorrecta
 */
int validarSolucion(
    Caja cajas[],
    Contenido respuesta[]
);

/*
 * Muestra la distribución real de las cajas.
 */
void mostrarSolucion(Caja cajas[]);

/*
 * Muestra la información de una caja.
 */
void mostrarCaja(Caja caja);

#endif
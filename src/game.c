/*Aquí vive toda la lógica del acertijo.
Generar escenarios,
validar solucion,
mostrar solucion*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/game.h"

const char *contenidoATexto(Contenido contenido)
{
    switch (contenido)
    {
        case CHOCOLATES:
            return "Chocolates";

        case MENTAS:
            return "Mentas";

        case MIXTO:
            return "Chocolates y Mentas";

        default:
            return "Desconocido";
    }
}
void generarEscenario(Caja cajas[])
{
    cajas[0].etiqueta = CHOCOLATES;
    cajas[1].etiqueta = MENTAS;
    cajas[2].etiqueta = MIXTO;

    int escenario = rand() % 2;

    if (escenario == 0)
    {
        cajas[0].contenidoReal = MENTAS;
        cajas[1].contenidoReal = MIXTO;
        cajas[2].contenidoReal = CHOCOLATES;
    }
    else
    {
        cajas[0].contenidoReal = MIXTO;
        cajas[1].contenidoReal = CHOCOLATES;
        cajas[2].contenidoReal = MENTAS;
    }
}
Contenido extraerDulce(Caja caja)
{
    if (caja.contenidoReal == CHOCOLATES)
        return CHOCOLATES;

    if (caja.contenidoReal == MENTAS)
        return MENTAS;

    if (rand() % 2 == 0)
        return CHOCOLATES;

    return MENTAS;
}

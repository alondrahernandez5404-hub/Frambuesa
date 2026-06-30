/*Aquí vive toda la lógica del acertijo.
Generar escenarios,
validar solucion,
mostrar solucion*/

/*
 * game.c
 * -------
 * Implementación de la lógica del acertijo de las cajas.
 *
 * Este módulo se encarga de:
 * - Generar un escenario válido.
 * - Simular la extracción de dulces.
 * - Validar la solución del usuario.
 * - Mostrar la solución correcta.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/game.h"
#include "../include/menu.h"


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
    /* Etiquetas (siempre son las mismas) */

    cajas[0].etiqueta = CHOCOLATES;
    cajas[1].etiqueta = MENTAS;
    cajas[2].etiqueta = MIXTO;

    /* Elegir uno de los dos escenarios válidos */

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
    {
        return CHOCOLATES;
    }

    if (caja.contenidoReal == MENTAS)
    {
        return MENTAS;
    }

    /* Si la caja es mixta, entregar un dulce aleatorio */

    if (rand() % 2 == 0)
    {
        return CHOCOLATES;
    }

    return MENTAS;
}


int validarSolucion(Caja cajas[], Contenido respuesta[])
{
    int i;

    for (i = 0; i < 3; i++)
    {
        if (cajas[i].contenidoReal != respuesta[i])
        {
            return 0;
        }
    }

    return 1;
}


void mostrarCaja(Caja caja)
{
    printf("Etiqueta          : %s\n",
           contenidoATexto(caja.etiqueta));

    printf("Contenido real    : %s\n",
           contenidoATexto(caja.contenidoReal));
}


void mostrarSolucion(Caja cajas[])
{
    int i;

    printf("\n=========================================\n");
    printf("       SOLUCION DEL ACERTIJO\n");
    printf("=========================================\n\n");

    for (i = 0; i < 3; i++)
    {
        printf("Caja %d\n", i + 1);

        mostrarCaja(cajas[i]);

        printf("-----------------------------------------\n");
    }
}

void resolverAcertijo(Caja cajas[])
{
    Contenido respuesta[3];

    int caja;

    printf("\n");
    printf("=========================================\n");
    printf("      RESUELVE EL ACERTIJO\n");
    printf("=========================================\n\n");

    printf("Ahora debes indicar el contenido real\n");
    printf("de cada una de las cajas.\n\n");

    /* -------- Primera caja -------- */

    printf("Selecciona la PRIMERA caja.\n");

    caja = seleccionarCaja();

    printf("\nElegiste la caja etiquetada como: %s\n",
           contenidoATexto(cajas[caja].etiqueta));

    printf("\n¿Que contiene realmente?\n");

    respuesta[caja] = seleccionarContenido();

    printf("\nAsignaste: %s\n\n",
           contenidoATexto(respuesta[caja]));

    /* -------- Segunda caja -------- */

    printf("Selecciona la SEGUNDA caja.\n");

    caja = seleccionarCaja();

    printf("\nElegiste la caja etiquetada como: %s\n",
           contenidoATexto(cajas[caja].etiqueta));

    printf("\n¿Que contiene realmente?\n");

    respuesta[caja] = seleccionarContenido();

    printf("\nAsignaste: %s\n\n",
           contenidoATexto(respuesta[caja]));

    /* -------- Tercera caja -------- */

    printf("Selecciona la TERCERA caja.\n");

    caja = seleccionarCaja();

    printf("\nElegiste la caja etiquetada como: %s\n",
           contenidoATexto(cajas[caja].etiqueta));

    printf("\n¿Que contiene realmente?\n");

    respuesta[caja] = seleccionarContenido();

    printf("\nAsignaste: %s\n\n",
           contenidoATexto(respuesta[caja]));

    /* -------- Validación -------- */

    printf("\n=========================================\n");

    if (validarSolucion(cajas, respuesta))
    {
        printf("¡¡FELICIDADES!!\n");
        printf("Resolviste correctamente el acertijo.\n");
    }
    else
    {
        printf("La respuesta no es correcta.\n");
    }

    mostrarSolucion(cajas);
}
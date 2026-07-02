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
#include "../include/terminal.h"

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

void modoExploracion(Caja cajas[])
{

} 

void resolverAcertijo(Caja cajas[])
{
Contenido respuesta[3];

int caja;
int i;
int ultimaCaja = -1;
int ultimoContenido = -1;

int cajaDisponible[3] =
{
    1,
    1,
    1
};

/* Indica qué contenidos siguen disponibles */

int contenidoDisponible[3] =
{
    1,
    1,
    1
};

    printf("\n");
    printf("=========================================\n");
    printf("      RESUELVE EL ACERTIJO\n");
    printf("=========================================\n\n");

    printf("Ahora debes indicar el contenido real\n");
    printf("de cada una de las cajas.\n\n");


for (i = 0; i < 2; i++)
{
    printf("-----------------------------------------\n");
    printf("Selecciona la caja %d.\n\n", i + 1);

    activarModoRaw();

    caja = menuVerticalDisponible(
        (const char *[])
        {
            "Caja etiquetada: Chocolates",
            "Caja etiquetada: Mentas",
            "Caja etiquetada: Chocolates y Mentas"
        },
        cajaDisponible,
        3
    );

    restaurarTerminal();

    cajaDisponible[caja] = 0;

    printf("\nElegiste la caja etiquetada como: %s\n",
           contenidoATexto(cajas[caja].etiqueta));

    printf("\n¿Que contiene realmente?\n\n");

    activarModoRaw();

    respuesta[caja] = (Contenido) menuVerticalDisponible(
        (const char *[])
        {
            "Chocolates",
            "Mentas",
            "Chocolates y Mentas"
        },
        contenidoDisponible,
        3
    );

    restaurarTerminal();

    contenidoDisponible[respuesta[caja]] = 0;

    printf("\nAsignaste: %s\n\n",
           contenidoATexto(respuesta[caja]));
}

for (i = 0; i < 3; i++)
{
    if (cajaDisponible[i])
    {
        ultimaCaja = i;
    }

    if (contenidoDisponible[i])
    {
        ultimoContenido = i;
    }
}

respuesta[ultimaCaja] = (Contenido) ultimoContenido;

printf("-----------------------------------------\n");
printf("Última asignación automática.\n\n");

printf("Caja: %s\n",
       contenidoATexto(cajas[ultimaCaja].etiqueta));

printf("Contenido: %s\n\n",
       contenidoATexto(respuesta[ultimaCaja]));

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

printf("\n");
printf("Presiona Enter para entrar al modo exploracion...");
getchar();

modoExploracion(cajas);
}
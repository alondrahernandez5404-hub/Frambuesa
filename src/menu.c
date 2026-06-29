/*Aqui vive toda la interfaz*/

/*
 * menu.c
 * -------
 * Implementación de los menús interactivos del programa.
 */

#include <stdio.h>

#include "../include/menu.h"
#include "../include/terminal.h"

/* Colores ANSI */

#define RESET      "\033[0m"
#define VERDE      "\033[32m"
#define CIAN       "\033[36m"
#define AMARILLO   "\033[33m"
#define NEGRITA    "\033[1m"

int menuVertical(
    const char *opciones[],
    int cantidad
)
{
    int seleccion = 0;
    int tecla;
    int i;

    while (1)
    {
        limpiarPantalla();

        printf("%s%s", CIAN, NEGRITA);
        printf("========================================\n");
        printf("        ACERTIJO DE LAS CAJAS\n");
        printf("========================================\n");
        printf("%s", RESET);

        printf("\n");

        printf("%s", AMARILLO);
        printf("Seleccione una opción\n\n");
        printf("↑ ↓  Moverse por el menú\n");
        printf("Enter  Seleccionar\n");
        printf("%s", RESET);

        printf("\n");

        for (i = 0; i < cantidad; i++)
        {
            if (i == seleccion)
            {
                printf("%s%s➜ [ %s ]%s\n",
       VERDE,
       NEGRITA,
       opciones[i],
       RESET);
            }
            else
            {
                printf("        %s\n", opciones[i]);
            }
        }

        tecla = leerTecla();

        if (tecla == TECLA_ARRIBA)
        {
            if (seleccion > 0)
            {
                seleccion--;
            }
        }
        else if (tecla == TECLA_ABAJO)
        {
            if (seleccion < cantidad - 1)
            {
                seleccion++;
            }
        }
        else if (tecla == TECLA_ENTER)
        {
            return seleccion;
        }
    }
}
int seleccionarCaja(void)
{
    const char *opciones[] =
    {
        "Caja etiquetada: Chocolates",
        "Caja etiquetada: Mentas",
        "Caja etiquetada: Chocolates y Mentas"
    };

    return menuVertical(opciones, 3);
}
Contenido seleccionarContenido(void)
{
    const char *opciones[] =
    {
        "Chocolates",
        "Mentas",
        "Chocolates y Mentas"
    };

    return (Contenido) menuVertical(opciones, 3);
}
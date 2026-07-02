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

printf("Use las flechas para moverse.\n");
printf("Presione Enter para seleccionar.\n");

printf("%s", RESET);
printf("\n");

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
    printf("        [ %s ]\n", opciones[i]);
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

activarModoRaw();

int opcion = menuVertical(opciones, 3);

restaurarTerminal();

return opcion;
}

Contenido seleccionarContenido(void)
{
    const char *opciones[] =
    {
        "Chocolates",
        "Mentas",
        "Chocolates y Mentas"
    };

activarModoRaw();

int opcion = menuVertical(opciones, 3);

restaurarTerminal();

return (Contenido) opcion;
}

int menuVerticalDisponible(
    const char *opciones[],
    int disponible[],
    int cantidad
)
{
    int seleccion = 0;
    int tecla;
    int i;

    /* Buscar la primera opción disponible */

    while (!disponible[seleccion])
    {
        seleccion++;
    }

    while (1)
    {
        limpiarPantalla();

        printf("========================================\n");
        printf("        ACERTIJO DE LAS CAJAS\n");
        printf("========================================\n\n");

        printf("Use las flechas para moverse.\n");
        printf("Presione Enter para seleccionar.\n\n");

        for (i = 0; i < cantidad; i++)
        {
            if (!disponible[i])
            {
                continue;
            }

            if (i == seleccion)
            {
                printf("➜ [ %s ]\n", opciones[i]);
            }
            else
            {
                printf("    %s\n", opciones[i]);
            }
        }

        tecla = leerTecla();

        if (tecla == TECLA_ARRIBA)
        {
            do
            {
                seleccion--;

                if (seleccion < 0)
                {
                    seleccion = cantidad - 1;
                }

            } while (!disponible[seleccion]);
        }

        else if (tecla == TECLA_ABAJO)
        {
            do
            {
                seleccion++;

                if (seleccion >= cantidad)
                {
                    seleccion = 0;
                }

            } while (!disponible[seleccion]);
        }

        else if (tecla == TECLA_ENTER)
        {
            return seleccion;
        }
    }
}
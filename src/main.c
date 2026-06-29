/* Mostrar bienvenida
↓
Generar escenario
↓
Permitir extracción
↓
Resolver acertijo
↓
Validar respuesta
↓
Mostrar solución
↓
Entrar en exploración libre
↓
Salir */

/*
 * main.c
 * --------
 * Programa principal del acertijo de las cajas.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/game.h"
#include "../include/menu.h"
#include "../include/terminal.h"

int main(void)
{
    Caja cajas[3];

    int cajaSeleccionada;
    Contenido dulce;

    srand(time(NULL));

    printf("========================================\n");
    printf("        ACERTIJO DE LAS CAJAS\n");
    printf("========================================\n\n");

    printf("Hay tres cajas.\n");
    printf("Todas las etiquetas son incorrectas.\n");
    printf("Solo puedes sacar un dulce de una caja.\n");
    printf("Con esa informacion debes deducir el contenido real.\n\n");

    printf("Presiona Enter para comenzar...");
    getchar();

    generarEscenario(cajas);

    activarModoRaw();

    cajaSeleccionada = menuVertical(opciones, 3);

    restaurarTerminal();

    limpiarPantalla();

    dulce = extraerDulce(cajas[cajaSeleccionada]);

    printf("========================================\n");
    printf("Resultado de la extracción\n");
    printf("========================================\n\n");

    printf("Elegiste la caja con etiqueta: %s\n",
           contenidoATexto(cajas[cajaSeleccionada].etiqueta));

    printf("Obtuviste: %s\n\n",
           contenidoATexto(dulce));

    printf("Presiona Enter para finalizar...");
    getchar();

    return 0;
}
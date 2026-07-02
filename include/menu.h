/*Declaracion de menus.
*/

#ifndef MENU_H
#define MENU_H
#include "game.h"
/*
 * Muestra un menú vertical navegable.
 *
 * Regresa el índice de la opción seleccionada.
 */
int menuVertical(
    const char *opciones[],
    int cantidad
);

/*
 * Permite elegir una caja.
 */
int seleccionarCaja(void);

/*
 * Permite elegir un contenido.
 */
Contenido seleccionarContenido(void);

/*
 * Permite seleccionar una opción
 * ignorando aquellas que ya fueron utilizadas.
 */
int menuVerticalDisponible(
    const char *opciones[],
    int disponible[],
    int cantidad
);
#endif
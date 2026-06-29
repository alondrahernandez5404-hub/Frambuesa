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

#endif
/*Declaracion de menus.
*/

#ifndef MENU_H
#define MENU_H

/*
 * Muestra un menú vertical navegable.
 *
 * Regresa el índice de la opción seleccionada.
 */
int menuVertical(
    const char *opciones[],
    int cantidad
);

#endif
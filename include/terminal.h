/*Este modulo sirve para que todo el programa funcione en Linux,
es lo mas cercano a linux*/

#ifndef TERMINAL_H
#define TERMINAL_H

/*
 * Códigos utilizados para identificar
 * las teclas especiales.
 */
#define TECLA_ARRIBA 1
#define TECLA_ABAJO 2
#define TECLA_ENTER 3
#define TECLA_ESC 4
#define TECLA_OTRA 0

/*
 * Activa el modo RAW de la terminal.
 */
void activarModoRaw(void);

/*
 * Restaura la configuración original
 * de la terminal.
 */
void restaurarTerminal(void);

/*
 * Lee una tecla del teclado.
 */
int leerTecla(void);

/*
 * Limpia la pantalla.
 */
void limpiarPantalla(void);

#endif
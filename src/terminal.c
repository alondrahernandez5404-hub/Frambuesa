/*Permite leer las teclas en la terminal
y restaurarlas cuando ya no se usen en terminal*/

#include <stdio.h>
#include <unistd.h>
#include <termios.h>

#include "../include/terminal.h"
static struct termios terminalOriginal;

void activarModoRaw(void)
{
    struct termios raw;

    tcgetattr(STDIN_FILENO, &terminalOriginal);

    raw = terminalOriginal;

    raw.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void restaurarTerminal(void)
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &terminalOriginal);
}

int leerTecla(void)
{
    char c = getchar();
        if (c == '\n')
    {
        return TECLA_ENTER;
    }

    if (c == 27)
    {
        char siguiente = getchar();

        if (siguiente == '[')
        {
            char direccion = getchar();

            switch (direccion)
            {
                case 'A':
                    return TECLA_ARRIBA;

                case 'B':
                    return TECLA_ABAJO;

                default:
                    return TECLA_OTRA;
            }
        }

        return TECLA_ESC;
    }

    return TECLA_OTRA;
}

void limpiarPantalla(void)
{
    printf("\033[2J");
    printf("\033[H");

    fflush(stdout);
}
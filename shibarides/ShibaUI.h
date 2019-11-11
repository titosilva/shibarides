#ifndef SHIBA_UI_H__
#define SHIBA_UI_H__

// Inclusão da biblioteca curses
#ifdef __unix__
    #include <ncurses.h>
#endif // __unix__

#ifdef _WIN32
#endif // _WIN32

#define ARROWDOWN    66
#define ARROWUP      65
#define ARROWLEFT    68
#define ARROWRIGHT   67
#define ENTER        10

// Função para obter eventos de key press
int kbhit(void);

#endif

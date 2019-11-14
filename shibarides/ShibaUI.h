#ifndef SHIBA_UI_H__
#define SHIBA_UI_H__

// Inclusão da biblioteca curses
#ifdef __unix__
    #include <ncurses.h>
#endif // __unix__

#ifdef _WIN32
    #include <curses.h>
#endif // _WIN32

#define ARROWDOWN    KEY_DOWN
#define ARROWUP      KEY_UP
#define ARROWLEFT    KEY_LEFT
#define ARROWRIGHT   KEY_RIGHT
#define ENTER        10
#define BACKSPACE    KEY_BACKSPACE

// Função para obter eventos de key press
int kbhit(void);

#endif

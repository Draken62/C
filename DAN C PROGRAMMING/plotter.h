#ifndef PLOTTER_H
#define PLOTTER_H

/*
 * Erases the given canvas buffer, by filling its contents with the value 0.
 */
void erase(char *canvas);

/*
 * Fills the given canvas with the given char value.
 */
void fill(char *canvas, char c);

/*
 * Plots the given char value at coordinates x,y in the given canvas buffer.
 */
void plot(char *canvas, int x, int y, char c);

/*
 * Replaces all instances of char old with char new in the given canvas buffer.
 */
void replace(char *canvas, char old, char new);

#endif
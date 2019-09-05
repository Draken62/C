#include <stdio.h>
#include "common.h"
#include <stdio.h>
#include <string.h>
#include "canvas.h"
#include "renderer.h"
#include "plotter.h"
#include <math.h>
/*
 * Erases the given canvas buffer, by filling its contents with the value 0.
 */
void erase(char *canvas) {
    int i = 0;
    while(*(canvas + i) != FINSISHEDOPERATION) {
        *(canvas + i) = ERASE_VALUE;
        i++;
    }
}

/*
 * Fills the given canvas with the given char value.
 */
void fill(char *canvas, char c) {
    int i = 0;
    while(*(canvas + i) != FINSISHEDOPERATION) {
        *(canvas + i) = c;
        i++;
    }
}

/*
 * Plots the given char value at coordinates x,y in the given canvas buffer.
 */
void plot(char *canvas, int x, int y, char c) {
    int lineLength = getWidth(canvas);
    if(lineLength == WIDTH_UNKNOWN) {
        ;
    }else {
        *(canvas + (y * lineLength) + x) = c;
    }
}

/*
 * replaces on canvas with new one 
 */
void replace(char *canvas, char old, char new) {
int i = 0;
while(*(canvas + i) != FINSISHEDOPERATION) {
if(*(canvas + i) == old) {
*(canvas + i) = new;
}
i++;
}
}
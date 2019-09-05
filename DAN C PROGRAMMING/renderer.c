#include <stdio.h>
#include "common.h"
#include <stdio.h>
#include <string.h>
#include "canvas.h"
#include "renderer.h"
#include "plotter.h"
#include <math.h>

static void (*handler)(char *msg);

/*
 * echos the result to console 
 */
void paint(char *canvas) {
    int i = 0, charCounter = 0;
    int lineLength = getWidth(canvas);

    //Common.c getWIdth implementation gives me the length of line for canvas
    while(*(canvas + i) != FINSISHEDOPERATION ) {
        if(*(canvas + i) != 0) {
            putchar(*(canvas + i));
            charCounter++;
        }
        i++;

        //output newline if a whole line has been printed
        if(i%lineLength == 0 && charCounter > 0) {
            printf("\n");
        }
    }
    //after painting send message to handler in main
    handler(MSG_PRINTING_CANVAS);
}


void registerRendererCallback(void (*callback)(char *message)) {
    handler = callback;
}
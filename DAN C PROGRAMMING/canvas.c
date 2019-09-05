#include <stdio.h>
#include "common.h"
#include <stdio.h>
#include <string.h>
#include "canvas.h"
#include "renderer.h"
#include "plotter.h"
#include <math.h>
#define BASELINE 0

static char bigBuffer[BUFFERSIZE];
static void (*handler)(char *msg);

//this variable holds the index of the buffer baseline 
static int index = BASELINE;
//this variable holds the index of the last created canvas
static int firstIndex = BASELINE;



void registerCanvasCallback(void (*callback)(char *message)) {
    handler = callback;
}

char *getCanvas(int height) {
    int canvasSize = height * height;

    if (index + canvasSize >= BUFFERSIZE) {
        //print passed message using function passed by registerCanvasCallback
        handler(MSG_ERR_OUT_OF_MEMORY);
        return NULL; //NULL is defined in stdef.h file
    }
   //variable for pointing at canvas
    char* newCanvas = &bigBuffer[index];
    //monitors the index
    firstIndex = index;

    index += canvasSize; //last index and size of new canvas
    bigBuffer[index] = FINSISHEDOPERATION; // assigning -1 to the last index

    index++; //new index is now at next available position in buffer

    return newCanvas;
}


int freeCanvas(char* canvas) {
    //DECREASE index by 2
    int i = firstIndex - 2;

    if(canvas != &(bigBuffer[firstIndex])) {
        handler(MSG_ERR_FREE_CANVAS_FAILURE);
        return 1;
    }

    index = firstIndex;
    for(;(bigBuffer[i]!=FINSISHEDOPERATION) && i != BASELINE; --i) { ; }

    firstIndex = i + 1;
    handler(MSG_INFO__CANVAS_FREED);
    return SUCCESS_VALUE;
}

int clone(char *srcCanvas, char* targetCanvas) {
    int i = 0, x = 0, y = 0;

    //those functions calculate the size of each canvas, so we are sure src will fit in target
    //I wrote getLength function because the code was being replicated 3 times.
    x = getLength(srcCanvas);
    y = getLength(targetCanvas);

    //clone only if target is bigger or equal to src, otherwise output error
    if(x <= y) {
        for(; srcCanvas[i] != FINSISHEDOPERATION; i++) {
            *(targetCanvas + i) = *(srcCanvas + i);
        }
    }else {
        handler(MSG_ERR_CLONE_CANVAS_FAILURE);
    }

    return SUCCESS_VALUE;
}
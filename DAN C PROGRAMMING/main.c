#include <stdio.h>
#include <string.h>
#include "canvas.h"
#include "renderer.h"
#include "plotter.h"
#include <math.h>




void testGetCanvas();
void testPaintCanvas();
void testFreeCanvas();
void testCloneCanvas();

void registerCallbacks();
void callbackHandler();
void checkMessage(char *statusMessage, char *msgToCheck);
int getSize(char *canvas);

char *lastMessage;

int main() {
    registerCallbacks();
    testGetCanvas();
    testPaintCanvas();
    testFreeCanvas();
    testCloneCanvas();
}

void testGetCanvas() {
    char *canvas = getCanvas(100);
    printf("Check canvas is null: %s\n", canvas == NULL ? "[PASS]" : "[FAIL]");
    checkMessage("Received out of memory message: %s\n", MSG_ERR_OUT_OF_MEMORY);
    canvas = getCanvas(10);
    int canvasSize = getSize(canvas);
    printf("Check canvas size: %s\n", canvasSize == 100 ? "[PASS]" : "[FAIL]");
}

void testPaintCanvas() {
    char *canvas = getCanvas(10);
    fill(canvas, '.');
    paint(canvas);
    checkMessage("Received painting message: %s\n", MSG_PRINTING_CANVAS);

    erase(canvas);
    paint(canvas);
    checkMessage("Received painting message: %s\n", MSG_PRINTING_CANVAS);

    // letter C
    for(int i=1; i < 8; i++) {
        plot(canvas, i, 1, '.');
        plot(canvas, 1, i, '.');
        plot(canvas, i, 8, '.');
    }

    paint(canvas);
    checkMessage("Received painting message: %s\n", MSG_PRINTING_CANVAS);

    replace(canvas, '.', '+');
    paint(canvas);

    // inverse
    replace(canvas, '+', '-');
    replace(canvas, 0, '+');
    replace(canvas, '-', '0');

    paint(canvas);

    // clean up
    erase(canvas);
    paint(canvas);
}

void testFreeCanvas() {
    char *canvasA = getCanvas(10);
    char *canvasB = getCanvas(10);
    freeCanvas(canvasA);
    checkMessage("Received free error message: %s\n", MSG_ERR_FREE_CANVAS_FAILURE);
    freeCanvas(canvasB);
    checkMessage("Received free success message: %s\n", MSG_INFO__CANVAS_FREED);
    freeCanvas(canvasA);
    checkMessage("Received free success message: %s\n", MSG_INFO__CANVAS_FREED);
}

void testCloneCanvas() {
    char *canvasA = getCanvas(10);
    paint(canvasA);
    char *canvasB = getCanvas(10);
    paint(canvasB);
    fill(canvasA, '@');
    clone(canvasA, canvasB);
    paint(canvasB);
    freeCanvas(canvasB);
    checkMessage("Received free success message: %s\n", MSG_INFO__CANVAS_FREED);
    freeCanvas(canvasA);
    checkMessage("Received free success message: %s\n", MSG_INFO__CANVAS_FREED);
}

void registerCallbacks() {
    registerCanvasCallback(callbackHandler);
    registerRendererCallback(callbackHandler);
}

void callbackHandler(char *message) {
    printf("%s\n", message);
    lastMessage = message;
}

void checkMessage(char *statusMessage, char *msgToCheck) {
    int match = strcmp(msgToCheck, lastMessage);
    printf(statusMessage, match ? "[FAIL]" : "[PASS]");
    lastMessage = NULL;
}

int getSize(char *canvas) {
    int size=0;
    while(*(canvas + size) != -1 && size < 10000) size++;
    return size;
}
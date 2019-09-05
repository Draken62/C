#ifndef CANVAS_H
#define CANVAS_H

#define MSG_ERR_OUT_OF_MEMORY "Not enough memory!"
#define MSG_ERR_FREE_CANVAS_FAILURE "Can't free canvas!"
#define MSG_ERR_CLONE_CANVAS_FAILURE "Can't clone canvas!"
#define MSG_INFO__CANVAS_FREED "Canvas freed!"

/*
 * Returns a char buffer of length (height x height) to the caller.
 * Returns NULL if a buffer cannot be allocated.
 */
char *getCanvas(int height);

/*
 * Frees the given char buffer.
 * Buffers must be freed in a LIFO fashion.
 * Returns 0 if the operation completes succesfully, nonzero otherwise.
 */
int freeCanvas(char *canvas);

/*
 * Clones the content of buffer srcCanvas to buffer targetCanvas.
 * Returns 0 if the operation completes succesfully, nonzero otherwise.
 */
int clone(char *srcCanvas, char* targetCanvas);

/*
 * Registers a callback function, which will be invoked to pass message
 * strings during certain library operations.
 */
void registerCanvasCallback(void (*callback)(char *message));

#endif
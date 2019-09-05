#ifndef RENDERER_H
#define RENDERER_H

#define MSG_BAD_CANVAS "Failed to paint bad canvas!"
#define MSG_PRINTING_CANVAS "Painting canvas!"

/*
 * Paints the given canvas buffer by echoing its contents to the console.
 */
void paint(char *canvas);

/*
 * Registers a callback function, which will be invoked to pass message
 *
 */
void registerRendererCallback(void (*callback)(char *message));

#endif
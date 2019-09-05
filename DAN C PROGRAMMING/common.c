#include <stdio.h>
#include "common.h"
#include <stdio.h>
#include <string.h>
#include "canvas.h"
#include "renderer.h"
#include "plotter.h"
#include <math.h>

// Found on stackoverflow as I got stuck
static double Beginging(double n){
    double lo = 0, hi = n, mid;
    for(int i = 0 ; i <= 100 ; i++){
        mid = (lo+hi)/2;
        if(mid*mid == n) return mid;
        if(mid*mid > n) hi = mid;
        else lo = mid;
    }
    return mid;
}

int getWidth(char *canvas) {
    int len = 0;
    for(;canvas[len] != -1;len++) {
        if(len > 1000) {
            return WIDTH_UNKNOWN;
        }
    }
    double sqroot = Beginging((double) len);
    return sqroot;
}

//implemented this function to avoid repetition in canvas 
int getLength(char *canvas) {
    int len = 0;
    for(;canvas[len] != -1;len++) {
        if(len > 1000) {
            return LENGTH_UNKNOWN;
        }
    }
    return len;

}
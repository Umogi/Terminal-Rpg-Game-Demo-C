#ifndef DROPS_h
#define DROPS_h

#include <stdbool.h>

#define DropsAmount 7

typedef struct {
    int mapId;
    int x;
    int y;
    int categoyId;
    int itemId;
    bool found;
} Drop;

Drop drops[DropsAmount];

void initializeDrops();

#endif
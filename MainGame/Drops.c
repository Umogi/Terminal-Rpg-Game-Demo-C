#include "Public.h"

#include "Drops.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 
#include <unistd.h>

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
#elif defined(__linux__)||define(__APPLE__)
    #include <unistd.h>
    #include <termios.h>
    void Sleep(int ms){
    	usleep(ms * 1000)
    }

    int _getch() {
        struct termios oldt, newt;
        int ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }
#endif

void initializeDrops(){

    drops[0] = (Drop){
        .mapId = 16,
        .x = 1,
        .y = 1,
        .categoyId = 1,
        .itemId = 1,
        .found = false
    };

    drops[1] = (Drop){
        .mapId = 17,
        .x = 1,
        .y = 5,
        .categoyId = 3,
        .itemId = 6,
        .found = false
    };

    drops[2] = (Drop){
        .mapId = 18,
        .x = 3,
        .y = 9,
        .categoyId = 0,
        .itemId = 7,
        .found = false
    };

    drops[3] = (Drop){
        .mapId = 19,
        .x = 1,
        .y = 5,
        .categoyId = 2,
        .itemId = 4,
        .found = false
    };

    drops[4] = (Drop){
        .mapId = 15,
        .x = 3,
        .y = 7,
        .categoyId = 3,
        .itemId = 7,
        .found = false
    };

    drops[5] = (Drop){
        .mapId = 13,
        .x = 2,
        .y = 5,
        .categoyId = 2,
        .itemId = 5,
        .found = false
    };

    drops[6] = (Drop){
        .mapId = 8,
        .x = 1,
        .y = 1,
        .categoyId = 0,
        .itemId = 0,
        .found = false
    };

}

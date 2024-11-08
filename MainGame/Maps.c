#include "Maps.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 
#include <unistd.h>
#include <stdbool.h>

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

int map[XLength][YLength];

char map0[XLength][YLength] = {
    {"+----^----+"},
    {"|       ~~|"},
    {"|~     ~~~|"},
    {"|~~    ~~ |"},
    {"|~~~      |"},
    {"| ~~~     |"},
    {"|~~      ~|"},
    {"+---------+"}
};

char map1[XLength][YLength] = {
    {"+----------^----------+"},
    {"|                     |"},
    {"|   ---         ---   |"},
    {"|  / 0 \\       / 0 \\  |"},
    {"|  +---+       +---+  |"},
    {"|  |=O=|       |=O=|  |"},
    {"|                     |"},
    {"|         ---         |"},
    {"|        / 0 \\        |"},
    {"|     ---|===|---     |"},
    {"|    / 0 \\   / 0 \\    |"},
    {"|    #---#---#---#    |"},
    {"|    |=0=][O][=0=|    |"},
    {"|                     |"},
    {"|                     |"},
    {"+----------v----------+"}
};

char map2[XLength][YLength] = {
    {"+--------------------+"},
    {"<                    >"},
    {"|   -     -------    |"},
    {"|  / \\   / 0   0 \\   |"},
    {"|  +=+   +---+---+   |"},
    {"|  |O|   |=0=O=0=|   |"},
    {"|                    |"},
    {"|                    |"},
    {"+----------v---------+"}
};

char map3[XLength][YLength] = {
    {"+---------+"},
    {"|         >"},
    {"|         |"},
    {"|         |"},
    {"|         |"},
    {"|         |"},
    {"|         |"},
    {"|         |"},
    {"|         |"},
    {"|         |"},
    {"+---------+"}
};

char map4[XLength][YLength] = {
    {"+------^------+"},
    {"<          ~~~|"},
    {"|           ~~|"},
    {"|    -----   ~|"},
    {"|   / -0- \\   |"},
    {"|  / 0[ ]0 \\  |"},
    {"|  +-------+  |"},
    {"|  |=0{O}0=|  |"},
    {"|             |"},
    {"|             |"},
    {"+------v------+"}
};

char map5[XLength][YLength] = {
    {"+----------^----------+"},
    {"|                     |"},
    {"|                     |"},
    {"|   -      -      -   |"},
    {"|  / \\    / \\    / \\  |"},
    {"|  +=+    +=+    +=+  |"},
    {"|  |O|    |O|    |O|  |"},
    {"|                     |"},
    {"|   -      -      -   |"},
    {"|  / \\    / \\    / \\  |"},
    {"|  +=+    +=+    +=+  |"},
    {"|  |O|    |O|    |O|  |"},
    {"|                     |"},
    {"|                     |"},
    {"+---------------------+"}
};


char map6[XLength][YLength] = {
    {"+----------^----------+"},
    {"|         | |         |"},
    {"|     _  /   \\  _     |"},
    {"|      \\-/   \\-/      |"},
    {"|      Y_H   H_Y      |"},
    {"|      |V/   \\V|      |"},
    {"|      /_/   \\_\\      |"},
    {"|     T Y / \\ Y T     |"},
    {"|    /  #-/ \\-#  \\    |"},
    {"|   | Y | / \\ | Y |   |"},
    {"|   | Y |/   \\| Y |   |"},
    {"|    \\_/       \\_/    |"},
    {"|      \\__| |__/      |"},
    {"|                     |"},
    {"|                     |"},
    {"|                     |"},
    {"+----------v----------+"}
};

char map7[XLength][YLength] = {
    {"+---------------------+"},
    {"|         MMM         |"},
    {"|        }|N|{        |"},
    {"|                     |"},
    {"|                     |"},
    {"+----------v----------+"}
};

char room101[XLength][YLength] = {//8
    {"+---0000---^---0000---+"},
    {"| |                 | |"},
    {"0 |        N        | 0"},
    {"0 |                 | 0"},
    {"|                     |"},
    {"+---0000---O---0000---+"}
};

char room102[XLength][YLength] = {//9
    {"      +----^----+      "},
    {"      |         |      "},
    {"      0         0      "},
    {"      |         |      "},
    {"      +---000---+      "}
};

char room103[XLength][YLength] = {//10
    {"+-00---00-+"},
    {"|         |"},
    {"0         0"},
    {"|         |"},
    {"+-00-O-00-+"}
};

char room104[XLength][YLength] = {//11
    {"+-00---00-+"},
    {"|         |"},
    {"0         0"},
    {"|         |"},
    {"+-00-O-00-+"}
};

char room201[XLength][YLength] = {//12
    {"+-0-00-0-00-0-+"},
    {"|             |"},
    {"0             0"},
    {"|             |"},
    {"+-000--O--000-+"}
};

char room202[XLength][YLength] = {//13
    {"+-00---00-+"},
    {"|         |"},
    {"0         0"},
    {"|         |"},
    {"+-00-O-00-+"}
};

char room401[XLength][YLength] = {//14
    {"+-0-00-^-00-0-+"},
    {"|             |"},
    {"0             0"},
    {"|             |"},
    {"+-000--O--000-+"}
};

char room402[XLength][YLength] = {//15
    {"+-0-00-^-00-0-+"},
    {"|             |"},
    {"0             0"},
    {"|             |"},
    {"+--00-000-00--+"}
};

char room501[XLength][YLength] = {//16
    {"+-00---00-+"},
    {"|         |"},
    {"0         0"},
    {"|         |"},
    {"+-00-O-00-+"}
};

char room502[XLength][YLength] = {//17
    {"+-00---00-+"},
    {"|         |"},
    {"0         0"},
    {"|         |"},
    {"+-00-O-00-+"}
};

char room503[XLength][YLength] = {//18
    {"+-00---00-+"},
    {"|         |"},
    {"0         0"},
    {"|         |"},
    {"+-00-O-00-+"}
};

char room504[XLength][YLength] = {//19
    {"+-00---00-+"},
    {"|         |"},
    {"0         0"},
    {"|         |"},
    {"+-00-O-00-+"}
};

char room505[XLength][YLength] = {//20
    {"+-00---00-+"},
    {"|         |"},
    {"0         0"},
    {"|         |"},
    {"+-00-O-00-+"}
};

char room506[XLength][YLength] = {//21
    {"+-00---00-+"},
    {"|         |"},
    {"0         0"},
    {"|         |"},
    {"+-00-O-00-+"}
};

int MapTempID = 0;

int MapItemFound[ItmeOnMapAmount] = {0, 0};

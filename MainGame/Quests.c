#include "Quests.h"

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

void initializeQuests(){

    quests[0] = (Quest){
        .QuestID = 0,
        .quest_line1 = false,
        .quest_line2 = false,
        .quest_line3 = false,
        .quest_line4 = false,
        .quest_line5 = false
    };
}


void NPCLines(int mapId){

    char Command;

    if(mapId == 8){
        if(quests[0].quest_line2 == false){
            printf("Ah, traveler. Wisdom often comes from chance encounters,\n");
            printf("wouldn't you agree? The road ahead is full of lessons and challenges.\n");
            Command = _getch();
            printf("\nI sense bravery in you. There are two dark creatures near the old ruins. If you deal\n");
            printf("with them, the path might become clearer.\n");
            Command = _getch();
            printf("\nWill you take on this small quest? Your choices today could guide your journey.\n");
            Command = _getch();
            quests[0].quest_line1 = true;
        }else if(quests[0].quest_line2 == true){
            printf("Ah, I see the task is done. Your courage has indeed cleared a path through the shadows.\n");
            Command =_getch();
            printf("\nEach victory shapes the journey, and yours is no exception. The road ahead may \n");
            printf("now reveal its secrets more openly.\n");
            Command = _getch();
            printf("\nContinue with this spirit, and wisdom will find you in due time. Safe travels, brave one.\n");
            Command = _getch();
            quests[0].quest_line3 = true;
        }
    }else if(mapId == 7){
        printf("You have done the impossible! The dragon, the scourge of our land, is no more. Your bravery \n");
        printf("and strength have brought peace to the realm.\n");
        Command = _getch();
        printf("\nThis victory is not just yours, but a triumph for all who call this land home. The shadow that loomed \n");
        printf("over us has been lifted, and it is thanks to your courage.\n");
        Command = _getch();
        printf("\nYou shall forever be honored as the hero of this kingdom. May your name be remembered for \n");
        printf("generations. Go now, with our deepest gratitude, and know that you have earned a place in the\n");
        printf("annals of history.\n");
        Command = _getch();
        quests[0].quest_line5 = true;
    }

}

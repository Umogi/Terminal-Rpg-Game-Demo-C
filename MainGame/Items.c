#include "Items.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

#define ItemAmount 8

void initializeItems(){
    items[0] = (Item){
        .name = "Health Potion",
        .mass = 0,
        .amount = 30,
        .Hp = true,
        .Mana = false,
        .Stamina = false
    };

    items[1] = (Item){
        .name = "Stamina Elixir",
        .mass = 1,
        .amount = 10,
        .Hp = false,
        .Mana = true,
        .Stamina = false
    };

    items[2] = (Item){
        .name = "Mana Crystal",
        .mass = 1,
        .amount = 5,
        .Hp = false,
        .Mana = false,
        .Stamina = true
    };

    items[3] = (Item){
        .name = "Revitalizing Herb",
        .mass = 1,
        .amount = 50,
        .Hp = false,
        .Mana = true,
        .Stamina = false
    };

    items[4] = (Item){
        .name = "Energy Drink",
        .mass = 1,
        .amount = 10,
        .Hp = true,
        .Mana = false,
        .Stamina = false
    };

    items[5] = (Item){
        .name = "Mystic Berry",
        .mass = 1,
        .amount = 15,
        .Hp = false,
        .Mana = true,
        .Stamina = true
    };

    items[6] = (Item){
        .name = "Phoenix Feather",
        .mass = 1,
        .amount = 100,
        .Hp = true,
        .Mana = false,
        .Stamina = true
    };

    items[7] = (Item){
        .name = "Endurance Potion",
        .mass = 0,
        .amount = 200,
        .Hp = true,
        .Mana = false,
        .Stamina = false
    };
}

void ItemInspector(){
    char Command;
    int OptionPointer = 0;

    int ItemsBuffer[ItemAmount];

    for ( int i = 0; i < ItemAmount; i++){
        ItemsBuffer[i] = -1;
    }

    int amount = 0;
    
    system("cls||clear");

    for(int i = 0; i < ItemAmount; i++){
        if(items[i].mass != 0){
            ItemsBuffer[amount] = i;
            amount++;
        } 
    }

    while(1){
        system("cls||clear");

        printf("======== Items ========\n");

        for(int i = 0; i < amount; i++){
            if(OptionPointer == i){printf(">");}
            printf("%d %s: ", items[ItemsBuffer[i]].mass, items[ItemsBuffer[i]].name);
            if(items[ItemsBuffer[i]].Hp == true) printf(" HP %d", items[ItemsBuffer[i]].amount);
            if(items[ItemsBuffer[i]].Stamina == true) printf(" Stamina %d ", items[ItemsBuffer[i]].amount);
            if(items[ItemsBuffer[i]].Mana == true) printf(" Mana %d ", items[ItemsBuffer[i]].amount);
            printf("\n");
        }   

        printf("=======================\n");

        Command = _getch();

        if(Command=='w' && OptionPointer > 0){
            OptionPointer--;
        }else if(Command=='s' && OptionPointer < amount-1){
            OptionPointer++; 
        }else if(Command=='e'){   
            printf("you can't use that right now!");
            sleep(2);
        }else if(Command=='q'){
            break;
        }
    }   
}

#include "Public.h"

#include "Talisman.h"

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

void initializeTalisman(){

    talismants[0] = (Talisman){
        .name = "Talisman of Vitality",
        .owned = true,
        .hp_plus = 5,
        .hp_recover = 0,
        .stamina_plus = 0,
        .stamina_recover = 0,
        .mana_plus = 0,
        .mana_recover = 0,
        .strenght = 0,
        .dexeterity = 0,
        .intelligence = 0,
        .faith = 0,
        .arcane = 0
    };

    talismants[1] = (Talisman){
        .name = "Talisman of Wisdom",
        .owned = false,
        .hp_plus = 5,
        .hp_recover = 0,
        .stamina_plus = 0,
        .stamina_recover = 0,
        .mana_plus = 0,
        .mana_recover = 0,
        .strenght = 0,
        .dexeterity = 0,
        .intelligence = 0,
        .faith = 0,
        .arcane = 0
    };

    talismants[2] = (Talisman){
        .name = "Talisman of Endurance",
        .owned = true,
        .hp_plus = 0,
        .hp_recover = 0,
        .stamina_plus = 0,
        .stamina_recover = 0,
        .mana_plus = 0,
        .mana_recover = 5,
        .strenght = 0,
        .dexeterity = 0,
        .intelligence = 0,
        .faith = 0,
        .arcane = 0
    };

    talismants[3] = (Talisman){
        .name = "Talisman of Power",
        .owned = true,
        .hp_plus = 5,
        .hp_recover = 0,
        .stamina_plus = 5,
        .stamina_recover = 0,
        .mana_plus = 0,
        .mana_recover = 0,
        .strenght = 0,
        .dexeterity = 0,
        .intelligence = 5,
        .faith = 0,
        .arcane = 0
    };

    talismants[4] = (Talisman){
        .name = "Talisman of Faith",
        .owned = true,
        .hp_plus = 5,
        .hp_recover = 0,
        .stamina_plus = 0,
        .stamina_recover = 0,
        .mana_plus = 0,
        .mana_recover = 0,
        .strenght = 0,
        .dexeterity = 0,
        .intelligence = 0,
        .faith = 5,
        .arcane = 0
    };

    talismants[5] = (Talisman){
        .name = "Talisman of Arcana",
        .owned = true,
        .hp_plus = 0,
        .hp_recover = 0,
        .stamina_plus = 0,
        .stamina_recover = 0,
        .mana_plus = 0,
        .mana_recover = 0,
        .strenght = 0,
        .dexeterity = 0,
        .intelligence = 0,
        .faith = 0,
        .arcane = 5
    };

    talismants[6] = (Talisman){
        .name = "Talisman of Regeneration",
        .owned = true,
        .hp_plus = 0,
        .hp_recover = 10,
        .stamina_plus = 0,
        .stamina_recover = 10,
        .mana_plus = 0,
        .mana_recover = 10,
        .strenght = 0,
        .dexeterity = 0,
        .intelligence = 0,
        .faith = 0,
        .arcane = 0
    };

    talismants[7] = (Talisman){
        .name = "Talisman of Protection",
        .owned = true,
        .hp_plus = 5,
        .hp_recover = 0,
        .stamina_plus = 0,
        .stamina_recover = 0,
        .mana_plus = 0,
        .mana_recover = 0,
        .strenght = 0,
        .dexeterity = 5,
        .intelligence = 0,
        .faith = 0,
        .arcane = 0
    };
}

void TalismantDisplay(){

    int TalismanPointer = 0;
    char Command;
    int temp;

    while(1){

        int TalismanBuffer[TalismanAmount] = {-1, -1, -1, -1, -1, -1, -1, -1};

        Talisman ID_1 = talismants[PlayerTalisman[TalismanPointer]];

        system("cls||clear");

        printf("To Unequipt press 'R'\n\n");
        printf("==== My Talismans ====\n");
        if(TalismanPointer == 0){printf(">");}
        if(PlayerTalisman[0] != -1){printf("%s \n", talismants[PlayerTalisman[0]].name);
        }else{printf("X \n");}
        if(TalismanPointer == 1){printf(">");}
        if(PlayerTalisman[1] != -1){printf("%s \n", talismants[PlayerTalisman[1]].name);
        }else{printf("X \n");}
        if(TalismanPointer == 2){printf(">");}
        if(PlayerTalisman[2] != -1){printf("%s \n", talismants[PlayerTalisman[2]].name);
        }else{printf("X \n");}
        if(TalismanPointer == 3){printf(">");}
        if(PlayerTalisman[3] != -1){printf("%s \n", talismants[PlayerTalisman[3]].name);
        }else{printf("X \n");}
        printf("======================\n");

        if(PlayerTalisman[TalismanPointer] != -1){
            printf("\n");

            printf("%s\n", ID_1.name);
            if (ID_1.hp_plus > 0) printf("| Adds %d levels of HP\n", ID_1.hp_plus);
            if (ID_1.hp_recover > 0) printf("| Recover %d HP\n", ID_1.hp_recover);
            if (ID_1.stamina_plus > 0) printf("| Adds %d levels of Stamina\n", ID_1.stamina_plus);
            if (ID_1.stamina_recover > 0) printf("| Recover %d Stamina\n", ID_1.stamina_recover);
            if (ID_1.mana_plus > 0) printf("| Adds %d levels of Mana:\n", ID_1.mana_plus);
            if (ID_1.mana_recover > 0) printf("| Recover %d Mana\n", ID_1.mana_recover);
            if (ID_1.strenght > 0) printf("| Adds %d levels of Strength\n", ID_1.strenght);
            if (ID_1.dexeterity > 0) printf("| Adds %d levels of Dexterity\n", ID_1.dexeterity);
            if (ID_1.intelligence > 0) printf("| Adds %d levels of Intelligence\n", ID_1.intelligence);
            if (ID_1.faith > 0) printf("| Adds %d levels of Faith\n", ID_1.faith);
            if (ID_1.arcane > 0) printf("| Adds %d levels of Arcane\n", ID_1.arcane); 

            printf("!\n");
        }
        
        Command = _getch();

        if(Command == 'w' && TalismanPointer > 0){
            TalismanPointer--;
        }else if(Command == 's' && TalismanPointer < 3){
            TalismanPointer++;
        }else if(Command == 'e'){ 

            int TalismanPointerEquipt = 0;
            int amount = 0;
            
            for(int i = 0; i < TalismanAmount; i++){
                if(talismants[i].owned == true ){
                    if(PlayerTalisman[0] != i && PlayerTalisman[1] != i && PlayerTalisman[2] != i && PlayerTalisman[3] != i){
                        TalismanBuffer[amount] = i;
                        amount++;
                    }
                }
            }

            while (1){
                system("cls||clear");

                printf("====== Talismants ======\n");

                    for (int i = 0; i < amount; i++){
                        if(TalismanPointerEquipt == i){printf(">");}
                        printf("%s\n", talismants[TalismanBuffer[i]].name);
                    }

                printf("=====================\n");

                Command = _getch();

                if(Command == 'w' && TalismanPointerEquipt > 0){
                    TalismanPointerEquipt--;
                }else if(Command == 's' && TalismanPointerEquipt < amount-1){
                    TalismanPointerEquipt++;
                }else if(Command == 'e'){
                    while (1){
                        Talisman ID_2 = talismants[TalismanBuffer[TalismanPointerEquipt]];

                        system("cls||clear");

                        printf("Press 'E' to add the Talisman\n\n");

                        printf("%s\n", ID_2.name);
                        
                        if (ID_2.hp_plus > 0) printf("| Adds %d levels of HP\n", ID_2.hp_plus);
                        if (ID_2.hp_recover > 0) printf("| Recover %d HP\n", ID_2.hp_recover);
                        if (ID_2.stamina_plus > 0) printf("| Adds %d levels of Stamina\n", ID_2.stamina_plus);
                        if (ID_2.stamina_recover > 0) printf("| Recover %d Stamina\n", ID_2.stamina_recover);
                        if (ID_2.mana_plus > 0) printf("| Adds %d levels of Mana:\n", ID_2.mana_plus);
                        if (ID_2.mana_recover > 0) printf("| Recover %d Mana\n", ID_2.mana_recover);
                        if (ID_2.strenght > 0) printf("| Adds %d levels of Strength\n", ID_2.strenght);
                        if (ID_2.dexeterity > 0) printf("| Adds %d levels of Dexterity\n", ID_2.dexeterity);
                        if (ID_2.intelligence > 0) printf("| Adds %d levels of Intelligence\n", ID_2.intelligence);
                        if (ID_2.faith > 0) printf("| Adds %d levels of Faith\n", ID_2.faith);
                        if (ID_2.arcane > 0) printf("| Adds %d levels of Arcane\n", ID_2.arcane);

                        printf("!\n");

                        Command = _getch();

                        if(Command == 'e'){
                            PlayerTalisman[TalismanPointer] = TalismanBuffer[TalismanPointerEquipt];
                        }

                        break;
                    }
                    break;
                }else if(Command == 'q'){
                    break;
                }
            }
        }else if(Command == 'r'){
            PlayerTalisman[TalismanPointer] = -1;
        }else if(Command == 'q'){
            break;
        }
    }

    
}

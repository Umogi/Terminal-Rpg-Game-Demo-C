#include "Public.h"

#include "Scrolls.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 
#include <windows.h>
#include <unistd.h>
#include <conio.h>

void initializeScrolls(){

    scrolls[0] = (Scroll){
        .name = "Scroll of Eclipsing Shadows",
        .owned = true,
        .strength_requirement = 0,
        .dexterity_requirement = 0,
        .intelligence_requirement = 12,
        .faith_requirement = 0,
        .arcane_requirement = 0,
        .damage_1 = 115,
        .abilitie_1 = "Shadow Reaper",
        .description_1 = "Summons a shadowy figure that drains the target's life force.",
        .mana_1 = 8,
        .damage_2 = 130,
        .abilitie_2 = "Umbral Vortex",
        .description_2 = "Creates a swirling vortex of darkness that disintegrates enemies.",
        .mana_2 = 12,
        .ice_damge = 0,
        .fire_damge = 0,
        .holy_damge = 0,
        .poison = 0,
        .bleed = 0,
        .burn = 0,
        .frost = 0,
        .category = Dark
    };

    scrolls[1] = (Scroll){
        .name = "Scroll of Arcane Tempest",
        .owned = true,
        .strength_requirement = 0,
        .dexterity_requirement = 9,
        .intelligence_requirement = 15,
        .faith_requirement = 0,
        .arcane_requirement = 0,
        .damage_1 = 117,
        .abilitie_1 = "Lightning Wrath",
        .description_1 = "Unleashes a powerful lightning bolt that electrocutes enemies.",
        .mana_1 = 7,
        .damage_2 = 135,
        .abilitie_2 = "Tempest Fury",
        .description_2 = "Summons a tempest that strikes all enemies with lightning.",
        .mana_2 = 13,
        .ice_damge = 0,
        .fire_damge = 0,
        .holy_damge = 0,
        .poison = 0,
        .bleed = 0,
        .burn = 0,
        .frost = 0,
        .category = Lightning
    };

    scrolls[2] = (Scroll){
        .name = "Scroll of Infernal Flames",
        .owned = true,
        .strength_requirement = 0,
        .dexterity_requirement = 0,
        .intelligence_requirement = 20,
        .faith_requirement = 0,
        .arcane_requirement = 0,
        .damage_1 = 120,
        .abilitie_1 = "Hellfire Blast",
        .description_1 = "Releases a wave of hellfire that incinerates everything in its path.",
        .mana_1 = 9,
        .damage_2 = 140,
        .abilitie_2 = "Inferno Surge",
        .description_2 = "Creates a massive inferno that engulfs enemies in flames.",
        .mana_2 = 11,
        .ice_damge = 0,
        .fire_damge = 100,
        .holy_damge = 0,
        .poison = 0,
        .bleed = 0,
        .burn = 0,
        .frost = 0,
        .category = Fire
    };

    scrolls[3] = (Scroll){
        .name = "Scroll of Frostbound Echoes",
        .owned = true,
        .strength_requirement = 0,
        .dexterity_requirement = 0,
        .intelligence_requirement = 25,
        .faith_requirement = 0,
        .arcane_requirement = 0,
        .damage_1 = 129,
        .abilitie_1 = "Glacial Spear",
        .description_1 = "Launches an icy spear that impales enemies, freezing them solid.",
        .mana_1 = 6,
        .damage_2 = 150,
        .abilitie_2 = "Frozen Cataclysm",
        .description_2 = "Unleashes a blizzard that freezes all enemies in its wake.",
        .mana_2 = 14,
        .ice_damge = 100,
        .fire_damge = 0,
        .holy_damge = 0,
        .poison = 0,
        .bleed = 0,
        .burn = 0,
        .frost = 0,
        .category = Ice
    };

    scrolls[4] = (Scroll){
        .name = "Scroll of Celestial Light",
        .owned = false,
        .strength_requirement = 0,
        .dexterity_requirement = 0,
        .intelligence_requirement = 30,
        .faith_requirement = 20,
        .arcane_requirement = 0,
        .damage_1 = 134,
        .abilitie_1 = "Holy Smite",
        .description_1 = "Calls down a beam of holy light that smites enemies.",
        .mana_1 = 8,
        .damage_2 = 155,
        .abilitie_2 = "Divine Wrath",
        .description_2 = "Unleashes divine wrath that purges all evil.",
        .mana_2 = 12,
        .ice_damge = 0,
        .fire_damge = 0,
        .holy_damge = 158,
        .poison = 0,
        .bleed = 0,
        .burn = 0,
        .frost = 0,
        .category = Holy
    };

    scrolls[5] = (Scroll){
        .name = "Scroll of Earthshaker",
        .owned = false,
        .strength_requirement = 15,
        .dexterity_requirement = 0,
        .intelligence_requirement = 0,
        .faith_requirement = 0,
        .arcane_requirement = 0,
        .damage_1 = 147,
        .abilitie_1 = "Quake Strike",
        .description_1 = "Strikes the ground, causing an earthquake that damages all enemies.",
        .mana_1 = 7,
        .damage_2 = 165,
        .abilitie_2 = "Stone Crush",
        .description_2 = "Crushes enemies with a massive boulder.",
        .mana_2 = 13,
        .ice_damge = 0,
        .fire_damge = 0,
        .holy_damge = 0,
        .poison = 0,
        .bleed = 0,
        .burn = 0,
        .frost = 0,
        .category = Earth
    };

    scrolls[6] = (Scroll){
        .name = "Scroll of Venomous Secrets",
        .owned = true,
        .strength_requirement = 0,
        .dexterity_requirement = 20,
        .intelligence_requirement = 15,
        .faith_requirement = 0,
        .arcane_requirement = 0,
        .damage_1 = 157,
        .abilitie_1 = "Toxic Cloud",
        .description_1 = "Releases a toxic cloud that poisons enemies.",
        .mana_1 = 6,
        .damage_2 = 170,
        .abilitie_2 = "Poison Fang",
        .description_2 = "Strikes enemies with a venomous bite.",
        .mana_2 = 14,
        .ice_damge = 0,
        .fire_damge = 0,
        .holy_damge = 0,
        .poison = 15,
        .bleed = 0,
        .burn = 0,
        .frost = 0,
        .category = Poison
    };

    scrolls[7] = (Scroll){
        .name = "Scroll of Ethereal Whispers",
        .owned = true,
        .strength_requirement = 0,
        .dexterity_requirement = 0,
        .intelligence_requirement = 35,
        .faith_requirement = 0,
        .arcane_requirement = 20,
        .damage_1 = 160,
        .abilitie_1 = "Soul Drain",
        .description_1 = "Drains the soul of the target, dealing ethereal damage.",
        .mana_1 = 9,
        .damage_2 = 175,
        .abilitie_2 = "Phantom Slash",
        .description_2 = "Slashes enemies with ethereal blades.",
        .mana_2 = 11,
        .ice_damge = 0,
        .fire_damge = 0,
        .holy_damge = 0,
        .poison = 0,
        .bleed = 0,
        .burn = 0,
        .frost = 0,
        .category = Dark
    };

}

void color(int stut, int ID){
    if(PlayerStuts[stut] < ID){
        printf("\033[0;31m");
    }else if(ID == 0){
        printf("\033[0m");
    }else if(PlayerStuts[stut] > ID){
        printf("\033[0;34m");
    }
}

void ScrollsDisplay(){

    const char* ScrollCategory[CategoryScrollAmount] = {
        "Fire",
        "Ice",
        "Dark", 
        "Holy",
        "Earth",
        "Potion"
    };

    int CategoryPointer = 0;
    char Command;
    
    while(1){
        system("cls||clear");

        printf("==== Category ====\n");

        for(int i = 0; i < CategoryScrollAmount; i++){
            if(CategoryPointer == i){printf(">");}
            printf("%s\n", ScrollCategory[i]);
        }

        printf("==================\n");

        Command = _getch();

        if(Command == 'w' && CategoryPointer > 0){
            CategoryPointer--;
        }else if(Command == 's' && CategoryPointer < CategoryScrollAmount-1){
            CategoryPointer++;
        }else if(Command == 'e'){
            int ScrollPointer = 0;
            int amount = 0;
            int scrollIdBuffer[ScrollAmount];

            //buffer
            for (int i = 0; i < ScrollAmount; i++) {
                if (scrolls[i].category == CategoryPointer){
                    scrollIdBuffer[amount] = i;
                    amount++;
                }
            }

            while (1){
                system("cls||clear");

                //print
                printf("====== Weopons ======\n");

                for (int i = 0; i < amount; i++) {
                    if(ScrollPointer == i){printf(">");}
                    printf(" %s\n", scrolls[scrollIdBuffer[i]].name);
                }

                printf("======================\n");

                Command = _getch();

                if(Command == 'w' && ScrollPointer > 0){
                    ScrollPointer--;
                }else if(Command == 's' && ScrollPointer < amount-1){
                    ScrollPointer++;
                }else if(Command == 'e'){
                    Scroll ID = scrolls[scrollIdBuffer[ScrollPointer]];

                    while (1){
                        system("cls||clear");

                        printf("%s\n", ID.name);
                        printf("| %s\n", ScrollCategory[ScrollPointer]);
                        printf("|\n");
                        printf("| Mana ( %d - %d )\n", ID.mana_1, ID.mana_2);
                        printf("!\n");
                        printf("%s\n", ID.abilitie_1);
                        printf("| %s\n", ID.description_1);
                        printf("!\n");
                        printf("%s\n", ID.abilitie_2);
                        printf("| %s\n", ID.description_2);
                        printf("!\n");
                        printf("Attribues Required\n");
                        color(3, ID.strength_requirement);
                        printf("| Str   %d\n", ID.strength_requirement);
                        printf("\033[0m");
                        color(4, ID.dexterity_requirement);
                        printf("| Dex   %d\n", ID.dexterity_requirement);
                        printf("\033[0m");
                        color(5, ID.intelligence_requirement);
                        printf("| Int   %d\n", ID.intelligence_requirement);
                        printf("\033[0m");
                        color(6, ID.faith_requirement);
                        printf("| Fai   %d\n", ID.faith_requirement);
                        printf("\033[0m");
                        color(7, ID.arcane_requirement);
                        printf("| Arc   %d\n", ID.arcane_requirement);
                        printf("\033[0m");
                        printf("!\n");

                        Command = _getch();

                        break;
                    
                    }
                    
                }else if(Command == 'q'){
                    break;
                }
            }
        }else if(Command == 'q'){
            break;
        }

    }
}
#include "Public.h"

#include "Weapons.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 
#include <windows.h>
#include <unistd.h>
#include <conio.h>

void initializeWeapons() {
    weapons[0] = (Weapon){
        .name = "Moonshadow Scimitar",
        .owned = true,
        .strength_requirement = 7,
        .dexterity_requirement = 0,
        .intelligence_requirement = 0,
        .faith_requirement = 0,
        .arcane_requirement = 10,
        .level_upgraded = 0,
        .added_damage = 8,
        .stamina_heavy = 24,
        .stamina_quick = 12,
        .physical_damage = 105,
        .ice_damge = 0,
        .fire_damge = 0,
        .holy_damge = 0,
        .poison = 0,
        .bleed = 20,
        .burn = 0,
        .frost = 0,
        .strength = 'C',
        .dexterity = '-',
        .intelligence = '-',
        .faith = '-',
        .arcane = 'B',
        .category = Scimitar
    };

    weapons[1] = (Weapon){
        .name = "Stormsong Rapier",
        .owned = true,
        .strength_requirement = 13,
        .dexterity_requirement = 0,
        .intelligence_requirement = 0,
        .faith_requirement = 0,
        .arcane_requirement = 0,
        .level_upgraded = 0,
        .added_damage = 8,
        .stamina_heavy = 20,
        .stamina_quick = 10,
        .physical_damage = 115,
        .ice_damge = 10,
        .fire_damge = 0,
        .holy_damge = 0,
        .poison = 0,
        .bleed = 0,
        .burn = 0,
        .frost = 0,
        .strength = 'C',
        .dexterity = '-',
        .intelligence = 'B',
        .faith = '-',
        .arcane = '-',
        .category = Rapier
    };

    weapons[2] = (Weapon){
        .name = "Bloodthorn Dagger",
        .owned = true,
        .strength_requirement = 18,
        .dexterity_requirement = 0,
        .intelligence_requirement = 0,
        .faith_requirement = 0,
        .arcane_requirement = 15,
        .level_upgraded = 0,
        .added_damage = 8,
        .stamina_heavy = 16,
        .stamina_quick = 8,
        .physical_damage = 100,
        .ice_damge = 0,
        .fire_damge = 0,
        .holy_damge = 0,
        .poison = 0,
        .bleed = 25,
        .burn = 0,
        .frost = 0,
        .strength = 'C',
        .dexterity = '-',
        .intelligence = '-',
        .faith = '-',
        .arcane = 'A',
        .category = Dagger
    };

    weapons[3] = (Weapon){
        .name = "Frostbane Longsword",
        .owned = true,
        .strength_requirement = 22,
        .dexterity_requirement = 0,
        .intelligence_requirement = 20,
        .faith_requirement = 0,
        .arcane_requirement = 0,
        .level_upgraded = 0,
        .added_damage = 8,
        .stamina_heavy = 36,
        .stamina_quick = 18,
        .physical_damage = 125,
        .ice_damge = 20,
        .fire_damge = 0,
        .holy_damge = 0,
        .poison = 0,
        .bleed = 0,
        .burn = 0,
        .frost = 0,
        .strength = 'C',
        .dexterity = '-',
        .intelligence = 'B',
        .faith = '-',
        .arcane = '-',
        .category = Longsword
    };

    weapons[4] = (Weapon){
        .name = "Emberstrike Katana",
        .owned = true,
        .strength_requirement = 29,
        .dexterity_requirement = 0,
        .intelligence_requirement = 25,
        .faith_requirement = 0,
        .arcane_requirement = 0,
        .level_upgraded = 0,
        .added_damage = 8,
        .stamina_heavy = 30,
        .stamina_quick = 15,
        .physical_damage = 135,
        .ice_damge = 0,
        .fire_damge = 20,
        .holy_damge = 0,
        .poison = 0,
        .bleed = 0,
        .burn = 0,
        .frost = 0,
        .strength = 'C',
        .dexterity = '-',
        .intelligence = 'B',
        .faith = '-',
        .arcane = '-',
        .category = Katana
    };

    weapons[5] = (Weapon){
        .name = "Verdant Viperblade",
        .owned = true,
        .strength_requirement = 34,
        .dexterity_requirement = 0,
        .intelligence_requirement = 0,
        .faith_requirement = 0,
        .arcane_requirement = 20,
        .level_upgraded = 0,
        .added_damage = 8,
        .stamina_heavy = 28,
        .stamina_quick = 14,
        .physical_damage = 140,
        .ice_damge = 0,
        .fire_damge = 0,
        .holy_damge = 0,
        .poison = 20,
        .bleed = 0,
        .burn = 0,
        .frost = 0,
        .strength = 'C',
        .dexterity = '-',
        .intelligence = '-',
        .faith = '-',
        .arcane = 'B',
        .category = Scimitar
    };

    weapons[6] = (Weapon){
        .name = "Celestial Saber",
        .owned = false,
        .strength_requirement = 50,
        .dexterity_requirement = 0,
        .intelligence_requirement = 0,
        .faith_requirement = 30,
        .arcane_requirement = 0,
        .level_upgraded = 0,
        .added_damage = 8,
        .stamina_heavy = 26,
        .stamina_quick = 13,
        .physical_damage = 150,
        .ice_damge = 0,
        .fire_damge = 0,
        .holy_damge = 20,
        .poison = 0,
        .bleed = 0,
        .burn = 0,
        .frost = 0,
        .strength = 'C',
        .dexterity = '-',
        .intelligence = '-',
        .faith = 'B',
        .arcane = '-',
        .category = Longsword
    };

    weapons[7] = (Weapon){
        .name = "Nightfall Broadsword",
        .owned = false,
        .strength_requirement = 69,
        .dexterity_requirement = 0,
        .intelligence_requirement = 0,
        .faith_requirement = 0,
        .arcane_requirement = 0,
        .level_upgraded = 0,
        .added_damage = 8,
        .stamina_heavy = 40,
        .stamina_quick = 20,
        .physical_damage = 160,
        .ice_damge = 0,
        .fire_damge = 0,
        .holy_damge = 0,
        .poison = 0,
        .bleed = 0,
        .burn = 0,
        .frost = 0,
        .strength = 'B',
        .dexterity = '-',
        .intelligence = '-',
        .faith = '-',
        .arcane = '-',
        .category = Broadsword
    };
}

void colorWeapon(int stut, int ID){
    if(PlayerStuts[stut] < ID){
        printf("\033[0;31m");
    }else if(ID == 0){
        printf("\033[0m");
    }else if(PlayerStuts[stut] > ID){
        printf("\033[0;34m");
    }
}

void WeaponsDisplay(){

    const char* WeaponsCategory[CategoryWeaponAmount] = {
        "Scimitar",
        "Rapier",
        "Dagger",
        "Longsword",
        "Katana",
        "Broadsword"
    };

    int CategoryPointer = 0;
    char Command;

    while (1){
        system("cls||clear");

        printf("==== Category ====\n");

        for(int i = 0; i < CategoryWeaponAmount; i++){
            if(CategoryPointer == i){printf(">");}
            printf("%s\n", WeaponsCategory[i]);
        }

        printf("==================\n");

        Command = _getch();

        if(Command == 'w' && CategoryPointer > 0){
            CategoryPointer--;
        }else if(Command == 's' && CategoryPointer < CategoryWeaponAmount-1){
            CategoryPointer++;
        }else if(Command == 'e'){
            int WeaponPointer = 0;
            int amount = 0;
            int weaponIdBuffer[WeaponAmount];

            //buffer
            for (int i = 0; i < WeaponAmount; i++) {
                if (weapons[i].category == CategoryPointer){
                    weaponIdBuffer[amount] = i;
                    amount++;
                }
            }

            while (1){
                system("cls||clear");

                //print
                printf("====== Weopons ======\n");

                for (int i = 0; i < amount; i++) {
                    if(WeaponPointer == i){printf(">");}
                    printf(" %s\n", weapons[weaponIdBuffer[i]].name);
                }

                printf("======================\n");

                Command = _getch();

                if(Command == 'w' && WeaponPointer > 0){
                    WeaponPointer--;
                }else if(Command == 's' && WeaponPointer < amount-1){
                    WeaponPointer++;
                }else if(Command == 'e'){
                    Weapon ID = weapons[weaponIdBuffer[WeaponPointer]];

                    while (1){
                        system("cls||clear");

                        printf("%s", ID.name);
                        if(ID.level_upgraded > 0){printf(" + %d", ID.level_upgraded);}
                        printf("\n");
                        printf("| %s\n", WeaponsCategory[CategoryPointer]);
                        printf("| Stamina ( %d - %d )\n", ID.stamina_quick, ID.stamina_heavy);
                        printf("!\n");

                        printf("Attack Power\n");
                        printf("| Physical  %d\n",ID.physical_damage + (ID.added_damage * ID.level_upgraded));
                        printf("| Ice       %d\n",ID.ice_damge + (ID.added_damage * ID.level_upgraded));
                        printf("| Fire      %d\n",ID.fire_damge + (ID.added_damage * ID.level_upgraded));
                        printf("| Holy      %d\n",ID.holy_damge + (ID.added_damage * ID.level_upgraded));
                        printf("!\n");

                        printf("Attribute Scaling\n");
                        printf("| Str   %c\n", ID.strength);
                        printf("| Dex   %c\n", ID.dexterity);
                        printf("| Int   %c\n", ID.intelligence);
                        printf("| Fai   %c\n", ID.faith);
                        printf("| Arc   %c\n", ID.arcane);
                        printf("!\n");

                        printf("Attribute Required\n");
                        colorWeapon(3, ID.strength_requirement);
                        printf("| Str   %d\n", ID.strength_requirement);
                        printf("\033[0m");
                        colorWeapon(4, ID.dexterity_requirement);
                        printf("| Dex   %d\n", ID.dexterity_requirement);
                        printf("\033[0m");
                        colorWeapon(5, ID.intelligence_requirement);
                        printf("| Int   %d\n", ID.intelligence_requirement);
                        printf("\033[0m");
                        colorWeapon(6, ID.faith_requirement);
                        printf("| Fai   %d\n", ID.faith_requirement);
                        printf("\033[0m");
                        colorWeapon(7, ID.arcane_requirement);
                        printf("| Arc   %d\n", ID.arcane_requirement);
                        printf("\033[0m");
                        printf("!\n");

                        printf("Passive Effects\n");
                        if(ID.poison > 0){printf("| Posion (%d)", ID.poison);}
                        if(ID.bleed > 0){printf("| bleed (%d)", ID.bleed);}
                        if(ID.burn > 0){printf("| burn (%d)", ID.burn);}
                        if(ID.frost > 0){printf("| frost (%d)", ID.frost);}
                        printf("!\n");

                        Command = _getch();

                        if(Command == 'e'){

                        }else if(Command == 'q'){
                            break;
                        }
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
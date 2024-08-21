#include "Enemies.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 
#include <windows.h>
#include <unistd.h>
#include <conio.h>

void initializeEnemies(){
    
    enemies[0] = (Enemy){
        .name = "Goblin",
        .Hp = 500,
        .At_1 = 10,
        .At_2 = 15,
        .physical_damage_resistance = 0,
        .ice_damage_resistance = 0,
        .fire_damage_resistance = 0,
        .holy_damage_resistance = 0,
        .poison_build = 100,
        .bleed_build = 100,
        .burn_build = 100,
        .frost_build = 100,
        .Xp = 100,
        .respawn = true
    };

    enemies[1] = (Enemy){
        .name = "Elf",
        .Hp = 720,
        .At_1 = 30,
        .At_2 = 60,
        .physical_damage_resistance = 0,
        .ice_damage_resistance = 0,
        .fire_damage_resistance = 0,
        .holy_damage_resistance = 0,
        .poison_build = 100,
        .bleed_build = 100,
        .burn_build = 100,
        .frost_build = 100,
        .Xp = 100,
        .respawn = true
    };

    enemies[2] = (Enemy){
        .name = "Dragon",
        .Hp = 50000,
        .At_1 = 50,
        .At_2 = 92,
        .physical_damage_resistance = 0,
        .ice_damage_resistance = 0,
        .fire_damage_resistance = 0,
        .holy_damage_resistance = 0,
        .poison_build = 100,
        .bleed_build = 100,
        .burn_build = 100,
        .frost_build = 100,
        .Xp = 100,
        .respawn = false
    };
}

void enemyInstance(){

    instances[0] = (Instance){
        .enemyData = &enemies[1],
        .display = 'E',
        .map = 3,
        .x = 9,
        .y = 5,
        .is_alive = true
    };

    instances[1] = (Instance){
        .enemyData = &enemies[0],
        .display = 'E',
        .map = 3,
        .x = 3,
        .y = 4,
        .is_alive = true
    };

    instances[2] = (Instance){
        .enemyData = &enemies[0],
        .display = 'E',
        .map = 3,
        .x = 4,
        .y = 3,
        .is_alive = true
    };

    instances[3] = (Instance){
        .enemyData = &enemies[0],
        .display = 'E',
        .map = 3,
        .x = 4,
        .y = 5,
        .is_alive = true
    };

    instances[4] = (Instance){
        .enemyData = &enemies[0],
        .display = 'E',
        .map = 3,
        .x = 5,
        .y = 4,
        .is_alive = true
    };

    instances[5] = (Instance){
        .enemyData = &enemies[0],
        .display = 'E',
        .map = 3,
        .x = 2,
        .y = 6,
        .is_alive = true
    };

    instances[6] = (Instance){
        .enemyData = &enemies[0],
        .display = 'E',
        .map = 3,
        .x = 1,
        .y = 3,
        .is_alive = true
    };

    instances[7] = (Instance){
        .enemyData = &enemies[0],
        .display = 'E',
        .map = 3,
        .x = 6,
        .y = 7,
        .is_alive = true
    };

    instances[8] = (Instance){
        .enemyData = &enemies[0],
        .display = 'E',
        .map = 3,
        .x = 8,
        .y = 2,
        .is_alive = true
    };

    instances[9] = (Instance){
        .enemyData = &enemies[0],
        .display = 'E',
        .map = 3,
        .x = 5,
        .y = 9,
        .is_alive = true
    };

    instances[10] = (Instance){
        .enemyData = &enemies[0],
        .display = 'E',
        .map = 3,
        .x = 8,
        .y = 8,
        .is_alive = true
    };

    instances[11] = (Instance){
        .enemyData = &enemies[0],
        .display = 'E',
        .map = 3,
        .x = 7,
        .y = 5,
        .is_alive = true
    };

    instances[12] = (Instance){
        .enemyData = &enemies[0],
        .display = 'E',
        .map = 3,
        .x = 3,
        .y = 8,
        .is_alive = true
    };

    instances[13] = (Instance){
        .enemyData = &enemies[0],
        .display = 'E',
        .map = 3,
        .x = 5,
        .y = 1,
        .is_alive = true
    };

    instances[14] = (Instance){
        .enemyData = &enemies[2],
        .display = 'B',
        .map = 6,
        .x = 9,
        .y = 11,
        .is_alive = true
    };
}
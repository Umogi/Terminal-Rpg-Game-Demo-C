#ifndef ENEMIES_H
#define ENEMIES_H

#include <stdbool.h>

#define EnemiesAmount 3
#define EnemiesInTheMap 15

// Data
typedef struct {
    const char *name;
    int Hp;
    int At_1;
    int At_2;
    int physical_damage_resistance;
    int ice_damage_resistance;
    int fire_damage_resistance;
    int holy_damage_resistance;
    int poison_build;
    int bleed_build;
    int burn_build;
    int frost_build;
    int strenght_build;
    int Xp;
    bool respawn;
} Enemy ;

Enemy enemies[EnemiesAmount];

typedef struct {
    Enemy *enemyData;
    char display;
    int map;
    int x;
    int y;
    bool is_alive;
} Instance ;

Instance instances[EnemiesInTheMap];

//Functions
void initializeEnemies();

void enemyInstance();

//MonsterAttack(int MonsterID);

#endif 
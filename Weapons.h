#ifndef WEAPONS_H
#define WEAPONS_H

#include <stdbool.h>

#define DTAmount 4
#define CategoryWeaponAmount 6
#define WeaponAmount 8

// Data
typedef enum {
    Scimitar,
    Rapier,
    Dagger,
    Longsword,
    Katana,
    Broadsword
} WeaponCategory;

typedef struct {
    const char *name;
    bool owned;
    int strength_requirement;
    int dexterity_requirement;
    int intelligence_requirement;
    int faith_requirement;
    int arcane_requirement;
    int level_upgraded;
    int added_damage;
    int stamina_heavy;
    int stamina_quick;
    int physical_damage;
    int ice_damge;
    int fire_damge;
    int holy_damge;
    int poison;
    int bleed;
    int burn;
    int frost;
    char strength;
    char dexterity;
    char intelligence;
    char faith;
    char arcane;
    WeaponCategory category;
} Weapon;

Weapon weapons[WeaponAmount];

//Functions
void initializeWeapons();

void WeaponsDisplay();

#endif
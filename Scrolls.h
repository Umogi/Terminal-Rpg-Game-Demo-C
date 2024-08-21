#ifndef SCROLLS_H
#define SCROLLS_H

#include <stdbool.h>

#define ScrollAmount 8
#define CategoryScrollAmount 6


// Data
typedef enum {
    Fire,
    Ice,
    Dark, 
    Holy,
    Earth,
    Poison,
    Lightning
} ScrollCategory;

typedef struct {
    const char *name;
    bool owned;
    int strength_requirement;
    int dexterity_requirement;
    int intelligence_requirement;
    int faith_requirement;
    int arcane_requirement;
    int damage_1;
    const char *abilitie_1;
    const char *description_1;
    int mana_1;
    int damage_2;
    const char *abilitie_2;
    const char *description_2;
    int mana_2;
    int ice_damge;
    int fire_damge;
    int holy_damge;
    int poison;
    int bleed;
    int burn;
    int frost;
    ScrollCategory category;
} Scroll;

Scroll scrolls[ScrollAmount];

//Functions
void initializeScrolls();

void ScrollsDisplay();

#endif
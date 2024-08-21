#ifndef TALISMANT_H
#define TALISMANT_H

#include <stdbool.h>

#define TalismanAmount 8 

// Data
typedef struct {
    const char *name;
    bool owned;
    int hp_plus;
    int hp_recover;
    int stamina_plus;
    int stamina_recover;
    int mana_plus;
    int mana_recover;
    int strenght;
    int dexeterity;
    int intelligence;
    int faith;
    int arcane;
} Talisman;

Talisman talismants[TalismanAmount];

//Functions

void initializeTalisman();

void TalismantDisplay();

#endif
#ifndef ITEMS_H
#define ITEMS_H

#include <stdbool.h>

#define ItemAmount 8

// Data
typedef struct {
    const char *name;
    int mass;
    int amount;
    bool Hp;
    bool Mana;
    bool Stamina;
} Item;

Item items[ItemAmount];

//Functions
void initializeItems();

void ItemInspector();

#endif
#ifndef QUESTS_H
#define QUESTS_H

#define QuestAmount 2

#include <stdbool.h>

// Data
typedef struct{
    int QuestID;
    bool quest_line1;
    bool quest_line2;
    bool quest_line3;
    bool quest_line4;
    bool quest_line5;
} Quest;

Quest quests[QuestAmount];

//Functions

void initializeQuests();

void NPCLines(int mapId);

#endif
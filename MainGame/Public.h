#ifndef PUBLIC_H
#define PUBLIC_H


//Player Info
char PlayerName[17];
//0   1      2       3       4     5      6     7
//hp mana stamina strength Dexte Intell faith arcane
int PlayerStuts[8];

int PlayerTalisman[4];
int PlayerWeaponId;
int PlayerScrollId;
char *PlayerRace;
char *PlayerClass;

int EnemiesKilled;

int xAxis;
int yAxis;
int PlayerLevel;
int TotalXp;

#endif
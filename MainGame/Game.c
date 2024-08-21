#include "Public.h"

#include "Drops.h"
#include "Quests.h"
#include "Enemies.h"
#include "Items.h"
#include "Maps.h"
#include "Scrolls.h"
#include "Talisman.h"
#include "Weapons.h"
#include "Battle.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <stdbool.h>

//Save File
int saves[4] = {
    0,
    0,
    0,
    0
};

char (*maps[])[XLength][YLength] = {&map0, &map1, &map2, &map3, &map4, &map5, &map6, &map7, &room101, &room102, &room103, &room104, &room201, &room202, &room501, &room502, &room503, &room504, &room505, &room506};

void MenuGame();
int StartGame();
int game();

int file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1; // File exists
    }
    return 0; // File does not exist
}

void printing(const char *String, int flag, int delay){
    int length = strlen(String);

    for (int i = 0; i < length; i++) {
        Sleep(delay);
        printf("%c", String[i]);
    }
    if(flag == 0){
        printf("\n");
    }
}

void levelUssage(){
    char Command;
    int OptionPointer = 0;

    while(1){
        system("cls||clear");
        if(OptionPointer == 0){printf(">");}
        printf("Hp: %d\n", PlayerStuts[0]);
        if(OptionPointer == 1){printf(">");}
        printf("Mana: %d\n", PlayerStuts[1]);
        if(OptionPointer == 2){printf(">");}
        printf("Stamina: %d\n", PlayerStuts[2]); 
        if(OptionPointer == 3){printf(">");}
        printf("Stengeth: %d\n", PlayerStuts[3]); 
        if(OptionPointer == 4){printf(">");}
        printf("Dexerity: %d\n", PlayerStuts[4]);
        if(OptionPointer == 5){printf(">");}
        printf("Intelligens: %d\n", PlayerStuts[5]);
        if(OptionPointer == 6){printf(">");}
        printf("Faith: %d\n", PlayerStuts[6]);
        if(OptionPointer == 7){printf(">");}
        printf("Arcane: %d\n", PlayerStuts[7]);

        Command = _getch();

        if(Command=='w' && OptionPointer > 0){
            OptionPointer--;
        }else if(Command=='s' && OptionPointer < 7){
            OptionPointer++; 
        }else if(Command=='e'){
            PlayerStuts[OptionPointer] += 1;
            break;
        }
    }   
}

int requiredXPForLevel(int level) {
    int baseXP = 100;
    int xpRequired = baseXP;
    
    for (int i = 1; i < level; i++) {
        xpRequired *= 1.5;
    }

    return xpRequired;
}

void Levelup(){
    while (TotalXp >= requiredXPForLevel(PlayerLevel + 1)) {
        TotalXp -= requiredXPForLevel(PlayerLevel + 1);
        (PlayerLevel)++;
        levelUssage();
        printf("Leveled up! New level");
    }

}

void DropFound(int Id){
    switch (drops[Id].categoyId)
    {
    case 0:
        printf("You found, %s !", items[drops[Id].itemId].name);
        items[drops[Id].itemId].mass += 1;
        break;
    case 1:
        printf("You found, ", talismants[drops[Id].itemId].name);
        talismants[drops[Id].itemId].owned = true;
        break;
    case 2:
        printf("You found, %s !", scrolls[drops[Id].itemId].name);
        scrolls[drops[Id].itemId].owned = true;
        break;
    case 3:
        printf("You found, %s !", weapons[drops[Id].itemId].name);
        weapons[drops[Id].itemId].owned = true;
        break;
    default:
        break;
    }
    char Command = _getch();
    drops[Id].found = true;
}

void use(int x, int y, int mapID){
    for (int i = 0; i < DropsAmount; i++){
        if(drops[i].mapId == mapID){
            if(drops[i].x == x+1 && drops[i].y == y){
                DropFound(i);
            }else if(drops[i].x == x-1 && drops[i].y == y){
                DropFound(i);
            }else if(drops[i].x == x && drops[i].y == y+1){
                DropFound(i);
            }else if(drops[i].x == x && drops[i].y == y-1){
                DropFound(i);
            }
        }
    }
    
}

int MapDestinationDataBase(int x, int y) {
    
    int mapId;

    switch (MapTempID)
    {
    case 0:
        if(x == 0 && y == 5){
            mapId = 1;
            xAxis = 14;
            yAxis = 11;
        }
        break; 

    case 1:
        if(x == 15 && y == 11){
            mapId = 0;
            xAxis = 1;
            yAxis = 5;
        }

        if(x == 0 && y == 11){
            if(quests[0].quest_line1 == true){
                mapId = 2;
                xAxis = 7;
                yAxis = 11;
            }else{
                printf("You have to talk to the tower mayor");
                char commant = _getch();
                mapId = 1;
            }
        }

        if(x == 12 && y == 11 ){
            mapId = 8;
            xAxis = 4;
            yAxis = 11;
        }
        
        if(x == 5 && y == 5 ){
            mapId = 10;
            xAxis = 3;
            yAxis = 5;
        }

        if(x == 5 && y == 17 ){
            mapId = 11;
            xAxis = 3;
            yAxis = 5;
        }
        
        break;
    case 2:
        if(x == 8 && y == 11 ){
            mapId = 1;
            xAxis = 1;
            yAxis = 11;
        }
        
        if(x == 1 && y == 21 ){
            mapId = 4;
            xAxis = 1;
            yAxis = 1;
        }

        if(x == 1 && y == 0 ){
            mapId = 3;
            xAxis = 1;
            yAxis = 9;
        }

        if(x == 5 && y == 13){
            mapId = 12;
            xAxis = 3;
            yAxis = 7;
        }

        if(x == 5 && y == 4){
            mapId = 13;
            xAxis = 3;
            yAxis = 5;
        }

        break;
    case 3:
        if(x == 1 && y == 10 ){
            mapId = 2;
            xAxis = 1;
            yAxis = 1;
        }
        
        break;
    case 4:
        if(x == 1 && y == 0){
            mapId = 2;
            xAxis = 1;
            yAxis = 20;
        }

        if(x == 0 && y == 7 ){
            mapId = 6;
            xAxis = 15;
            yAxis = 11;  
        }

        if(x == 10 && y == 7 ){
            mapId = 5;
            xAxis = 1;
            yAxis = 11;  
        }

        if(x == 7 && y == 7 ){
            mapId = 14;
            xAxis = 3;
            yAxis = 7;  
        }
        break;
    case 5:
        if(x == 0 && y == 11 ){
            mapId = 4;
            xAxis = 9;
            yAxis = 7;
        }

        if(x == 6 && y == 4){
            mapId = 16;
            xAxis = 3;
            yAxis = 5;
        }

        if(x == 6 && y == 11){
            mapId = 17;
            xAxis = 3;
            yAxis = 5;
        }

        if(x == 6 && y == 18){
            mapId = 18;
            xAxis = 3;
            yAxis = 5;
        }

        if(x == 11 && y == 4){
            mapId = 19;
            xAxis = 3;
            yAxis = 5;
        }

        if(x == 11 && y == 11){
            mapId = 20;
            xAxis = 3;
            yAxis = 5;
        }

        if(x == 11 && y == 18){
            mapId = 21;
            xAxis = 3;
            yAxis = 5;
        }

        break;
    case 6:
        if(x == 16 && y == 11 ){
            mapId = 4;
            xAxis = 1;
            yAxis = 7;
        }

        if(x == 0 && y == 11 ){
            mapId = 7;
            xAxis = 4;
            yAxis = 11;
        }

        break;
    case 7:
        if(x == 5 && y == 11 ){
            mapId = 6;
            xAxis = 1;
            yAxis = 11;
        }

        break;
    case 8:
        if(x == 5 && y == 11 ){
            mapId = 1;
            xAxis = 13;
            yAxis = 11;
        }

        if(x == 0 && y == 11 ){
            mapId = 9;
            xAxis = 1;
            yAxis = 11;
        }

        break;
    case 9:
        if(x == 0 && y == 11 ){
            mapId = 8;
            xAxis = 1;
            yAxis = 11;
        }

        break;
    case 10:
        if(x == 4 && y == 5 ){
            mapId = 1;
            xAxis = 6;
            yAxis = 5;        
        }

        break;
    case 11:
        if(x == 4 && y == 5 ){
            mapId = 1;
            xAxis = 6;
            yAxis = 17;        
        }
        
        break;
    case 12:
        if(x == 4 && y == 7 ){
            mapId = 2;
            xAxis = 6;
            yAxis = 13;        
        }
        
        break;
    case 13:
        if(x == 4 && y == 5 ){
            mapId = 2;
            xAxis = 6;
            yAxis = 4;        
        }
        
        break;
    case 14:
        if(x == 0 && y == 7 ){
            mapId = 15;
            xAxis = 1;
            yAxis = 7;        
        }

        if(x == 4 && y == 7){
            mapId = 4;
            xAxis = 8;
            yAxis = 7;
        }

        break;
    case 15:
        if(x == 0 && y == 7){
            mapId = 14;
            xAxis = 1;
            yAxis = 7;
        }

        break;
    case 16:
        if(x == 4 && y == 5){
            mapId = 5;
            xAxis = 7;
            yAxis = 4;
        }

        break;

    case 17:
        if(x == 4 && y == 5){
            mapId = 5;
            xAxis = 7;
            yAxis = 11;
        }

        break;

    case 18:
        if(x == 4 && y == 5){
            mapId = 5;
            xAxis = 7;
            yAxis = 18;
        }

        break;

    case 19:
        if(x == 4 && y == 5){
            mapId = 5;
            xAxis = 12;
            yAxis = 4;
        }

        break;

    case 20:
        if(x == 4 && y == 5){
            mapId = 5;
            xAxis = 12;
            yAxis = 11;
        }

        break;

    case 21:
        if(x == 4 && y == 5){
            mapId = 5;
            xAxis = 12;
            yAxis = 18;
        }

        break;
    default:
        break;
    }

    return mapId;
}

void AllocateMap(char ConverMap[XLength][YLength]){
    for (int i = 0; i < XLength; i++) {
        for (int j = 0; j < YLength; j++) {
            map[i][j] = ConverMap[i][j];
        }
    }
}

void MapFunction(int xAxis,int yAxis, int mapId){
    if(MapTempID != mapId){
        switch (mapId) {
        case 0:
            AllocateMap(map0);
            break;

        case 1:
            AllocateMap(map1);
            break;

        case 2:
            AllocateMap(map2);
            break;

        case 3:
            AllocateMap(map3);
            break;

        case 4:
            AllocateMap(map4);
            break;

        case 5:
            AllocateMap(map5);
            break; 

        case 6:
            AllocateMap(map6);
            break;

        case 7:
            AllocateMap(map7);
            break;

        case 8:
            AllocateMap(room101);
            break;

        case 9:
            AllocateMap(room102);
            break;
            
        case 10:
            AllocateMap(room103);
            break;

        case 11:
            AllocateMap(room104);
            break;

        case 12:
            AllocateMap(room201);
            break;

        case 13:
            AllocateMap(room202);
            break;

        case 14:
            AllocateMap(room401);
            break;

        case 15:
            AllocateMap(room402);
            break;

        case 16:
            AllocateMap(room501);
            break;

        case 17:
            AllocateMap(room502);
            break;

        case 18:
            AllocateMap(room503);
            break;

        case 19:
            AllocateMap(room504);
            break;

        case 20:
            AllocateMap(room505);
            break;

        case 21:
            AllocateMap(room506);
            break;

        default:
            printf("Invalid mapId\n");
            return;
        }
        for(int i = 0; i<EnemiesInTheMap; i++){
            if(instances[i].enemyData->respawn == true){
                instances[i].is_alive = true;
            }
        }
    }

    int temp = map[xAxis][yAxis];
    map[xAxis][yAxis] = 'A';

    for(int i = 0; i<EnemiesInTheMap; i++){
        if(instances[i].map == mapId && instances[i].is_alive == true){
            map[instances[i].x][instances[i].y] = instances[i].display;
        }
    }
    for (int i = 0; i < DropsAmount; i++){
        if(drops[i].mapId == mapId && drops[i].found == false){
            map[drops[i].x][drops[i].y] = '*';
        }
    }

    //print the map of the game
    for(int i=0; i<XLength; i++){
        for(int z=0; z<YLength; z++){
            printf("%c ", map[i][z]);   
        }
        printf("\n");
        if(i<XLength){if(map[i+1][0] == '\0'){break;}}
    }

    map[xAxis][yAxis] = temp;

    MapTempID = mapId;
    
}

int processMovement(char CommandToMove, int mapId) {
    int newX = xAxis;
    int newY = yAxis;

    // Determine the new coordinates based on the command
    if (CommandToMove == 'w') {
        newX--;
    } else if (CommandToMove == 's') {
        newX++;
    } else if (CommandToMove == 'd') {
        newY++;
    } else if (CommandToMove == 'a') {
        newY--;
    } else {
        return mapId; // Invalid command
    }

    char destination = map[newX][newY];

    // Handle movement and special destination logic
    if (destination == '^') {
        mapId = MapDestinationDataBase(newX, newY);
    } else if (destination == 'v') {
        mapId = MapDestinationDataBase(newX, newY);
    } else if (destination == '>') {
        mapId = MapDestinationDataBase(newX, newY);
    } else if (destination == '<') {
        mapId = MapDestinationDataBase(newX, newY);
    }else if(destination == 'O'){
        mapId = MapDestinationDataBase(newX, newY);
    }

    // Ensure the new coordinates are within map bounds
    if (map[newX][newY] != ' ') {
        return mapId;
    } 
    
    xAxis = newX;
    yAxis = newY;

    return mapId;
}

void PlayerIspection(){

    char Command;  

    system("cls||clear");

    printf("========== %s =============\n", PlayerName);

    printf("%s \n", PlayerName);
    printf("Level: %d \n\n", PlayerLevel);

    printf("Player Race: %s\n", PlayerRace);
    printf("Player Class: %s\n\n", PlayerClass);

    printf("Weapon: %s\n", weapons[PlayerWeaponId].name);
    printf("Scroll: %s\n\n", scrolls[PlayerScrollId].name);

    printf("Hp: %d\n", PlayerStuts[0]);
    printf("Mana: %d\n", PlayerStuts[1]);
    printf("Stamina: %d\n", PlayerStuts[2]); 
    printf("Stengeth: %d\n", PlayerStuts[3]); 
    printf("Faith: %d\n", PlayerStuts[4]);
    printf("Arche: %d\n\n", PlayerStuts[5]);

    if(PlayerTalisman[0] != -1){printf("Talismant: %s \n", talismants[PlayerTalisman[0]].name);
    }else{printf("Talismant: X \n");}
    if(PlayerTalisman[1] != -1){printf("Talismant: %s \n", talismants[PlayerTalisman[1]].name);
    }else{printf("Talismant: X \n");}
    if(PlayerTalisman[2] != -1){printf("Talismant: %s \n", talismants[PlayerTalisman[2]].name);
    }else{printf("Talismant: X \n");}
    if(PlayerTalisman[3] != -1){printf("Talismant: %s \n", talismants[PlayerTalisman[3]].name);
    }else{printf("Talismant: X \n");}

    printf("==============================\n");

    Command = _getch();

    if(Command == 'e'){
        system("cls||clear");
        printf("New Name: ");
        scanf("%s", &PlayerName);
    }

}

void save_game(int slot) {
    char filename[20];
    snprintf(filename, sizeof(filename), "save%d.dat", slot + 1);

    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }

    time_t currentTime = time(NULL);
    fwrite(&currentTime, sizeof(currentTime), 1, file);

    fwrite(saves, sizeof(saves), 1, file);
    fwrite(PlayerName, sizeof(PlayerName), 1, file);
    fwrite(PlayerStuts, sizeof(PlayerStuts), 1, file);
    fwrite(&PlayerLevel, sizeof(PlayerLevel), 1, file);
    fwrite(PlayerTalisman, sizeof(PlayerTalisman), 1, file);
    fwrite(&PlayerWeaponId, sizeof(PlayerWeaponId), 1, file);
    fwrite(&PlayerScrollId, sizeof(PlayerScrollId), 1, file);
    fwrite(&MapTempID, sizeof(MapTempID), 1, file);
    fwrite(&EnemiesKilled, sizeof(EnemiesKilled), 1, file);
    fwrite(&xAxis, sizeof(xAxis), 1, file);
    fwrite(&yAxis, sizeof(yAxis), 1, file);
    for(int i = 0; i < WeaponAmount; i++){
        fwrite(&weapons[i].owned, sizeof(weapons[i].owned), 1, file);
    }
    for(int i = 0; i < WeaponAmount; i++){
        fwrite(&scrolls[i].owned, sizeof(scrolls[i].owned), 1, file);
    }
    for(int i = 0; i < TalismanAmount; i++){
        fwrite(&talismants[i].owned, sizeof(talismants[i].owned), 1, file);
    }
    for(int i = 0; i < TalismanAmount; i++){
        fwrite(&items[i].mass, sizeof(items[i].mass), 1, file);
    }
    fwrite(&TotalXp, sizeof(TotalXp), 1, file);
    for (int i = 0; i < sizeof(maps) / sizeof(maps[0]); i++){
        fwrite(maps[i], sizeof(char) * XLength * YLength, 1, file);
    }
    for(int i = 0; i < EnemiesInTheMap; i++){
        if(instances[i].enemyData->respawn = false){
            fwrite(&instances[i].is_alive, sizeof(instances[i].is_alive), 1, file);
        }
    }
    for (int i = 0; i < DropsAmount; i++){
        fwrite(&drops[i].found, sizeof(drops[i].found), 1, file);
    }
    
    fclose(file);
    printf("Game saved to slot %d.\n", slot + 1);
    Sleep(1000);
}

void load_game(int slot) {
    char filename[20];
    snprintf(filename, sizeof(filename), "save%d.dat", slot + 1);

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file for loading.\n");
        return;
    }

    time_t saveTime;
    fread(&saveTime, sizeof(saveTime), 1, file);

    fread(saves, sizeof(saves), 1, file);
    fread(PlayerName, sizeof(PlayerName), 1, file);
    fread(PlayerStuts, sizeof(PlayerStuts), 1, file);
    fread(&PlayerLevel, sizeof(PlayerLevel), 1, file);
    fread(PlayerTalisman, sizeof(PlayerTalisman), 1, file);
    fread(&PlayerWeaponId, sizeof(PlayerWeaponId), 1, file);
    fread(&PlayerScrollId, sizeof(PlayerScrollId), 1, file);
    fread(&MapTempID, sizeof(MapTempID), 1, file);
    fread(&EnemiesKilled, sizeof(EnemiesKilled), 1, file);
    fread(&xAxis, sizeof(xAxis), 1, file);
    fread(&yAxis, sizeof(yAxis), 1, file);
    for(int i = 0; i < WeaponAmount; i++){
        fread(&weapons[i].owned, sizeof(weapons[i].owned), 1, file);
    }
    for(int i = 0; i < WeaponAmount; i++){
        fread(&scrolls[i].owned, sizeof(scrolls[i].owned), 1, file);
    }
    for(int i = 0; i < TalismanAmount; i++){
        fread(&talismants[i].owned, sizeof(talismants[i].owned), 1, file);
    }
    for(int i = 0; i < TalismanAmount; i++){
        fread(&items[i].mass, sizeof(items[i].mass), 1, file);
    }
    fread(&TotalXp, sizeof(TotalXp), 1, file);
    for (int i = 0; i < sizeof(maps) / sizeof(maps[0]); i++){
        fread(maps[i], sizeof(char) * XLength * YLength, 1, file);
    }
    for(int i = 0; i < EnemiesInTheMap; i++){
        if(instances[i].enemyData->respawn = false){
            fread(&instances[i].is_alive, sizeof(instances[i].is_alive), 1, file);
        }
    }
    for (int i = 0; i < DropsAmount; i++){
        fread(&drops[i].found, sizeof(drops[i].found), 1, file);
    }
    fclose(file);
    printf("Game loaded from slot %d.\n", slot + 1);
    Sleep(1000);
}

int check_save(int slot, char *saveInfo) {
    char filename[20];
    snprintf(filename, sizeof(filename), "save%d.dat", slot + 1);

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        strcpy(saveInfo, "(none)");
        return 0;
    }

    time_t saveTime;
    fread(&saveTime, sizeof(saveTime), 1, file);
    fclose(file);

    struct tm *timeInfo = localtime(&saveTime);
    strftime(saveInfo, 20, "(%Y-%m-%d %H:%M)", timeInfo);
    return 1;
}

void SaveFile(){
    int SavePointer = 0;
    char Command;
    char saveInfo[4][20];
    char YesOrNo; 

    while (1) {
        for (int i = 0; i < 4; i++) {
            check_save(i, saveInfo[i]);
        }

        system("cls||clear");
        printf("====== Save File ======\n");
        if (SavePointer == 0) { printf(">"); }
        printf("Save 1: %s\n", saveInfo[0]);     
        if (SavePointer == 1) { printf(">"); }
        printf("Save 2: %s\n", saveInfo[1]);
        if (SavePointer == 2) { printf(">"); }
        printf("Save 3: %s\n", saveInfo[2]);
        if (SavePointer == 3) { printf(">"); }
        printf("Save 4: %s\n", saveInfo[3]);
        printf("=======================\n");

        Command = _getch();

        if (Command == 'w' && SavePointer > 0) {
            SavePointer--;
        } else if (Command == 's' && SavePointer < 3) {
            SavePointer++; 
        } else if (Command == 'e') {
            printf("\n");
            printing("Are you sure you wanna save your file here? (y\\n): ", 1, 10);
            YesOrNo = _getch();
            if(YesOrNo == 'y'){
                save_game(SavePointer);
                saves[SavePointer] = 1;
            }else if(YesOrNo == 'n'){printing("OK Good!", 0, 10);}
        } else if (Command == 'q') {
            break;
        }
    }
}

void LoadFile(){

    int SavePointer = 0;
    char Command;
    char saveInfo[4][20];
    int YesOrNo; 

    while (1) {
        for (int i = 0; i < 4; i++) {
            check_save(i, saveInfo[i]);
        }

        system("cls||clear");
        printf("====== Load Save ======\n");
        if (SavePointer == 0) { printf(">"); }
        printf("Save 1: %s\n", saveInfo[0]);     
        if (SavePointer == 1) { printf(">"); }
        printf("Save 2: %s\n", saveInfo[1]);
        if (SavePointer == 2) { printf(">"); }
        printf("Save 3: %s\n", saveInfo[2]);
        if (SavePointer == 3) { printf(">"); }
        printf("Save 4: %s\n", saveInfo[3]);
        printf("=======================\n");

        Command = _getch();

        if (Command == 'w' && SavePointer > 0) {
            SavePointer--;
        } else if (Command == 's' && SavePointer < 3) {
            SavePointer++; 
        } else if (Command == 'e') {
            printf("\n");
            printing("Are you sure you wanna load this save? (y\\n): ", 1, 10);
            YesOrNo = _getch();
            if(YesOrNo == 'y'){
                load_game(SavePointer);
                game();
            }else if(YesOrNo == 'n'){printing("OK Good!", 0, 10);}
        } else if (Command == 'q') {
            break;
        }
    } 
}

//----------------------------------------------------------------------------------------------------

void OptionScreen(){

    int OptionPointer = 1;
    char CommandOptionScreen;

    while(1){
        system("cls||clear");
        printf("===== Option Screen =====\n");
        if(OptionPointer == 1){printf(">");}
        printf("Weapons\n");
        if(OptionPointer == 2){printf(">");}
        printf("Scrools\n");
        if(OptionPointer == 3){printf(">");}
        printf("Talismans\n");
        if(OptionPointer == 4){printf(">");}
        printf("Items\n");
        if(OptionPointer == 5){printf(">");}
        printf("%s\n", PlayerName);
        if(OptionPointer == 6){printf(">");}
        printf("Save\n");
        if(OptionPointer == 7){printf(">");}
        printf("Load\n");
        if(OptionPointer == 8){printf(">");}
        printf("Exit\n");
        printf("=====================\n");

        CommandOptionScreen = _getch();

        if(CommandOptionScreen=='w' && OptionPointer > 1){
            OptionPointer--;
        }else if(CommandOptionScreen=='s' && OptionPointer < 8){
            OptionPointer++; 
        }else if(CommandOptionScreen=='e'){
            switch (OptionPointer){
            case 1:
                WeaponsDisplay();
                break;
            
            case 2:
                ScrollsDisplay();
                break;
            
            case 3:
                TalismantDisplay();
                break;

            case 4:
                ItemInspector();
                break;

            case 5:
                PlayerIspection();
                break;

            case 6:
                SaveFile();
                break;
            
            case 7:
                LoadFile();
                break;

            case 8:
                MenuGame();
                break;

            default:
                break;
            }
        }else if(CommandOptionScreen=='b' || CommandOptionScreen == 'q'){
            break;
        }
    }
}

//----------------------------------------------------------------------------------------------------

void SaveFileWriter(){
    const char *filename = "saves.dat";

    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
    }

    fwrite(saves, sizeof(saves), 1, file);

    fclose(file);
}

void SaveFileReader(){
    const char *filename = "saves.dat";

    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
    }

    fread(saves, sizeof(saves), 1, file);

    fclose(file);
}

int main(){

    
    const char *filename = "saves.dat";

    while(file_exists(filename) == 0){
        SaveFileWriter();
    }

    SaveFileReader();

    MenuGame();
    
    return 0;
}

void MenuGame(){

    int OptionPointer = 1;
    char Command;

    while(1){

        system("cls||clear");
        printf("===== Menu Screen =====\n");
        if(OptionPointer == 1){printf(">");}
        printf("New Game\n");
        if(OptionPointer == 2){printf(">");}
        printf("Load Game\n");
        if(OptionPointer == 3){printf(">");}
        printf("Exit \n");
        printf("=====================\n");
        
        Command = _getch();
        printf("\n");

        if(Command=='w' && OptionPointer > 1){
            OptionPointer--;
        }else if(Command=='s' && OptionPointer < 3){
            OptionPointer++; 
        }else if(Command=='e'){
            switch (OptionPointer){
            case 1: StartGame(); break;
                
            case 2: LoadFile(); break;
            
            case 3: 
                SaveFileWriter();
            
                exit(0); 
                break;
            default: break;
            }
        }else if(Command=='b'){
            break;
        }
    }

}

int StartGame(){

    initializeEnemies();
    enemyInstance();
    initializeItems();
    initializeWeapons();
    initializeScrolls();
    initializeTalisman();
    initializeQuests();
    initializeDrops();

    srand(time(0));

    int Class[6][8] = {
        //hp mana stamina strength dexerity intlligens faith arce
        {14, 9, 12, 16, 9, 7, 8, 11},
        {10, 11, 10, 9, 13, 9, 8, 14},
        {9, 15, 9, 8, 12, 16, 7, 9},
        {11, 12, 11, 10, 16, 10, 8, 9},
        {10, 13, 10, 12, 12, 9, 14, 9},
        {11, 12, 11, 11, 14, 14, 6, 9},
    };

    int LevelClass[6] = {7, 5, 6, 8, 10, 9};

    char CommandOptionScreen ;

    int NameFlag = 0;
    int RaceFlag = 0;
    int ClassFlag = 0;
    int attempts = 0;
    char answer;

    const char *String;

    int RacePointer;
    int Pick;
    int OptionPointer = 0; 
    
    int Won;

    while (NameFlag == 0){
        system("cls||clear");

        if (attempts == 0){
            printing("Name should be 16 characters or less. ", 0, 10);
        } 

        if (attempts < 5) {
            String = "What is your name: ";
        } else if (attempts < 7){
            String = "For the last time, what is your name: ";
        }else {
            String = "Name: ";
        }

        printing(String, 1, 10);

        scanf(" %16s", PlayerName);

        if (attempts < 5) {
            String = "Are you sure this is your name? (y/n): ";
        } else if (attempts < 7){
            String = "Is this it? (y/n): ";
        }else {
            String = "(y/n): ";
        }

        printing(String, 1, 10);        

        while(1){

            answer = _getch();
            printf("\n");
        
            if (answer == 'y' || answer == 'Y') {
                if (attempts < 5) {
                    printing("Great! Lets pick a race ", 1, 10);
                    printing(PlayerName, 1, 10); 
                    String = " <3";
                } else if (attempts < 7){
                    String = "FINALLY! Pick you race now. Don't harder thatn it shuold be!";
                }else{
                    String = "OH MY GOD FINALLY! Hope you live a Nightmare here!";
                }

                printing(String, 0, 10); 

                NameFlag = 1;
                break;

            } else if (answer == 'n' || answer == 'N') {
                if (attempts < 4) {
                    String = "Ok! Let's try again";
                } else if (attempts < 6){
                    String = "Bro, are you done choosing?";
                } else {
                    String = "...";
                }

                printing(String, 0, 10); 

                attempts++;
                break;

            } else {
                printing("Invalid input. Please respond with 'y' or 'n'.", 0, 10); 
            }

        }
		
        sleep(2);

    }

    attempts = 0;

    char *RaceName[6]= {
        "Human",
        "Elf",
        "Goblin",
        "Skeleton",
        "Spirit",
        "Troll"
    };

    char *ClassName[6] = {
        "Warrior",
        "Mage",
        "Wisard",
        "Sumoner",
        "Hero",
        "Ranger"
    };

    while (RaceFlag == 0){

        while (1){
            system("cls||clear");
            printf("===== Race Piker =====\n");
            for (int i = 0; i < 6; i++){
                if(OptionPointer == i) printf(">");
                printf("%s\n", RaceName[i]);
            }
            printf("=====================\n");

            CommandOptionScreen = _getch();

            if(CommandOptionScreen=='w' && OptionPointer > 0){
                OptionPointer--;
            }else if(CommandOptionScreen=='s' && OptionPointer < 5){
                OptionPointer++; 
            }else if(CommandOptionScreen=='e'){
                PlayerRace = RaceName[OptionPointer];
                break;
            }  
        }

        if (attempts < 5) {
            String = "Are you sure this is your race? (y/n): ";
        } else if (attempts < 7){
            String = "Is this it? (y/n): ";
        }else {
            String = "(y/n): ";
        }

        printing(String, 1, 10); 

        while(1){

            answer = _getch();
            printf("\n");
        
            if(answer == 'y' || answer == 'Y'){
                if (attempts < 5) {
                    String = "Great! Lets pick a class "; 
                } else if (attempts < 7){
                    String = "Please make it quick the class!";
                }else{
                    String = "Class...";
                }

                printing(String, 1, 10); 

                RaceFlag = 1;
                
                break;

            }else if (answer == 'n' || answer == 'N'){
                if (attempts < 4) {
                    String = "Ok! Let's try again";
                } else if (attempts < 6){
                    String = "Bro, are you done choosing?";
                } else {
                    String = "...";
                }

                printing(String, 0, 10); 

                attempts++;
                break;

            }else{
                printing("Invalid input. Please respond with 'y' or 'n'.", 0, 10); 
            }

            printing(String, 0, 10);  
        }

        sleep(2);
    }

    attempts = 0;
    OptionPointer = 0;

    while (ClassFlag == 0){

        while (1){
            system("cls||clear");
            printf("===== Class Piker =====\n");
            for (int i = 0; i < 6; i++){
                if(OptionPointer == i) printf(">");
                printf("%s\n", ClassName[i]);
            }
            printf("\n");
            printf("Level: ");
            printf("%d\n", LevelClass[OptionPointer]);
            printf("Hp: ");
            printf("%d\n", Class[OptionPointer][0]);
            printf("Mana: ");
            printf("%d\n", Class[OptionPointer][1]);
            printf("Stamina: ");
            printf("%d\n", Class[OptionPointer][2]);
            printf("Stengeth: ");
            printf("%d\n", Class[OptionPointer][3]);
            printf("Dexerity: ");
            printf("%d\n", Class[OptionPointer][4]);
            printf("Intelligens: ");
            printf("%d\n", Class[OptionPointer][5]);
            printf("Faith: ");
            printf("%d\n", Class[OptionPointer][6]);
            printf("Arcane: ");
            printf("%d\n", Class[OptionPointer][7]);
            printf("=====================\n");

            CommandOptionScreen = _getch();

            if(CommandOptionScreen=='w' && OptionPointer > 0){
                OptionPointer--;
            }else if(CommandOptionScreen=='s' && OptionPointer < 5){
                OptionPointer++; 
            }else if(CommandOptionScreen=='e'){
                PlayerClass = ClassName[OptionPointer];
                break;
            }
        }
        
        if (attempts < 5) {
            String = "Are you sure this is your race? (y/n): ";
        } else if (attempts < 7){
            String = "Is this it? (y/n): ";
        }else {
            String = "(y/n): ";
        }

        printing(String, 1, 10); 

        while(1){

            answer = _getch();
            printf("\n");
        
            if (answer == 'y' || answer == 'Y') {
                if (attempts < 5) {
                    String = "Awesome "; 
                } else if (attempts < 7){
                    String = "Please make it quick with the class!";
                }else{
                    String = "Class...";
                }

                printing(String, 0, 10); 

                ClassFlag = 1;

                for(int i = 0; i <8; i++){
                    PlayerStuts[i] = Class[OptionPointer][i];
                }

                PlayerWeaponId = 0;

                PlayerScrollId = 0;

                PlayerLevel = LevelClass[OptionPointer];

                break;

            } else if (answer == 'n' || answer == 'N') {
                if (attempts < 4) {
                    String = "Ok! Let's try again";
                } else if (attempts < 6){
                    String = "Bro, are you done choosing?";
                } else {
                    String = "...";
                }

                printing(String, 0, 10); 

                attempts++;
                break;

            } else {
                printing("Invalid input. Please respond with 'y' or 'n'.", 0, 10); 
            }

            printing(String, 0, 10);
        }

        sleep(2);
    }
    
	system("cls||clear");
    printing("Welcome to the enchanting realm of Thaloria, a world steeped in ancient magic and inhabited by diverse races and mythical creatures. Here, sprawling forests whisper ancient secrets, towering mountains guard forgotten temples, and bustling villages thrive amidst untamed wilderness.", 1, 10);
	sleep(5);

    Won = game();

}

int EnemyFinder(int x ,int y, int mapId){

    int MonsterId;

    for(int i = 0; i<EnemiesInTheMap; i++){
        if(instances[i].map == mapId){
            if(instances[i].x == x+1 && instances[i].y == y){
                MonsterId = i;
                break;
            }else if(instances[i].x == x-1 && instances[i].y == y){
                MonsterId = i;
                break;
            }else if(instances[i].x == x && instances[i].y == y+1){
                MonsterId = i;
                break;
            }else if(instances[i].x == x && instances[i].y == y-1){
                MonsterId = i;
                break;
            }
        }
    }

    return MonsterId;
}

//----------------------------------------------------------------------------------------------------

int game(){

    char CommandToMove ;
    int won;
    system("cls||clear");

    int mapId = MapTempID;

    char (*selectedMap)[XLength][YLength] = maps[mapId];

    for (int i = 0; i < XLength; i++) {
        for (int j = 0; j < YLength; j++) {
            map[i][j] = (*selectedMap)[i][j];
        }
    }

    while(1){

        //prints the map and move the character
        MapFunction(xAxis, yAxis, mapId);

        //Waits for user to ender the diraction where the player will move
        CommandToMove = _getch();
        printf("\n");

        mapId = processMovement(CommandToMove, mapId);

        //Move the player Bas on the comant that the User gave
        if(CommandToMove == 'e'){
            if(map[xAxis-1][yAxis] == 'E' || map[xAxis+1][yAxis] == 'E' || map[xAxis][yAxis+1] == 'E' || map[xAxis][yAxis-1] == 'E'){
                int MonsterId = EnemyFinder(xAxis, yAxis, mapId);
                won = BattleScreen(MonsterId);
                if(won == 1){
                    if(map[xAxis-1][yAxis] == 'E') map[xAxis-1][yAxis] = ' ';
                    if(map[xAxis+1][yAxis] == 'E') map[xAxis+1][yAxis] = ' ';
                    if(map[xAxis][yAxis+1] == 'E') map[xAxis][yAxis+1] = ' ';
                    if(map[xAxis][yAxis-1] == 'E') map[xAxis][yAxis-1] = ' ';
                    instances[MonsterId].is_alive = false;
                    TotalXp += instances[MonsterId].enemyData->Xp;
                    Levelup();
                    EnemiesKilled++;
                }
                if(EnemiesKilled == 2){
                    quests[0].quest_line2 = true;
                }
            }else if(map[xAxis-1][yAxis] == 'B' || map[xAxis+1][yAxis] == 'B' || map[xAxis][yAxis+1] == 'B' || map[xAxis][yAxis-1] == 'B'){
                int MonsterId = EnemyFinder(xAxis, yAxis, mapId);
                won = BattleScreen(MonsterId);
                if(won == 1){
                    if(map[xAxis-1][yAxis] == 'B'){ map[xAxis-1][yAxis] = ' ';}
                    else if(map[xAxis+1][yAxis] == 'B'){ map[xAxis+1][yAxis] = ' ';}
                    else if(map[xAxis][yAxis+1] == 'B'){ map[xAxis][yAxis+1] = ' ';}
                    else if(map[xAxis][yAxis-1] == 'B'){ map[xAxis][yAxis-1] = ' ';}
                    instances[MonsterId].is_alive = false;
                    TotalXp += instances[MonsterId].enemyData->Xp;
                    Levelup();
                    quests[0].quest_line4 = true;
                }else if(won == 0){
                    mapId = 0;
					xAxis = 6;
					yAxis = 5;
                }
            }else if(map[xAxis-1][yAxis] == '*' || map[xAxis+1][yAxis] == '*' || map[xAxis][yAxis+1] == '*' || map[xAxis][yAxis-1] == '*'){
                use(xAxis, yAxis, mapId);
                if(map[xAxis-1][yAxis] == '*') {map[xAxis-1][yAxis] = ' ';}
                else if(map[xAxis+1][yAxis] == '*') {map[xAxis+1][yAxis] = ' ';}
                else if(map[xAxis][yAxis+1] == '*') {map[xAxis][yAxis+1] = ' ';}
                else if(map[xAxis][yAxis-1] == '*') {map[xAxis][yAxis-1] = ' ';}
            }else if(map[xAxis-1][yAxis] == 'N' || map[xAxis+1][yAxis] == 'N' || map[xAxis][yAxis+1] == 'N' || map[xAxis][yAxis-1] == 'N'){
                NPCLines(mapId);
            }
        } else if(CommandToMove == 'b'){ 
            OptionScreen();
        } else if(CommandToMove == 'p'){
            break;
        }

        //Clears the terminal
        system("cls||clear");

    }
    
    return 1;
}

    
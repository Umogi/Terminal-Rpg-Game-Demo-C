#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 
#include <windows.h>
#include <unistd.h>
#include <conio.h>

#define XLength 10
#define YLength 10
#define WeaponAmount 8
#define ScrollAmount 8
#define TalismansAmount 8
#define ItemAmount 8

char PlayerName[17];
//0   1      2       3       4    5
//hp mana stamina strength faith arce
int PlayerStuts[6];

int playerLevel = 10;

int PlayerTalisman[4] = {1, 2, 3, 4};

int PlayerWeaponId;

int PlayerScrollId;

int mapTempID = 1;

int xAxis = 8 ;
int yAxis = 1 ;

int saves[4] = {
    0,
    0,
    0,
    0
};

int MonsterStuts[3][7] = {
    //lvl hp At1 At2 At3 At3 flag
    {5, 10, 5, 6, 0, 0, 1},
    {10, 20, 10, 20, 0, 0, 1},
    {25, 30, 30, 50, 10, 15, 0}
};

const char *MonsterName[3] = {
    "Goblin",
    "Elf",
    "Werewolf"
};

float WeaponDamage[WeaponAmount] = {
    1.11,
    1.34,
    1.75,
    1.92,
    1.81,
    1.19,
    2.09,
    2.29
};

const char *WeaponsName[WeaponAmount] = {
    "Moonshadow Scimitar",
    "Stormsong Rapier",
    "Bloodthorn Dagger",
    "Frostbane Longsword",
    "Emberstrike Katana",
    "Verdant Viperblade",
    "Celestial Saber",
    "Nightfall Broadsword"
};

int WeaponStamina[WeaponAmount][2] = {
    {24, 12},
    {20, 10},
    {16, 8},
    {36, 18},
    {30, 15},
    {28, 14},
    {26, 13},
    {40, 20}
};

int WeaponOwned[WeaponAmount][2] = {
//Owned level
    {1, 0},
    {1, 0},
    {1, 0},
    {0, 0},
    {1, 0},
    {0, 0},
    {0, 0},
    {1, 0}
};

int WeaonRequirment[WeaponAmount] = {
    7, 
    13, 
    18, 
    22,
    29, 
    34,
    50,
    69 
};

int ScrollDamage[ScrollAmount] = {
    1.15, 
    1.17, 
    1.2,
    1.29,
    1.34,
    1.47,
    1.57,
    1.6
};

const char *ScrollName[ScrollAmount]= {
    "Scroll of Eclipsing Shadows",
    "Scroll of Arcane Tempest",
    "Scroll of Infernal Flames",
    "Scroll of Frostbound Echoes",
    "Scroll of Celestial Light",
    "Scroll of Earthshaker",
    "Scroll of Venomous Secrets",
    "Scroll of Ethereal Whispers"
};

int ScrollMana[ScrollAmount][2] = {
    {8, 12},
    {7, 13},
    {9, 11},
    {6, 14},
    {8, 12},
    {7, 13},
    {6, 14},
    {9, 11}
};

const char *ScrollAbility[ScrollAmount][2] = {
    {"Shadow Reaper", "Umbral Vortex"},
    {"Lightning Wrath", "Tempest Fury"},
    {"Hellfire Blast", "Inferno Surge"},
    {"Glacial Spear", "Frozen Cataclysm"},
    {"Holy Smite", "Divine Wrath"},
    {"Quake Strike", "Stone Crush"},
    {"Toxic Cloud", "Poison Fang"},
    {"Soul Drain", "Phantom Slash"},
};

int ScrollOwned[ScrollAmount][2] = {
//Owned level
    {1, 0},
    {1, 0},
    {1, 0},
    {1, 0},
    {1, 0},
    {1, 0},
    {1, 0},
    {1, 0}
};

int ScrollRequirment[ScrollAmount] = {
    3, 
    9, 
    13, 
    17,
    20, 
    26,
    29,
    32 
};

int TalismanOwned[TalismansAmount] = {
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1
};

char *talismanNames[8] = {
    "Talisman of Vitality",
    "Talisman of Wisdom",
    "Talisman of Endurance",
    "Talisman of Power",
    "Talisman of Faith",
    "Talisman of Arcana",
    "Talisman of Regeneration",
    "Talisman of Protection"
};

int talismantPowers[TalismansAmount][3] = {
    //amount
    //0 = hp, 1 = mana, 2 = stamina, 3 = strength, 4 = faith, 5 = arche
    //0 = overall, 1 = overtime
    {5, 0, 0},
    {5, 1, 1},
    {3, 2, 0}, 
    {7, 3, 0}, 
    {5, 4, 0}, 
    {10, 5, 0}, 
    {10, 0, 1}, 
    {15, 1, 0}  
};

int Items[ItemAmount][3] = {
//amount howMuch Where
    {2, 30, 0},
    {1, 10, 1},
    {0, 5, 2},
    {1, 50, 0},
    {5, 10, 1},
    {2, 15, 3},
    {0, 100, 0},
    {2, 200, 0}
};

char *itemName[ItemAmount] = {
    "Health Potion",
    "Stamina Elixir",
    "Mana Crystal",
    "Revitalizing Herb",
    "Energy Drink",
    "Mystic Berry",
    "Phoenix Feather",
    "Endurance Potion"
};

int map[XLength][YLength];

char map1[XLength][YLength] = {
    {"+---^----+"},
    {"|        |"},
    {"|        |"},
    {"|        |"},
    {"|     E  |"},
    {"|        |"},
    {"|        |"},
    {"|        |"},
    {"|        |"},
    {"+--------+"}
};

char map2[XLength][YLength] = {
    {"+--------+"},
    {"| E    E |"},
    {"|        |"},
    {"|        |"},
    {"|        |"},
    {"|        |"},
    {"|        |"},
    {"|        |"},
    {"|        |"},
    {"+---v----+"}
};

char (*maps[])[XLength][YLength] = {&map1, &map2};

int TotalXp = 0;

void MenuGame();
int StartGame();
int game();
int battle(int mapId);

int file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1; // File exists
    }
    return 0; // File does not exist
}

int maximum(int Player, int add, int buff){

    if(buff + add >= Player){
        buff = Player;
    }else{
        buff += add;
    }

    return buff;
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
        printf("Faith: %d\n", PlayerStuts[4]);
        if(OptionPointer == 5){printf(">");}
        printf("Arche: %d\n", PlayerStuts[5]);

        Command = _getch();

        if(Command=='w' && OptionPointer > 0){
            OptionPointer--;
        }else if(Command=='s' && OptionPointer < 5){
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
    while (TotalXp >= requiredXPForLevel(playerLevel + 1)) {
        TotalXp -= requiredXPForLevel(playerLevel + 1);
        (playerLevel)++;
        printf("Leveled up! New level");
    }

}

int MonsterHpFinder(int MonsterID){

    float Hp;
    int Returnal;

    if(MonsterStuts[MonsterID][1] <= 10){
        Hp = MonsterStuts[MonsterID][1] * 1 ;
    }else if(MonsterStuts[MonsterID][1] <= 20){
        Hp = (MonsterStuts[MonsterID][1] - 10) * 2.61 + 10;
    }else if(MonsterStuts[MonsterID][1] <= 45){
        Hp = (MonsterStuts[MonsterID][1] - 35) * 4.89 +  36.1;
    }else if(MonsterStuts[MonsterID][1] <= 70){
        Hp = (MonsterStuts[MonsterID][1] - 60) * 5.26 + 158.35 ;
    }else if(MonsterStuts[MonsterID][1] <= 80){
        Hp = (MonsterStuts[MonsterID][1] - 70) * 3.03 +  237.25;
    }else if(MonsterStuts[MonsterID][1] <= 99){
        Hp = (MonsterStuts[MonsterID][1] - 80) * 1.98 +  267.55;
    }

    Returnal = (int)Hp;

    sleep(2);

    return Returnal;
}

int MonsterAttack(int MonsterID){

    int EnemyMove;
    int Negative;

    switch (MonsterStuts[MonsterID][6]){
    case 0: 
        EnemyMove = rand() % 3;

        if(EnemyMove == 0){
            Negative = MonsterStuts[MonsterID][2];
        }else if(EnemyMove == 1){
            Negative = MonsterStuts[MonsterID][3];
        }else if(EnemyMove == 2){
            Negative = MonsterStuts[MonsterID][4];
        }else if(EnemyMove == 3){
            Negative = MonsterStuts[MonsterID][5];
        }
        break;

    case 1: 

        EnemyMove = rand() % 1;

        if(EnemyMove == 0){
            Negative = MonsterStuts[MonsterID][3];
        }else if(EnemyMove == 1){
            Negative = MonsterStuts[MonsterID][4];
        }
        break;
    
    default:
        break;
    }

    return Negative;
}

int HpFinder(){

    float Hp;
    int Returnal;

    if(PlayerStuts[0] <= 10){
        Hp = PlayerStuts[0] * 1 ;
    }else if(PlayerStuts[0] <= 20){
        Hp = (PlayerStuts[0] - 10) * 2.61 + 10;
    }else if(PlayerStuts[0] <= 45){
        Hp = (PlayerStuts[0] - 35) * 4.89 +  36.1;
    }else if(PlayerStuts[0] <= 70){
        Hp = (PlayerStuts[0] - 60) * 5.26 + 158.35 ;
    }else if(PlayerStuts[0] <= 80){
        Hp = (PlayerStuts[0] - 70) * 3.03 +  237.25;
    }else if(PlayerStuts[0] <= 99){
        Hp = (PlayerStuts[0] - 80) * 1.98 +  267.55;
    }

    Returnal = (int)Hp + 40;

    sleep(2);

    return Returnal;
}

int MapDestinationDataBase(int x, int y) {
    
    int mapId;

    switch (mapTempID)
    {
    case 1:
        if(x == 0 && y == 4 ){
            mapId = 2;
        }
        break;
    case 2:
        if(x == 9 && y == 4 ){
            mapId = 1;
        }
        break;

    default:
        break;
    }

    return mapId;
}

void MapFunction(int xAxis,int yAxis, int mapId){
    
    if(mapTempID != mapId){
       switch (mapId) {
        case 1:
            for (int i = 0; i < XLength; i++) {
                for (int j = 0; j < YLength; j++) {
                    map[i][j] = map1[i][j];
                }
            }
            break;

        case 2:
            for (int i = 0; i < XLength; i++) {
                for (int j = 0; j < YLength; j++) {
                    map[i][j] = map2[i][j];
                }
            }
            break;

        default:
            printf("Invalid mapId\n");
            return;
        }
    }
    
    int temp = map[xAxis][yAxis];
    map[xAxis][yAxis] = 'A';

    //print the map of the game
    for(int i=0; i<XLength; i++){
        for(int z=0; z<YLength; z++){
            printf("%c ", map[i][z]);   
        }
        printf("\n");
    }

    map[xAxis][yAxis] = temp; 

    mapTempID = mapId;

}

int processMovement(char CommandToMove, int mapId) {
    int newX = xAxis;
    int newY = yAxis;
    int flag = 0;

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
        newX = 8;
        flag = 1;
    } else if (destination == 'v') {
        mapId = MapDestinationDataBase(newX, newY);
        newX = 1;
        flag = 1;
    } else if (destination == '>') {
        mapId = MapDestinationDataBase(newX, newY);
        newY = 9;
        flag = 1;
    } else if (destination == '<') {
        mapId = MapDestinationDataBase(newX, newY);
        newY = 1;
        flag = 1;
    }

    // Ensure the new coordinates are within map bounds
    if (map[newX][newY] != ' ' && flag == 0) {
        printf("%c", CommandToMove);
        return mapId;
    } 
    
    xAxis = newX;
    yAxis = newY;

    return mapId;
}

void WeaponsDisplay(){

    int OptionPointer = 0;
    char Command;

    int amount=0;
    int WeaponListId[WeaponAmount];

    for(int i = 0; i < 8; i++){
        if(WeaponOwned[i][0] == 1){
            WeaponListId[amount] = i;
            amount++;
        }
    }

    while(1){
        system("cls||clear");
        printf("====== Weapons ======\n");

        for(int i = 0; i < amount; i++){
            if(OptionPointer == i){printf(">");}
            printf("%s \n", WeaponsName[WeaponListId[i]]);
        }

        printf("=====================\n");

        printf("%d\n", OptionPointer);

        Command = _getch();
        printf("\n");

        if(Command=='w' && OptionPointer > 0){
            OptionPointer--;
        }else if(Command=='s' && OptionPointer < amount-1){
            OptionPointer++; 
        }else if(Command=='e'){
            while (1){
                int id = OptionPointer;
            
                int Damage = WeaponDamage[id] * PlayerStuts[3];

                system("cls||clear");

                printf("=== %s ===\n", WeaponsName[id]);
                printf("Requarment: %d Strength\n", WeaonRequirment[id]);
                printf("Damage: %d \n", Damage);
                printf("Stamina For Heavy Attack: %d \n", WeaponStamina[id][0]);
                printf("Stamina For Quick Attack: %d \n", WeaponStamina[id][1]);
                printf("=====================\n");

                printf("\n"); 

                printf("do you wanna equipt this? (y\\n): ");

                Command = _getch();

                if(Command == 'y'){
                    if(PlayerStuts[3]  >= WeaonRequirment[id]){
                        PlayerWeaponId = id;
                    }else{
                        printing("You can handle thiss weapon yet", 0, 10);
                        sleep(1);
                    }
                    break;
                }else if(Command == 'n'){
                    break;
                }
            }
        }else if(Command=='q'){
            break;
        }
    }   

}

void ScrollsDisplay(){

    int OptionPointer = 0;
    char Command;

    int amount=0;
    int ScrollListId[ScrollAmount];

    for(int i = 0; i < 8; i++){
        if(ScrollOwned[i][0] == 1){
            ScrollListId[amount] = i;
            amount++;
        }
    }

    while(1){
        system("cls||clear");
        printf("====== Scrolls ======\n");

        for(int i = 0; i < amount; i++){
            if(OptionPointer == i){printf(">");}
            printf("%s \n", ScrollName[ScrollListId[i]]);
        }

        printf("=====================\n");

        Command = _getch();
        printf("\n");

        if(Command=='w' && OptionPointer > 0){
            OptionPointer--;
        }else if(Command=='s' && OptionPointer < amount-1){
            OptionPointer++; 
        }else if(Command=='e'){
            while (1){
                int id = OptionPointer;
            
                int Damage = ScrollDamage[id] * PlayerStuts[4];

                system("cls||clear");

                printf("=== %s ===\n", ScrollName[id]);
                printf("Requarment: %d Faith\n", ScrollRequirment[id]);
                printf("Damage: %d \n", Damage);
                printf("Move 1: %s \n", ScrollAbility[id][0]);
                printf("Move 2: %s \n", ScrollAbility[id][1]);
                printf("Mana For Move 1 Attack: %d \n", ScrollMana[id][0]);
                printf("Mana For Move 2 Attack: %d \n", ScrollMana[id][1]);
                printf("=====================\n");

                printf("\n"); 

                printf("do you wanna equipt this? (y\\n) :");

                Command = _getch();

                if(Command == 'y'){
                    if(PlayerStuts[4] >= ScrollRequirment[id]){
                        PlayerScrollId = id;
                    }else{
                        printing("You can handle thiss scroll yet", 0, 10);
                        sleep(1);
                    }
                    
                    break;
                }else if(Command == 'n'){
                    break;
                }
            }
        }else if(Command=='b'){
            break;
        }
    }   
}

void TalismantDisplay(){

    int OptionPointer = 0;
    char Command;
    int amount = 0;
    int temp;
    
    while (1){

        int TalismantListId[TalismansAmount] = {9, 9, 9, 9, 9, 9, 9, 9};
        int TalissmanEquipted[TalismansAmount] = {9, 9, 9, 9, 9, 9, 9, 9};

        amount = 0;

        for(int i = 0; i < TalismansAmount; i++){
            if(TalismanOwned[i] == 1){
                TalismantListId[amount] = i;
                amount++;
            }
            if(i < 4){
                if(PlayerTalisman[i] != -1){
                    TalissmanEquipted[i] = PlayerTalisman[i];
                }
            }
            for(int i = 0; i < amount; i++) {
                for(int y = 0; y < 4; y++) {
                    if(TalissmanEquipted[y] == TalismantListId[i]) {
                        amount -= 1;
                    }
                }
            }
        }

        system("cls||clear");
        printf("To Unequipt press 'R'\n");
        printf("==== My Talismans ====\n");
        if(OptionPointer == 0){printf(">");}
        if(PlayerTalisman[0] != -1){printf("%s \n", talismanNames[PlayerTalisman[0]]);
        }else{printf("X \n");}
        if(OptionPointer == 1){printf(">");}
        if(PlayerTalisman[1] != -1){printf("%s \n", talismanNames[PlayerTalisman[1]]);
        }else{printf("X \n");}
        if(OptionPointer == 2){printf(">");}
        if(PlayerTalisman[2] != -1){printf("%s \n", talismanNames[PlayerTalisman[2]]);
        }else{printf("X \n");}
        if(OptionPointer == 3){printf(">");}
        if(PlayerTalisman[3] != -1){printf("%s \n", talismanNames[PlayerTalisman[3]]);
        }else{printf("X \n");}
        printf("\n");

        switch (talismantPowers[PlayerTalisman[OptionPointer]][1]) {
            case 0: printf("HP %d ", talismantPowers[PlayerTalisman[OptionPointer]][0]); break;
            case 1: printf("Mana %d ", talismantPowers[PlayerTalisman[OptionPointer]][0]); break;
            case 2: printf("Stamina %d ", talismantPowers[PlayerTalisman[OptionPointer]][0]); break;
            case 3: printf("Strength %d ", talismantPowers[PlayerTalisman[OptionPointer]][0]); break;
            case 4: printf("Faith %d ", talismantPowers[PlayerTalisman[OptionPointer]][0]); break;
            case 5: printf("Arche %d ", talismantPowers[PlayerTalisman[OptionPointer]][0]); break;
        }

        if(PlayerTalisman[OptionPointer] != -1){
            printf("%s\n",talismantPowers[PlayerTalisman[OptionPointer]][2] == 0 ? "overall" : "overtime");
        }

        printf("======================\n");

        Command = _getch();

        if(Command=='w' && OptionPointer > 0){
            OptionPointer--;
        }else if(Command=='s' && OptionPointer < 3){
            OptionPointer++; 
        }else if(Command=='e'){
            int TalismanPointer = 0;
            while(1){
                system("cls||clear");
            
                printf("====== Talisman ======\n");

                for(int i = 0; i < amount; i++){
                    if(TalismanPointer == i){printf(">");}
                    printf("%s \n", talismanNames[TalismantListId[i]]);
                }
                printf("\n");
                switch (talismantPowers[PlayerTalisman[TalismanPointer]][1]) {
                    case 0: printf("HP %d ", talismantPowers[PlayerTalisman[TalismanPointer]][0]); break;
                    case 1: printf("Mana %d ", talismantPowers[PlayerTalisman[TalismanPointer]][0]); break;
                    case 2: printf("Stamina %d ", talismantPowers[PlayerTalisman[TalismanPointer]][0]); break;
                    case 3: printf("Strength %d ", talismantPowers[PlayerTalisman[TalismanPointer]][0]); break;
                    case 4: printf("Faith %d ", talismantPowers[PlayerTalisman[TalismanPointer]][0]); break;
                    case 5: printf("Arche %d ", talismantPowers[PlayerTalisman[TalismanPointer]][0]); break;
                }

                printf("%s\n",talismantPowers[PlayerTalisman[TalismanPointer]][2] == 0 ? "overall" : "overtime");

                printf("=====================\n");

                Command = _getch();

                if(Command=='w' && TalismanPointer > 0){
                    TalismanPointer--;
                }else if(Command=='s' && TalismanPointer < amount-1){
                    TalismanPointer++; 
                }else if(Command=='e'){
                    temp = PlayerTalisman[OptionPointer];
                    PlayerTalisman[OptionPointer] = TalismantListId[TalismanPointer];
                    TalismantListId[TalismanPointer] = temp;
                    break;
                }else if(Command=='q'){
                    break;
                }
            }
        }else if(Command=='r'){
            PlayerTalisman[OptionPointer] = -1;

        }else if(Command=='q'){
            break;
        }
    }
}

void ItemInspector(){

    char Command;
    int OptionPointer = 0;

    int ItemsBuff[ItemAmount] = {9, 9, 9, 9, 9, 9, 9, 9};
    int amount = 0;
    
    system("cls||clear");

    for(int i = 0; i < ItemAmount; i++){
        if(Items[i][0] != 0){
            ItemsBuff[amount] = i;
            amount++;
            
        } 
    }

    while(1){
        system("cls||clear");

        printf("======== Items ========\n");

        for(int i = 0; i < amount; i++){
            if(OptionPointer == i){printf(">");}
            switch (Items[ItemsBuff[i]][2]) {
            case 0: printf("%d | %s hp: %d \n", Items[ItemsBuff[i]][0], itemName[ItemsBuff[i]], Items[ItemsBuff[i]][1]); break;
            case 1: printf("%d | %s St: %d \n", Items[ItemsBuff[i]][0], itemName[ItemsBuff[i]], Items[ItemsBuff[i]][1]); break;
            case 2: printf("%d | %s Mn: %d \n", Items[ItemsBuff[i]][0], itemName[ItemsBuff[i]], Items[ItemsBuff[i]][1]); break;
            case 3:
                if(ItemsBuff[i] == 5){
                   printf("%d | %s hp: %d Mn: %d\n", Items[ItemsBuff[i]][0], itemName[ItemsBuff[i]], Items[ItemsBuff[i]][1], Items[ItemsBuff[i]][1]);
                }
                break;
            }
        }

        printf("=======================\n");

        Command = _getch();

        if(Command=='w' && OptionPointer > 0){
            OptionPointer--;
        }else if(Command=='s' && OptionPointer < amount-1){
            OptionPointer++; 
        }else if(Command=='e'){   
            if(ItemsBuff[OptionPointer] == 5){
                printing("You can't use this item", 0, 10);
            }
        }else if(Command=='q'){
            break;
        }
    }   
}

void PlayerIspection(){

    char Command;  

    system("cls||clear");

    printf("%s \n", PlayerName);
    printf("Level: %d", playerLevel);

    printf("Weapon: %s\n", WeaponsName[PlayerWeaponId]);
    printf("Scroll: %s\n\n", ScrollName[PlayerScrollId]);

    printf("Hp: %d\n", PlayerStuts[0]);
    printf("Mana: %d\n", PlayerStuts[1]);
    printf("Stamina: %d\n", PlayerStuts[2]); 
    printf("Stengeth: %d\n", PlayerStuts[3]); 
    printf("Faith: %d\n", PlayerStuts[4]);
    printf("Arche: %d\n\n", PlayerStuts[5]);

    if(PlayerTalisman[0] != -1){printf("Talismant: %s \n", talismanNames[PlayerTalisman[0]]);
    }else{printf("Talismant: X \n");}
    if(PlayerTalisman[1] != -1){printf("Talismant: %s \n", talismanNames[PlayerTalisman[1]]);
    }else{printf("Talismant: X \n");}
    if(PlayerTalisman[2] != -1){printf("Talismant: %s \n", talismanNames[PlayerTalisman[2]]);
    }else{printf("Talismant: X \n");}
    if(PlayerTalisman[3] != -1){printf("Talismant: %s \n", talismanNames[PlayerTalisman[3]]);
    }else{printf("Talismant: X \n");}

    Command = _getch();
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
    fwrite(&playerLevel, sizeof(playerLevel), 1, file);
    fwrite(PlayerTalisman, sizeof(PlayerTalisman), 1, file);
    fwrite(&PlayerWeaponId, sizeof(PlayerWeaponId), 1, file);
    fwrite(&PlayerScrollId, sizeof(PlayerScrollId), 1, file);
    fwrite(&mapTempID, sizeof(mapTempID), 1, file);
    fwrite(&xAxis, sizeof(xAxis), 1, file);
    fwrite(&yAxis, sizeof(yAxis), 1, file);
    fwrite(WeaponOwned, sizeof(WeaponOwned), 1, file);
    fwrite(ScrollOwned, sizeof(ScrollOwned), 1, file);
    fwrite(TalismanOwned, sizeof(TalismanOwned), 1, file);
    fwrite(Items, sizeof(Items), 1, file);
    fwrite(&TotalXp, sizeof(TotalXp), 1, file);

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
    fread(&playerLevel, sizeof(playerLevel), 1, file);
    fread(PlayerTalisman, sizeof(PlayerTalisman), 1, file);
    fread(&PlayerWeaponId, sizeof(PlayerWeaponId), 1, file);
    fread(&PlayerScrollId, sizeof(PlayerScrollId), 1, file);
    fread(&mapTempID, sizeof(mapTempID), 1, file);
    fread(&xAxis, sizeof(xAxis), 1, file);
    fread(&yAxis, sizeof(yAxis), 1, file);
    fread(WeaponOwned, sizeof(WeaponOwned), 1, file);
    fread(ScrollOwned, sizeof(ScrollOwned), 1, file);
    fread(TalismanOwned, sizeof(TalismanOwned), 1, file);
    fread(Items, sizeof(Items), 1, file);
    fread(&TotalXp, sizeof(TotalXp), 1, file);

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

    srand(time(0));

    int Class[6][6] = {
        //hp mana stamina strength faith arce
        {10, 5, 10, 10, 3, 2},
        {7, 10, 5, 3, 10, 5},
        {5, 10, 5, 3, 15, 2},
        {5, 15, 5, 3, 10, 2},
        {10, 10, 10, 5, 3, 2},
        {8, 5, 10, 5, 2, 10},
    };

    char CommandOptionScreen ;

    int NameFlag = 0;
    int RaceFlag = 0;
    int ClassFlag = 0;
    int attempts = 0;
    char answer;

    const char *String;

    int RacePointer;
    int Pick;
    int OptionPointer = 1; 

    playerLevel = 10;

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

    while (RaceFlag == 0){

        while (1){
            system("cls||clear");
            printf("===== Race Piker =====\n");
            if(OptionPointer == 1) printf(">");
            printf("Human\n");
            if(OptionPointer == 2) printf(">");
            printf("Elf\n");
            if(OptionPointer == 3) printf(">");
            printf("Goblin\n");
            if(OptionPointer == 4) printf(">");
            printf("Skeleton\n");
            if(OptionPointer == 5) printf(">");
            printf("Spirit\n");
            if(OptionPointer == 6) printf(">");
            printf("Troll\n");
            printf("=====================\n");

            CommandOptionScreen = _getch();

            if(CommandOptionScreen=='w' && OptionPointer > 1){
                OptionPointer--;
            }else if(CommandOptionScreen=='s' && OptionPointer < 6){
                OptionPointer++; 
            }else if(CommandOptionScreen=='e'){
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
    OptionPointer = 1;

    while (ClassFlag == 0){

        while (1){
            system("cls||clear");
            printf("===== Class Piker =====\n");
            if(OptionPointer == 1) printf(">");
            printf("Warrior\n");
            if(OptionPointer == 2) printf(">");
            printf("Mage\n");
            if(OptionPointer == 3) printf(">");
            printf("Wisard\n");
            if(OptionPointer == 4) printf(">");
            printf("Sumoner\n");
            if(OptionPointer == 5) printf(">");
            printf("Hero\n");
            if(OptionPointer == 6) printf(">");
            printf("Ranger\n");
            printf("\n");
            printf("Hp: ");
            printf("%d\n", Class[OptionPointer-1][0]);
            printf("Mana: ");
            printf("%d\n", Class[OptionPointer-1][1]);
            printf("Stamina: ");
            printf("%d\n", Class[OptionPointer-1][2]);
            printf("Stengeth: ");
            printf("%d\n", Class[OptionPointer-1][3]);
            printf("Faith: ");
            printf("%d\n", Class[OptionPointer-1][4]);
            printf("Arche: ");
            printf("%d\n", Class[OptionPointer-1][5]);
            printf("=====================\n");

            CommandOptionScreen = _getch();

            if(CommandOptionScreen=='w' && OptionPointer > 1){
                OptionPointer--;
            }else if(CommandOptionScreen=='s' && OptionPointer < 6){
                OptionPointer++; 
            }else if(CommandOptionScreen=='e'){
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

                for(int i = 0; i <= 5; i++){
                    PlayerStuts[i] = Class[OptionPointer -1][i];
                }

                PlayerWeaponId = 0;

                PlayerScrollId = 0;

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

int game(){

    char CommandToMove ;
    int won;
    system("cls||clear");

    int mapId = mapTempID;

   char (*selectedMap)[XLength][YLength] = maps[mapId-1];

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
                won = battle(mapId);
                if(won == 1){
                    if(map[xAxis-1][yAxis] == 'E') map[xAxis-1][yAxis] = ' ';
                    if(map[xAxis+1][yAxis] == 'E') map[xAxis+1][yAxis] = ' ';
                    if(map[xAxis][yAxis+1] == 'E') map[xAxis][yAxis+1] = ' ';
                    if(map[xAxis][yAxis-1] == 'E') map[xAxis][yAxis-1] = ' ';
                } 
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

int battle(int mapId){

    int MonsterID;

    if (mapId == 1){
        MonsterID = 0;
    }else if(mapId == 2){
        MonsterID = 1;
    }
    
    int OptionPointer = 1;
    int OptionPointerMove = 1;
    int flagOpen = 0;
    int flag;
    char option;
    
    int TalismantHealthRegenaration = 0;
    int StaminaRegenaration = 20;
    int ManaRegenaration = 3;

    for(int i = 0; i<4; i++){
        if(PlayerTalisman[i] != -1 && talismantPowers[PlayerTalisman[i]][2] != 1){
            switch (talismantPowers[PlayerTalisman[i]][1]) {
            case 0: PlayerStuts[0] += talismantPowers[PlayerTalisman[i]][0]; break;
            case 1: PlayerStuts[1] += talismantPowers[PlayerTalisman[i]][0]; break;
            case 2: PlayerStuts[2] += talismantPowers[PlayerTalisman[i]][0]; break;
            case 3: PlayerStuts[3] += talismantPowers[PlayerTalisman[i]][0]; break;
            case 4: PlayerStuts[4] += talismantPowers[PlayerTalisman[i]][0]; break;
            case 5: PlayerStuts[5] += talismantPowers[PlayerTalisman[i]][0]; break;
            }
        }else if(talismantPowers[PlayerTalisman[i]][2] == 1){
            switch (talismantPowers[PlayerTalisman[i]][1]) {
            case 0: TalismantHealthRegenaration += talismantPowers[PlayerTalisman[i]][0]; break;
            case 1: StaminaRegenaration += talismantPowers[PlayerTalisman[i]][0]; break;
            case 2: ManaRegenaration += talismantPowers[PlayerTalisman[i]][0]; break;
            default :break;
            }
        }
    }

    int MonsterHealth = MonsterHpFinder(MonsterID);
    int MonsterHealthUpdate = MonsterHealth;

    int PlayerHealth = HpFinder();
    int PlayerHealthUpdate = PlayerHealth;

    float PPD1 = (PlayerStuts[3] + PlayerStuts[3]/2) * WeaponDamage[PlayerWeaponId];
    int PlayerPhyDamage1 = (int)PPD1;
    int PWSC1 = WeaponStamina[PlayerWeaponId][0]; //Player Weapon Stamina Consum
    float PPD2 = PlayerStuts[3] * WeaponDamage[PlayerWeaponId];
    int PlayerPhyDamage2 = (int)PPD2;
    int PWSC2 = WeaponStamina[PlayerWeaponId][1];

    float MP1 = PlayerStuts[4] * ScrollDamage[PlayerScrollId];
    int MagicPower1 = (int)MP1;
    int PSMC1 = ScrollMana[PlayerScrollId][0]; //Player Scroll Mana Consum
    float MP2 = PlayerStuts[4] * ScrollDamage[PlayerScrollId];
    int MagicPower2 = (int)MP2;
    int PSMC2 = ScrollMana[PlayerScrollId][1];

    int PlayerStamina = PlayerStuts[2] * 2 + 100;
    int PlayerStaminaUpdate = PlayerStamina;

    int PlayerMana = PlayerStuts[1] * 2;
    int PlayerManaUpdate = PlayerMana;

    int EnemyMove;
    int Amount = 2;

    int Cflag = 0;

    while(1){
        Cflag = 0;

        system("cls||clear");
       
        printf("%s Level: %d\n", MonsterName[MonsterID], MonsterStuts[MonsterID][0]);
        printf("Hp: %d\\%d\n", MonsterHealthUpdate, MonsterHealth);

        printf("\n");

        printf("%s Level: %d\n", PlayerName, playerLevel);
        printf("Hp: %d\\%d\n", PlayerHealthUpdate, PlayerHealth);
        printf("Stamina: %d\\%d\n", PlayerStaminaUpdate, PlayerStamina);
        printf("Mana: %d\\%d\n", PlayerManaUpdate, PlayerManaUpdate);
        
        printf("\n");
        
        if(PlayerHealthUpdate <= 0){
            printing("You Died", 0, 100);
            sleep(2);
            return 0;
        }

        if(flagOpen == 0){
            
            if(option=='w' && OptionPointer > 1) OptionPointer--;
            if(option=='s' && OptionPointer < 4) OptionPointer++;
            
            if(OptionPointer == 1) printf(">");
            printf("Physicals\n");
            if(OptionPointer == 2) printf(">");
            printf("Magic\n");
            if(OptionPointer == 3) printf(">");
            printf("Item\n");
            if(OptionPointer == 4) printf(">");
            printf("Run\n");

        }else if(flagOpen == 1){

            if(option=='w' && OptionPointerMove > 1) OptionPointerMove--;
            if(option=='s' && OptionPointerMove < 2) OptionPointerMove++;
            
            if(OptionPointer == 1){

                printf("Physicals --+-- ");
                if(OptionPointerMove == 1) printf(">");
                printf("Heavy St: %d\n", PWSC1);
                printf("            +-- ");
                if(OptionPointerMove == 2) printf(">");
                printf("Quick St: %d\n", PWSC2);

                printf("Magic\n");
                printf("Item\n");
                printf("Run\n");

            }else if(OptionPointer == 2){

                printf("Physicals\n");

                printf("Magic --+-- ");
                if(OptionPointerMove == 1) printf(">");
                printf("Fire Mn: %d\n", PSMC1);
                printf("        +-- ");
                if(OptionPointerMove == 2) printf(">");
                printf("Ice Mn: %d\n", PSMC2);

                printf("Item\n");
                printf("Run\n");
            }else if(OptionPointer == 3){

                char Command;
                int OptionPointer = 0;

                int ItemsBuff[ItemAmount] = {9, 9, 9, 9, 9, 9, 9, 9};
                int amount = 0;
    
                system("cls||clear");

                for(int i = 0; i < ItemAmount; i++){
                    if(Items[i][0] != 0){
                        ItemsBuff[amount] = i;
                        amount++;
                        
                    } 
                }

                while(1){
                    system("cls||clear");

                    printf("======== Items ========\n");

                    for(int i = 0; i < amount; i++){
                        if(OptionPointer == i){printf(">");}
                        switch (Items[ItemsBuff[i]][2]) {
                        case 0: printf("%d | %s hp: %d \n", Items[ItemsBuff[i]][0], itemName[ItemsBuff[i]], Items[ItemsBuff[i]][1]); break;
                        case 1: printf("%d | %s St: %d \n", Items[ItemsBuff[i]][0], itemName[ItemsBuff[i]], Items[ItemsBuff[i]][1]); break;
                        case 2: printf("%d | %s Mn: %d \n", Items[ItemsBuff[i]][0], itemName[ItemsBuff[i]], Items[ItemsBuff[i]][1]); break;
                        case 3:
                            if(ItemsBuff[i] == 5){
                            printf("%d | %s hp: %d Mn: %d\n", Items[ItemsBuff[i]][0], itemName[ItemsBuff[i]], Items[ItemsBuff[i]][1], Items[ItemsBuff[i]][1]);
                            }
                            break;
                        }
                    }

                    printf("=======================\n");

                    Command = _getch();
                    fflush(stdin);

                    if(Command=='w' && OptionPointer > 0){
                        OptionPointer--;
                    }else if(Command=='s' && OptionPointer < amount-1){
                        OptionPointer++; 
                    }else if(Command=='e'){
                        switch(Items[ItemsBuff[OptionPointer]][2]){
                        case 0:
                            PlayerHealthUpdate = maximum(PlayerHealth, Items[ItemsBuff[OptionPointer]][1], PlayerHealthUpdate);
                            Items[ItemsBuff[OptionPointer]][0]--;
                            break;

                        case 1:
                            PlayerStaminaUpdate = maximum(PlayerStamina, Items[ItemsBuff[OptionPointer]][1], PlayerStaminaUpdate); 
                            Items[ItemsBuff[OptionPointer]][0]--;
                            break;
                        
                        case 2:
                            PlayerManaUpdate = maximum(PlayerMana, Items[ItemsBuff[OptionPointer]][1], PlayerManaUpdate);
                            Items[ItemsBuff[OptionPointer]][0]--;
                            break;

                        case 3:
                            if(ItemsBuff[OptionPointer] == 5){
                                PlayerManaUpdate = maximum(PlayerMana, Items[ItemsBuff[OptionPointer]][1], PlayerManaUpdate);

                                PlayerHealthUpdate = maximum(PlayerHealth, Items[ItemsBuff[OptionPointer]][1], PlayerHealthUpdate);

                                Items[ItemsBuff[OptionPointer]][0]--;
                            }
                            break;
                        }
                    }else if(Command=='q'){
                        printf("exit\n");
                        Cflag = 1;
                        break;
                    }
                }   

            }else if(OptionPointer == 4){
                break;
            }

        }

        if(Cflag == 0){option = _getch();}else{option = 'q';} 

        if(option == 'e' && flagOpen == 0){
            flagOpen = 1; 
            OptionPointerMove = 1; 
        }else if(option == 'e' && flagOpen == 1){
            if(OptionPointer == 1){
                if(OptionPointerMove == 1 && PlayerStaminaUpdate - PWSC1 >= 0){
                    MonsterHealthUpdate -= PlayerPhyDamage1;
                    PlayerStaminaUpdate -= PWSC1;
                    flag = 1;
                }else if(OptionPointerMove == 2 && PlayerStaminaUpdate - PWSC2 >= 0){
                    MonsterHealthUpdate -= PlayerPhyDamage2;
                    PlayerStaminaUpdate -= PWSC2;
                    flag = 1;
                }else{
                    flag = 0;
                }
            }else if(OptionPointer == 2){
                if(OptionPointerMove == 1 && PlayerManaUpdate - PSMC1 >= 0){
                    MonsterHealthUpdate -= MagicPower1;
                    PlayerManaUpdate -= PSMC1;
                    flag = 1;
                }else if(OptionPointerMove == 2 && PlayerManaUpdate - PSMC2 >= 0){
                    MonsterHealthUpdate -= MagicPower2;
                    PlayerManaUpdate -= PSMC2;
                    flag = 1;
                }else{
                    flag = 0;
                }
            }

            flagOpen = 0; 
            OptionPointer = 1; 

            system("cls||clear");
       
            printf("%s Level: %d\n", MonsterName[MonsterID], MonsterStuts[MonsterID][0]);
            printf("Hp: %d\\%d\n", MonsterHealthUpdate, MonsterHealth);

            printf("\n");

            printf("%s Level: %d\n", PlayerName, playerLevel);
            printf("Hp: %d\\%d\n", PlayerHealthUpdate, PlayerHealth);
            printf("Stamina: %d\\%d\n", PlayerStaminaUpdate, PlayerStamina);
            printf("Mana: %d\\%d\n", PlayerManaUpdate, PlayerManaUpdate);
            printf("\n");
            printf("Physicals\n");
            printf("Magic\n");
            printf("Item\n");
            printf("Run\n");

            if(flag == 1){
                PlayerStaminaUpdate = maximum(PlayerStamina, StaminaRegenaration, PlayerStaminaUpdate); 
                
                PlayerManaUpdate = maximum(PlayerMana, ManaRegenaration, PlayerManaUpdate);

                PlayerHealthUpdate = maximum(PlayerHealth, TalismantHealthRegenaration, PlayerHealthUpdate);
                    
                if(MonsterHealthUpdate <= 0){
                    TotalXp += MonsterStuts[MonsterID][0] * 3;
                    Sleep(500);
                    printf("\n");
                    printing("Monster Faild", 0, 100);
                    printing("Killed enemy of level ", 1, 10);
                    printf("%d ", MonsterStuts[MonsterID][0]);
                    printing("and Gained ", 1, 10);
                    printf("%d ", TotalXp);
                    printing("Xp", 0, 10);

                    sleep(2);
                    Levelup();
                    return 1;
                }

                sleep(1);

                PlayerHealthUpdate -= MonsterAttack(MonsterID);

                system("cls||clear");
       
                printf("%s Level: %d\n", MonsterName[MonsterID], MonsterStuts[MonsterID][0]);
                printf("Hp: %d\\%d\n", MonsterHealthUpdate, MonsterHealth);

                printf("\n");

                printf("%s Level: %d\n", PlayerName, playerLevel);
                printf("Hp: %d\\%d\n", PlayerHealthUpdate, PlayerHealth);
                printf("Stamina: %d\\%d\n", PlayerStaminaUpdate, PlayerStamina);
                printf("Mana: %d\\%d\n", PlayerManaUpdate, PlayerManaUpdate);
                printf("\n");
                printf("Physicals\n");
                printf("Magic\n");
                printf("Item\n");
                printf("Run\n");

            }else{
                printf("\n");
                printing("You don't have enough Mana/Stamina for this move", 0, 10);
                sleep(2);
            }
            
        }
        
        if(option == 'q'){
            flagOpen = 0; 
        }
        
    }
    
}
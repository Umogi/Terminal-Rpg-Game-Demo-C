#include "Public.h"
#include "Items.h"
#include "Maps.h"
#include "Scrolls.h"
#include "Talisman.h"
#include "Weapons.h"
#include "Enemies.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 
#include <windows.h>
#include <unistd.h>
#include <conio.h>

int scrollDamage(int Id){

    int MonsterID = 0;
    int Damage = 0;

    Scroll S_Id = scrolls[PlayerScrollId];
    Enemy E_Id = enemies[MonsterID];

    int ice = S_Id.ice_damge;
    int fire = S_Id.fire_damge;
    int holly = S_Id.holy_damge;

    if(Id == 0){
        S_Id.damage_1 += ice - ice * E_Id.ice_damage_resistance;
        S_Id.damage_1 += fire - fire* E_Id.fire_damage_resistance;
        S_Id.damage_1 += holly - holly * E_Id.holy_damage_resistance;
        return S_Id.damage_1;

    }else if(Id == 1){
        S_Id.damage_2 += (ice - ice * E_Id.ice_damage_resistance);
        S_Id.damage_2 += (fire - fire* E_Id.fire_damage_resistance);
        S_Id.damage_2 += (holly - holly * E_Id.holy_damage_resistance);
        return S_Id.damage_2;

    }

}

int ScallingWeapon(int Base){

    int AddDamage = 0;

    Weapon W_Id = weapons[PlayerWeaponId];

    if(W_Id.strength != '-'){

        switch (W_Id.strength)
        {
        case 'S':
            AddDamage += PlayerStuts[3] * 0.1 * W_Id.physical_damage;
            break;

        case 'A':
            AddDamage += PlayerStuts[3] * 0.08 * W_Id.physical_damage;
            break;

        case 'B':
            AddDamage += PlayerStuts[3] * 0.06 * W_Id.physical_damage;
            break;

        case 'C':
            AddDamage += PlayerStuts[3] * 0.05 * W_Id.physical_damage;
            break;

        case 'D':
            AddDamage += PlayerStuts[3] * 0.03 * W_Id.physical_damage;
            break;

        case 'E':
            AddDamage += PlayerStuts[3] * 0.02 * W_Id.physical_damage;
            break;

        default:
            break;
        }
    }
    if(W_Id.dexterity != '-'){

        switch (W_Id.dexterity)
        {
        case 'S':
            AddDamage += PlayerStuts[3] * 0.1 * W_Id.physical_damage;
            break;

        case 'A':
            AddDamage += PlayerStuts[3] * 0.08 * W_Id.physical_damage;
            break;

        case 'B':
            AddDamage += PlayerStuts[3] * 0.06 * W_Id.physical_damage;
            break;

        case 'C':
            AddDamage += PlayerStuts[3] * 0.05 * W_Id.physical_damage;
            break;

        case 'D':
            AddDamage += PlayerStuts[3] * 0.03 * W_Id.physical_damage;
            break;

        case 'E':
            AddDamage += PlayerStuts[3] * 0.02 * W_Id.physical_damage;
            break;

        default:
            break;
        }

    }
    if(W_Id.intelligence != '-'){

        switch (W_Id.intelligence)
        {
        case 'S':
            AddDamage += PlayerStuts[3] * 0.1 * W_Id.physical_damage;
            break;

        case 'A':
            AddDamage += PlayerStuts[3] * 0.08 * W_Id.physical_damage;
            break;

        case 'B':
            AddDamage += PlayerStuts[3] * 0.06 * W_Id.physical_damage;
            break;

        case 'C':
            AddDamage += PlayerStuts[3] * 0.05 * W_Id.physical_damage;
            break;

        case 'D':
            AddDamage += PlayerStuts[3] * 0.03 * W_Id.physical_damage;
            break;

        case 'E':
            AddDamage += PlayerStuts[3] * 0.02 * W_Id.physical_damage;
            break;

        default:
            break;
        }

    }
    if(W_Id.faith != '-'){

        switch (W_Id.faith)
        {
        case 'S':
            AddDamage += PlayerStuts[3] * 0.1 * W_Id.physical_damage;
            break;

        case 'A':
            AddDamage += PlayerStuts[3] * 0.08 * W_Id.physical_damage;
            break;

        case 'B':
            AddDamage += PlayerStuts[3] * 0.06 * W_Id.physical_damage;
            break;

        case 'C':
            AddDamage += PlayerStuts[3] * 0.05 * W_Id.physical_damage;
            break;

        case 'D':
            AddDamage += PlayerStuts[3] * 0.03 * W_Id.physical_damage;
            break;

        case 'E':
            AddDamage += PlayerStuts[3] * 0.02 * W_Id.physical_damage;
            break;

        default:
            break;
        }

    }
    if(W_Id.arcane != '-'){

        switch (W_Id.arcane)
        {
        case 'S':
            AddDamage += PlayerStuts[3] * 0.1 * W_Id.physical_damage;
            break;

        case 'A':
            AddDamage += PlayerStuts[3] * 0.08 * W_Id.physical_damage;
            break;

        case 'B':
            AddDamage += PlayerStuts[3] * 0.06 * W_Id.physical_damage;
            break;

        case 'C':
            AddDamage += PlayerStuts[3] * 0.05 * W_Id.physical_damage;
            break;

        case 'D':
            AddDamage += PlayerStuts[3] * 0.03 * W_Id.physical_damage;
            break;

        case 'E':
            AddDamage += PlayerStuts[3] * 0.02 * W_Id.physical_damage;
            break;

        default:
            break;
        }

    }

    return AddDamage;
}

int wepaonDamage(int Id){

    int MonsterID = 0;
    int Damage = 0;

    Weapon W_Id = weapons[PlayerWeaponId];
    Enemy E_Id = enemies[MonsterID];

    int physical = W_Id.physical_damage;
    int ice = W_Id.ice_damge;
    int fire = W_Id.fire_damge;
    int holly = W_Id.holy_damge;

    if(Id == 0){
        Damage += physical + ScallingWeapon(physical) - physical * E_Id.physical_damage_resistance;
        Damage += ice - ice * E_Id.ice_damage_resistance;
        Damage += fire - fire* E_Id.fire_damage_resistance;
        Damage += holly - holly * E_Id.holy_damage_resistance;
    }else if(Id == 1){
        Damage += (physical + ScallingWeapon(physical) - physical * E_Id.physical_damage_resistance)* 1.2;
        Damage += (ice - ice * E_Id.ice_damage_resistance)* 1.2;
        Damage += (fire - fire* E_Id.fire_damage_resistance)* 1.2;
        Damage += (holly - holly * E_Id.holy_damage_resistance)* 1.2;
    }

    return Damage;
}

void InfoBattle(int EnemyHealthUpdate, int EnemyHealth, int PlayerHealthUpdate, int PlayerHealth, int PlayerStaminaUpdate, int PlayerStamina, int PlayerManaUpdate, int PlayerMana){
    system("cls||clear");

    printf("Enemy\n");
    printf("Hp: %d\\%d\n", EnemyHealthUpdate, EnemyHealth);
    printf("\n");
    printf("%s\n", PlayerName);
    printf("Hp: %d\\%d\n", PlayerHealthUpdate, PlayerHealth);
    printf("Sta: %d\\%d\n",PlayerStaminaUpdate, PlayerStamina);
    printf("Mana: %d\\%d\n", PlayerManaUpdate, PlayerMana);
    printf("\n");
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

int BattleScreen(int MonsterId){

    int OptionPointerMove = 0;
    int flagOpen = 0;
    int flag = 0;

    int EnemyMove;

    int OptionPointer = 0;
    char Command; 

    int EnemyHealth = instances[MonsterId].enemyData->Hp;
    int EnemyHealthUpdate = EnemyHealth;

    int PlayerHealth = HpFinder();
    int PlayerHealthUpdate = PlayerHealth;

    int PlayerStamina = PlayerStuts[2] * 2 + 100;
    int PlayerStaminaUpdate = PlayerStamina;

    int PlayerMana = PlayerStuts[1] * 2;
    int PlayerManaUpdate = PlayerMana;

    int enemy_poison_build = instances[MonsterId].enemyData->poison_build;
    int enemy_bleed_build = instances[MonsterId].enemyData->bleed_build;
    int enemy_burn_build = instances[MonsterId].enemyData->burn_build;
    int enemy_frost_build = instances[MonsterId].enemyData->frost_build;

    int Poison_Turns = 0;
    int Burn_Turns = 0;
    int frost_turn = 0;

    while(1){

        flag = 0;

        InfoBattle(EnemyHealthUpdate, EnemyHealth, PlayerHealthUpdate, PlayerHealth, PlayerStaminaUpdate, PlayerStamina, PlayerManaUpdate, PlayerMana);

        if(PlayerHealthUpdate <= 0){
            printf("Player Died");
            sleep(2);
            return 0;
        }

		if(flagOpen == 0){

            if(OptionPointer == 0) printf(">");
            printf("Physicals\n");
            if(OptionPointer == 1) printf(">");
            printf("Magic\n");
            if(OptionPointer == 2) printf(">");
            printf("Item\n");
            if(OptionPointer == 3) printf(">");
            printf("Run\n");

        }else if(flagOpen == 1){

            if(OptionPointer == 0){

                printf("Physicals --+-- ");
                if(OptionPointerMove == 0) printf(">");
                printf("Heavy St: %d\n", 10);
                printf("            +-- ");
                if(OptionPointerMove == 1) printf(">");
                printf("Quick St: %d\n", 15);

                printf("Magic\n");
                printf("Item\n");
                printf("Run\n");

            }else if(OptionPointer == 1){

                printf("Physicals\n");

                printf("Magic --+-- ");
                if(OptionPointerMove == 0) printf(">");
                printf("Fire Mn: %d\n", 10);
                printf("        +-- ");
                if(OptionPointerMove == 1) printf(">");
                printf("Ice Mn: %d\n", 10);

                printf("Item\n");
                printf("Run\n");
            }else if(OptionPointer == 2){
                
                flag = 1;

                char Command;
                int ItemPointer = 0;

                int ItemsBuffer[ItemAmount];
                
                for ( int i = 0; i < ItemAmount; i++){
                    ItemsBuffer[i] = -1;
                }

                int amount = 0;
                
                system("cls||clear");

                for(int i = 0; i < ItemAmount; i++){
                    if(items[i].mass != 0){
                        ItemsBuffer[amount] = i;
                        amount++;
                    } 
                }

                while(1){
                    system("cls||clear");

                    printf("======== Items ========\n");

                    for(int i = 0; i < amount; i++){
                        if(ItemPointer == i){printf(">");}
                        printf("%d %s: ", items[ItemsBuffer[i]].mass, items[ItemsBuffer[i]].name);
                        if(items[ItemsBuffer[i]].Hp == true) printf(" HP %d", items[ItemsBuffer[i]].amount);
                        if(items[ItemsBuffer[i]].Stamina == true) printf(" Stamina %d ", items[ItemsBuffer[i]].amount);
                        if(items[ItemsBuffer[i]].Mana == true) printf(" Mana %d ", items[ItemsBuffer[i]].amount);
                        printf("\n");
                    }   

                    printf("=======================\n");

                    Command = _getch();

                    if(Command=='w' && ItemPointer > 0){
                        ItemPointer--;
                    }else if(Command=='s' && ItemPointer < amount-1){
                        ItemPointer++; 
                    }else if(Command=='e'){ 

                        if(items[ItemsBuffer[ItemPointer]].Hp == true){
                            if(PlayerHealthUpdate + items[ItemsBuffer[ItemPointer]].amount >= PlayerHealth){
                                PlayerHealthUpdate = PlayerHealth;
                            }else{
                                PlayerHealthUpdate += items[ItemsBuffer[ItemPointer]].amount;
                            }
                        }else if(items[ItemsBuffer[ItemPointer]].Stamina == true){
                            if(PlayerHealthUpdate + items[ItemsBuffer[ItemPointer]].amount >= PlayerHealth){
                                PlayerHealthUpdate = PlayerHealth;
                            }else{
                                PlayerHealthUpdate += items[ItemsBuffer[ItemPointer]].amount;
                            }
                        }else if(items[ItemsBuffer[ItemPointer]].Mana == true){
                            if(PlayerManaUpdate + items[ItemsBuffer[ItemPointer]].amount >= PlayerMana){
                                PlayerManaUpdate = PlayerMana;
                            }else{
                                PlayerManaUpdate += items[ItemsBuffer[ItemPointer]].amount;
                            }
                        }

                        items[ItemsBuffer[ItemPointer]].mass -= 1;

                        break;

                    }else if(Command=='q'){
                        break;
                    }
                }   

            }else if(OptionPointer == 3){
                break;
            }

        }

        if(flag == 0) Command = _getch();
        
        if(flagOpen == 0){
            if(Command=='w' && OptionPointer > 0 ) {
                OptionPointer--;
            }else if(Command=='s' && OptionPointer < 3) {
                OptionPointer++;
            }else if(Command=='e') {
                flagOpen = 1;
                OptionPointerMove = 0;
            }
        }else if(flagOpen == 1){
            if(Command=='w' && OptionPointerMove > 0) {
                OptionPointerMove--;
            }else if(Command=='s' && OptionPointerMove < 1) {
                OptionPointerMove++;
            }else if(Command=='e' && flagOpen == 1) {
                int eflag = 0;
                if(OptionPointer == 0){
                    if(OptionPointerMove == 0){
                        if(weapons[PlayerWeaponId].stamina_heavy <= PlayerStaminaUpdate){
                            PlayerStaminaUpdate -= weapons[PlayerWeaponId].stamina_heavy;
                            EnemyHealthUpdate -= wepaonDamage(OptionPointer);
                            eflag = 1;
                        }else{
                            printf("\nYou don't have enough Strenght\n");
                            sleep(2);
                        }
                    }else if(OptionPointerMove == 1){
                        if(weapons[PlayerWeaponId].stamina_quick <= PlayerStaminaUpdate){
                            PlayerStaminaUpdate -= weapons[PlayerWeaponId].stamina_quick;
                            EnemyHealthUpdate -= wepaonDamage(OptionPointer);
                            eflag = 1;
                        }else{
                            printf("\nYou don't have enough Strenght\n");
                            sleep(2);
                        }
                    }
                    if(eflag == 1){
                        if(instances[MonsterId].enemyData->poison_build != 0){
                            enemy_poison_build -= weapons[PlayerWeaponId].poison;
                            if(enemy_poison_build <= 0) {
                                Poison_Turns = 3;
                                enemy_poison_build = instances[MonsterId].enemyData->poison_build;
                                printf("You Poisont the enemy for 3 turns\n");
                                sleep(1);
                            }
                        }else if(instances[MonsterId].enemyData->bleed_build != 0){
                            enemy_bleed_build -= weapons[PlayerWeaponId].bleed;
                            if(enemy_bleed_build <= 0){
                                EnemyHealthUpdate -= EnemyHealth * 0.4;
                                enemy_bleed_build = instances[MonsterId].enemyData->bleed_build;
                                printf("You Bleed the enemy\n");
                                sleep(1);
                            }
                        }else if(instances[MonsterId].enemyData->burn_build != 0){
                            enemy_burn_build -= weapons[PlayerWeaponId].burn;
                            if(enemy_burn_build <= 0) {
                                Burn_Turns = 3;
                                enemy_burn_build = instances[MonsterId].enemyData->burn_build;
                                printf("You Burn the enemy for 3 turns\n");
                                sleep(1);
                            }
                        }else if(instances[MonsterId].enemyData->frost_build != 0){
                            enemy_frost_build -= weapons[PlayerWeaponId].frost;
                            if(enemy_frost_build <= 0){
                                frost_turn = 1;
                                enemy_frost_build = instances[MonsterId].enemyData->frost_build;
                                printf("You Frost the enemy for 1 turn\n");
                                sleep(1);
                            }
                        }
                    }
                }else if(OptionPointer == 1){
                    if(OptionPointerMove == 0){
                        if(scrolls[PlayerScrollId].mana_1 <= PlayerManaUpdate){
                            PlayerManaUpdate -= scrolls[PlayerScrollId].mana_1;
                            EnemyHealthUpdate -= scrollDamage(OptionPointer);
                            eflag = 1;
                        }else{
                            printf("\nYou don't have enough Mana\n");
                            sleep(2);
                        }
                    }else if(OptionPointerMove == 1){
                        if(scrolls[PlayerScrollId].mana_2 <= PlayerManaUpdate){
                            PlayerManaUpdate -= scrolls[PlayerScrollId].mana_2;
                            EnemyHealthUpdate -= scrollDamage(OptionPointer);
                            eflag = 1;
                        }else{
                            printf("\nYou don't have enough Mana\n");
                            sleep(2);
                        }
                    }
                }

                flagOpen = 0;
                OptionPointer = 0;

                if(EnemyHealthUpdate <= 0){
                    InfoBattle(EnemyHealthUpdate, EnemyHealth, PlayerHealthUpdate, PlayerHealth, PlayerStaminaUpdate, PlayerStamina, PlayerManaUpdate, PlayerMana);

                    printf("\nEnemy Failed\n");
                    sleep(2);

                    return 1;
                }

                if(Poison_Turns != 0){
                    EnemyHealthUpdate -= EnemyHealth * 0.02;
                }

                if(Burn_Turns != 0){
                    EnemyHealthUpdate -= EnemyHealth * 0.02;
                }

                EnemyMove = rand() % 1;

                if(frost_turn == 0){
                    if(EnemyMove == 0){
                        PlayerHealthUpdate -= instances[MonsterId].enemyData->At_1;
                    }else if(EnemyMove == 1){
                        PlayerHealthUpdate -= instances[MonsterId].enemyData->At_2;
                    }
                    frost_turn = 0;
                }
                InfoBattle(EnemyHealthUpdate, EnemyHealth, PlayerHealthUpdate, PlayerHealth, PlayerStaminaUpdate, PlayerStamina, PlayerManaUpdate, PlayerMana);

                sleep(1);

            }else if(Command=='q' && flagOpen == 1) {
                flagOpen = 0;
            }
        }
    }
}

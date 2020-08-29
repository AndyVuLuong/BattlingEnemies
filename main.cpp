/*
You have 3 possible attacks
1. Standard: 5 Hit
2. Heavy: 10 Hit but lose 5 HP
3. Luck: 8 Hit but 50% Accuracy
*/

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
using namespace std;

int createEnemy() {
    srand (time(NULL)); //different number each time you build
    return rand() % (10-5+1) + 5; //a random number that stays the same each build
}

int main() {
    int playerAlive = true;
    int playerAttack;
    int playerHealth = 30;
    int enemyKilled = 0;
    string playerName = "";
    /*
    cout <<"You are a Knight who will fight till his end." << endl << "Press [Enter] to start";
    cin.get();
    cout << "Please enter your name: ";
    cin >> playerName;
    cout << "Get ready to fight for your life, " << playerName << "!" << endl;
    */

    //cout << "You start with 30 HP" << endl;
    while(playerAlive) {
    //create enemy
    int enemy = createEnemy();

    while(enemy > 0) {
    int attack;
    cout << "\nYour health " << playerHealth << endl;
    cout << "Enemy health is " << enemy << endl;
    cout << "Press 1 to deal 5-10 damage ";
    cin >> attack;


    if(attack==1)
    {
        srand (time(NULL));
        playerAttack = rand() % (10-5+1) + 5;
        enemy = enemy-playerAttack;

        if(enemy > 0) {
            playerHealth = playerHealth-(rand() % (10-5+1) + 5);
        }

        if(enemy < 0)
        {
            cout << "Enemy killed" << endl;
            enemyKilled++;
            cout << "You have killed " << enemyKilled << " so far" << endl;
        }
    }

    /*
    else if(attack==2) {
        enemy-10;
        playerHealth-5;
    }
    else if(attack==3)
    {
        int chance = (rand()%2);
        if(chance==1) enemy-8;
        else enemy-0;
    }
    else { enemy-0; }

    if(enemy > 0) {
        int enemyAttack = rand() % 10;
        playerHealth - enemyAttack;
    } */


    if(playerHealth<=0) {
        playerAlive = false;
        break;
    }
    }
    }
    cout << "Total Enemies Killed: " << enemyKilled << endl;
}







//
// Created by Tamer Khalifa on 29/11/2022.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string.h>

class Player{
    char *name;
    int level;
    unsigned int force;
    unsigned int maxHP;
    unsigned int hp;
    unsigned int coins;

public:
    Player(char *name, unsigned int maxHP, unsigned int force);
    Player(const Player&);
    ~Player();
    void printInfo();
    void levelUp();
    int getLevel();
    void buff(int value);
    void heal (int value);
    void damage (int value);
    bool isKnockedOut();
    void addCoins(int value);
    bool pay(int value);
    unsigned int getAttackStrength();

};

#endif //EX2_PLAYER_H

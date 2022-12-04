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
    Player(const char *name, unsigned int maxHP = 100, unsigned int force = 5);
    Player(const Player&);
    ~Player();
    void printInfo() const;
    void levelUp();
    int getLevel() const;
    void buff(int value);
    void heal (int value);
    void damage (int value);
    bool isKnockedOut() const;
    void addCoins(int value);
    bool pay(int value);
    unsigned int getAttackStrength() const;

};

#endif //EX2_PLAYER_H

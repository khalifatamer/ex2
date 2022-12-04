//
// Created by Tamer Khalifa on 29/11/2022.
//

#include "Player.h"
#include "utilities.h"

Player::Player(const char *name, unsigned int maxHP, unsigned int force)
{
    int size = strlen(name);
    this->name = new char[size + 1];
    strcpy(this->name, name);
    level = DEFAULT_STARTING_LEVEL;
    this->force = force;
    this->maxHP = maxHP;
    hp = maxHP;
    coins = 0;
}

Player::Player(const Player& copy):
    name(new char [strlen(copy.name)+1]),
    level(copy.level),
    force(copy.force),
    maxHP(copy.maxHP),
    hp(copy.hp),
    coins(copy.coins)
{
    int size = strlen(copy.name);
    for (int i = 0; i < size; ++i) {
        name[i] = copy.name[i];
    }
}

Player::~Player()
{
    delete [] name;
}

void Player::printInfo() const
{
    printPlayerInfo(name, level, force, hp, coins);
}

void Player::levelUp()
{
    level++;
}

int Player::getLevel() const
{
    return level;
}

void Player::buff(int value)
{
    force += value;
}

void Player::heal(int value)
{
    hp += value;
}

void Player::damage(int value)
{
    hp -= value;
}

bool Player::isKnockedOut() const
{
    if (hp == 0){
        return true;
    }
    return false;
}

void Player::addCoins(int value)
{
    coins += value;
}

bool Player::pay(int value)
{
    if(coins >= value){
        coins -= value;
        return true;
    }
    return false;
}

unsigned int Player::getAttackStrength() const
{
    return (level + force);
}
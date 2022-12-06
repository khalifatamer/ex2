//
// Created by Tamer Khalifa on 29/11/2022.
//

#include "Player.h"

Player::Player(const char *name, int maxHP, int force)
{
    int size = strlen(name);
    this->name = new char[size + 1];
    strcpy(this->name, name);
    level = DEFAULT_STARTING_LEVEL;
    if(force < 0)
    {
        this->force = DEFAULT_FORCE;
    }
    else
    {
        this->force = force;
    }
    if(maxHP <= 0)
    {
        this->maxHP = DEFAULT_MAX_HP;
    }
    else
    {
        this->maxHP = maxHP;
    }
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
    strcpy(name,copy.name);
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
    if(level != MAX_LEVEL)
    {
        level++;
    }
}

int Player::getLevel() const
{
    return level;
}

void Player::buff(int value)
{
    if(value >= 0)
    {
        force += value;
    }
}

void Player::heal(int value)
{
    if(value >= 0)
    {
        if (hp + value <= maxHP)
        {
            hp += value;
        } else {
            hp = maxHP;
        }
    }
}

void Player::damage(int value)
{
    if(value >= 0)
    {
        if(hp >= value)
        {
            hp -= value;
        }
        else{
            hp = 0;
        }
    }

}

bool Player::isKnockedOut() const
{
    if (hp == 0)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int value)
{
    if(value >= 0)
    {
        coins += value;
    }
}

bool Player::pay(int value)
{
    if(coins >= value)
    {
        if(value >= 0)
        {
            coins -= value;
        }
        return true;
    }
    return false;
}

int Player::getAttackStrength() const
{
    return (level + force);
}
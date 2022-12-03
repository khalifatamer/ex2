#include "Card.h"

Card::Card(CardType type, const CardStats &stats)
{
    m_effect = type;
    m_stats = stats;
}

void Card::applyEncounter(Player& player) const
{
    if(m_effect == CardType::Battle)
    {
        if(player.getAttackStrength() >= m_stats.force){
            player.levelUp();
            player.addCoins(m_stats.loot);
            printBattleResult(true);
        }
        else
        {
            player.damage(m_stats.hpLossOnDefeat);
            printBattleResult(false);
        }
    }

    if(m_effect == CardType::Buff)
    {
        player.buff(m_stats.buff);
        return;
    }

    if(m_effect == CardType::Heal)
    {
        player.heal(m_stats.heal);
        return;
    }

    if(m_effect == CardType::Treasure)
    {
        player.addCoins(m_stats.loot);
        return;
    }


}

void Card::printInfo() const
{
    switch (m_effect) {
        case CardType::Battle:
            printBattleCardInfo(m_stats);
            break;
        case CardType::Buff:
            printBuffCardInfo(m_stats);
            break;
        case CardType::Heal:
            printHealCardInfo(m_stats);
            break;
        case CardType::Treasure:
            printTreasureCardInfo(m_stats);
            break;
    }
}

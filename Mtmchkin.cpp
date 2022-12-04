#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards)
{
    Player m_player = Player(playerName);
    Mtmchkin::setGameStatus(GameStatus::MidGame);
//    Player player = Player(playerName);
    m_cards = new Card[numOfCards];
    for (int i = 0; i < numOfCards; ++i) {
        m_cards[i] = cardsArray[i];
    }
}
void Mtmchkin::playNextCard()
{
    m_cards->printInfo();
    m_cards->applyEncounter(m_player);
    m_player.printInfo();
    m_cards += 1;

}

bool Mtmchkin::isOver() const
{
    if (m_player.getLevel() == 10 || m_player.isKnockedOut())
    {
        return true;
    }
}

GameStatus Mtmchkin::getGameStatus() const
{

}
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards):m_player(playerName)
{
    Player copy(playerName);
    Mtmchkin::setGameStatus(GameStatus::MidGame);
    this->numOfCards = numOfCards;
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
    if (m_player.isKnockedOut()){
        m_status = GameStatus::Loss;
    }
    if (m_player.getLevel() == MAX_LEVEL){
        m_status = GameStatus::Win;
    }
    Card temp = *(m_cards);
    for (int i = 0; i < numOfCards-1; ++i) {
        m_cards[i] = m_cards[i+1];
    }
    m_cards[numOfCards-1] = temp;

}

bool Mtmchkin::isOver() const
{
    if (m_player.getLevel() == MAX_LEVEL || m_player.isKnockedOut())
    {
        return true;
    }

    else
    {
        return false;
    }
}

GameStatus Mtmchkin::getGameStatus() const
{
    return m_status;
}
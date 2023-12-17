#include "hand.h"
#include <algorithm>

Hand::Hand(string handString, int bid)
{
    m_bid = bid;
    m_handString = handString;

    int i=0;
    for(auto card : handString)
    {
        int value = 0;
        switch (card)
        {
        case 'A':
            value = 14;
            break;
        case 'K':
            value = 13;
            break;
        case 'Q':
            value = 12;
            break;
        case 'J':
            value = 11;
            break;
        case 'T':
            value = 10;
            break;
        default:
            value = card-48;
            break;
        }
        m_cardValues[i] = value;
        i++;
    }
    calculateType();
}

void Hand::calculateType()
{
    int pair = 0;
    bool three = false;
    int jokers = count(m_cardValues, m_cardValues + 5, 1);
    m_type = HIGH_CARD;
    for (int i = 0; i < 5; i++)
    {
        if(m_cardValues[i]==1) continue;
        int cardCount = count(m_cardValues, m_cardValues + 5, m_cardValues[i]);
        if(cardCount + jokers == 5)
        {
            m_type = FIVE;
            break;
        }
        if(cardCount + jokers == 4)
        {
            m_type = FOUR;
            break;
        }
        if(cardCount + jokers == 3)
        {
            jokers = 0;
            if(pair)
            {
                m_type = FULL;
                break;
            }
            m_type = THREE;
            three = true;
        }
        if(cardCount == 2)
        {
            jokers = 0;
            if(three)
            {
                m_type = FULL;
                break;
            }
            if(pair == 2)
            {
                m_type = TWO_PAIR;
                break;
            }
            m_type = PAIR;
            pair += 1;
        }
    }
}

void Hand::updateToJokerRule()
{
    for (int i = 0; i < 5; i++)
    {
        if(m_cardValues[i] == 11)
        {
            m_cardValues[i] = 1;
        }
    }
    int jokers = count(m_cardValues, m_cardValues + 5, 11);
    calculateType();
}

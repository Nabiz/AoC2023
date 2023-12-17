#include "hand.h"
#include <algorithm>
#include <vector>
#include <iostream>

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
    m_type = HIGH_CARD;
    vector<int> countedValues;
    vector<int> counts;
    int jokers = count(m_cardValues, m_cardValues + 5, 1);
    
    for (int i = 0; i < 5; i++)
    {
        if(m_cardValues[i]==1) continue;
        
        if(countedValues.empty())
        {
            counts.push_back(count(m_cardValues, m_cardValues + 5, m_cardValues[i]));
            countedValues.push_back(m_cardValues[i]);
            continue;
        }
        if(find(countedValues.begin(), countedValues.end(), m_cardValues[i]) == countedValues.end())
        {
            countedValues.push_back(m_cardValues[i]);
            counts.push_back(count(m_cardValues, m_cardValues + 5, m_cardValues[i]));
        }
    }
    sort(counts.begin(), counts.end(), greater<>());
    switch (counts[0])
    {
    case 5:
        m_type = FIVE;
        break;
    case 4:
        m_type = FOUR;
        break;
    case 3:
        if(counts[1] == 2)
        {
            m_type = FULL;
        }
        else
        {
            m_type = THREE;
        }
        break;
    case 2:
        if(counts[1] == 2)
        {
            m_type = TWO_PAIR;
        }
        else
        {
            m_type = PAIR;
        }
        break;
    default:
        break;
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

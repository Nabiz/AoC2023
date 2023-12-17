#include "hand.h"
#include <algorithm>
#include <vector>
#include <iostream>

Hand::Hand(string handString, int bid)
{
    m_bid = bid;
    m_handString = handString;

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
        m_cardValues.push_back(value);
    }
    //calculateType();
}

void Hand::calculateType()
{
    m_type = HIGH_CARD;
    vector<int> countedValues;
    vector<int> counts;
    int jokers = count(m_cardValues.begin(), m_cardValues.end(), 1);
    for (int i = 0; i < 5; i++)
    {
        if(m_cardValues[i]==1) continue;
 
        if(countedValues.empty())
        {
            counts.push_back(count(m_cardValues.begin(), m_cardValues.end(), m_cardValues[i]));
            countedValues.push_back(m_cardValues[i]);
        }
        else if(find(countedValues.begin(), countedValues.end(), m_cardValues[i]) == countedValues.end())
        {
            countedValues.push_back(m_cardValues[i]);
            counts.push_back(count(m_cardValues.begin(), m_cardValues.end(), m_cardValues[i]));
        }
    }
    if(!countedValues.empty())
    {
        sort(counts.begin(), counts.end(), greater<>());
        int score = counts[0] + jokers;
        if(score==5)
        {
            m_type = FIVE;
        }
        else if(score==4)
        {
            m_type = FOUR;
        }
        else if(score==3)
        {
            if(counts[1] == 2)
            {
                m_type = FULL;
            }
            else
            {
                m_type = THREE;
            }
        }
        else if(score==2)
        {
            if(counts[1] == 2)
            {
                m_type = TWO_PAIR;
            }
            else
            {
                m_type = PAIR;
            }
        }
    }
    else
    {
        m_type = FIVE;
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
    calculateType();
}

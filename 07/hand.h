#pragma once
#include <string>
#include <vector>

using namespace std;

class Hand
{
public:
    enum camelTypes {HIGH_CARD, PAIR, TWO_PAIR, THREE, FULL, FOUR, FIVE};
    string m_handString;
    vector<int> m_cardValues;
    int m_bid;
    int m_type;
    int rank;
    Hand(string handString, int bid);
    void updateToJokerRule();
private:
    void calculateType();
    void setType(int newType);
};

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "hand.h"
#include <algorithm>

using namespace std;

bool compareCameleHands(Hand first, Hand seccond)
{   
    if(first.m_type == seccond.m_type)
    {
        int i = -1;
        do
        {
            i++;
        }while(first.m_cardValues[i] == seccond.m_cardValues[i]);
        return first.m_cardValues[i] <= seccond.m_cardValues[i];
    }
    else
    {
        return first.m_type <= seccond.m_type;
    }
}

int main()
{
    fstream inputFile;
    vector<Hand> camelHands;
    inputFile.open("input", ios::in);
    if(inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {
            string handString = line.substr(0, line.find(" "));
            int bid = atoi(line.substr(line.find(" ")).c_str());
            Hand hand = Hand(handString, bid);
            camelHands.push_back(hand);
        }   
    }
    inputFile.close();
    int sum = 0;
    sort(camelHands.begin(), camelHands.end(), compareCameleHands);
    for(int i=1;i<=camelHands.size();i++)
    {
        sum+=i*camelHands[i-1].m_bid;
    }
    cout << sum << endl;

    for(int i=0;i<camelHands.size();i++)
    {
        camelHands[i].updateToJokerRule();
    }
    sort(camelHands.begin(), camelHands.end(), compareCameleHands);
    sum = 0;
    for(int i=1;i<=camelHands.size();i++)
    {
        sum+=i*camelHands[i-1].m_bid;
    }
    cout << sum << endl;
}

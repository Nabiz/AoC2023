#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

int main()
{
    int sum = 0;
    fstream inputFile;

    deque<int> cardCopies;
    inputFile.open("input", ios::in);
    if(inputFile.is_open())
    {
        string line;
        int card = 0;
        while (getline(inputFile, line))
        {
            card++;
            string winNumbersString = line.substr(line.find(":")+1, line.find("|")-line.find(":")-1);
            string yourNumbersString = line.substr(line.find("|")+1);
            stringstream winStringstream(winNumbersString);
            stringstream yourStringstream(yourNumbersString);
            string numberString;
            vector<int> winningNumbers;
            vector<int> yourNumbers;
            while(winStringstream >> numberString)
            {
                winningNumbers.push_back(stoi(numberString));
            }
            while(yourStringstream >> numberString)
            {
                yourNumbers.push_back(stoi(numberString));
            }

            int winCount = 0;
            for(auto yourNum : yourNumbers)
            {
                for(auto winNum : winningNumbers)
                {
                    if(yourNum==winNum)
                    {
                        winCount++;
                        break;
                    }
                }
            }
            int multi = 1;
            if(!cardCopies.empty())
            {
                multi += cardCopies[0];
                cardCopies.pop_front();
            }
            sum+=multi;
            if(winCount>=1)
            {
                for(int i=0; i<winCount; i++)
                {
                    if(cardCopies.size() > i)
                    {
                        cardCopies[i] += multi;
                    }
                    else
                    {
                        cardCopies.push_back(multi);
                    }
                }
            }
        }
    }
    inputFile.close();
    cout << sum << endl;
    return 0;
}

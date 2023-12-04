#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int sum = 0;
    fstream inputFile;
    
    inputFile.open("input", ios::in);
    if(inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {
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

            int winCount = -1;
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
            if(winCount>=0)
            {
                sum += pow(2, winCount);
            }
        }
    }
    inputFile.close();

    cout << sum << endl;
    return 0;
}
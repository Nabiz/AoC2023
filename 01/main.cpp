#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string digitNumTab[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
const string digitWordTab[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

bool findDigit(string str, string digitNumber, string digitWord, bool isPart2=false)
{
    return str.find(digitNumber) != string::npos || (isPart2 && str.find(digitWord) != string::npos);
}

int puzzleResult(bool isPart2 = false)
{
    fstream inputFile;
    int sum = 0;

    inputFile.open("input", ios::in);
    if(inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {   
            int x = 0, y=0;
            
            for(int i=0; i<=line.size(); i++)
            {
                string str = line.substr(0, i);
                for(int i=1; i<=9; i++)
                {
                    if(findDigit(str, digitNumTab[i], digitWordTab[i], isPart2))
                    {
                        x = i;
                        break;
                    }        
                }
                if(x!=0)
                {
                    break;
                }
            }

            for(int i=0; i<=line.size(); i++)
            {
                string str = line.substr(line.size()-i, line.size());
                for(int i=1; i<=9; i++)
                {
                    if(findDigit(str, digitNumTab[i], digitWordTab[i], isPart2))
                    {
                        y = i;
                        break;
                    }        
                }
                if(y!=0)
                {
                    break;
                }
            }
            sum+= 10*x+y;
        }
    }
    inputFile.close();
    return sum;
}

int main()
{
    cout << puzzleResult() << endl;
    cout << puzzleResult(true) << endl;
    return 0;
}

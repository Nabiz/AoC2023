#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;


int main()
{
    fstream inputFile;
    int sum = 0;

    int maxRed = 12;
    int maxGreen = 13;
    int maxBlue = 14;

    inputFile.open("input", ios::in);
    if(inputFile.is_open())
    {
        string line;
        const regex re("([0-9])* (red|blue|green)");
        smatch roundMatch;
        int lineNumber = 0;
        while (getline(inputFile, line))
        {   
            lineNumber++;
            bool possible = true;
            string::const_iterator searchStart(line.cbegin());
            while(regex_search(searchStart, line.cend(), roundMatch, re))
            {
                string match = roundMatch[0];
                int number;
                if(match.find(" red") != string::npos)
                {
                    number = stoi(match.substr(0, match.find(" red")));
                    if(number > maxRed)
                    {
                        possible = false;
                    } 
                }
                else if(match.find(" green") != string::npos)
                {
                    number = stoi(match.substr(0, match.find(" green")));
                    if(number > maxGreen)
                    {
                        possible = false;
                    } 
                }
                else if(match.find(" blue") != string::npos)
                {
                    number = stoi(match.substr(0, match.find(" blue")));
                    if(number > maxBlue)
                    {
                        possible = false;
                    } 
                }

                searchStart = roundMatch.suffix().first;
                if(!possible)
                {
                    break;
                }
            }
            if(possible)
            {
                sum+=lineNumber;
            }
        }
    }
    inputFile.close();
    cout << sum;
    return 0;
}

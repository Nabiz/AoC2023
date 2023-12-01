#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    fstream inputFile;
    int sum = 0;

    inputFile.open("input", ios::in);
    if(inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {   
            vector<int> digitsInLine;
            for(char character: line)
            {
                if(isdigit(character))
                {
                    digitsInLine.push_back(character-48);
                }
            }
            sum += 10*digitsInLine[0] + digitsInLine[digitsInLine.size()-1];
        }
    }
    inputFile.close();
    cout << sum;
    return 0;
}

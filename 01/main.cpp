#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int preplace(string& input, const string& a, const string& b){
    size_t index;
    int n = 0;
    while((index = input.find(a,0)) != string::npos){
        input.replace(index, a.size(), b);
        n++;
    }
    return n;
}

void replaceSpelledDigits(string& s)
{
    preplace(s, "one", "o1ne");
    preplace(s, "two", "t2wo");
    preplace(s, "three", "t3hree");
    preplace(s, "four", "f4our");
    preplace(s, "five", "f5ive");
    preplace(s, "six", "s6ix");
    preplace(s, "seven", "s7even");
    preplace(s, "eight", "e8ight");
    preplace(s, "nine", "n9ine");
    preplace(s, "zero", "z0ero");
}

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
            if(!digitsInLine.empty())
            {
                sum += 10*digitsInLine[0] + digitsInLine[digitsInLine.size()-1];
            }
        }
    }
    inputFile.close();
    cout << sum << endl;
    
    // //PART 2
    sum = 0;
    inputFile.open("input", ios::in);
    if(inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {   
            replaceSpelledDigits(line);
            vector<int> digitsInLine;
            for(char character: line)
            {
                if(isdigit(character))
                {
                    digitsInLine.push_back(character-48);
                }
            }
            if(!digitsInLine.empty())
            {
                cout << 10*digitsInLine[0] + digitsInLine[digitsInLine.size()-1] << endl;
                sum += 10*digitsInLine[0] + digitsInLine[digitsInLine.size()-1];
            }
        }
    }
    inputFile.close();
    cout << sum;
    return 0;
}

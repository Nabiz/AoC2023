#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

char neutralChars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};

bool checkNeighbourhood(vector<string> s, int row, int col, int MAX_ROW, int MAX_COL)
{
    for(int i=clamp(row-1, 0, MAX_ROW); i<=clamp(row+1, 0, MAX_ROW-1); i++)
    {
        for(int j=clamp(col-1, 0, MAX_COL); j<=clamp(col+1, 0, MAX_COL-1); j++)
        {
            if(!(i==row && j==col))
            {
                bool isSpecial = true;
                for(auto c : neutralChars)
                {
                    if(s[i][j] == c)
                    {
                        isSpecial = false;
                    }
                }
                if(isSpecial)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    fstream inputFile;
    vector<string> schema;
    inputFile.open("input", ios::in);
    if(inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {
            schema.push_back(line);
        }
    }
    inputFile.close();
    const int MAX_ROW = schema.size();
    const int MAX_COL = schema[0].size();

    vector<int> digits;
    bool isSpecial = false;
    int sum = 0;
    for (int i = 0; i < MAX_ROW; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            if(schema[i][j] >= 48 && schema[i][j] <= 57)
            {
                digits.push_back(int(schema[i][j]-48));
                //cout << schema[i][j];
                if(!isSpecial)
                {
                    isSpecial = checkNeighbourhood(schema, i, j, MAX_ROW, MAX_COL);
                }
            }
            else
            {
                if(isSpecial)
                {
                    int psum = sum;
                    for(int n=0; n<digits.size(); n++)
                    {
                        sum += digits[n] * pow(10, digits.size()-1-n);
                    }
                    cout << sum - psum << " <-SPECIAL";
                }
                if(!digits.empty()) cout << endl;
                digits.clear();
                isSpecial = false;
            }
        }
        if(isSpecial)
        {
            int psum = sum;
            for(int n=0; n<digits.size(); n++)
            {
                sum += digits[n] * pow(10, digits.size()-1-n);
            }
            cout << sum - psum << " <-SPECIAL";
        }
        if(!digits.empty()) cout << endl;
        digits.clear();
        isSpecial = false;
    }
    cout << sum;
    return 0;
}

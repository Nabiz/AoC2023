#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int getWholeNumber(vector<string> s, int x, int y, const int MAX_COL)
{
    int wholeNumber = 0;
    vector<int> digits;
    digits.push_back(int(s[x][y]-48));
    int n=1;
    while(y-n >= 0)
    {
        if(48 <= s[x][y-n] && s[x][y-n] <= 57)
        {
            digits.insert(digits.begin(), int(s[x][y-n]-48));
        }
        else
        {
            break;
        }
        n++;
    }
    n=1;
    while(y+n < MAX_COL)
    {
        if(48 <= s[x][y+n] && s[x][y+n] <= 57)
        {
            digits.push_back(int(s[x][y+n]-48));
        }
        else
        {
            break;
        }
        n++;
    }

    for(int n=0; n<digits.size(); n++)
    {
        wholeNumber += digits[n] * pow(10, digits.size()-1-n);
    }
    return wholeNumber;
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

    int sum = 0;

    for (int i = 0; i < MAX_ROW; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            bool north = false, south = false;
            int numberCount = 0;
            int x1 = -1, y1 = -1;
            int x2 = -1, y2 = -1;
            if(schema[i][j] == '*')
            {
                if(j-1 >= 0)
                {
                    if(48 <= schema[i][j-1] && schema[i][j-1] <= 57)
                    {
                        numberCount++;
                        x1 = i, y1 = j-1;
                    }
                }

                if(j+1 < MAX_COL)
                {
                    if(48 <= schema[i][j+1] && schema[i][j+1] <= 57)
                    {
                        numberCount++;
                        if(x1==-1)
                        {
                            x1 = i, y1 = j+1;    
                        }
                        else
                        {
                            x2 = i, y2 = j+1;
                        }
                    }
                }

                if(i-1 >= 0)
                {
                    if(48 <= schema[i-1][j] && schema[i-1][j] <= 57)
                    {
                        north = true;
                        numberCount++;
                        if(numberCount > 2)
                        {
                            continue;
                        }
                        if(x1==-1)
                        {
                            x1 = i-1, y1 = j;    
                        }
                        else
                        {
                            x2 = i-1, y2 = j;
                        }
                    }
                }

                if(i+1 < MAX_ROW)
                {
                    if(48 <= schema[i+1][j] && schema[i+1][j] <= 57)
                    {
                        south = true;
                        numberCount++;
                        if(numberCount > 2)
                        {
                            continue;
                        }
                        if(x1==-1)
                        {
                            x1 = i+1, y1 = j;    
                        }
                        else
                        {
                            x2 = i+1, y2 = j;
                        }
                    }
                }

                if(!north && i-1 >= 0)
                {
                    if(j-1 >= 0)
                    {
                        if(48 <= schema[i-1][j-1] && schema[i-1][j-1] <= 57)
                        {
                            numberCount++;
                            if(numberCount > 2)
                            {
                                continue;
                            }
                            if(x1==-1)
                            {
                                x1 = i-1, y1 = j-1;    
                            }
                            else
                            {
                                x2 = i-1, y2 = j-1;
                            }
                        }
                    }

                    if(j+1 < MAX_COL)
                    {
                        if(48 <= schema[i-1][j+1] && schema[i-1][j+1] <= 57)
                        {
                            numberCount++;
                            if(numberCount > 2)
                            {
                                continue;
                            }
                            if(x1==-1)
                            {
                                x1 = i-1, y1 = j+1;    
                            }
                            else
                            {
                                x2 = i-1, y2 = j+1;
                            }
                        }
                    }
                }

                if(!south && i+1 < MAX_ROW)
                {
                    if(j-1 >= 0)
                    {
                        if(48 <= schema[i+1][j-1] && schema[i+1][j-1] <= 57)
                        {
                            numberCount++;
                            if(numberCount > 2)
                            {
                                continue;
                            }
                            if(x1==-1)
                            {
                                x1 = i+1, y1 = j-1;    
                            }
                            else
                            {
                                x2 = i+1, y2 = j-1;
                            }
                        }
                    }

                    if(j+1 < MAX_COL)
                    {
                        if(48 <= schema[i+1][j+1] && schema[i+1][j+1] <= 57)
                        {
                            numberCount++;
                            if(numberCount > 2)
                            {
                                continue;
                            }
                            if(x1==-1)
                            {
                                x1 = i+1, y1 = j+1;    
                            }
                            else
                            {
                                x2 = i+1, y2 = j+1;
                            }
                        }
                    }
                }
                if(numberCount == 2)
                {
                    sum += getWholeNumber(schema, x1, y1, MAX_COL) * getWholeNumber(schema, x2, y2, MAX_COL);
                }
            }
        }
    }
    cout << sum;
    return 0;
}

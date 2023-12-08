#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    fstream inputFile;
    
    vector<int> time;
    vector<int> distance;

    inputFile.open("input", ios::in);
    if(inputFile.is_open())
    {
        string line;
        getline(inputFile, line);
        stringstream ss;
        int number;
        ss << line.substr(7);
        while(ss >> number)
        {
            time.push_back(number);
        }
        getline(inputFile, line);
        ss.clear();
        ss << line.substr(11);
        while(ss >> number)
        {
            distance.push_back(number);
        }
        
    }
    inputFile.close();

    int result = 1;
    for(int r=0; r<time.size(); r++)
    {
        int count = 0;
        for(int i=0; i<=time[r]; i++)
        {
            if(i*(time[r]-i)>distance[r])
            {
                count++;
            }
        }
        result *= count;
    }
    cout << result << endl;
}
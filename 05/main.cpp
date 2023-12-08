#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "map.h"

using namespace std;

int main()
{
    fstream inputFile;
    
    vector<long long> seeds;

    Map seedToSoil, soilToFert, fertToWater, waterToLight, lightToTemp, tempToHum, humToLoc;
  
    Map* currentMap;

    inputFile.open("input", ios::in);
    if(inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {
            if(!line.empty())
            {
                stringstream ss;
                if(line=="seed-to-soil map:") currentMap = &seedToSoil;
                else if(line=="soil-to-fertilizer map:") currentMap = &soilToFert;
                else if(line=="fertilizer-to-water map:") currentMap = &fertToWater;
                else if(line=="water-to-light map:") currentMap = &waterToLight;
                else if(line=="light-to-temperature map:") currentMap = &lightToTemp;
                else if(line=="temperature-to-humidity map:") currentMap = &tempToHum;
                else if(line=="humidity-to-location map:") currentMap = &humToLoc;
                else if(line.find("seeds:") != string::npos)
                {
                    ss << line.substr(7);
                    long long seed;
                    while(ss >> seed)
                    {
                        seeds.push_back(seed);
                    }
                }
                else
                {
                    ss << line;
                    long long dest, source, range;
                    ss >> dest;
                    ss >> source;
                    ss >> range;

                    currentMap->mapLines.push_back(MapLine(dest, source, range));
                }
            }
        }
    }
    inputFile.close();

    long long location = LLONG_MAX;
    for(auto seed : seeds)
    {
        long long number = seed;
        number = seedToSoil.sourceToDest(number);
        number = soilToFert.sourceToDest(number);
        number = fertToWater.sourceToDest(number);
        number = waterToLight.sourceToDest(number);
        number = lightToTemp.sourceToDest(number);
        number = tempToHum.sourceToDest(number);
        number = humToLoc.sourceToDest(number);
        if(location > number)
        {
            location = number;
        }
    }

    long long locationPart2 = LLONG_MAX;
    for(int i=0;i<seeds.size();i+=2)
    {
        long long seed = seeds[i];
        long long seedRange = seeds[i+1];
        for(int n=0; n<seedRange; n++)
        {
            long long number = seed + n;
            number = seedToSoil.sourceToDest(number);
            number = soilToFert.sourceToDest(number);
            number = fertToWater.sourceToDest(number);
            number = waterToLight.sourceToDest(number);
            number = lightToTemp.sourceToDest(number);
            number = tempToHum.sourceToDest(number);
            number = humToLoc.sourceToDest(number);
            if(locationPart2 > number)
            {
                locationPart2 = number;
            }
        }
    }

    cout << location << endl;
    cout << locationPart2 << endl;
    return 0;
}
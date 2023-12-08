#pragma once
#include <string>
#include <vector>

using namespace std;

class MapLine
{
    public:
    long long m_dest;
    long long m_source;
    long long m_range;

    MapLine(long long dest, long long source, long long range);
};

class Map
{
    public:
    string destinationType;
    string sourceType;
    vector<MapLine> mapLines;

    long long sourceToDest(long long source);
};
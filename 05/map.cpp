#include "map.h"

MapLine::MapLine(long long dest, long long source, long long range)
{
    m_dest = dest;
    m_source = source;
    m_range = range;
}

long long Map::sourceToDest(long long source)
{
    long long dest = source;
    for(auto ml : mapLines)
    {
        if(ml.m_source <= source && source < ml.m_source + ml.m_range)
        {
            dest = source - ml.m_source + ml.m_dest;
            break;
        }
    }
    return dest;
}
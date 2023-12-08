#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    fstream inputFile;
    
    double time = 42686985;
    double distance = 284100511221341;

    double sqrtDelta = sqrt(time*time - 4.0f*distance);
    double x1 = (time - sqrtDelta)/2.0f;
    double x2 = (time + sqrtDelta)/2.0f;

    cout << x1 << endl << x2 << endl;

    int result = floor(x2) - ceil(x1) + 1;
    if(x1 == ceil(x1)) result--;
    if(x2 == floor(x2)) result --;

    cout << result;
}
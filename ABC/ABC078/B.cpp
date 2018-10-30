#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define long long ll

using namespace std;

int X, Y, Z;

int main()
{
    cin >> X >> Y >> Z;
    cout << (X + Y) / (Y + Z) - 1;
    return 0;
}

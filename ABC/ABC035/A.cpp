#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int W, H;

int main()
{
    cin >> W >> H;
    cout << (W * 3 == H * 4 ? "4:3" : "16:9") << endl;
    return 0;
}

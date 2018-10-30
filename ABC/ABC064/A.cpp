#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int r, g, b;

int main()
{
    cin >> r >> g >> b;
    cout << ((100 * r + 10 * g + b) % 4 == 0 ? "YES" : "NO") << endl;
    return 0;
}

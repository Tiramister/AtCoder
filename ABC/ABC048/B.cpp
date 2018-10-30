#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll a, b, x;

int main()
{
    cin >> a >> b >> x;
    if (a > 0) {
        cout << b / x - (a - 1) / x << endl;
    } else {
        cout << b / x + 1 << endl;
    }
    return 0;
}

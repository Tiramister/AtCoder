#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int m, VV;

int main()
{
    cin >> m;

    if (m < 100) {
        VV = 0;
    } else if (m <= 5000) {
        VV = m / 100;
    } else if (m <= 30000) {
        VV = m / 1000 + 50;
    } else if (m <= 70000) {
        VV = (m / 1000 - 30) / 5 + 80;
    } else {
        VV = 89;
    }

    cout << setfill('0') << setw(2) << right << VV << endl;

    return 0;
}

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

char c[4][4];

int main()
{
    for (size_t y = 0; y < 4; y++) {
        for (size_t x = 0; x < 4; x++) {
            cin >> c[y][x];
        }
    }

    for (size_t y = 0; y < 4; y++) {
        for (size_t x = 0; x < 4; x++) {
            cout << c[3 - y][3 - x];
            if (x < 3) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }

    return 0;
}

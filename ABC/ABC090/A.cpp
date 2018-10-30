#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

char c[3][3];

int main()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << c[i][i];
    }
    cout << endl;
    return 0;
}

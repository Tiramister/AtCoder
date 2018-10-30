#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int x[3], y[3];
int dx[2], dy[2];

int main()
{
    for (int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < 2; i++) {
        dx[i] = x[i + 1] - x[0];
        dy[i] = y[i + 1] - y[0];
    }

    int s2 = abs(dx[0] * dy[1] - dx[1] * dy[0]);

    cout << s2 / 2;
    if (s2 % 2 > 0) {
        cout << ".5";
    }
    cout << endl;

    return 0;
}

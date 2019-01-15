#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll X, Y;

int main()
{
    cin >> X >> Y;
    if (X % Y == 0) {
        cout << -1;
    } else {
        cout << X;
    }
    return 0;
}

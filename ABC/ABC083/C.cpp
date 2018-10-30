#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define ll long long
ll X, Y;
int length = 0;

using namespace std;

int main()
{
    cin >> X >> Y;

    while (X <= Y) {
        X *= 2;
        length++;
    }

    cout << length << endl;

    return 0;
}

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;
int a, b, c, d;

int main()
{
    cin >> a >> b >> c >> d;

    if ((a + b) < (c + d)) {
        cout << " Right";
    } else if ((a + b) > (c + d)) {
        cout << "Left";
    } else {
        cout << "Balanced";
    }

    return 0;
}

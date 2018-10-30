#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int s, e, sum = 0;

int main()
{
    for (int i = 0; i < 3; i++) {
        cin >> s >> e;
        sum += s * e / 10;
    }
    cout << sum << endl;
    return 0;
}

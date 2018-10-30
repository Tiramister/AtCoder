#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int a, b;

int main()
{
    cin >> a >> b;
    cout << min(abs(a - b), 10 - abs(a - b)) << endl;
    return 0;
}

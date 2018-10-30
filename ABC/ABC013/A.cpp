#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

char X;

int main()
{
    cin >> X;
    cout << static_cast<int>(X) - 'A' + 1 << endl;
    return 0;
}

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    cout << (A * B + B * C + C * A) * 2 << endl;
    return 0;
}

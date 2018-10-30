#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int A, B, C, D;

int main()
{
    cin >> A >> B >> C >> D;
    cout << (A * D > B * C ? "AOKI" : (A * D == B * C ? "DRAW" : "TAKAHASHI")) << endl;
    return 0;
}

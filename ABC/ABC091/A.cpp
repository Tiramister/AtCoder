#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int A, B, C;

int main()
{
    cin >> A >> B >> C;
    cout << ((A + B >= C) ? "Yes" : "No") << endl;
    return 0;
}

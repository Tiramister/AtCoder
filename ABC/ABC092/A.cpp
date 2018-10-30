#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << min(A, B) + min(C, D) << endl;
    return 0;
}

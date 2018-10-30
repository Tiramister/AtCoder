#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll N, M;

int main()
{
    cin >> N >> M;
    if (N == 1) {
        N = 3;
    }
    if (M == 1) {
        M = 3;
    }

    cout << (N - 2) * (M - 2) << endl;
    return 0;
}

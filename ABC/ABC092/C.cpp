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
    ll N, A[100001], maxC = 0;
    A[0] = 0;
    cin >> N;
    for (size_t i = 1; i <= N; i++) {
        cin >> A[i];
        maxC += abs(A[i] - A[i - 1]);
    }
    maxC += abs(A[N]);

    for (size_t i = 1; i <= N; i++) {
        cout << maxC - abs(A[i] - A[i - 1]) - abs(A[i + 1] - A[i]) + abs(A[i + 1] - A[i - 1]) << endl;
    }

    return 0;
}

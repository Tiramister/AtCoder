#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N;

int main()
{
    cin >> N;

    ll L[N + 1];
    L[0] = 2;
    L[1] = 1;

    for (int i = 2; i <= N; i++) {
        L[i] = L[i - 1] + L[i - 2];
    }

    cout << L[N] << endl;

    return 0;
}

#include <cmath>
#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[2][N];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    ll max = 0;
    for (ll i = 0; i < N; i++) {
        ll sum = 0;
        for (ll x = 0; x <= i; x++) {
            sum += A[0][x];
        }
        for (int x = i; x < N; x++) {
            sum += A[1][x];
        }
        if (max < sum) {
            max = sum;
        }
    }

    cout << max;
    return 0;
}

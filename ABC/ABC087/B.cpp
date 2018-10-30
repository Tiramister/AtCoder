#include <cmath>
#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int main() {
    ll A, B, C, X;
    cin >> A >> B >> C >> X;
    ll counter = 0;
    for (ll i = 0; i <= A; i++) {
        for (ll j = 0; j <= B; j++) {
            if (X >= 500 * i + 100 * j && X - 500 * i - 100 * j <= 50 * C) {
                counter++;
            }
        }
    }
    cout << counter;
    return 0;
}

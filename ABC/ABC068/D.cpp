#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll unsigned long long

using namespace std;

ll K;
vector<ll> num(50);

int main()
{
    cin >> K;
    cout << 50 << endl;

    ll q = K / 50;
    ll r = K % 50;

    for (size_t i = 0; i < 50; i++) {
        num[i] = i + q;
    }

    for (size_t j = 0; j < r; j++) {
        for (size_t k = 0; k < 50; k++) {
            if (k == j) {
                num[k] += 50;
            } else {
                num[k] -= 1;
            }
        }
    }

    for (size_t i = 0; i < 50; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}

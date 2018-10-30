#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

size_t N;
vector<ll> a;
ll mindiff = 0;

int main()
{
    cin >> N;
    a.resize(N);

    ll x = 0, y = 0;

    for (size_t i = 0; i < N; i++) {
        cin >> a[i];
        if (i == 0) {
            x = a[i];
        } else {
            y += a[i];
        }
    }

    ll mindiff = abs(x - y);

    for (size_t i = 1; i < N - 1; i++) {
        x += a[i];
        y -= a[i];
        mindiff = min(mindiff, abs(x - y));
    }

    cout << mindiff << endl;
    return 0;
}

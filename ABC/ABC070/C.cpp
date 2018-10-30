#include <iostream>
using namespace std;
using ll = long long;

template <typename T>
T gcd(T a, T b) {
    if (a > b) return gcd(b, a);
    return a == 0 ? b : gcd(b % a, a);
}

int main() {
    int N;
    cin >> N;

    ll ans;
    cin >> ans;

    for (int i = 0; i < N - 1; ++i) {
        ll t;
        cin >> t;
        ans = t / gcd(ans, t) * ans;
    }

    cout << ans << endl;
    return 0;
}

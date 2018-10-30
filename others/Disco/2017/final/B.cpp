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
    ll Z;
    cin >> N >> Z;

    ll a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    ll ans = 1;
    for (int i = 0; i < N; ++i) {
        ll g = gcd(Z, a[i]);
        ans *= g / gcd(ans, g);
        // gcdとのlcmを取る
    }

    cout << ans << endl;
    return 0;
}

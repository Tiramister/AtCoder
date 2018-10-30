#include <iostream>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll mypow(ll b, ll n) {
    if (n == 0) return 1;
    if (n == 1) return b % MOD;
    if (n % 2 == 0) {
        return mypow(b * b % MOD, n / 2);
    } else {
        return mypow(b, n - 1) * b % MOD;
    }
}

ll fact(ll n) {
    return n == 0 ? 1 : n * fact(n - 1) % MOD;
}

int main() {
    ll N;
    cin >> N;

    ll A[N + 1];
    for (ll i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    ll dsum[N + 1];
    dsum[0] = 0;
    for (ll i = 1; i <= N; ++i) {
        dsum[i] = dsum[i - 1] + mypow(i, MOD - 2);
        dsum[i] %= MOD;
    }

    ll ans = 0;
    for (ll i = 1; i <= N; ++i) {
        ans += (dsum[i] + dsum[N - i + 1] - 1) % MOD * A[i] % MOD;
        ans %= MOD;
    }

    cout << ans * fact(N) % MOD << endl;
    return 0;
}

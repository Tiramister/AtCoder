#include <iostream>
using namespace std;
using ll = long long;

const ll MOD = 998244353;
const ll MAX_V = 10000;
ll fact[MAX_V + 1], invfact[MAX_V + 1];

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b % MOD;
    if (n % 2 == 0) {
        return mypow(b * b % MOD, n / 2);
    } else {
        return mypow(b, n - 1) * b % MOD;
    }
}

void precalc() {
    invfact[0] = fact[0] = 1;
    for (ll i = 1; i <= MAX_V; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invfact[MAX_V] = mypow(fact[MAX_V], MOD - 2);
    for (ll i = MAX_V - 1; i >= 0; --i) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
    return;
}

ll comb(ll a, ll b) {
    if (a < b) return 0;
    if (a == 0) return 1;  // a = b = 0

    return fact[a] * invfact[a - b] % MOD * invfact[b] % MOD;
}

ll calc(ll N, ll s, ll d) {
    ll ret = 0;
    for (ll q = 0; q <= min(d, N); ++q) {
        ret += (mypow(2LL, q) * comb(d, q) % MOD) * comb(s + N - 1, N - q) % MOD;
        ret %= MOD;
    }
    return ret;
}

int main() {
    precalc();

    ll K, N;
    cin >> K >> N;

    for (ll i = 2; i <= K * 2; ++i) {
        ll d = (i <= K + 1 ? (i - 1) / 2 : (2 * K - i + 1) / 2);
        if (i % 2 > 0) {
            cout << calc(N, K - d * 2, d) << endl;
        } else {
            cout << (calc(N, K - d * 2 - 1, d) + calc(N - 1, K - d * 2 - 1, d)) % MOD << endl;
        }
    }
    return 0;
}

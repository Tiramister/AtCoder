#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

template <typename T>
T gcd(T a, T b) {
    if (a > b) return gcd(b, a);
    return a == 0 ? b : gcd(b % a, a);
}

vector<ll> factor(ll K) {
    vector<ll> ret;
    ll L = K;
    for (ll k = 2; k * k <= L; ++k) {
        if (K % k == 0) {
            ret.push_back(k);
            while (K % k == 0) {
                K /= k;
            }
        }
    }
    if (K > 1) ret.push_back(K);
    return ret;
}

ll calc(ll N, ll K) {
    vector<ll> primes = factor(K);
    ll L = primes.size();

    ll ret = 0;
    for (int b = 0; b < (1 << L); ++b) {
        ll p = 1;
        for (int i = 0; i < L; ++i) {
            if ((b >> i) & 1) p *= primes[i];
        }

        ll l = N / p;
        ll sum = l * (l + 1) / 2 % MOD * p % MOD;

        ret += ((__builtin_popcountll(b) % 2) ? MOD - sum : sum);
        ret %= MOD;
    }
    return ret;
}

int main() {
    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    for (ll k = 1; k * k <= K; ++k) {
        if (K % k > 0) continue;
        ans += calc(N / k, K / k) * k % MOD * (K / gcd(k, K)) % MOD;
        ans %= MOD;

        if (k * k == K) continue;
        ans += calc(N / (K / k), k) * (K / k) % MOD * (K / gcd(K / k, K)) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}

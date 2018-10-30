#include <iostream>
#include <string>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

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

int main() {
    int N, K;
    string S;
    cin >> N >> S;
    K = S.length();

    ll dp[N + 1];
    fill(dp, dp + N + 1, 0);
    dp[0] = 1;
    // dp[i] = i文字打たれているパターン数

    for (int q = 0; q < N; ++q) {
        ll ndp[N + 1];
        fill(ndp, ndp + N + 1, 0);

        for (int i = 0; i < N; ++i) {
            ndp[i + 1] += dp[i] * 2;
            ndp[max(0, i - 1)] += dp[i];
        }

        for (int i = 0; i <= N; ++i) {
            dp[i] = ndp[i] % MOD;
        }
    }

    // 2^Kで割る = 2^Kの逆元を掛ける
    cout << dp[K] * mypow(mypow(2LL, K), MOD - 2) % MOD << endl;

    return 0;
}

#include <iostream>
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

ll dp[50][1 << 18];
// dp[i][S] = i個の数値でSが作れるパターン数

int main() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;
    int W = X + Y + Z;

    fill(dp[0], dp[45], 0);
    dp[0][0] = 1;

    ll ans = 0;

    for (int i = 0; i <= N; ++i) {
        for (int S = 0; S < (1 << W); ++S) {
            if (((S >> (X - 1)) & 1) && ((S >> (X + Y - 1)) & 1) && ((S >> (X + Y + Z - 1)) & 1)) {
                ans += dp[i][S] * mypow(10LL, N - i);
                ans %= MOD;
                dp[i][S] = 0;
            }
        }

        for (int S = 0; S < (1 << W); ++S) {
            for (int k = 1; k <= 10; ++k) {
                int T = ((S << k) + (1 << (k - 1))) & ((1 << W) - 1);
                dp[i + 1][T] += dp[i][S];
                dp[i + 1][T] %= MOD;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

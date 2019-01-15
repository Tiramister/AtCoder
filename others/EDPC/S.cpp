#include <iostream>
#include <string>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int D;
ll dp[10010][100];

// k % D = d (0 <= k <= K)
ll rec(const string& K, int d) {
    if (K.empty()) return d == 0;

    ll ret = 0;

    int t = K.front() - '0';

    // [t00~000, K]
    ret = rec(K.substr(1), (d + D - t) % D);

    for (int k = 0; k < t; ++k) {
        // [k00~000, k99~999]
        ret += dp[K.size() - 1][(d + D - k) % D];
    }

    return ret % MOD;
}

int main() {
    string K;
    cin >> K >> D;

    dp[0][0] = 1;
    for (int n = 1; n <= 10000; ++n) {
        for (int d = 0; d < D; ++d) {
            for (int k = 0; k < 10; ++k) {
                dp[n][(k + d) % D] += dp[n - 1][d];
                dp[n][(k + d) % D] %= MOD;
            }
        }
    }

    cout << (rec(K, 0) + MOD - 1) % MOD << endl;
    return 0;
}

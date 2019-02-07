#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int main() {
    string k;
    int d;
    cin >> k >> d;
    reverse(k.begin(), k.end());

    int n = k.length();
    ll dp[n + 1][d][2];
    fill(dp[0][0], dp[n + 1][0], 0);
    dp[0][0][0] = dp[0][0][1] = 1;

    for (int m = 1; m <= n; ++m) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < d; ++j) {
                dp[m][(i + j) % d][0] += dp[m - 1][j][0];
                dp[m][(i + j) % d][0] %= MOD;
            }
        }

        int p = k[m - 1] - '0';
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < d; ++j) {
                dp[m][(i + j) % d][1] += dp[m - 1][j][0];
                dp[m][(i + j) % d][1] %= MOD;
            }
        }

        for (int j = 0; j < d; ++j) {
            dp[m][(p + j) % d][1] += dp[m - 1][j][1];
            dp[m][(p + j) % d][1] %= MOD;
        }
    }

    cout << (dp[n][0][1] + MOD - 1) % MOD << endl;
}

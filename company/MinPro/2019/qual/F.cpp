#include <iostream>
#include <string>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

ll dp[4010][4010];

int main() {
    string S;
    cin >> S;
    int N = S.length();

    int rsum[N * 2 + 1], bsum[N * 2 + 1];
    rsum[0] = bsum[0] = 0;
    // 各ボール数の累積和 (1-indexed)

    for (int i = 1; i <= N; ++i) {
        rsum[i] = rsum[i - 1] + ('2' - S[i - 1]);
        bsum[i] = bsum[i - 1] + (S[i - 1] - '0');
    }
    for (int i = N + 1; i <= N * 2; ++i) {
        rsum[i] = rsum[i - 1];
        bsum[i] = bsum[i - 1];
    }

    dp[0][0] = 1;
    for (int r = 0; r <= rsum[N]; ++r) {
        for (int b = 0; b <= bsum[N]; ++b) {
            if (r == rsum[N] && b == bsum[N]) continue;

            // 赤ボールを置けるか？
            if (rsum[r + b + 1] > r) {
                dp[r + 1][b] += dp[r][b];
                dp[r + 1][b] %= MOD;
            }

            // 青ボールを置けるか？
            if (bsum[r + b + 1] > b) {
                dp[r][b + 1] += dp[r][b];
                dp[r][b + 1] %= MOD;
            }
        }
    }

    cout << dp[rsum[N]][bsum[N]] << endl;
    return 0;
}

#include <iostream>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

const int more = 100;

int main() {
    int T;
    cin >> T;
    int a[T + more + 1];
    fill(a, a + T + more + 1, 0);
    for (int i = 0; i < T; ++i) {
        cin >> a[i];
    }

    ll dp[T + more + 1][301];
    fill(dp[0], dp[T + more + 1], 0);
    dp[0][0] = 1;
    // dp[t][i] = 0~t-1までを処理した時点で、
    //            tがi個あるようなパターン数

    // 配るdp
    for (int t = 0; t < T + more; ++t) {
        for (int i = 0; i <= 300; ++i) {
            // tをj個書くとする
            for (int j = 0; j <= a[t]; ++j) {
                if ((i + j) % 2 > 0) continue;
                dp[t + 1][(i + j) / 2] += dp[t][i];
                dp[t + 1][(i + j) / 2] %= MOD;
            }
        }
    }

    ll ans = 0;
    for (int t = 0; t <= T + more; ++t) {
        // すでに1個書かれていて、あとは何も書かない場合
        ans += dp[t][1];

        // まだ何も書かれていない状態でtを1個書き、あとは何も書かない場合
        if (a[t] > 0) ans += dp[t][0];

        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}

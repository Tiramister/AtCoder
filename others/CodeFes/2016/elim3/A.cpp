#include <deque>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;

    ll A[N + 1];
    for (ll i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    ll dp[N + 1];
    fill(dp, dp + N + 1, 0);
    // dp[n] = A_nをk個目として選んだときの最大スコア
    // kについて逐次更新

    for (ll k = 1; k <= K; ++k) {
        ll ndp[N + 1];

        deque<ll> que;
        // スライド最大値
        // [i - M + 1, i]の最大値を求める

        for (ll i = 0; i < N; ++i) {
            // 古い上に値の小さいindexを破棄
            while (!que.empty() && dp[que.back()] <= dp[i]) {
                que.pop_back();
            }

            que.push_back(i);

            // 先頭が範囲内か確認
            while (que.front() <= i - M) {
                que.pop_front();
            }

            ndp[i + 1] = dp[que.front()] + A[i + 1] * k;
        }

        // k未満を更新するとWA
        // A_1がやたら大きいときにA_1 * Kを答えにしてしまう
        for (ll i = k; i <= N; ++i) {
            dp[i] = ndp[i];
        }
    }

    ll ans = 0;
    for (ll i = 1; i <= N; ++i) {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
    return 0;
}

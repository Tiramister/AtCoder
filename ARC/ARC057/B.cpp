#include <iostream>

using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

int main() {
    ll N, K;
    cin >> N >> K;

    ll sum[N + 1];
    sum[0] = 0;
    for (int i = 1; i <= N; ++i) {
        ll a;
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }

    if (sum[N] == K) {
        cout << 1 << endl;
        return 0;
    }

    ll dp[N + 1][N + 1];
    fill(dp[0], dp[1], INF);
    dp[0][0] = 0;
    // dp[i][j]=i日目まででj日機嫌がいいときの、最小の勝数

    for (int i = 1; i <= N; ++i) {
        copy(dp[i - 1], dp[i], dp[i]);
        for (int j = 1; j <= i; ++j) {
            // 前日の勝率が0のときは1勝でOK
            if (dp[i - 1][j - 1] == 0) {
                dp[i][j] = 1;
                continue;
            }

            // 前日の勝率が1のときは無理
            if (dp[i - 1][j - 1] == sum[i - 1]) continue;

            ll ok = sum[i] - sum[i - 1], ng = 0;
            // i日目に少なくともok回勝てば機嫌がよくなる

            while (ok - ng > 1) {
                ll mid = (ok + ng) / 2;
                // (ok+dp[i-1][j-1])/sum[i] > dp[i-1][j-1]/sum[i-1] が条件
                if ((mid + dp[i - 1][j - 1]) * sum[i - 1] > dp[i - 1][j - 1] * sum[i]) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }

            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + ok);
        }
    }

    ll ok = 0, ng = N + 1;
    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if (dp[N][mid] <= K) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ok << endl;
    return 0;
}

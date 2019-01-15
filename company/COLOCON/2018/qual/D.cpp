#include <iostream>
using namespace std;
using ll = long long;
const ll INF = 1LL << 50;

int main() {
    int N;
    ll X;
    cin >> N >> X;

    ll t[N + 1];
    for (int i = 0; i < N; ++i) {
        cin >> t[i];
    }
    t[N] = INF;

    ll dp[N + 1][N];
    // t_iにてスタミナが0で, あとj回消費できるときの最適解
    fill(dp[N], dp[N] + N, -INF);

    for (int i = N - 1; i >= 0; --i) {
        fill(dp[i], dp[i] + N, 0);
        int id = i;
        for (int j = i; j <= N; ++j) {
            if (t[j] >= t[i] + X) {
                id = j;
                break;
            }
        }

        for (int k = 0; k < N - 1; ++k) {
            dp[i][k + 1] = max(dp[i][k + 1], dp[id][k] + X);
            if (id > i) {
                dp[i][k + 1] = max(dp[i][k + 1], dp[id - 1][k] + t[id - 1] - t[i]);
            }
        }

        ll ma = 0;
        for (int k = 0; k < N; ++k) {
            ma = max(ma, dp[i][k]);
            dp[i][k] = ma;
        }
    }

    for (int k = 0; k < N; ++k) {
        cout << dp[0][k] + X << endl;
    }
    return 0;
}

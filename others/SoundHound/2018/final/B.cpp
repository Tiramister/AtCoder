#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;
    ll b[N];
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
    }

    ll dp[N + 1], ma[N + 1];
    // dp[i] = 1 ~ iにおける最適解
    // ただしdp[0] = 0
    // ma[i] = max(dp[0], ... ,dp[i])
    dp[0] = ma[0] = 0;

    for (int i = 1; i <= N; ++i) {
        dp[i] = dp[i - 1] + b[i - 1];
        if (i >= K) {
            dp[i] = max(dp[i], ma[i - K]);
        }
        ma[i] = max(ma[i - 1], dp[i]);
    }

    cout << dp[N] << endl;
    return 0;
}

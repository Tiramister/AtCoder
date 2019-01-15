#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    int N, K;
    cin >> N >> K;

    int a[N + 1];
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    sort(a + 1, a + N + 1);

    ll dp[100010];
    dp[0] = 1;
    // dp[k] = a_1 ~ a_iでkを作るパターン数
    // 1つの配列を更新していく

    int limit = 0;
    // a_1 ~ a_iのXORで作れる最大値

    for (int i = 1; i <= N; ++i) {
        ll ndp[100010];
        fill(ndp, ndp + (limit | a[i]) + 1, 0);
        // 毎回全部更新するとTLEなので注意(2敗)

        for (int k = 0; k <= limit; ++k) {
            ndp[k] += dp[k];
            ndp[k] %= MOD;
            ndp[k ^ a[i]] += dp[k];
            ndp[k ^ a[i]] %= MOD;
        }
        limit |= a[i];

        // ここも毎回全部コピーするとTLEなので注意(1敗)
        for (int k = 0; k <= limit; ++k) {
            dp[k] = ndp[k];
        }
    }

    cout << dp[K] << endl;

    return 0;
}

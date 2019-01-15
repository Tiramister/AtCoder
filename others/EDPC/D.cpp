#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

int main() {
    int N, W;
    cin >> N >> W;

    ll dp[N + 1][W + 1];
    fill(dp[0], dp[1], -INF);
    dp[0][0] = 0;
    for (int i = 1; i <= N; ++i) {
        memcpy(dp[i], dp[i - 1], sizeof(dp[i]));
        int w;
        ll v;
        cin >> w >> v;

        for (int ws = 0; ws + w <= W; ++ws) {
            dp[i][ws + w] = max(dp[i][ws + w], dp[i - 1][ws] + v);
        }
    }

    cout << *max_element(dp[N], dp[N + 1]) << endl;
    return 0;
}

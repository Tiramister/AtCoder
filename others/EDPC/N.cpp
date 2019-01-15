#include <iostream>

using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

ll sum[410], dp[410][410];
bool visited[410][410];

ll rec(int l, int r) {
    if (visited[l][r]) return dp[l][r];
    if (l == r) return 0;
    visited[l][r] = true;

    dp[l][r] = INF;
    for (int i = l; i < r; ++i) {
        dp[l][r] = min(dp[l][r], rec(l, i) + rec(i + 1, r));
    }

    dp[l][r] += sum[r] - sum[l - 1];
    return dp[l][r];
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        ll a;
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }

    cout << rec(1, N) << endl;
    return 0;
}

#include <iostream>

using namespace std;
using ll = long long;

int N;
ll a[16][16];
bool visited[1 << 16];
ll dp[1 << 16];

ll rec(int s) {
    if (visited[s]) return dp[s];

    visited[s] = true;
    dp[s] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (((s >> i) & 1) & ((s >> j) & 1)) dp[s] += a[i][j];
        }
    }

    for (int t = 1; t < s; ++t) {
        if (t != (t & s)) continue;
        dp[s] = max(dp[s], rec(t) + rec(s ^ t));
    }

    return dp[s];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }

    cout << rec((1 << N) - 1) << endl;
    return 0;
}

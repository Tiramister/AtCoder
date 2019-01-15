#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

vector<int> path[100010];
ll dp[2][100010];
// white, black
bool visited[100010];

void dfs(int v) {
    visited[v] = true;

    dp[0][v] = dp[1][v] = 1;

    for (int sv : path[v]) {
        if (visited[sv]) continue;
        dfs(sv);
        dp[0][v] *= dp[0][sv] + dp[1][sv];
        dp[1][v] *= dp[0][sv];

        for (int i = 0; i < 2; ++i) {
            dp[i][v] %= MOD;
        }
    }

    return;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    dfs(0);
    cout << (dp[0][0] + dp[1][0]) % MOD << endl;
    return 0;
}

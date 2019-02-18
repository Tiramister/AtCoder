#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll MOD;
vector<int> path[100010];
ll dp[100010], ans[100010];

ll dfs(int v, int r) {
    dp[v] = 1;
    for (int sv : path[v]) {
        if (sv == r) continue;
        dp[v] *= dfs(sv, v) + 1;
        dp[v] %= MOD;
    }
    return dp[v];
}

void edfs(int v, int r, ll par) {
    ans[v] = dp[v] * (par + 1) % MOD;

    vector<int> chv = {-1};
    for (int sv : path[v]) {
        if (sv == r) continue;
        chv.push_back(sv);
    }
    int L = chv.size() - 1;

    ll fore[L + 2], back[L + 2];
    fore[0] = back[L + 1] = 1;
    for (int i = 1; i <= L; ++i) fore[i] = fore[i - 1] * (dp[chv[i]] + 1) % MOD;
    for (int i = L; i >= 1; --i) back[i] = back[i + 1] * (dp[chv[i]] + 1) % MOD;

    for (int i = 1; i <= L; ++i) {
        edfs(chv[i], v, fore[i - 1] * back[i + 1] % MOD * (par + 1) % MOD);
    }
}

int main() {
    int N;
    cin >> N >> MOD;
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    dfs(0, -1);
    edfs(0, -1, 0);
    for (int v = 0; v < N; ++v) cout << ans[v] << endl;
    return 0;
}

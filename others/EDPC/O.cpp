#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int N;
vector<int> path[21];
ll dp[21][1 << 21];
bool visited[21][1 << 21];

ll rec(int i, int S) {
    if (i == N) return 1;
    if (visited[i][S]) return dp[i][S];

    visited[i][S] = true;
    for (int j : path[i]) {
        if ((S >> j) & 1) continue;
        dp[i][S] += rec(i + 1, S | (1 << j));
        dp[i][S] %= MOD;
    }

    return dp[i][S];
}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int a;
            cin >> a;
            if (a == 1) path[i].push_back(j);
        }
    }

    cout << rec(0, 0) << endl;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

template <typename T>
T sq(T a) {
    return a * a;
}

vector<int> path[100010];
int d[100010];

// vを含む連結成分に奇数長の閉路が含まれるか
bool dfs(int v) {
    bool ret = false;

    for (int sv : path[v]) {
        if (d[sv] < 0) {
            d[sv] = d[v] + 1;
            ret = dfs(sv) || ret;
        } else if ((d[v] - d[sv]) % 2 == 0) {
            // 奇数長閉路判定
            ret = true;
        }
    }

    return ret;
}

int main() {
    ll N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    ll single = 0, odd = 0, even = 0;
    // single = 頂点数1の連結成分(孤立点)の数
    // odd = 奇数長の閉路をもつ連結成分の数
    // even = それ以外の連結成分の数

    fill(d, d + N, -1);

    for (int v = 0; v < N; ++v) {
        if (d[v] >= 0) continue;

        d[v] = 0;
        if (path[v].empty()) {
            ++single;
        } else {
            if (dfs(v)) {
                ++odd;
            } else {
                ++even;
            }
        }
    }

    cout << sq(N) - sq(N - single) + sq(even + odd) + sq(even) << endl;
    return 0;
}

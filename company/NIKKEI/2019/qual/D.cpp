#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> child[N];
    int innum[N];  // 入次数
    fill(innum, innum + N, 0);

    for (int i = 0; i < N + M - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        child[u].push_back(v);
        ++innum[v];
    }

    // 入次数が最小=0な頂点が根となる
    int r = min_element(innum, innum + N) - innum;

    int par[N];
    fill(par, par + N, -1);
    queue<int> que;
    que.push(r);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (int sv : child[v]) {
            par[sv] = v;

            // これ以上入ってくる辺がなくなったら探索開始
            if (--innum[sv] == 0) que.push(sv);
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << par[i] + 1 << endl;
    }

    return 0;
}

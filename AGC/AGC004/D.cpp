#include <iostream>
#include <vector>

using namespace std;

int K, ans = 0;
vector<int> path[100010];

// 頂点vの高さを返す
// 0に繋いだ場合は-1
int dfs(int v, int r) {
    int h = 0;

    for (int sv : path[v]) {
        h = max(h, dfs(sv, v) + 1);
    }

    if (h == K - 1 && r > 0) {
        ++ans;
        h = -1;
    }

    return h;
}

int main() {
    int N;
    cin >> N >> K;

    for (int v = 0; v < N; ++v) {
        int p;
        cin >> p;
        --p;

        if (v == 0) {
            if (p != 0) ++ans;  // 首都の行き先は首都
        } else {
            path[p].push_back(v);
        }
    }

    dfs(0, -1);
    cout << ans << endl;
    return 0;
}

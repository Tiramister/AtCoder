#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> path[100010];
bool visited[100010];
int d[100010];

int dfs(int v) {
    if (visited[v]) return d[v];

    visited[v] = true;

    d[v] = 0;
    for (int sv : path[v]) {
        d[v] = max(d[v], dfs(sv) + 1);
    }

    return d[v];
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        path[u].push_back(v);
    }

    for (int v = 0; v < N; ++v) {
        if (visited[v]) continue;
        dfs(v);
    }

    cout << *max_element(d, d + N) << endl;
    return 0;
}

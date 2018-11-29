#include <iostream>
#include <vector>

using namespace std;

vector<int> path[100010];
bool visited[100010];

int dfs(int v) {
    visited[v] = true;
    int ret = 0;
    for (int sv : path[v]) {
        if (visited[sv]) continue;
        ret ^= (dfs(sv) + 1);
    }
    return ret;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        path[x].push_back(y);
        path[y].push_back(x);
    }

    fill(visited, visited + N, false);

    cout << (dfs(0) > 0 ? "Alice" : "Bob") << endl;

    return 0;
}

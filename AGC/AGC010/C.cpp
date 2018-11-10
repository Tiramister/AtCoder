#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

ll A[100010];
vector<int> path[100010];
bool visited[100010];

ll dfs(int v) {
    visited[v] = true;

    vector<ll> chl;
    ll sum = 0;
    for (int sv : path[v]) {
        if (visited[sv]) continue;
        ll res = dfs(sv);

        if (res < 0) return -1;

        chl.push_back(res);
        sum += res;
    }

    if (chl.empty()) {
        return A[v];
    }

    if (sum < A[v] || A[v] * 2 < sum) {
        return -1;
    }

    sort(chl.begin(), chl.end());
    ll ma = chl.back();

    if (sum - ma < ma && ma > A[v]) {
        return -1;
    }

    return A[v] * 2 - sum;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    fill(visited, visited + N, false);
    for (int v = 0; v < N; ++v) {
        if (path[v].size() == 1) continue;
        cout << (dfs(v) == 0 ? "YES" : "NO") << endl;
        return 0;
    }

    cout << (A[0] == A[1] ? "YES" : "NO") << endl;
    return 0;
}

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> path[3000];
int N, K;

int solve(int r) {
    int d[3000];
    fill(d, d + 3000, 3000);
    d[r] = 0;

    queue<int> que;
    que.push(r);
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (int sv : path[v]) {
            if (d[sv] < 3000) continue;
            d[sv] = d[v] + 1;
            que.push(sv);
        }
    }

    int ret = 0;
    for (int v = 0; v < N; ++v) {
        ret += (d[v] <= K / 2);
    }
    return ret;
}

int solve(int r1, int r2) {
    int d[3000];
    fill(d, d + 3000, 3000);
    d[r1] = d[r2] = 0;

    queue<int> que;
    que.push(r1);
    que.push(r2);
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (int sv : path[v]) {
            if (d[sv] < 3000) continue;
            d[sv] = d[v] + 1;
            que.push(sv);
        }
    }

    int ret = 0;
    for (int v = 0; v < N; ++v) {
        ret += (d[v] <= K / 2);
    }
    return ret;
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    int ans = N;

    if (K % 2 == 0) {
        for (int v = 0; v < N; ++v) {
            ans = min(ans, N - solve(v));
        }
    } else {
        for (int v = 0; v < N; ++v) {
            for (int sv : path[v]) {
                ans = min(ans, N - solve(v, sv));
            }
        }
    }

    cout << ans << endl;
    return 0;
}

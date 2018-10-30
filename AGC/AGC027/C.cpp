#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, M;
    string S;
    cin >> N >> M >> S;

    vector<int> path[N];

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    int nc[N][2];
    fill(nc[0], nc[N], 0);
    // neighbor color
    // nc[v] = {vに隣接するAの数, vに隣接するBの数}

    vector<int> del;
    // nc[v][0] = 0かnc[v][1] = 0を満たす頂点集合

    for (int v = 0; v < N; ++v) {
        for (int sv : path[v]) {
            ++nc[v][S[sv] - 'A'];
        }
        if (nc[v][0] * nc[v][1] == 0) {
            del.push_back(v);
        }
    }

    bool remain[N];
    fill(remain, remain + N, true);
    // まだ取り除かれてない頂点集合

    while (!del.empty()) {
        int v = del.back();
        del.pop_back();
        if (!remain[v]) continue;

        remain[v] = false;

        for (int sv : path[v]) {
            --nc[sv][S[v] - 'A'];
            if (nc[sv][0] * nc[sv][1] == 0) {
                del.push_back(sv);
            }
        }
    }

    for (int v = 0; v < N; ++v) {
        if (remain[v]) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}

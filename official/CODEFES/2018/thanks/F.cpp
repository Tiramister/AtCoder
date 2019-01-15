#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    if (K == 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> child[N + 1];
    for (int i = 1; i <= N; ++i) {
        int p;
        cin >> p;
        child[p].push_back(i);
    }

    queue<int> que;
    que.push(0);

    int depth[N + 1];
    depth[0] = 0;

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (int sv : child[v]) {
            depth[sv] = depth[v] + 1;
            que.push(sv);
        }
    }

    vector<int> ans;

    bool closed[N + 1];
    fill(closed, closed + N + 1, false);

    while (ans.size() < M) {
        bool putted = false;

        for (int r = 1; r <= N; ++r) {
            if (closed[r]) continue;
            closed[r] = true;

            int dcnt[N + 1];
            fill(dcnt, dcnt + N + 1, 0);
            que.push(0);

            while (!que.empty()) {
                int v = que.front();
                que.pop();

                for (int sv : child[v]) {
                    if (closed[sv]) continue;
                    ++dcnt[depth[sv]];
                    que.push(sv);
                }
            }

            int sumd = depth[r], cnt = ans.size() + 1;
            for (int i : ans) {
                sumd += depth[i];
            }

            closed[r] = false;

            int mi = sumd, micnt = cnt;
            for (int i = 1; i <= N; ++i) {
                mi += i * min(dcnt[i], M - micnt);
                micnt += min(dcnt[i], M - micnt);
            }

            if (micnt < M) continue;

            int ma = sumd, macnt = cnt;
            for (int i = N; i >= 1; --i) {
                ma += i * min(dcnt[i], M - macnt);
                macnt += min(dcnt[i], M - macnt);
            }

            // cout << r << " (" << mi << "," << ma << ")" << endl;

            if (mi <= K && K <= ma) {
                ans.push_back(r);
                putted = true;
                closed[r] = true;

                que.push(r);
                while (!que.empty()) {
                    int v = que.front();
                    que.pop();

                    for (int sv : child[v]) {
                        closed[sv] = true;
                        que.push(sv);
                    }
                }
                break;
            }
        }

        if (!putted) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int v : ans) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
using ll = long long;

const int INF = 1 << 30;

int main() {
    int N, M, R, T;
    cin >> N >> M >> R >> T;

    vector<pair<int, int>> path[N];
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        path[a].push_back(make_pair(b, c));
        path[b].push_back(make_pair(a, c));
    }

    ll ans = 0;
    for (int A = 0; A < N; ++A) {
        int dist[N];
        fill(dist, dist + N, INF);
        dist[A] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        que.push(make_pair(0, A));

        while (!que.empty()) {
            int d, v;
            tie(d, v) = que.top();
            que.pop();
            if (d > dist[v]) continue;

            for (auto p : path[v]) {
                int sv, c;
                tie(sv, c) = p;
                if (dist[sv] <= dist[v] + c) continue;
                dist[sv] = dist[v] + c;
                que.push(make_pair(dist[sv], sv));
            }
        }

        sort(dist, dist + N);
        for (int B = 1; B < N; ++B) {
            int ok = 0, ng = N;
            // dist[ok] / T < dist[B] / R

            while (ng - ok > 1) {
                int mid = (ok + ng) / 2;
                if (dist[mid] * R < dist[B] * T) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            ans += ok;
            if (ok >= B) --ans;
        }
    }

    cout << ans << endl;
    return 0;
}

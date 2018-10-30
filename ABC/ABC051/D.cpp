#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const int INF = 1e7;
size_t N, M;
vector<vector<int>> edge;
vector<vector<int>> dist;


void init()
{
    cin >> N >> M;
    edge.resize(N + 1);
    dist.resize(N + 1);
    for (size_t i = 1; i <= N; i++) {
        edge[i].resize(N + 1);
        dist[i].resize(N + 1);
        for (size_t j = 0; j <= N; j++) {
            if (i == j) {
                dist[i][j] = edge[i][j] = 0;
            } else {
                dist[i][j] = edge[i][j] = INF;
            }
        }
    }

    size_t a, b;
    int c;
    for (size_t i = 0; i < M; i++) {
        cin >> a >> b >> c;
        edge[a][b] = edge[b][a] = c;
    }
}


void min_dist(size_t s)
{
    vector<bool> used(N + 1, false);
    for (size_t i = 0; i < N; i++) {
        size_t minv = 0;
        for (size_t v = 1; v <= N; v++) {
            if (dist[s][v] < dist[s][minv] && !used[v]) {
                minv = v;
            }
        }
        // cout << minv << endl;
        used[minv] = true;

        for (size_t j = 1; j <= N; j++) {
            dist[s][j] = min(dist[s][j], dist[s][minv] + edge[minv][j]);
            // cout << "(" << s << ", " << j << ") : " << dist[s][j] << endl;
        }
    }
    return;
}


bool judge(size_t i, size_t j)
{
    for (size_t s = 1; s <= N; s++) {
        if (dist[s][i] + edge[i][j] == dist[s][j]) {
            return false;
        }
    }

    // cout << "(" << i << ", " << j << ")" << endl;
    return true;
}


int main()
{
    init();
    // cout << "Init finished" << endl;

    for (size_t s = 1; s <= N; s++) {
        min_dist(s);
    }
    // cout << "dist calculated" << endl;

    int cnt = 0;

    for (size_t i = 1; i < N; i++) {
        for (size_t j = i + 1; j <= N; j++) {
            if (edge[i][j] < INF) {
                cnt += judge(i, j);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}

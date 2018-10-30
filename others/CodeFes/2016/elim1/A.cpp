#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

using ll = long long;

const int MAX_V = 5000;

class UnionFind {
public:
    // コンストラクタ
    explicit UnionFind(int N) : V_NUM(N) {
        for (int i = 0; i < V_NUM; ++i) {
            par[i] = i;
        }
        fill(rank, rank + V_NUM, 0);
    }

    // xの親を返す+更新
    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    // xとyを含むグループを統合する
    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        // rank[x] >= rank[y]にする
        if (rank[x] < rank[y]) swap(x, y);
        par[y] = x;
        if (rank[x] == rank[y]) ++rank[x];
    }

    // xとyが同じグループに属するか判定
    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int V_NUM;
    int par[MAX_V], rank[MAX_V];
};

int main() {
    int N, M;
    cin >> N >> M;

    tuple<ll, int, int> edges[M];
    for (int i = 0; i < M; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges[i] = make_tuple(c, --a, --b);
    }

    sort(edges, edges + M);
    UnionFind uf(N);

    // 最小全域木の辺とコスト
    vector<pair<int, ll>> path[N];
    ll total = 0;

    // Kruskalで最小全域木を構築
    for (int i = 0; i < M; ++i) {
        int a, b;
        ll c;
        tie(c, a, b) = edges[i];

        if (uf.same(a, b)) continue;
        uf.unite(a, b);
        total += c;
        path[a].push_back(make_pair(b, c));
        path[b].push_back(make_pair(a, c));
    }

    ll emax[N][N];
    // emax[i][j] = iからjのパス上で最大コストの辺のコスト

    // 各頂点始点のBFS
    for (int r = 0; r < N; ++r) {
        fill(emax[r], emax[r] + N, -1);
        emax[r][r] = 0;
        queue<int> que;
        que.push(r);

        while (!que.empty()) {
            int v = que.front();
            que.pop();

            for (auto p : path[v]) {
                int sv;
                ll cost;
                tie(sv, cost) = p;

                if (emax[r][sv] >= 0) continue;
                emax[r][sv] = max(emax[r][v], cost);
                que.push(sv);
            }
        }
    }

    // クエリ処理
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int s, t;
        cin >> s >> t;
        cout << total - emax[--s][--t] << endl;
    }
    return 0;
}

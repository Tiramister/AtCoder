#include <iostream>
#include <vector>
using namespace std;

const int MAX_V = 100010;

class UnionFind {
public:
    // コンストラクタ
    explicit UnionFind(int N) : V_NUM(N) {
        for (int i = 0; i < V_NUM; ++i) {
            par[i] = i;
        }
        fill(rank, rank + V_NUM, 0);
        fill(num, num + V_NUM, 1);
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

        // rankの大きい方、つまりxにyをくっつける
        num[x] += num[y];
        par[y] = x;
        if (rank[x] == rank[y]) ++rank[x];
    }

    // xとyが同じグループに属するか判定
    bool same(int x, int y) {
        return find(x) == find(y);
    }

    const int INF = 1 << 25;
    int V_NUM;
    int par[MAX_V], rank[MAX_V], num[MAX_V];
};


int main() {
    int N, M;
    cin >> N >> M;

    int a[M + 1], b[M + 1];
    for (int t = 1; t <= M; ++t) {
        cin >> a[t] >> b[t];
    }

    int Q;
    cin >> Q;

    int x[Q], y[Q];
    for (int q = 0; q < Q; ++q) {
        cin >> x[q] >> y[q];
    }

    int ok[Q], ng[Q];
    fill(ok, ok + Q, M + 1);
    fill(ng, ng + Q, 0);

    while (true) {
        bool finished = true;
        vector<int> point[M + 1];
        for (int q = 0; q < Q; ++q) {
            if (ok[q] - ng[q] <= 1) continue;
            finished = false;
            point[(ok[q] + ng[q]) / 2].push_back(q);
        }

        if (finished) break;

        UnionFind uf(N + 1);
        for (int t = 1; t <= M; ++t) {
            uf.unite(a[t], b[t]);
            for (int q : point[t]) {
                if (uf.same(x[q], y[q])) {
                    ok[q] = t;
                } else {
                    ng[q] = t;
                }
            }
        }
    }

    for (int q = 0; q < Q; ++q) {
        cout << (ok[q] > M ? -1 : ok[q]) << endl;
    }
    return 0;
}

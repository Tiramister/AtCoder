#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const ll INF = 1LL << 50;
const int MAX_V = 100010;

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

        if (rank[x] < rank[y]) swap(x, y);
        // rank[x] >= rank[y]

        // rankの大きい方、つまりxにyをくっつける
        par[y] = x;
        if (rank[x] == rank[y]) ++rank[x];
    }

    // xとyが同じグループに属するか判定
    bool same(int x, int y) {
        return find(x) == find(y);
    }

    const int INF = 1 << 25;
    int V_NUM;
    int par[MAX_V], rank[MAX_V];
};

int main() {
    int N, M;
    cin >> N >> M;

    ll v[N + 1];
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        ans += v[i];
    }

    UnionFind uf(N);
    int x[M], y[M];
    for (int i = 0; i < M; ++i) {
        cin >> x[i] >> y[i];

        // xとyを辺で結ぶ
        uf.unite(--x[i], --y[i]);
    }

    int sz[N];
    fill(sz, sz + N, 0);
    // sz[v] = vを親とするグラフが含む辺の本数

    for (int i = 0; i < M; ++i) {
        ++sz[uf.find(x[i])];
    }

    vector<int> child[N];
    // child[v] = vを親とするグラフが含む頂点の集合

    for (int i = 0; i < N; ++i) {
        child[uf.find(i)].push_back(i);
    }

    for (int i = 0; i < N; ++i) {
        // 条件:
        // 1. iがグラフの親である
        // 2. iを親とするグラフが木である
        if (i == uf.find(i) && child[i].size() == sz[i] + 1) {

            // このとき, 木から1つ頂点を選ぶことができなくなる
            ll del = INF;
            for (int j : child[i]) {
                del = min(del, v[j]);
            }

            ans -= del;
        }
    }

    cout << ans << endl;
    return 0;
}

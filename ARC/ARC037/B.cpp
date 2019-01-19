#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class UnionFind {
public:
    explicit UnionFind(int N) : V_NUM(N) {
        par.resize(N);
        iota(par.begin(), par.end(), 0);
        num.assign(N, 1);
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        if (num[x] < num[y]) swap(x, y);

        num[x] += num[y];
        par[y] = x;
    }

    bool same(int x, int y) { return find(x) == find(y); }
    bool ispar(int x) { return x == find(x); }
    int size(int x) { return num[find(x)]; }

    int V_NUM;
    vector<int> par, num;
};

int main() {
    int N, M;
    cin >> N >> M;

    UnionFind uf(N);

    int u[M], v[M];
    for (int i = 0; i < M; ++i) {
        cin >> u[i] >> v[i];
        --u[i], --v[i];
        uf.unite(u[i], v[i]);
    }

    int edge[N];
    fill(edge, edge + N, 0);
    // 各集合に属する辺の数

    for (int i = 0; i < M; ++i) {
        ++edge[uf.find(u[i])];
    }

    int ans = 0;
    for (int g = 0; g < N; ++g) {
        // 木の条件: 頂点数-辺数=1
        if (uf.size(g) - edge[g] == 1) ++ans;
    }

    cout << ans << endl;
}

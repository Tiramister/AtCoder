#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 100010;

class UnionFind {
public:
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

    int size(int x) {
        return num[x];
    }

    int V_NUM;
    int par[MAX_V], rank[MAX_V], num[MAX_V];
};

int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    for (int q = 0; q < Q; ++q) {
        int p, a, b;
        cin >> p >> a >> b;

        if (p == 0) {
            uf.unite(a, b);
        } else {
            cout << (uf.same(a, b) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}

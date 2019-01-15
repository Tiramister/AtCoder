#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b % MOD;
    if (n % 2 == 0) {
        return mypow(b * b % MOD, n / 2);
    } else {
        return mypow(b, n - 1) * b % MOD;
    }
}

class UnionFind {
public:
    explicit UnionFind(int N) : V_NUM(N) {
        par.resize(V_NUM);
        rank.resize(V_NUM);
        num.resize(V_NUM);

        for (int i = 0; i < V_NUM; ++i) {
            par[i] = i;
        }
        fill(rank.begin(), rank.end(), 0);
        fill(num.begin(), num.end(), 1);
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

        if (rank[x] < rank[y]) swap(x, y);

        num[x] += num[y];
        par[y] = x;
        if (rank[x] == rank[y]) ++rank[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool ispar(int x) {
        return x == find(x);
    }

    int size(int x) {
        return num[find(x)];
    }

    const int INF = 1 << 25;
    int V_NUM;
    vector<int> par, rank, num;
};


int N, M;
tuple<ll, int, int> edges[2010];

ll kruskal(int id) {
    UnionFind uf(N);

    int u, v;
    ll w;

    tie(w, u, v) = edges[id];
    ll ret = w;
    uf.unite(u, v);

    for (int i = 0; i < M; ++i) {
        tie(w, u, v) = edges[i];
        if (uf.same(u, v)) continue;

        ret += w;
        uf.unite(u, v);
    }

    return ret;
}

int main() {
    ll X;
    cin >> N >> M >> X;

    for (int i = 0; i < M; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges[i] = make_tuple(w, u - 1, v - 1);
    }

    sort(edges, edges + M);

    int cnt[3] = {0, 0, 0};
    for (int i = 0; i < M; ++i) {
        ll cost = kruskal(i);
        ++cnt[cost < X ? 0 : (cost == X ? 1 : 2)];
    }

    if (cnt[1] == 0) {
        cout << 0 << endl;
    } else if (cnt[0] == 0) {
        cout << (mypow(2LL, cnt[1]) - 2) * mypow(2LL, cnt[2]) % MOD << endl;
    } else {
        cout << 2 * (mypow(2LL, cnt[1]) - 1) * mypow(2LL, cnt[2]) % MOD << endl;
    }
    return 0;
}

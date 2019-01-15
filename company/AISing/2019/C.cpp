#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

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
    int H, W;
    cin >> H >> W;

    string S[H];
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
        for (int j = 0; j < W; ++j) {
            if ((i + j) % 2 == 0) {
                S[i][j] = (S[i][j] == '#' ? '.' : '#');
            }
        }
    }

    UnionFind uf(H * W);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i < H - 1 && S[i][j] == S[i + 1][j]) {
                uf.unite(i * W + j, (i + 1) * W + j);
            }
            if (j < W - 1 && S[i][j] == S[i][j + 1]) {
                uf.unite(i * W + j, i * W + (j + 1));
            }
        }
    }

    ll cnt[H * W][2];
    fill(cnt[0], cnt[H * W], 0);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            ++cnt[uf.find(i * W + j)][(i + j) % 2];
        }
    }

    ll ans = 0;
    for (int i = 0; i < H * W; ++i) {
        ans += cnt[i][0] * cnt[i][1];
    }

    cout << ans << endl;
    return 0;
}

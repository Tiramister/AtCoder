#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

ll mypow(ll n, ll k) {
    if (k == 0) return 1;
    if (k == 1) return n;

    if (k % 2 > 0) {
        return mypow(n, k - 1) * n % MOD;
    } else {
        return mypow(n * n % MOD, k / 2);
    }
}

class UnionFind {
public:
    int V_NUM;
    vector<int> par, num;

    explicit UnionFind(int N) : V_NUM(N) {
        par.resize(N);
        iota(par.begin(), par.end(), 0);
        num.assign(N, 1);
    }

    int find(int x) {
        return (par[x] == x) ? x : (par[x] = find(par[x]));
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;

        if (num[x] < num[y]) swap(x, y);
        num[x] += num[y];
        par[y] = x;
    }

    bool same(int x, int y) { return find(x) == find(y); }
    bool ispar(int x) { return x == find(x); }
    int size(int x) { return num[find(x)]; }
};

const ll MAX_V = 200010;

ll fact[MAX_V + 1], invfact[MAX_V + 1];

void precalc() {
    invfact[0] = fact[0] = 1;
    for (ll i = 1; i <= MAX_V; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invfact[MAX_V] = mypow(fact[MAX_V], MOD - 2);
    for (ll i = MAX_V - 1; i >= 0; --i) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
    return;
}

int main() {
    precalc();

    int n, x, y;
    cin >> n >> x >> y;

    pair<int, int> balls[n];  // (weight, color)
    for (int i = 0; i < n; ++i) {
        cin >> balls[i].second >> balls[i].first;
        --balls[i].second;
    }

    sort(balls, balls + n);

    vector<pair<int, int>> colors[n];  // (weight, index)
    for (int i = 0; i < n; ++i) {
        colors[balls[i].second].push_back(make_pair(balls[i].first, i));
    }

    UnionFind uf(n);

    // 一番軽いやつと連結
    for (int i = 1; i < n; ++i) {
        int limit = (balls[0].second == balls[i].second ? x : y);
        if (balls[0].first + balls[i].first <= limit) uf.unite(0, i);
    }

    // 各色内で最も軽いやつと連結
    for (int c = 0; c < n; ++c) {
        for (int i = 1; i < colors[c].size(); ++i) {
            if (colors[c][0].first + colors[c][i].first <= x) {
                uf.unite(colors[c][0].second, colors[c][i].second);
            }
        }
    }

    // 一番軽いやつと違う色で、最も軽いやつを選ぶ
    int widx = -1;
    for (int c = 0; c < n; ++c) {
        if (c == balls[0].second || colors[c].empty()) continue;
        if (widx < 0 || colors[c][0].first < balls[widx].first) {
            widx = colors[c][0].second;
        }
    }

    // 一番軽いやつの色の集合と、widxを連結
    for (auto ball : colors[balls[0].second]) {
        if (ball.first + balls[widx].first <= y) {
            uf.unite(ball.second, widx);
        }
    }

    map<int, int> groups[n];
    // UnionFindによる各グループに、各色がいくつ含まれるか
    for (int i = 0; i < n; ++i) {
        ++groups[uf.find(i)][balls[i].second];
    }

    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        if (!uf.ispar(i)) continue;

        ll sum = 0;
        for (auto color : groups[i]) sum += color.second;

        ll pat = fact[sum];
        for (auto color : groups[i]) {
            pat *= invfact[color.second];
            pat %= MOD;
        }

        ans *= pat;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}

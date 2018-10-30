/* main code starts from line 136. */

/* ---------- STL Libraries ---------- */

// IO library
#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>

// container library
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>


/* ---------- Namespace ---------- */

using namespace std;


/* ---------- Type Abbreviation ---------- */

template <typename T>
using V = vector<T>;
template <typename T, typename U>
using P = pair<T, U>;
template <typename T>
using PQ = priority_queue<T>;

using ll = long long;
using str = string;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define mt make_tuple


/* ---------- conversion ---------- */

#define INT(c) static_cast<int>(c)
#define CHAR(n) static_cast<char>(n)
#define LL(n) static_cast<ll>(n)
#define DOUBLE(n) static_cast<double>(n)


/* ---------- container ---------- */

#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) (LL((v).size()))

#define FIND(v, k) (v).find(k) != (v).end()
#define VFIND(v, k) find(ALL(v), k) != (v).end

#define SORT(v) sort(ALL(v))
#define GSORT(v) sort(ALL(v), greater<decltype((v).front())>())


/* ---------- repetition ---------- */

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define NREP(i, n) FOR(i, 1, n + 1)

#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define RREP(i, n) RFOR(i, n - 1, 0)
#define RNREP(i, n) RFOR(i, n, 1)

// Usual REP runs from 0 to n-1 (R: n-1 to 0)
// Natural REP runs from 1 to n (R: n to 1)


/* ---------- Short Functions ---------- */

template <typename T>
T sq(T a) {
    return a * a;
}

#define fcout cout << fixed << setprecision(10)


/* ---------- Constants ---------- */

// const ll MOD = 1e9 + 7;
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const double PI = 3.14159265358979;
// const ll dx[4] = {0, -1, 1, 0};
// const ll dy[4] = {-1, 0, 0, 1};
// const ll dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const ll dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};


/* ----------- debug ---------- */

template <typename T, typename U>
void testP2(T a, U b) {
    cout << "(" << a << ", " << b << ")" << endl;
    return;
}

template <typename T>
void testV(T v) {
    cout << "[";
    for (auto i : v) {
        cout << i << ", ";
    }
    cout << "\b\b]" << endl;
    return;
}

template <typename T>
void testV2(T v) {
    for (auto sv : v) {
        testV(sv);
    }
    cout << endl;
    return;
}

#define GET_VAR_NAME(variable) #variable
#define test(x) cout << GET_VAR_NAME(x) << " = " << x << endl;
#define testP(p)                      \
    cout << GET_VAR_NAME(p) << " = "; \
    testP2(p.fst, p.snd);


/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

/* ---------- Type Definition ----------- */

class UnionFind {
public:
    // コンストラクタ
    UnionFind(ll N) {
        V_NUM = N;
        REP(i, V_NUM) {
            // 初期化: par[i] = i, rank[i] = 0
            par.pb(i);
            rank.pb(0);
            num.pb(1);
        }
    }

    // xの親を返す+更新
    ll find(ll x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    // xとyを含むグループを統合する
    void unite(ll x, ll y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        num[find(x)] += num[find(y)];
        num[find(y)] = num[find(x)];

        // rankの小さい方にくっつける
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }

    // xとyが同じグループに属するか判定
    bool same(ll x, ll y) {
        return find(x) == find(y);
    }

    ll V_NUM;
    V<ll> par, rank, num;
};

/* ---------- Global Variance ----------- */


/* ------------- Functions -------------- */


/* ----------- Main Function ------------ */

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;

    V<tuple<ll, ll, ll>> edge;
    REP(i, M) {
        ll a, b, y;
        cin >> a >> b >> y;
        edge.pb(mt(y, a, b));
    }

    SORT(edge);

    V<tuple<ll, ll, ll>> query;
    // 年数、頂点、番号の順

    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll v, w;
        cin >> v >> w;
        query.pb(mt(w, v, i));
    }

    GSORT(query);

    V<ll> ans(Q);
    UnionFind uf(N + 1);

    for (auto q : query) {
        ll w, v, id;
        tie(w, v, id) = q;

        while (!edge.empty()) {
            auto e = edge.back();
            ll y, a, b;
            tie(y, a, b) = e;

            if (y <= w) break;
            edge.pop_back();
            uf.unite(a, b);
        }

        ans[id] = uf.num[uf.find(v)];
    }

    REP(i, Q) {
        cout << ans[i] << endl;
    }
    return 0;
}

/* main code starts from line 130. */

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
#include <array>
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

/* ---------- Constants ---------- */

// const ll MOD = 1e9 + 7;
// const int INF = 1 << 25;
const ll INF = 1LL << 50;
// const double PI = 3.14159265358979;
// const ll dx[4] = {0, -1, 1, 0};
// const ll dy[4] = {-1, 0, 0, 1};
// const ll dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const ll dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

/* ---------- Type Definition ----------- */

const ll MAX_V = 200;

struct edge {
    ll to;
    ll cap;
    ll rev;  // path[to]中でのfromのイテレータ
    edge(ll to_, ll cap_, ll rev_) : to(to_), cap(cap_), rev(rev_){};
};

class Dinic {
public:
    array<V<edge>, MAX_V> path;
    array<ll, MAX_V> level;
    array<ll, MAX_V> iter;

    void add_edge(ll from, ll to, ll cap) {
        path[from].pb(edge(to, cap, SIZE(path[to])));
        path[to].pb(edge(from, cap, SIZE(path[from]) - 1));
    }

    void bfs(ll s) {
        fill(ALL(level), -1);
        queue<ll> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            ll v = que.front();
            que.pop();

            for (auto e : path[v]) {
                ll sv = e.to, c = e.cap;
                if (c > 0 && level[sv] < 0) {
                    level[sv] = level[v] + 1;
                    que.push(sv);
                }
            }
        }
    }

    ll dfs(ll v, ll g, ll f) {
        if (v == g) return f;

        for (ll& itr = iter[v]; itr < SIZE(path[v]); itr++) {
            edge e = path[v][itr];

            if (e.cap > 0 && level[v] < level[e.to]) {
                ll df = dfs(e.to, g, min(f, e.cap));
                if (df > 0) {
                    path[v][itr].cap -= df;
                    path[e.to][e.rev].cap += df;
                    return df;
                }
            }
        }
        return 0;
    }

    ll max_flow(ll s, ll g) {
        ll flow = 0;
        while (true) {
            bfs(s);
            if (level[g] < 0) {
                return flow;
            }
            fill(ALL(iter), 0);
            ll f;
            while (true) {
                f = dfs(s, g, INF);
                if (f == 0) break;
                flow += f;
            }
        }
    }
};

/* ---------- Global Variance ----------- */


/* ------------- Functions -------------- */


/* ----------- Main Function ------------ */

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, G, E;
    cin >> N >> G >> E;
    Dinic dinic;
    REP(i, G) {
        int p;
        cin >> p;
        dinic.add_edge(p, N, 1);
    }

    REP(i, E) {
        int a, b;
        cin >> a >> b;
        dinic.add_edge(a, b, 1);
    }

    cout << dinic.max_flow(0, N) << endl;
    return 0;
}

/* ---------- STL Libraries ---------- */

// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
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
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

using ll = long long;

#define fst first
#define snd second
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
#define VFIND(v, k) find(ALL(v), k) != (v).end()

#define gsort(b, e) sort(b, e, greater<decltype(*b)>())
#define SORT(v) sort((v).begin(), (v).end())
#define GSORT(v) sort((v).begin(), (v).end(), greater<decltype((v).front())>())

/* ----------- debug ---------- */

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, set<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.fst << "," << p.snd << ")";
}

/* ---------- Constants ---------- */

// const ll MOD = 1e9 + 7;
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const double PI = acos(-1);
// const double EPS = 1e-10;
// const ll dx[4] = {0, -1, 1, 0};
// const ll dy[4] = {-1, 0, 0, 1};
// mt19937 melt(LL(time(0)));

/* ---------- Short Functions ---------- */

template <typename T>
T sq(T a) {
    return a * a;
}

template <typename T>
T gcd(T a, T b) {
    if (a > b) return gcd(b, a);
    return a == 0 ? b : gcd(b % a, a);
}

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b /* % MOD */;
    if (n % 2 == 0) {
        return mypow(b * b /* % MOD */, n / 2);
    } else {
        return mypow(b, n - 1) * b /* % MOD */;
    }
}

ll pcnt(ll b) {
    return __builtin_popcountll(b);
}

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

const int INF = 1 << 30;

int main() {
    int N, M;
    cin >> N >> M;

    set<int> comp[N];
    vector<pair<int, int>> nodes;

    for (int v = 0; v < N; ++v) {
        nodes.push_back(mp(v, -1));
    }

    int p[M], q[M], c[M];
    for (int i = 0; i < M; ++i) {
        cin >> p[i] >> q[i] >> c[i];
        --p[i];
        --q[i];
        comp[p[i]].insert(c[i]);
        comp[q[i]].insert(c[i]);
        nodes.push_back(mp(p[i], c[i]));
        nodes.push_back(mp(q[i], c[i]));
    }

    SORT(nodes);
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

    map<pair<int, int>, int> dic;
    for (int i = 0; i < SIZE(nodes); ++i) {
        dic[nodes[i]] = i;
    }

    vector<pair<int, int>> path[SIZE(nodes)];

    for (int v = 0; v < N; ++v) {
        for (int c : comp[v]) {
            path[dic[mp(v, c)]].push_back(mp(dic[mp(v, -1)], 0));
            path[dic[mp(v, -1)]].push_back(mp(dic[mp(v, c)], 1));
        }
    }

    for (int i = 0; i < M; ++i) {
        path[dic[mp(p[i], c[i])]].push_back(mp(dic[mp(q[i], c[i])], 0));
        path[dic[mp(q[i], c[i])]].push_back(mp(dic[mp(p[i], c[i])], 0));
    }

    int s = dic[mp(0, -1)], g = dic[mp(N - 1, -1)];

    int dis[SIZE(nodes)];
    fill(dis, dis + SIZE(nodes), INF);
    GPQ<pair<int, int>> que;
    que.push(mp(0, s));

    while (!que.empty()) {
        int d, v;
        tie(d, v) = que.top();
        que.pop();

        if (d >= dis[v]) continue;
        dis[v] = d;

        for (auto p : path[v]) {
            int sv, c;
            tie(sv, c) = p;
            que.push(mp(c + d, sv));
        }
    }

    cout << (dis[g] == INF ? -1 : dis[g]) << endl;
    return 0;
}

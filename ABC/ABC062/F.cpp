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
const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const double PI = acos(-1);
// const double EPS = 1e-10;
// mt19937 mert(LL(time(0)));

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

struct edge {
    int to;
    int cap;
    int rev;  // path[to]中でのfromのイテレータ
    edge(int to_, int cap_, int rev_) : to(to_), cap(cap_), rev(rev_){};
};

class Dinic {
public:
    vector<vector<edge>> path;
    vector<int> level, iter;

    explicit Dinic(int N) {
        path.resize(N);
        level.resize(N);
        iter.resize(N);
    }

    void add_edge(int from, int to, int cap) {
        // fromとtoの間に双方向の辺を加える
        // 有向の場合は後者のcapを0にする
        path[from].push_back(edge(to, cap, path[to].size()));
        path[to].push_back(edge(from, 0, path[from].size() - 1));
    }

    void bfs(int s) {
        // 頂点sからのcap>0の辺のみを通った最短距離を求める
        // 辿り着けなければ-1

        fill(level.begin(), level.end(), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();

            for (auto e : path[v]) {
                int sv = e.to, c = e.cap;
                if (c > 0 && level[sv] < 0) {
                    level[sv] = level[v] + 1;
                    que.push(sv);
                }
            }
        }
    }

    int dfs(int v, int g, int f) {
        if (v == g) return f;

        // iterで事前にどこまで探索したかをセーブ
        for (int& itr = iter[v]; itr < path[v].size(); ++itr) {
            edge e = path[v][itr];

            if (e.cap > 0 && level[v] < level[e.to]) {
                int df = dfs(e.to, g, min(f, e.cap));
                if (df > 0) {
                    path[v][itr].cap -= df;
                    path[e.to][e.rev].cap += df;
                    return df;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int g) {
        // sからgへの最大フロー(最小カット)を求める

        int flow = 0;
        while (true) {
            bfs(s);
            if (level[g] < 0) {
                return flow;
            }
            fill(iter.begin(), iter.end(), 0);
            int f;
            while (true) {
                f = dfs(s, g, INF);
                if (f == 0) break;
                flow += f;
            }
        }
    }
};


int main() {
    int H, W;
    cin >> H >> W;

    string a[H];
    pair<int, int> s, g;
    for (int i = 0; i < H; ++i) {
        cin >> a[i];
        for (int j = 0; j < W; ++j) {
            if (a[i][j] == 'S') {
                s = make_pair(i, j);
            } else if (a[i][j] == 'T') {
                g = make_pair(i, j);
            }
        }
    }

    if (s.first == g.first || s.second == g.second) {
        cout << -1 << endl;
        return 0;
    }

    Dinic dinic(H + W + 2);
    dinic.add_edge(H + W, s.first, INF);
    dinic.add_edge(H + W, s.second + H, INF);
    dinic.add_edge(g.first, H + W + 1, INF);
    dinic.add_edge(g.second + H, H + W + 1, INF);

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (a[i][j] == 'o') {
                dinic.add_edge(i, j + H, 1);
                dinic.add_edge(j + H, i, 1);
            }
        }
    }

    cout << dinic.max_flow(H + W, H + W + 1) << endl;
    return 0;
}

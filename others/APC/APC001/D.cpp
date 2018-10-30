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
// const ll INF = 1LL << 40;
// const double PI = acos(-1);
// const double EPS = 1e-10;
// const ll dx[4] = {0, -1, 1, 0};
// const ll dy[4] = {-1, 0, 0, 1};
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

int main() {
    ll N, M;
    cin >> N >> M;

    ll a[N];
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
    }

    vector<ll> path[N];
    for (ll i = 0; i < M; ++i) {
        ll x, y;
        cin >> x >> y;
        path[x].push_back(y);
        path[y].push_back(x);
    }

    if (N - M == 1) {
        cout << 0 << endl;
        return 0;
    }

    bool visited[N];
    fill(visited, visited + N, false);

    vector<GPQ<ll>> group;

    for (ll i = 0; i < N; ++i) {
        if (visited[i]) continue;
        visited[i] = true;

        GPQ<ll> pque;

        queue<ll> que;
        que.push(i);
        while (!que.empty()) {
            ll v = que.front();
            que.pop();
            pque.push(a[v]);

            for (ll sv : path[v]) {
                if (!visited[sv]) {
                    visited[sv] = true;
                    que.push(sv);
                }
            }
        }

        group.push_back(pque);
    }

    ll nodes = SIZE(group);

    if (N < (nodes - 1) * 2) {
        cout << "Impossible" << endl;
        return 0;
    }

    ll ans = 0;
    GPQ<ll> total;
    for (auto& pque : group) {
        ans += pque.top();
        pque.pop();
        while (!pque.empty()) {
            total.push(pque.top());
            pque.pop();
        }
    }

    for (ll i = 0; i < nodes - 2; ++i) {
        ans += total.top();
        total.pop();
    }

    cout << ans << endl;
    return 0;
}

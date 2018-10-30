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
#define SORT(v) sort(ALL(v))
#define GSORT(v) sort(ALL(v), greater<decltype(v.front())>())

/* ---------- repetition ---------- */

#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (ll i = (b)-1; i >= (a); --i)

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
const double PI = acos(-1);
// const double EPS = 1e-10;
// const ll dx[4] = {0, -1, 1, 0};
// const ll dy[4] = {-1, 0, 0, 1};
// mt19937 mt(LL(time(0)));

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
        return mypow(sq(b) /* % MOD */, n / 2);
    } else {
        return mypow(b, n - 1) * b /* % MOD */;
    }
}

ll pcnt(ll b) {
    return __builtin_popcountll(b);
}

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

// #define DEBUG

class BIT {
public:
    explicit BIT(ll N, ll v) : V_NUM(N) {
        data.resize(N);
        fill(ALL(data), v);
    }

    ll query(ll i) {
        ll ret = 0;
        while (i > 0) {
            ret = max(ret, data[i]);
            i -= (i & -i);
        }
        return ret;
    }

    void update(ll i, ll v) {
        while (i < V_NUM) {
            data[i] = max(data[i], v);
            i += (i & -i);
        }
    }

    ll V_NUM;
    V<ll> data;
};

struct coo {
    coo(ll _x = 0, ll _y = 0) : x(_x), y(_y){};
    ll x;
    ll y;

    bool operator<(const coo& r) const {
        return x == r.x ? y < r.y : x < r.x;
    }
};

map<ll, ll> compress(const V<coo>& a) {
    set<ll> sety;
    for (coo c : a) {
        sety.insert(c.y);
    }

    map<ll, ll> ret;
    ll idx = 1;
    for (ll y : sety) {
        ret[y] = idx;
        ++idx;
    }

    return ret;
}

void solve() {
    coo s, g;
    cin >> s.x >> s.y >> g.x >> g.y;

    if (s.y > g.y) swap(s, g);

    ll N;
    cin >> N;
    V<coo> a;
    FOR(_, 0, N) {
        ll x, y;
        cin >> x >> y;
        if (y < s.y || g.y < y) continue;

        if (s.x < g.x) {
            if (s.x <= x && x <= g.x) {
                a.push_back(coo(x - s.x, y - s.y));
            }
        } else {
            if (g.x <= x && x <= s.x) {
                a.push_back(coo(s.x - x, y - g.y));
            }
        }
    }

    SORT(a);
    map<ll, ll> com = compress(a);

    BIT bit(SIZE(com) + 10, 0);

    for (coo c : a) {
        ll y = com[c.y];
        bit.update(y, bit.query(y) + 1);
    }

    ll turn = bit.query(SIZE(com) + 5);
    // cout << "turn : " << turn << endl;

    double ans = (abs(g.x - s.x) + abs(g.y - s.y)) * 100;
    ans -= (20 - PI * 5) * turn;
    if (turn == abs(g.y - s.y) + 1 || turn == abs(g.x - s.x) + 1) {
        ans += PI * 5;
    }

    cout << ans << endl;
    return;
}


/* ---------- Do not edit below part ---------- */


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    int num;
    cin >> num;
    FOR(_, 1, num) {
        cout << "++++++++++++++++++++" << endl;
        solve();
    }
#else
    solve();
#endif

    return 0;
}

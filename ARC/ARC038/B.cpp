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
// const ll INF = 1LL << 50;
// const double PI = 3.14159265358979;
const ll dx[3] = {1, 0, 1};
const ll dy[3] = {0, 1, 1};
// const ll dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const ll dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

/* ---------- Type Definition ----------- */


/* ---------- Global Variance ----------- */

int H, W;
V<string> S(101);
V<V<int>> res(101, V<int>(101, 0));
// res[i][j] = (i, j)で自分の番が来たとき、
// 勝てるなら1、負けるなら2

/* ------------- Functions -------------- */

bool play(int x, int y) {
    if (res[x][y] > 0) {
        return res[x][y] == 1;
    }

    if (S[x][y] == '#') {
        // ありえない位置にいる
        // = 先のターンで既に相手の負け
        res[x][y] = 1;
        return true;
    }

    REP(i, 3) {
        int sx = x + dx[i];
        int sy = y + dy[i];
        if (sx < 0 || sx >= H || sy < 0 || sy >= W) continue;
        if (!play(sx, sy)) {
            // 相手が(sx, sy)になったら負け
            // == 自分がその手を指せば勝ち
            res[x][y] = 1;
            return true;
        }
    }
    res[x][y] = 2;
    return false;
}

/* ----------- Main Function ------------ */

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W;
    res.resize(H);
    REP(i, H) {
        cin >> S[i];
        res[i].resize(W);
    }

    if (play(0, 0)) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    return 0;
}

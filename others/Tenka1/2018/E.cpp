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
// const int INF = 1 << 25;
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

int brd[1001][1000];

int main() {
    int H, W;
    cin >> H >> W;

    fill(brd[0], brd[1000], 0);

    for (int x = 0; x < H; ++x) {
        string s;
        cin >> s;
        for (int y = 0; y < W; ++y) {
            if (s[y] == '#') brd[x + y + 200][x - y + 500] = 1;
        }
    }

    int imos[1000][1000];
    for (int x = 0; x < 1000; ++x) {
        imos[x][0] = brd[x][0];
        for (int y = 1; y < 1000; ++y) {
            imos[x][y] = imos[x][y - 1] + brd[x][y];
        }
    }

    int ans = 0;

    for (int x = 0; x < 1000; ++x) {

        for (int i = 0; i < 1000; ++i) {
            if (brd[x][i] != 1) continue;
            for (int j = i + 1; j < 1000; ++j) {
                if (brd[x][j] != 1) continue;

                int d = j - i;
                if (x >= d) {
                    ans += imos[x - d][j] - imos[x - d][i - 1];
                }
                if (x + d < 1000) {
                    ans += imos[x + d][j] - imos[x + d][i - 1];
                }
            }
        }
    }

    for (int y = 0; y < 1000; ++y) {
        imos[0][y] = brd[0][y];
        for (int x = 1; x < 1000; ++x) {
            imos[x][y] = imos[x - 1][y] + brd[x][y];
        }
    }

    for (int y = 0; y < 1000; ++y) {

        for (int i = 0; i < 1000; ++i) {
            if (brd[i][y] != 1) continue;
            for (int j = i + 1; j < 1000; ++j) {
                if (brd[j][y] != 1) continue;

                int d = j - i;
                if (y >= d) {
                    ans += imos[j - 1][y - d] - imos[i][y - d];
                }
                if (y + d < 1000) {
                    ans += imos[j - 1][y + d] - imos[i][y + d];
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}

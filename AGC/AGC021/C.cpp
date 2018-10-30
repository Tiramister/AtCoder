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
#define VFIND(v, k) find(ALL(v), k) != (v).end()

#define gsort(b, e) sort(b, e, greater<decltype(*b)>())
#define SORT(v) sort(ALL(v))
#define GSORT(v) gsort(ALL(v))

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
// const double PI = acos(-1);
// const double EPS = 1e-10;
// const ll dx[4] = {0, -1, 1, 0};
// const ll dy[4] = {-1, 0, 0, 1};

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

V<V<char>> tile(2000, V<char>(2000, '.'));

// 偶数×偶数のグリッドをタイルで埋める
bool tiling(ll N, ll M, ll A, ll B) {
    ll need = (A + 1) / 2 * 4 + (B + 1) / 2 * 4;
    if (N * M < need) return false;

    FOR(i, 0, N / 2) {
        FOR(j, 0, M / 2) {
            FOR(k, 0, 2) {
                if (A == 0) break;
                tile[i * 2 + k][j * 2] = '<';
                tile[i * 2 + k][j * 2 + 1] = '>';
                --A;
            }
        }
    }

    RFOR(i, 0, N / 2) {
        RFOR(j, 0, M / 2) {
            FOR(k, 0, 2) {
                if (B == 0) break;
                tile[i * 2][j * 2 + k] = '^';
                tile[i * 2 + 1][j * 2 + k] = 'v';
                --B;
            }
        }
    }
    return true;
}

// コーナーケースで左下が埋まってるとき専用
bool tiling_corner(ll N, ll M, ll A, ll B) {
    ll need = (A + 1) / 2 * 4 + (B + 1) / 2 * 4;

    // 左下が埋められている分制約が変わる
    if (N * M - 4 < need) return false;

    FOR(i, 0, N / 2) {
        FOR(j, 0, M / 2) {
            // 左下のすでに埋められている箇所は飛ばす
            if (i == N / 2 - 1 && j == 0) continue;

            FOR(k, 0, 2) {
                if (A == 0) break;
                tile[i * 2 + k][j * 2] = '<';
                tile[i * 2 + k][j * 2 + 1] = '>';
                --A;
            }
        }
    }

    RFOR(i, 0, N / 2) {
        RFOR(j, 0, M / 2) {
            // 左下のすでに埋められている箇所は飛ばす
            if (i == N / 2 - 1 && j == 0) continue;

            FOR(k, 0, 2) {
                if (B == 0) break;
                tile[i * 2][j * 2 + k] = '^';
                tile[i * 2 + 1][j * 2 + k] = 'v';
                --B;
            }
        }
    }
    return true;
}

void solve() {
    ll N, M, A, B;
    cin >> N >> M >> A >> B;

    bool res;
    // 敷き詰めが可能か否かを受け取る

    if (N % 2 == 0 && M % 2 == 0) {
        res = tiling(N, M, A, B);

    } else if (N % 2 == 1 && M % 2 == 0) {
        // 一番下の行を埋める
        FOR(j, 0, M / 2) {
            if (A == 0) break;
            tile[N - 1][j * 2] = '<';
            tile[N - 1][j * 2 + 1] = '>';
            --A;
        }
        res = tiling(N - 1, M, A, B);

    } else if (N % 2 == 0 && M % 2 == 1) {
        // 一番右の列を埋める
        FOR(i, 0, N / 2) {
            if (B == 0) break;
            tile[i * 2][M - 1] = '^';
            tile[i * 2 + 1][M - 1] = 'v';
            --B;
        }
        res = tiling(N, M - 1, A, B);

    } else {
        // 一番下の行を埋める
        FOR(j, 0, M / 2) {
            if (A == 0) break;
            tile[N - 1][j * 2 + 1] = '<';
            tile[N - 1][j * 2 + 2] = '>';
            --A;
        }

        // 一番右の列を埋める
        FOR(i, 0, N / 2) {
            if (B == 0) break;
            tile[i * 2][M - 1] = '^';
            tile[i * 2 + 1][M - 1] = 'v';
            --B;
        }

        // 残ったA, Bが共に奇数の場合は特殊処理
        if (A % 2 == 1 && B % 2 == 1) {
            tile[N - 3][0] = '<';
            tile[N - 3][1] = '>';
            tile[N - 2][0] = '^';
            tile[N - 1][0] = 'v';
            --A;
            --B;
            res = tiling_corner(N - 1, M - 1, A, B);
        } else {
            res = tiling(N - 1, M - 1, A, B);
        }
    }

    if (res) {
        cout << "YES" << endl;
        FOR(i, 0, N) {
            FOR(j, 0, M) {
                cout << tile[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return;
}


/* ---------- ここから下は手を加えないこと ----------- */


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // cout << fixed << setprecision(10);

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

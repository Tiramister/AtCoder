/* main code starts from line 123. */

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
#include <deque>
#include <list>
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

using ll = long long;
using PL = P<ll, ll>;
using PS = P<string, ll>;

using VI = V<int>;
using VVI = V<VI>;
using VL = V<ll>;
using VVL = V<VL>;
using VS = V<string>;
using VB = V<bool>;
using VVB = V<VB>;
using VPL = V<PL>;
using VPS = V<PS>;

#define fst first
#define snd second
#define pb push_back


/* ---------- conversion ---------- */

#define INT(c) static_cast<int>(c)
#define CHAR(n) static_cast<char>(n)
#define LL(n) static_cast<ll>(n)
#define DOUBLE(n) static_cast<double>(n)


/* ---------- container ---------- */

#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) (LL((v).size()))

#define FIND(v, k) (v).find(k) != (v).end()
#define EACH(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)
#define REACH(i, v) for (auto itr = (v).rbegin(); itr != (v).rend(); itr++)

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


/* ---------- Constants ---------- */

// const ll MOD = 1e9 + 7;
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const double PI = 3.14159265358979;
// const ll dx[4] = {0, -1, 1, 0};
// const ll dy[4] = {-1, 0, 0, 1};
// const ll dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const ll dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};


/* ---------- Short Functions ---------- */

template <typename T>
T sq(T a) {
    return a * a;
}


/* ---------- Debug ---------- */

#define GET_VAR_NAME(variable) #variable

#define test(x) cout << GET_VAR_NAME(x) << " = " << x << endl;
#define testP(p) cout << GET_VAR_NAME(p) << " = (" << (p).fst << ", " << (p).snd << ")" << endl;
#define testP2(a, b) cout << "(" << a << ", " << b << ")" << endl;


/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

/* ---------- Global Variance ----------- */


/* ------------- Functions -------------- */


/* ----------- Main Function ------------ */

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;

    ll total = 0;
    // お気に入りキー使わない場合の操作数

    VVL light(M + 1);
    // light[i]: A[j]=iなるjの集合

    VL key(M + 1);
    // key[i]: iをお気に入りにしたとき、
    //         totalから削減できる回数

    ll turn = 0;
    // 何回M->1の切り替えが起こるか

    VL A(N);
    cin >> A[0];
    light[A[0]].pb(0);
    NREP(i, N - 1) {
        cin >> A[i];
        if (A[i - 1] < A[i]) {
            total += A[i] - A[i - 1];
        } else {
            total += A[i] - A[i - 1] + M;
            key[1] += M - A[i - 1];
            turn++;
        }
        light[A[i]].pb(i);
    }

    ll first = 0;
    // key > A[0]なら1、他は0
    ll last = 1;
    // key <= A[N - 1]なら1、他は0

    ll mdec = key[1];
    // max decrease

    FOR(i, 2, M + 1) {
        key[i] = key[i - 1] + (turn + first + last - 1);
        for (ll j : light[i - 1]) {
            // 既にkeyがoverしていた照度の集合
            if (j == 0) {
                first = 1;
                // cout << "first over" << endl;
                continue;
            } else if (j == N - 1) {
                last = 0;
                // cout << "last over" << endl;
            }

            if (A[j - 1] < A[j]) {
                key[i] -= A[j] - A[j - 1];
            } else {
                key[i] -= A[j] - A[j - 1] + M;
            }
        }

        mdec = max(mdec, key[i]);
    }

    cout << total - mdec << endl;
    return 0;
}

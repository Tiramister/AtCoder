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

const ll MOD = 1e9 + 7;
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

ll calc_pow(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b % 2 == 0) {
        return calc_pow(sq(a) % MOD, b / 2) % MOD;
    } else {
        return calc_pow(a, b - 1) * a % MOD;
    }
}

/* ----------- Main Function ------------ */

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;

    ll nmax = 0;
    VL mp(N, 0);
    REP(i, N) {
        ll A;
        cin >> A;
        mp[A]++;
        nmax = max(nmax, A);

        if (i == 0 && A > 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    if (mp[0] > 1) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    NREP(i, nmax) {
        if (mp[i] == 0) {
            ans = 0;
        } else {
            ll s = calc_pow(2, mp[i - 1]) - 1;
            ans *= calc_pow(s, mp[i]);
            ans %= MOD;
            ans *= calc_pow(2, mp[i] * (mp[i] - 1) / 2);
            ans %= MOD;
        }
    }

    cout << ans << endl;
    return 0;
}

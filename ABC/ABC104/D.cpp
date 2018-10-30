/* main code starts from line 155. */

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

#define SORT(v) sort(ALL(v))
#define GSORT(v) sort(ALL(v), greater<decltype((v).front())>())

/* ---------- repetition ---------- */

#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)

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

/* --------------------
template <typename T>
T mypow(T b, T n) {
    if (n == 0) return 1;
    if (n == 1) return n;
    if (n % 2 == 0) {
        return mypow(sq(b), n / 2);
    } else {
        return mypow(b, n - 1) * b;
    }
}

template <typename T>
T mypow(T b, T n) {
    if (n == 0) return 1;
    if (n == 1) return n % MOD;
    if (n % 2 == 0) {
        return mypow(sq(b) % MOD, n / 2);
    } else {
        return mypow(b, n - 1) * b % MOD;
    }
}
-------------------- */

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

// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const double PI = acos(-1);
// const double EPS = 1e-10;
// const ll dx[4] = {0, -1, 1, 0};
// const ll dy[4] = {-1, 0, 0, 1};
// const ll dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const ll dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

/* ---------- Type Definition ----------- */


/* ---------- Global Variance ----------- */

const ll MOD = 1e9 + 7;
string S;
ll N;
ll qnum[100010];
ll dp[100010][4];

/* ------------- Functions -------------- */

ll rec(ll itr, ll k) {
    if (itr >= N) {
        if (k == 3) return 1;
        return 0;
    }

    if (dp[itr][k] >= 0) return dp[itr][k];

    if (k == 3) {
        dp[itr][k] = rec(itr + 1, k) * (S[itr] == '?' ? 3 : 1) % MOD;
        return dp[itr][k];
    }

    dp[itr][k] = 0;
    if (S[itr] == "ABC"[k] || S[itr] == '?') {
        dp[itr][k] += rec(itr + 1, k + 1);
    }

    dp[itr][k] += rec(itr + 1, k) * (S[itr] == '?' ? 3 : 1);
    dp[itr][k] %= MOD;
    return dp[itr][k];
}

/* ----------- Main Function ------------ */

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> S;
    N = SIZE(S);

    fill(dp[0], dp[N], -1);
    cout << rec(0, 0) << endl;
    return 0;
}

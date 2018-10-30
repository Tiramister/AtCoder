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

string ani = "WS";
map<char, int> kind;
map<char, bool> judge;

int N;
string S;

/* ------------- Functions -------------- */

bool rational(char c0, char c1) {
    string assign(N, 'a');
    assign[0] = c0;
    assign[1] = c1;

    NREP(i, N - 2) {
        if (kind[assign[i]] ^ judge[S[i]]) {
            // 両隣は違う種類
            assign[i + 1] = ani[(kind[assign[i - 1]] + 1) % 2];
        } else {
            assign[i + 1] = ani[kind[assign[i - 1]]];
        }
    }


    bool result = false;
    if (kind[assign[N - 1]] ^ judge[S[N - 1]]) {
        if (assign[0] == ani[(kind[assign[N - 2]] + 1) % 2]) {
            result = true;
        }
    } else {
        if (assign[0] == ani[kind[assign[N - 2]]]) {
            result = true;
        }
    }

    if (!result) {
        return false;
    }

    result = false;
    if (kind[assign[0]] ^ judge[S[0]]) {
        if (assign[N - 1] != assign[1]) {
            result = true;
        }
    } else {
        if (assign[N - 1] == assign[1]) {
            result = true;
        }
    }

    if (result) {
        cout << assign << endl;
    }

    return result;
}

/* ----------- Main Function ------------ */

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> S;

    kind['W'] = 0;
    kind['S'] = 1;
    judge['x'] = 0;
    judge['o'] = 1;

    REP(i, 2) {
        REP(j, 2) {
            if (rational(ani[i], ani[j])) {
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}

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

VI delete0(VI a) {
    while (true) {
        if (a.back() > 0) break;
        a.pop_back();
    }
    return a;
}


// 繰り上がり処理
VI moveup(VI a) {
    REP(i, SIZE(a) - 1) {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    return a;
}


void Vprint(VI a) {
    a = moveup(a);

    while (true) {
        if (a[0] == 0 && a[1] == 0) {
            a.erase(a.begin(), a.begin() + 2);
        } else {
            break;
        }
    }

    a = delete0(a);

    while (!a.empty()) {
        cout << a.back();
        a.pop_back();
    }
    cout << endl;
    return;
}


// a < bなら0、a = bなら1、a > bなら2を返す
int Vcomp(VI a, VI b) {
    a = moveup(a);

    int Na = SIZE(a);

    REP(i, Na) {
        if (a[Na - i - 1] != b[Na - i - 1]) {
            return (a[Na - i - 1] < b[Na - i - 1] ? 0 : 2);
        }
    }

    return 1;
}


// a^2を計算
VI calc_sq(const VI& a) {

    int N = SIZE(a);
    VI ret(N * 2 + 2, 0);
    REP(i, N) {
        REP(j, N) {
            ret[i + j] += a[i] * a[j];
        }
    }

    return moveup(ret);
}


/* ----------- Main Function ------------ */

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    int N = SIZE(S);
    VI a(N);
    REP(i, N) {
        a[i] = INT(S[N - i - 1] - '0');
    }

    VI sqN = calc_sq(a);
    a[0]++;
    VI sqM = calc_sq(a);

    int Na = SIZE(sqN);

    VI ans(Na);
    REP(i, Na) {
        ans[Na - i * 2 - 1] = sqN[Na - i * 2 - 1];
        ans[Na - i * 2 - 2] = sqN[Na - i * 2 - 2];

        // 条件は sqN <= ans < sqM
        if (Vcomp(ans, sqN) == 1) {
            Vprint(ans);
            return 0;
        }

        ans[Na - i * 2 - 2]++;
        if (Vcomp(ans, sqM) == 0) {
            Vprint(ans);
            return 0;
        }

        ans[Na - i * 2 - 2]--;
    }

    return 0;
}

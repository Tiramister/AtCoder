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
#include <stack>
#include <string>
#include <tuple>
#include <vector>

/* ---------- Namespace ---------- */

using namespace std;

/* ---------- Type Abbreviation ---------- */

using ll = long long;

template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

#define mp make_pair
#define mt make_tuple

/* ---------- conversion ---------- */

#define INT(c) static_cast<int>(c)
#define CHAR(n) static_cast<char>(n)
#define LL(n) static_cast<ll>(n)
#define DOUBLE(n) static_cast<double>(n)

/* ---------- container ---------- */

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
    return os << "(" << p.first << "," << p.second << ")";
}

/* ---------- Constants ---------- */

// const ll MOD = 1e9 + 7;
// const int INF = 1 << 25;
const ll INF = 1LL << 50;
// const double PI = acos(-1);
// const double EPS = 1e-10;
// mt19937 mert(LL(time(0)));

/* ---------- Short Functions ---------- */

template <typename T>
inline T sq(T a) { return a * a; }

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
    int N;
    cin >> N;

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    ll fore[N - 1], back[N - 1];
    for (int i = 0; i < N - 1; ++i) {
        fore[i] = 0;
        while (A[i] * mypow(4LL, fore[i]) < A[i + 1]) {
            ++fore[i];
        }

        if (fore[i] == 0) {
            fore[i] = -15;
            while (A[i] < A[i + 1] * mypow(4LL, -fore[i])) {
                ++fore[i];
            }
        }

        back[i] = 0;
        while (A[i] > A[i + 1] * mypow(4LL, back[i])) {
            ++back[i];
        }

        if (back[i] == 0) {
            back[i] = -15;
            while (A[i] * mypow(4LL, -back[i]) > A[i + 1]) {
                ++back[i];
            }
        }

        // cout << i << ":" << fore[i] << " " << back[i] << endl;
    }

    ll fsum[N + 1], bsum[N + 1];

    fsum[0] = fsum[1] = 0;
    vector<pair<ll, ll>> stk;
    stk.push_back(mp(-1, -INF));

    for (int s = 0; s <= N - 2; ++s) {
        fsum[s + 2] = fsum[s + 1];
        ll k = fore[s];

        if (k < 0) {
            stk.push_back(mp(s, k));
        } else {
            ll cur = s;
            while (true) {
                auto p = stk.back();
                stk.pop_back();

                fsum[s + 2] += (cur - p.first) * k * 2;
                k += p.second;
                cur = p.first;

                if (k <= 0) {
                    if (k < 0) {
                        p.second = k;
                        stk.push_back(p);
                    }
                    break;
                }
            }
        }
    }

    stk.clear();

    bsum[N] = bsum[N - 1] = 0;
    stk.push_back(mp(N - 1, -INF));
    for (int s = N - 2; s >= 0; --s) {
        bsum[s] = bsum[s + 1];
        ll k = back[s];

        if (k < 0) {
            stk.push_back(mp(s, k));
        } else {
            ll cur = s;
            while (true) {
                auto p = stk.back();
                stk.pop_back();

                bsum[s] += (p.first - cur) * k * 2;
                k += p.second;
                cur = p.first;

                if (k <= 0) {
                    if (k < 0) {
                        p.second = k;
                        stk.push_back(p);
                    }
                    break;
                }
            }
        }
    }

    ll ans = INF;

    for (int s = 0; s <= N; ++s) {
        ans = min(ans, fsum[s] + bsum[s] + s);
        // cout << s << ":" << fsum[s] << " " << bsum[s] << endl;
    }

    cout << ans << endl;
    return 0;
}

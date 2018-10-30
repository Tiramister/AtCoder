/* ---------- STL Libraries ---------- */ zzzz

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

const ll p[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

ll maxdiv(ll n, ll m) {
    ll cnt = 0;
    while (n % m == 0) {
        n /= m;
        ++cnt;
    }
    return cnt;
}

ll t[25];
ll ex[25];

ll calc(ll b, ll e) {
    if (e - b == 1) {
        t[b] = (ex[b] > 0);
        return mypow(p[b], ex[b]);
    }

    ll mid = (b + e) / 2;
    ll L = calc(b, mid), P = calc(mid, e);

    for (ll a = 0; a < L; ++a) {
        if ((a * P - 1) % L == 0) {
            ll b = (a * P - 1) / L;
            for (ll j = b; j < mid; ++j) {
                t[j] *= a;
            }
            for (ll j = mid; j < e; ++j) {
                t[j] *= -b;
            }
            return L * P;
        }
    }

    terminate();
}

int main() {
    ll N;
    cin >> N;

    fill(ex, ex + 25, 0);

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < 25; ++j) {
            ex[j] = max(ex[j], maxdiv(i, p[j]));
        }
    }

    calc(0, 25);

    ll ans[N + 1];
    fill(ans + 1, ans + N + 1, 0);

    for (ll i = 0; i < 25; ++i) {
        ans[mypow(p[i], ex[i])] = t[i];
    }

    for (ll i = 1; i <= N; ++i) {
        while (ans[i] < 0) {
            ans[1] -= (1LL << 15);
            ans[i] += (1LL << 15) * i;
        }

        if (ans[i] >= i) {
            ans[1] += ans[i] / i;
            ans[i] %= i;
        }

        for (ll j = 2; j < i; ++j) {
            if (j % i > 0) continue;
            while (ans[i] >= i / j) {
                ans[j] += 1;
                ans[i] -= i / j;
            }
        }
    }

    ll Q = 0;
    for (ll i = 1; i <= N; ++i) {
        Q += abs(ans[i]);
    }

    cout << Q << endl;
    for (ll i = 1; i <= N; ++i) {
        if (ans[i] > 0) {
            for (ll k = 0; k < ans[i]; ++k) {
                cout << "+ " << i << endl;
            }
        }
    }

    for (ll i = 1; i <= N; ++i) {
        if (ans[i] < 0) {
            for (ll k = 0; k < -ans[i]; ++k) {
                cout << "- " << i << endl;
            }
        }
    }

    return 0;
}

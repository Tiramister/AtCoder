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

using ll = long long;

template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

#define mp make_pair
#define mt make_tuple

/* ----------- debug ---------- */

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p);

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

// const ll MOD = 1000000007;
// const ll MOD = 998244353;
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
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

template <typename T>
T iceil(T n, T d) {
    return (n + d - 1) / d;
}

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

int main() {
    ll L;
    int N;
    cin >> L >> N;

    ll X[N + 2];
    X[0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> X[i];
    }
    X[N + 1] = L;

    ll cost = 0;
    ll ans = max(ans, L - X[N]);

    for (int l = 1; l <= N - l; ++l) {
        // X[1] ~ X[l]までのl個
        // X[l+1] ~ X[2l]までのl個

        cost += X[l];
        cost -= L - X[l];
        cost += (L - X[l * 2 - 1]) + (L - X[l * 2]);

        ans = max(ans, cost * 2 - min(X[l], L - X[l + 1] - (L - X[l * 2 + 1]) * 2));
    }

    for (int i = 0; i <= N + 1; ++i) {
        X[i] = L - X[i];
    }

    reverse(X, X + N + 2);

    cost = 0;
    ans = max(ans, L - X[N]);

    for (int l = 1; l <= N - l; ++l) {
        // X[1] ~ X[l]までのl個
        // X[l+1] ~ X[2l]までのl個

        cost += X[l];
        cost -= L - X[l];
        cost += (L - X[l * 2 - 1]) + (L - X[l * 2]);

        ans = max(ans, cost * 2 - min(X[l], L - X[l + 1] - (L - X[l * 2 + 1]) * 2));
    }

    cout << ans << endl;

    return 0;
}

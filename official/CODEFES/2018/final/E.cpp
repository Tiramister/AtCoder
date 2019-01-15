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

/* ---------- conversion ---------- */

#define INT(c) static_cast<int>(c)
#define CHAR(n) static_cast<char>(n)
#define LL(n) static_cast<ll>(n)
#define DOUBLE(n) static_cast<double>(n)

/* ---------- container ---------- */

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
    return os << "(" << p.first << "," << p.second << ")";
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

void pque(GPQ<pair<ll, int>> que) {
    while (!que.empty()) {
        cout << que.top() << ",";
        que.pop();
    }
    cout << endl;
}

int main() {
    int N, K;
    cin >> N >> K;

    ll A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    GPQ<pair<ll, int>> que;
    // (A[i], i)

    ll ans = 0;
    int now = 0, itr = 1, buf = K;
    // buff = 空になってるPETの数

    while (true) {
        // cout << now << "," << ans << "," << buf << endl;

        bool charged = false;
        for (; itr < min(now + K + 1, N); ++itr) {
            if (A[itr] <= A[now]) {
                // itrまでの分の水を買って移動
                // 必要なPETはitr - now個
                // 今K - buf個のPETが埋まっている
                ans += A[now] * ((itr - now) - (K - buf));
                now = itr;
                buf = K;
                ++itr;
                charged = true;
                break;
            }
            que.push(make_pair(A[itr], itr));
        }

        if (charged) continue;

        while (!que.empty() && que.top().second <= now) {
            que.pop();
        }

        // pque(que);

        if (que.empty()) {
            // N - 1で止まっている場合
            ans += A[N - 1];
            break;
        }

        auto p = que.top();
        que.pop();

        // 町Nに着ける場合は移動する
        // 今K - buf個のPETが埋まっている
        if (now + K >= N) {
            ans += A[now] * (N - now - (K - buf));
            break;
        }

        // 買えるだけ水を買い、p.secondへ
        ans += A[now] * buf;
        buf = p.second - now;
        now = p.second;
    }

    cout << ans << endl;
    return 0;
}

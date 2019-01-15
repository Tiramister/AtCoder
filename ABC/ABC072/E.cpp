#include <iostream>
#include <set>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b % MOD;
    if (n % 2 == 0) {
        return mypow(b * b % MOD, n / 2);
    } else {
        return mypow(b, n - 1) * b % MOD;
    }
}

bool linear(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int dx[2] = {b.first - a.first, c.first - a.first};
    int dy[2] = {b.second - a.second, c.second - a.second};

    return dx[0] * dy[1] == dx[1] * dy[0];
}

int main() {
    int N;
    cin >> N;

    pair<int, int> x[N];
    for (int i = 0; i < N; ++i) {
        cin >> x[i].first >> x[i].second;
    }

    set<set<int>> lineset;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            set<int> s = {i, j};

            for (int k = 0; k < N; ++k) {
                if (k == i || k == j) continue;
                if (linear(x[i], x[j], x[k])) s.insert(k);
            }

            lineset.insert(s);
        }
    }

    ll ans = (mypow(2LL, N) - N - 1 + MOD) % MOD;

    for (auto s : lineset) {
        int n = s.size();
        ans += MOD - (mypow(2LL, n) - n - 1);
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}

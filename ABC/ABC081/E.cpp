#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

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

vector<ll> child[200010];

pair<ll, ll> rec(ll v) {
    ll pat = 0, cnt = 1;

    for (ll sv : child[v]) {
        ll p, c;
        tie(p, c) = rec(sv);
        cnt += c;
        pat += p;
    }

    pat *= mypow(2LL, child[v].size());
    pat += mypow(2LL, cnt - 1);
    return make_pair(pat, cnt);
}

int main() {
    ll N;
    cin >> N;

    for (ll v = 1; v <= N; ++v) {
        ll p;
        cin >> p;
        child[p].push_back(v);
    }

    cout << rec(0).first << endl;
    return 0;
}

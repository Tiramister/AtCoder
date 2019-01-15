#include <iostream>

using namespace std;
using ll = long long;

ll a[3010];
pair<ll, ll> dp[3010][3010];
bool visited[3010][3010];

pair<ll, ll> sim(int l, int r) {
    if (r < l) return make_pair(0, 0);
    if (visited[l][r]) return dp[l][r];

    visited[l][r] = true;

    pair<ll, ll> lres = sim(l + 1, r);
    swap(lres.first, lres.second);
    lres.first += a[l];

    dp[l][r] = lres;

    pair<ll, ll> rres = sim(l, r - 1);
    swap(rres.first, rres.second);
    rres.first += a[r];

    if (lres.first - lres.second < rres.first - rres.second) {
        dp[l][r] = rres;
    }

    return dp[l][r];
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    pair<ll, ll> res = sim(0, N - 1);
    cout << res.first - res.second << endl;
    return 0;
}

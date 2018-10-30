#include <iostream>
#include <map>
using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

int main() {
    int N;
    cin >> N;

    ll sum[N + 1];
    sum[0] = 0;
    for (int i = 1; i <= N; ++i) {
        ll A;
        cin >> A;
        sum[i] = sum[i - 1] + A;
    }

    ll fore[N + 1];
    fore[0] = 0;
    // fore[i] = A_1 ~ A_iのたぴさ

    map<ll, ll> app;
    app[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fore[i] = fore[i - 1];
        if (app.find(sum[i]) != app.end()) {
            fore[i] += app[sum[i]];
            ++app[sum[i]];
        } else {
            app[sum[i]] = 1;
        }
    }

    ll back[N + 2];
    back[N + 1] = 0;
    // back[i] = A_i ~ A_Nのたぴさ

    app.clear();
    app[sum[N]] = 1;
    for (int i = N; i >= 1; --i) {
        back[i] = back[i + 1];
        if (app.find(sum[i - 1]) != app.end()) {
            back[i] += app[sum[i - 1]];
            ++app[sum[i - 1]];
        } else {
            app[sum[i - 1]] = 1;
        }
    }

    ll ans = INF;
    for (int i = 1; i <= N; ++i) {
        ans = min(ans, fore[i - 1] + back[i + 1]);
    }

    cout << ans << endl;
    return 0;
}

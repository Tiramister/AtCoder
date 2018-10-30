#include <iostream>
using ll = long long;
using namespace std;

int main() {
    ll N, x;
    cin >> N >> x;

    ll a[N], c[N];
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        c[i] = a[i];
        ans += a[i];
    }

    for (ll t = 1; t < N; ++t) {
        ll cost = t * x;
        for (int i = 0; i < N; ++i) {
            c[i] = min(c[i], a[(i + N - t) % N]);
            cost += c[i];
        }
        ans = min(ans, cost);
    }

    cout << ans << endl;
    return 0;
}

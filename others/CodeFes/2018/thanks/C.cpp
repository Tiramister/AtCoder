#include <algorithm>
#include <iostream>

using namespace std;

using ll = long long;

int main() {
    ll N;
    cin >> N;

    ll x[N];
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }
    sort(x, x + N);

    ll ans = 0, sum = 0;
    for (int i = 0; i < N; ++i) {
        ans += x[i] * i - sum;
        sum += x[i];
    }

    cout << ans << endl;
    return 0;
}

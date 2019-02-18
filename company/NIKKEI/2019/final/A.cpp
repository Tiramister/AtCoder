#include <iostream>

using namespace std;
using ll = long long;

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

    for (int k = 1; k <= N; ++k) {
        ll ans = 0;
        for (int i = 0; i + k <= N; ++i) {
            ans = max(ans, sum[i + k] - sum[i]);
        }
        cout << ans << endl;
    }
    return 0;
}

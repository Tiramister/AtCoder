#include <algorithm>
#include <iostream>

using namespace std;

using ll = long long;

int main() {
    ll N, C, K;
    cin >> N >> C >> K;

    ll T[N];
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }
    sort(T, T + N);

    ll ans = 0;
    ll limit = -1, cap = 0;

    for (int i = 0; i < N; ++i) {
        if (cap == C || T[i] > limit) {
            ++ans;
            limit = T[i] + K;
            cap = 0;
        }
        ++cap;
    }

    cout << ans << endl;
    return 0;
}

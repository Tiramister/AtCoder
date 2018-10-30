#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

using ll = long long;

int main() {
    int N;
    cin >> N;

    ll A[N], B[N];
    ll asum = 0, bsum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
        asum += A[i];
        bsum += B[i];
    }

    ll ans = min(asum, bsum);

    pair<ll, int> w[N * 2];
    for (int i = 0; i < N; ++i) {
        w[i] = make_pair(A[i], i);
    }
    for (int i = 0; i < N; ++i) {
        w[i + N] = make_pair(B[i], i);
    }

    sort(w, w + N * 2);

    int cnt[N];
    fill(cnt, cnt + N, 0);

    ll total = 0;
    for (int i = 0; i < N; ++i) {
        auto p = w[i];
        total += p.first;
        ++cnt[p.second];
    }

    bool judge = false;
    for (int i = 0; i < N; ++i) {
        if (cnt[i] == 2) judge = true;
    }

    if (judge) {
        ans = min(ans, total);
    } else {
        for (int i = 0; i < N; ++i) {
            // A[i]とB[i]を両方選ぶ場合
            auto p = w[N - 1];
            if (p.second == i) p = w[N - 2];
            ans = min(ans, total - p.first + max(A[i], B[i]));
        }
    }

    cout << ans << endl;
    return 0;
}

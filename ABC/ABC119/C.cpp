#include <iostream>
#include <cmath>

using namespace std;

const int INF = 1 << 25;

template <typename T, typename U>
T ipow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b;
    return n % 2 == 0 ? ipow(b * b, n / 2) : ipow(b, n - 1) * b;
}

int main() {
    int N;
    cin >> N;

    int A[3];
    for (int k = 0; k < 3; ++k) cin >> A[k];

    int L[N];
    for (int i = 0; i < N; ++i) cin >> L[i];

    int ans = INF;
    for (int t = 0; t < ipow(4, N); ++t) {
        int l[3] = {0, 0, 0};
        int cnt = 0, used = 0;

        for (int i = 0; i < N; ++i) {
            int k = t / ipow(4, i) % 4;
            if (k == 3) continue;

            ++used;
            if (l[k] == 0) ++cnt;
            l[k] += L[i];
        }

        if (cnt < 3) continue;

        int cost = 0;
        for (int k = 0; k < 3; ++k) {
            cost += abs(A[k] - l[k]);
        }
        ans = min(ans, cost + (used - 3) * 10);
    }

    cout << ans << endl;
    return 0;
}

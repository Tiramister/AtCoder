#include <algorithm>
#include <iostream>

using namespace std;

const int INF = 1 << 30;
// INF >= 10^9

int main() {
    int N, K;
    cin >> N >> K;

    int h[N];
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }
    sort(h, h + N);

    int ans = INF;
    for (int i = 0; i + K - 1 < N; ++i) {
        ans = min(ans, h[i + K - 1] - h[i]);
    }

    cout << ans << endl;
    return 0;
}

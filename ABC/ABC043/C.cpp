#include <iostream>

using namespace std;

const int INF = 1 << 30;

int main() {
    int N;
    cin >> N;

    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int ans = INF;

    for (int y = -100; y <= 100; ++y) {
        int cost = 0;
        // 全要素をyに変える場合のコスト

        for (int i = 0; i < N; ++i) {
            cost += (a[i] - y) * (a[i] - y);
        }

        ans = min(ans, cost);
    }

    cout << ans << endl;
    return 0;
}

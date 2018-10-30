#include <iostream>
using namespace std;
const int INF = 1 << 30;

int main() {
    int N, K;
    cin >> N >> K;

    int x[N];
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }

    int ans = INF;
    for (int i = 0; i < N; ++i) {
        int j = i + K - 1;
        if (j > N - 1) break;

        // 最初にx_iとx_jの近い方に行く
        // その後x_iからx_jへ、あるいはx_jからx_iへ移動する
        ans = min(ans, min(abs(x[i]), abs(x[j])) + x[j] - x[i]);
    }

    cout << ans << endl;
    return 0;
}

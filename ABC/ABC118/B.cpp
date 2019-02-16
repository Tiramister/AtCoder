#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int cnt[M];
    fill(cnt, cnt + M, 0);
    for (int i = 0; i < N; ++i) {
        int K;
        cin >> K;
        for (int j = 0; j < K; ++j) {
            int a;
            cin >> a;
            ++cnt[--a];
        }
    }

    int ans = 0;
    for (int i = 0; i < M; ++i) ans += cnt[i] / N;
    cout << ans << endl;
    return 0;
}

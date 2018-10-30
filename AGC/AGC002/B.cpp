#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int num[N + 1];
    fill(num, num + N + 1, 1);
    // 箱iにはボールがnum[i]個入っている

    bool red[N + 1];
    fill(red, red + N + 1, false);
    red[1] = true;
    // red[i] = 赤いボールが入っている「可能性がある」か

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        if (red[x]) red[y] = true;
        // 赤ボールが移動するかもしれない

        --num[x];
        ++num[y];
        if (num[x] == 0) red[x] = false;
        // 空箱に赤ボールが入っている可能性は0
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (red[i]) ++ans;
    }
    cout << ans << endl;
    return 0;
}

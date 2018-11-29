#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // 降順ソート
    sort(a, a + N, greater<int>());

    int ans = 0;
    for (int i = 0; i < N; i++) {
        // 偶数ならAliceが取るのでplus
        // 奇数ならBobが取るのでminus
        ans += a[i] * (i % 2 == 0 ? 1 : -1);
    }

    cout << ans << endl;
    return 0;
}

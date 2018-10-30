#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int N, x;
    cin >> N >> x;
    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    sort(a, a + N);
    int ans = 0;

    // 少ない子から順に飴を配る
    for (int i = 0; i < N; ++i) {
        if (x >= a[i]) {
            ++ans;
            x -= a[i];
        }
    }

    // 飴が余っていたら1人を犠牲にする
    if (ans == N && x > 0) --ans;

    cout << ans << endl;
    return 0;
}

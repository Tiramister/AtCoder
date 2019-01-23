#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int h[N];
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    int ans = 0;
    // l : h[i] > 0なる最小のi
    for (int l = 0; l < N; ++l) {
        while (h[l] > 0) {
            int r;
            for (r = l + 1; r < N; ++r) {
                if (h[r] == 0) break;
            }
            // 区間[l, r)は全て正
            // この区間に対して水やりをする
            for (int x = l; x < r; ++x) --h[x];
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}

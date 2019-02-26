#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int a[N];
    for (int i = 0; i < N; ++i) cin >> a[i];

    int idx[N];
    iota(idx, idx + N, 0);

    vector<int> ans;
    int pass = -1;
    // 直前の周で最後に選ばれたもの
    // この周では絶対にこの箱には入っていない

    for (int k = 0; k <= K; ++k) {
        sort(idx, idx + N, [&](int i, int j) { return a[i] < a[j]; });

        int last = idx[0];
        if (last == pass) last = idx[1];
        // 残り回数が最も少ないものを最後に選ぶ
        // 2周連続で最後に選ぶことはできない

        for (int i = 0; i < N; ++i) {
            // passには入ってないので開く意味はない
            if (i != pass && i != last) {
                ans.push_back(i + 1);
                --a[i];
            }
        }

        // 最後にlastを開く
        ans.push_back(last + 1);
        --a[last];
        pass = last;
    }

    // 回数超過して開いたものがあればアウト
    if (any_of(a, a + N, [](int v) { return v < 0; })) {
        cout << -1 << endl;
    } else {
        cout << ans.size() << endl;
        for (int x : ans) cout << x << " ";
        cout << endl;
    }
    return 0;
}

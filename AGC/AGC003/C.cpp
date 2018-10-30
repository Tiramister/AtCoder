#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    map<int, int> cnt;
    // 偶数indexに出てくる数と、その回数を記録

    for (int i = 0; i < N; i += 2) {
        if (cnt.find(A[i]) != cnt.end()) {
            ++cnt[A[i]];
        } else {
            cnt[A[i]] = 1;
        }
    }

    sort(A, A + N);

    int ans = 0;
    for (int i = 0; i < N; i += 2) {
        if (cnt.find(A[i]) == cnt.end() || cnt[A[i]] == 0) {
            ++ans;
        } else {
            --cnt[A[i]];
        }
    }

    cout << ans << endl;
    return 0;
}

#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    int a[N + 1], b[N + 1];

    int x = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        x ^= a[i];
    }
    a[N] = x;

    x = 0;
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
        x ^= b[i];
    }
    b[N] = x;

    map<int, int> cnt;
    for (int i = 0; i <= N; ++i) {
        if (cnt.find(a[i]) == cnt.end()) {
            cnt[a[i]] = 1;
        } else {
            ++cnt[a[i]];
        }

        if (cnt.find(b[i]) == cnt.end()) {
            cnt[b[i]] = -1;
        } else {
            --cnt[b[i]];
        }
    }

    for (auto p : cnt) {
        if (p.second != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (a[i] != b[i]) ++ans;
    }

    if (a[N] == b[N] && ans > 0) {
        ++ans;
        for (int i = 0; i < N; ++i) {
            if (a[i] != b[i] && b[i] == a[N]) {
                --ans;
                break;
            }
        }
    }

    cout << (ans == 0 ? 0 : ans) << endl;
    return 0;
}

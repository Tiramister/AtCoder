#include <iostream>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;

    int d[13];
    fill(d, d + 13, 0);
    d[0] = 1;
    for (int i = 0; i < N; ++i) {
        int D;
        cin >> D;
        ++d[D];
    }

    if (d[0] > 1 || d[12] > 1) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i < 12; ++i) {
        if (d[i] > 2) {
            cout << 0 << endl;
            return 0;
        }
    }

    int ans = 0;
    for (int b = 0; b < (1 << 13); ++b) {
        set<int> t;
        for (int i = 0; i < 13; ++i) {
            if (d[i] == 0) continue;
            if (d[i] == 2) {
                t.insert(12 - i);
                t.insert(12 + i);
                continue;
            }
            if ((b >> i) & 1) {
                t.insert(12 + i);
            } else {
                t.insert(12 - i);
            }
        }

        int s = 30;
        int pre = *t.rbegin();
        for (int now : t) {
            s = min(s, (now - pre + 24) % 24);
            pre = now;
        }

        ans = max(ans, s);
    }

    cout << ans << endl;
    return 0;
}

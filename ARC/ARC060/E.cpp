#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    int x[N + 1];
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }

    int L, Q;
    cin >> L >> Q;

    int fore[20][N];
    int back[20][N];
    // fore[d][i] = 2^d日でx_iからどこまで進めるか
    // back[d][i] = 2^d日でx_iからどこまで戻れるか

    for (int i = 0; i < N; ++i) {
        int ok = i, ng = N;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            if (x[mid] - x[i] <= L) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        fore[0][i] = ok;

        ok = i, ng = -1;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;
            if (x[i] - x[mid] <= L) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        back[0][i] = ok;
    }

    for (int d = 1; d < 20; ++d) {
        for (int i = 0; i < N; ++i) {
            fore[d][i] = fore[d - 1][fore[d - 1][i]];
            back[d][i] = back[d - 1][back[d - 1][i]];
        }
    }

    for (int q = 0; q < Q; ++q) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        int ans = 0;
        if (a <= b) {
            while (a < b) {
                if (fore[0][a] >= b) {
                    ++ans;
                    a = fore[0][a];
                    continue;
                }
                for (int d = 19; d >= 0; --d) {
                    if (fore[d][a] >= b) continue;
                    ans += (1 << d);
                    a = fore[d][a];
                    break;
                }
            }
        } else {
            while (a > b) {
                if (back[0][a] <= b) {
                    ++ans;
                    a = back[0][a];
                    continue;
                }
                for (int d = 19; d >= 0; --d) {
                    if (back[d][a] <= b) continue;
                    ans += (1 << d);
                    a = back[d][a];
                    break;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}

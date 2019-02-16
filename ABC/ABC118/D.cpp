#include <iostream>
#include <set>

using namespace std;

const int INF = 1 << 25;
const int c[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
    int N, M;
    cin >> N >> M;

    set<int> a;
    for (int i = 0; i < M; ++i) {
        int b;
        cin >> b;
        a.insert(b);
    }

    int dp[N + 1], rev[N + 1];
    fill(dp, dp + N + 1, -INF);
    dp[0] = -1;
    for (int n = 1; n <= N; ++n) {
        for (int i : a) {
            if (n >= c[i]) {
                int dig = dp[n - c[i]] + 1;
                if (dig >= dp[n]) {
                    dp[n] = dig;
                    rev[n] = i;
                }
            }
        }
    }

    while (N > 0) {
        cout << rev[N];
        N -= c[rev[N]];
    }
    cout << endl;
    return 0;
}

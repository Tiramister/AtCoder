#include <iomanip>
#include <iostream>

using namespace std;

int N;
long double dp[301][301][301];
bool visited[301][301][301];

long double rec(int a, int b, int c) {
    if (visited[a][b][c]) return dp[a][b][c];
    if (a + b + c == 0) return 0;
    visited[a][b][c] = true;

    long double s = a + b + c;
    dp[a][b][c] = N / s;

    if (a > 0) dp[a][b][c] += a / s * rec(a - 1, b, c);
    if (b > 0) dp[a][b][c] += b / s * rec(a + 1, b - 1, c);
    if (c > 0) dp[a][b][c] += c / s * rec(a, b + 1, c - 1);

    return dp[a][b][c];
}

int main() {
    cin >> N;

    int cnt[3] = {0, 0, 0};
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        ++cnt[a - 1];
    }

    cout << fixed << setprecision(10) << rec(cnt[0], cnt[1], cnt[2]) << endl;
    return 0;
}

#include <iomanip>
#include <iostream>

using namespace std;

int N, K;
double dp[1010][1010];
bool visited[1010][1010];

// すでにidx個見て、used個食べている
// かつまだNが出ていないときにNを食べられる最高確率
double rec(int idx, int used) {
    if (idx == N || used == K) return 0;
    if (visited[idx][used]) return dp[idx][used];

    visited[idx][used] = true;

    double isn = 1.0 / (N - idx);
    double notn = 1.0 / (idx + 1) * (1 - isn);
    double notmax = 1 - isn - notn;

    // maxでないので食べないパターン
    double ret = rec(idx + 1, used) * notmax;

    // maxのパターン、食べる食べないでより良い方を選ぶ
    ret += max(isn + notn * rec(idx + 1, used + 1), notn * rec(idx + 1, used));
    return dp[idx][used] = ret;
}

int main() {
    cin >> N >> K;
    cout << fixed << setprecision(10) << rec(0, 0) << endl;
    return 0;
}

#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int main() {
    int N, M;
    cin >> N >> M;

    int A[N + 1], B[M + 1];
    for (int x = 0; x < N; ++x) {
        cin >> A[x];
    }
    A[N] = 0;
    for (int y = 0; y < M; ++y) {
        cin >> B[y];
    }
    B[M] = 0;

    sort(A, A + N + 1, greater<int>());
    sort(B, B + M + 1, greater<int>());

    ll ans = 1;
    int nx = 0, ny = 0;
    for (int v = N * M; v > 0; --v) {
        if (A[nx] == v && B[ny] == v) {
            // vは(nx, ny)に入る
            ++nx, ++ny;
        } else if (A[nx] == v) {
            // vは(nx, 0)~(nx, ny-1)に入る
            ++nx;
            ans *= ny;
            ans %= MOD;
        } else if (B[ny] == v) {
            // vは(0, ny)~(nx-1, ny)に入る
            ++ny;
            ans *= nx;
            ans %= MOD;
        } else {
            // vは(0, 0)~(nx-1, ny-1)に入る
            // すでにN*M-v個埋まっている
            int unfilled = (nx * ny) - (N * M - v);
            ans *= unfilled;
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}

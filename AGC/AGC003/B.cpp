#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    ll A[N + 1];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    A[N] = 0;

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        // i同士のペアを作れるだけ作る
        ans += A[i] / 2;
        A[i] %= 2;

        // iとi+1のペアを作れれば作る
        if (A[i] > 0 && A[i + 1] > 0) {
            ++ans;
            --A[i];
            --A[i + 1];
        }
    }

    cout << ans << endl;
    return 0;
}

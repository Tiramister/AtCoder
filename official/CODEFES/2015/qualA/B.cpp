#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += A[i] * (1 << (N - i - 1));
    }

    cout << ans << endl;
    return 0;
}

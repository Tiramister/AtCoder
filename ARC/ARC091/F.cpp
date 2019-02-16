#include <iostream>

using namespace std;

int grundy(int A, int K) {
    if (A < K) return 0;
    if (A % K == 0) return A / K;

    int dec = A / K + 1;
    A -= ((A % K - 1) / dec + 1) * dec;
    return grundy(A, K);
}

int main() {
    int N;
    cin >> N;

    int x = 0;
    for (int i = 0; i < N; ++i) {
        int A, K;
        cin >> A >> K;
        x ^= grundy(A, K);
    }
    cout << (x == 0 ? "Aoki" : "Takahashi") << endl;
    return 0;
}

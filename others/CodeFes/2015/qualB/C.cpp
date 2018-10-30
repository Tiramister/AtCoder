#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int A[N], B[M];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int j = 0; j < M; ++j) {
        cin >> B[j];
    }

    sort(A, A + N);
    sort(B, B + M);

    int j = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] >= B[j]) ++j;
        if (j == M) break;
    }

    cout << (j == M ? "YES" : "NO") << endl;
    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int A[2], K;
    cin >> A[0] >> A[1] >> K;

    for (int i = 0; i < K; ++i) {
        if (A[i % 2] % 2) --A[i % 2];
        A[i % 2] /= 2;
        A[(i + 1) % 2] += A[i % 2];
    }

    cout << A[0] << " " << A[1] << endl;
    return 0;
}

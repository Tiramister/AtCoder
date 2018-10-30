#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    int D[N];
    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        T -= A;
        D[i] = A - B;
    }

    sort(D, D + N, greater<int>());
    for (int i = 0; i < N; ++i) {
        if (T >= 0) {
            cout << i << endl;
            return 0;
        }
        T += D[i];
    }

    cout << (T >= 0 ? N : -1) << endl;
    return 0;
}

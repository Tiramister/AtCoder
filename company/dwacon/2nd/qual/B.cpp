#include <iostream>

using namespace std;

const int INF = 1 << 30;

int main() {
    int N;
    cin >> N;

    int L[N + 1];
    L[0] = INF;
    for (int i = 1; i < N; ++i) {
        cin >> L[i];
    }
    L[N] = INF;

    for (int i = 0; i < N; ++i) {
        cout << min(L[i], L[i + 1]) << " ";
    }

    cout << endl;
    return 0;
}

#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int N;
    ll P;
    cin >> N >> P;

    ll A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (P == 1 && A[i] == 1) {
            cout << "Yay!" << endl;
            return 0;
        }
    }

    int l = 0;
    ll pro = 1;
    for (int r = 0; r < N; ++r) {
        pro *= A[r];

        while (pro > P) {
            pro /= A[l];
            ++l;
        }

        if (pro == P) {
            cout << "Yay!" << endl;
            return 0;
        }
    }

    cout << ":(" << endl;
    return 0;
}

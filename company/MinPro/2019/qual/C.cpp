#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll K, A, B;
    cin >> K >> A >> B;

    if (K + 1 <= A || B - A <= 2) {
        cout << K + 1 << endl;
        return 0;
    }

    K -= A - 1;
    cout << A + (B - A) * (K / 2) + K % 2 << endl;
    return 0;
}

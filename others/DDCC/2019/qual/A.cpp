#include <iostream>

using namespace std;

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b /* % MOD */;
    if (n % 2 == 0) {
        return mypow(b * b /* % MOD */, n / 2);
    } else {
        return mypow(b, n - 1) * b /* % MOD */;
    }
}

int main() {
    int N;
    cin >> N;
    cout << mypow(4, N) << endl;
    return 0;
}

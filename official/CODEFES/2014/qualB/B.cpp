#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        K -= a;
        if (K <= 0) {
            cout << i << endl;
            return 0;
        }
    }

    terminate();
    return 0;
}

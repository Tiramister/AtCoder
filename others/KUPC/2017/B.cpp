#include <iostream>
using namespace std;

int main() {
    int N, S, T;
    cin >> N >> S >> T;

    for (int i = 0; i < 30; ++i) {
        if ((T >> i) == S) {
            cout << i << endl;
            break;
        } else if ((T >> i) < S) {
            cout << -1 << endl;
            break;
        }
    }
    return 0;
}

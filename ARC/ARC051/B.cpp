#include <iostream>

using namespace std;

int main() {
    int K;
    cin >> K;
    int a = 0, b = 1;
    for (int k = 0; k < K; ++k) {
        int tmp = a + b;
        a = b;
        b = tmp;
    }
    cout << a << " " << b << endl;
    return 0;
}

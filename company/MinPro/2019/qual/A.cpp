#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int M = K * 2 - 1;
    cout << (N >= M ? "YES" : "NO") << endl;
    return 0;
}

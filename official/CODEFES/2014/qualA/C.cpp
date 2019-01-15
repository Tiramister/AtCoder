#include <iostream>

using namespace std;

int uruu(int N) {
    return N / 4 - N / 100 + N / 400;
}

int main() {
    int A, B;
    cin >> A >> B;
    cout << uruu(B) - uruu(A - 1) << endl;
    return 0;
}

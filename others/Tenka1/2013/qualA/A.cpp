#include <iostream>

using namespace std;

int main() {
    int N = 42;
    for (; N <= 130000000; N *= 2) {};
    cout << N << endl;
    return 0;
}

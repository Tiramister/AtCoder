#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = N; i < 1000; ++i) {
        if (i / 100 == (i / 10) % 10 && i / 100 == i % 10) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}

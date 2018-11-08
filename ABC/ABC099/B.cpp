#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int t = b - a - 1;
    cout << t * (t + 1) / 2 - a << endl;
    return 0;
}

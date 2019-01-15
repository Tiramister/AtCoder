#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int h[2];
    for (int i = 0; i < 2; ++i) {
        char c;
        cin >> c >> h[i];
        if (c == 'W') h[i] *= -1;
    }

    cout << abs(h[1] - h[0]) / 15 << endl;
    return 0;
}

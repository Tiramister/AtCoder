#include <iostream>

using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;

    if ((X + Y) % 4 > 0) {
        cout << "No" << endl;
        return 0;
    }

    int t = (X + Y) / 4;
    X -= t;
    Y -= t;
    cout << ((X >= 0 && Y >= 0 && X % 2 == 0) ? "Yes" : "No") << endl;
    return 0;
}

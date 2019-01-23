#include <iostream>

using namespace std;

int main() {
    int s;
    cin >> s;

    int index = 1;
    while (s > 4 || s == 3) {  // !(s == 1 || s == 2 || s == 4) と同値
        s = (s % 2 == 0 ? s / 2 : s * 3 + 1);
        ++index;
    }

    cout << index + 3 << endl;
    return 0;
}

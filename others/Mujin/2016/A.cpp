#include <iostream>
#include <string>

using namespace std;

int main() {
    const string R = "OPKL";
    char c;
    cin >> c;
    for (int i = 0; i < 4; ++i) {
        if (c == R[i]) {
            cout << "Right" << endl;
            return 0;
        }
    }
    cout << "Left" << endl;
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    string X;
    cin >> X;

    int cnt = 0, ans = 0;
    for (char c : X) {
        if (c == 'S') {
            ++cnt;
        } else {
            if (cnt == 0) {
                ++ans;
            } else {
                --cnt;
            }
        }
    }

    cout << ans + cnt << endl;
    return 0;
}

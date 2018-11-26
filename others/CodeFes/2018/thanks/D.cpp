#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    char now = 'z';
    int ans = 0;
    for (char c : S) {
        if (c <= now) {
            ++ans;
            now = c;
        }
    }

    cout << ans << endl;
    return 0;
}

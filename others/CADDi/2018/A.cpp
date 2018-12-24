#include <iostream>
#include <string>

using namespace std;

int main() {
    string N;
    cin >> N;

    int ans = 0;
    for (char c : N) {
        ans += c == '2';
    }

    cout << ans << endl;
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    const string way = "EWSN";
    bool dir[4];
    fill(dir, dir + 4, false);
    for (char c : S) {
        for (int i = 0; i < 4; ++i) {
            if (c == way[i]) dir[i] = true;
        }
    }

    if (dir[0] == dir[1] && dir[2] == dir[3]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

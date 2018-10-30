#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;
    for (char c : S) {
        cout << '9' - c + 1;
    }
    cout << endl;
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;
    for (char c : S) {
        cout << c << c;
    }
    cout << endl;
    return 0;
}

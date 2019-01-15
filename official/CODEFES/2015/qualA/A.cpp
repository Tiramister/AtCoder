#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;
    S.back() = '5';
    cout << S << endl;
    return 0;
}

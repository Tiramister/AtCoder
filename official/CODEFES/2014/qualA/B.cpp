#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    int B;
    cin >> S >> B;
    cout << S[(B - 1) % S.length()] << endl;
    return 0;
}

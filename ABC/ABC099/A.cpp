#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    cout << "AB" << (N < 1000 ? 'C' : 'D') << endl;
    return 0;
}

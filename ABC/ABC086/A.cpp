#include <cmath>
#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a * b % 2) {
        cout << "Odd";
    } else {
        cout << "Even";
    }
    return 0;
}

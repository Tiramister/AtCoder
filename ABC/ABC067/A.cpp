#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    A %= 3;
    B %= 3;
    if (A * B == 0 || (A + B) % 3 == 0) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}

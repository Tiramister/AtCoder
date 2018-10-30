#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll edge[3];
    bool even = false;
    for (int i = 0; i < 3; ++i) {
        cin >> edge[i];
        if (edge[i] % 2 == 0) even = true;
    }
    sort(edge, edge + 3);
    cout << (even ? 0 : edge[0] * edge[1]) << endl;
    return 0;
}

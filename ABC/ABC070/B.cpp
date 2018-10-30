#include <iostream>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int ans;
    if (B < C || D < A) {
        ans = 0;
    } else if (A <= C && D <= B) {
        ans = D - C;
    } else if (C <= A && B <= D) {
        ans = B - A;
    } else {
        ans = min(B - C, D - A);
    }

    cout << ans << endl;
}

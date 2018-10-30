#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int K, S;
int cnt = 0;

int main()
{
    cin >> K >> S;
    for (int X = 0; X <= K; X++) {
        // cout << X << ":";
        if (S - X > K * 2) {
            // cout << 0 << endl;
        } else if (S - X > K) {
            cnt += 2 * K - S + X + 1;
            // cout << 2 * K - S + X + 1 << endl;
        } else if (S - X >= 0) {
            cnt += S - X + 1;
            // cout << S - X + 1 << endl;
        } else {
            // cout << 0 << endl;
        }
    }

    cout << cnt << endl;
    return 0;
}

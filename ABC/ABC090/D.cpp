#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N, K, b;
ll cnt = 0;

int main()
{
    cin >> N >> K;
    for (int b = K + 1; b <= N; b++) {
        if (N % b == b - 1) {
            cnt += (b - K) * ((N + 1) / b - 1);
        } else {
            cnt += (b - K) * ((N + 1) / b);
        }
        cnt += max(N % b - K + (K > 0), 0);
        // cout << b << " " << cnt << endl;
    }

    cout << cnt << endl;
    return 0;
}

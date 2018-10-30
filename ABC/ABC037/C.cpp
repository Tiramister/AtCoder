#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;
int K, N;
vector<ll> a;
int times;
ll sum = 0;

int main()
{
    cin >> N >> K;
    a.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    if (K > N / 2) {
        K = N - K + 1;
    }

    if (N % 2 > 0) {
        for (int i = 0; i < N / 2; i++) {
            times = min(i + 1, K);
            sum += (a[i] + a[N - i - 1]) * times;
        }
        sum += a[(N - 1) / 2] * min((N + 1) / 2, K);
    } else {
        for (int i = 0; i < N / 2; i++) {
            times = min(i + 1, K);
            sum += (a[i] + a[N - i - 1]) * times;
        }
    }

    cout << sum << endl;
    return 0;
}

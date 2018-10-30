#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N, sum;
vector<int> a;

int main()
{
    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < N; i++) {
        if (i % 2 > 0) {
            sum -= a[N - i - 1];
        } else {
            sum += a[N - i - 1];
        }
    }

    cout << sum << endl;
    return 0;
}

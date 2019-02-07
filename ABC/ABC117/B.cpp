#include <iostream>
#include <numeric>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    int l[n];
    for (int i = 0; i < n; ++i) cin >> l[i];
    sort(l, l + n);

    // l[0]~l[n-2]の総和
    int sum = accumulate(l, l + n - 1, 0);
    cout << (sum > l[n - 1] ? "Yes" : "No") << endl;
    return 0;
}

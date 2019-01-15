#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N;
int add1 = 0;
int buff2 = 0;

int main()
{
    cin >> N;
    ll a[N], b[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
        if (a[i] < b[i]) {
            buff2 += (b[i] - a[i]) / 2;
        } else {
            add1 += a[i] - b[i];
        }
    }

    if (add1 <= buff2) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}

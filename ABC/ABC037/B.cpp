#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N, Q;
int L, R, T;
vector<int> a;

int main()
{
    cin >> N >> Q;
    vector<int> a(N, 0);

    for (int i = 0; i < Q; i++) {
        cin >> L >> R >> T;
        for (L; L <= R; L++) {
            a[L - 1] = T;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << a[i] << endl;
    }
    return 0;
}

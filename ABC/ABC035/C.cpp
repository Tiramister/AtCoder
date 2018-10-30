#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N, Q;
vector<int> S, l, r;

int main()
{
    cin >> N >> Q;
    S.resize(N + 2);
    l.resize(Q + 1);
    r.resize(Q);

    for (int i = 0; i < Q; i++) {
        cin >> l[i] >> r[i];
        r[i]++;
    }
    l[Q] = N + 1;

    l.insert(l.end(), r.begin(), r.end());
    sort(l.begin(), l.end());

    for (int i = 0; i < 2 * Q; i++) {
        for (int j = l[i]; j < l[i + 1]; j++) {
            S[j] = (i + 1) % 2;
        }
    }

    for (size_t i = 1; i <= N; i++) {
        cout << S[i];
    }
    cout << endl;
    return 0;
}

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int X, Y;
size_t N, M;
vector<int> a, b;
size_t pa = 0;
size_t pb = 0;
int now = 0;
int cnt = 0;

bool fly(int p)
{
    switch (p) {
    case 0:
        for (; pa < N; pa++) {
            if (a[pa] >= now) {
                now = a[pa] + X;
                // cout << "take a : " << a[pa] << " - " << now << endl;
                cnt++;
                return true;
            }
        }
        break;

    case 1:
        for (; pb < M; pb++) {
            if (b[pb] >= now) {
                now = b[pb] + Y;
                // cout << "take b : " << b[pb] << " - " << now << endl;
                cnt++;
                return true;
            }
        }
        break;
    }
    return false;
}

int main()
{
    cin >> N >> M >> X >> Y;
    a.resize(N);
    b.resize(M);

    for (size_t i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (size_t j = 0; j < M; j++) {
        cin >> b[j];
    }

    while (true) {
        if (fly(0)) {
            if (fly(1)) {
                continue;
            }
        }
        break;
    }

    cout << cnt / 2 << endl;
    return 0;
}

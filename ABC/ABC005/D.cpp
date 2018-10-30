#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

size_t N, Q;
vector<vector<int>> D;
vector<vector<int>> D_sub(100, vector<int>(100, 0));
vector<int> P;
vector<int> D_max(10000, 0);

void solve()
{
    D_sub.resize(N + 1);
    D_sub[0].resize(N + 1);
    for (size_t i = 1; i <= N; i++) {
        D_sub[i].resize(N + 1);
        for (size_t j = 1; j <= N; j++) {
            D_sub[i][j] = D[i][j] + D_sub[i - 1][j] + D_sub[i][j - 1] - D_sub[i - 1][j - 1];
        }
    }

    for (size_t i1 = 0; i1 < N; i1++) {
        for (size_t j1 = 0; j1 < N; j1++) {
            for (size_t i2 = i1 + 1; i2 <= N; i2++) {
                for (size_t j2 = j1 + 1; j2 <= N; j2++) {
                    size_t area = (j2 - j1) * (i2 - i1);
                    int D_part = D_sub[i2][j2] - D_sub[i2][j1] - D_sub[i1][j2] + D_sub[i1][j1];
                    D_max[area] = max(D_max[area], D_part);
                }
            }
        }
    }

    for (size_t k = 2; k <= N * N; k++) {
        for (size_t l = 1; l < k; l++) {
            if (D_max[k] < D_max[l]) {
                D_max[k] = D_max[l];
            }
        }
    }
}

int main()
{
    cin >> N;
    D.resize(N + 1);
    for (size_t i = 1; i <= N; i++) {
        D[i].resize(N + 1);
        for (size_t j = 1; j <= N; j++) {
            cin >> D[i][j];
        }
    }

    solve();

    cin >> Q;
    P.resize(Q);
    for (size_t i = 0; i < Q; i++) {
        cin >> P[i];
    }

    for (size_t i = 0; i < Q; i++) {
        cout << D_max[P[i]] << endl;
    }
    return 0;
}

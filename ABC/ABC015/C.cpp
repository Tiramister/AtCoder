#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N, K;
vector<vector<int>> T;

bool bug_find(int value, int d)
{
    if (d < N) {
        for (int j = 0; j < K; j++) {
            if (bug_find(value ^ T[d][j], d + 1)) {
                return true;
                break;
            }
        }
        return false;
    } else {
        if (value == 0) {
            return true;
        } else {
            return false;
        }
    }
}

int main()
{
    cin >> N >> K;
    T.resize(N);
    for (size_t i = 0; i < N; i++) {
        T[i].resize(K);
        for (size_t j = 0; j < K; j++) {
            cin >> T[i][j];
        }
    }

    cout << (bug_find(0, 0) ? "Found" : "Nothing") << endl;

    return 0;
}

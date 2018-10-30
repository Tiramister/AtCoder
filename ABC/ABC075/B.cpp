#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

size_t H, W;
char mine = '#';
vector<vector<char>> S;
vector<vector<int>> a;

bool inarea(int k, int l)
{
    return (k >= 0 && k < H && l >= 0 && l < W);
}

void calc(int i, int j)
{
    for (int k = i - 1; k <= i + 1; k++) {
        for (int l = j - 1; l <= j + 1; l++) {
            if (inarea(k, l) && !(i == k && j == l)) {
                if (S[k][l] == mine) {
                    a[i][j]++;
                }
            }
        }
    }
}


int main()
{
    cin >> H >> W;
    S.resize(H);
    a.resize(H);
    for (size_t i = 0; i < H; i++) {
        S[i].resize(W);
        a[i].resize(W);
        for (size_t j = 0; j < W; j++) {
            cin >> S[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                a[i][j] = -1;
            } else {
                a[i][j] = 0;
                calc(i, j);
            }
        }
    }

    for (size_t i = 0; i < H; i++) {
        for (size_t j = 0; j < W; j++) {
            if (a[i][j] < 0) {
                cout << '#';
            } else {
                cout << a[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}

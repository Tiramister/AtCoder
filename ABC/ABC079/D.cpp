#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int INF = 10000;
int H, W;
int c[10][10];
int d[10];
bool used[10];
int sum = 0;

int min_d()
{
    int min_num = -1;
    int min = INF;
    for (int i = 0; i <= 9; i++) {
        if (!used[i] && d[i] < min) {
            min_num = i;
            min = d[min_num];
        }
    }
    return min_num;
}


int main()
{
    cin >> H >> W;
    int A[H + 1][W + 1];

    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            cin >> c[i][j];
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i <= 9; i++) {
        d[i] = INF;
        used[i] = false;
    }
    d[1] = 0;

    while (true) {
        int to = min_d();

        if (to < 0) {
            break;
        }

        used[to] = true;

        for (int i = 0; i <= 9; i++) {
            if (!used[i]) {
                d[i] = min(d[i], c[i][to] + d[to]);
            }
        }
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (A[i][j] >= 0) {
                sum += d[A[i][j]];
            }
        }
    }

    cout << sum << endl;
    return 0;
}

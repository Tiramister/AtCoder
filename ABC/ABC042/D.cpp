#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const ll modulo = 1e9 + 7;

size_t H, W, A, B;
vector<vector<int>> route;

int main()
{
    cin >> H >> W >> A >> B;
    route.resize(H + 1);
    for (size_t i = 1; i <= H; i++) {
        for (size_t j = 1; j <= W; j++) {
            route[i].resize(W + 1);

            if (i > H - A && j <= B) {
                route[i][j] = 0;
            } else if (i == 1 || j == 1) {
                route[i][j] = 1;
            } else {
                route[i][j] = route[i - 1][j] + route[i][j - 1] % modulo;
            }
        }
    }

    /*
    for (size_t i = 1; i <= H; i++) {
        for (size_t j = 1; j <= W; j++) {
            cout << route[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << route[H][W] << endl;
    return 0;
}

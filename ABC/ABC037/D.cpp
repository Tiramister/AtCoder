#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const int modulo = 1e9 + 7;
int H, W;
vector<vector<ll>> a, route;
ll route_sum;

struct map {
    int c;
    int r;
};

int dr[4]
    = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

map now = {0, 0};

int mysearch(int r, int c);
bool noedge(int r, int c);

int main()
{
    cin >> H >> W;
    a.resize(H);
    route.resize(H);
    for (int r = 0; r < H; r++) {
        a[r].resize(W);
        route[r].resize(W);
        for (int c = 0; c < W; c++) {
            cin >> a[r][c];
            route[r][c] = -1;
        }
    }

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            mysearch(r, c);
        }
    }

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            route_sum += route[r][c];
        }
    }

    cout << route_sum % modulo << endl;

    return 0;
}


int mysearch(int r, int c)
{
    if (route[r][c] >= 0) {
        return route[r][c];
    } else if (!noedge(r, c)) {
        return 0;
    } else {
        route[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            if (noedge(r + dr[i], c + dc[i]) && (a[r + dr[i]][c + dc[i]] > a[r][c])) {
                route[r][c] += mysearch(r + dr[i], c + dc[i]);
            }
        }
        route[r][c] %= modulo;
        return route[r][c];
    }
}

bool noedge(int r, int c)
{
    return r >= 0 && r < H && c >= 0 && c < W;
}

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

vector<string> pic, pre;
const char white = '.';
const char black = '#';
int H, W;
int di[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dj[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};


bool noedge(int i, int j)
{
    if (i < 0 || i >= H || j < 0 || j >= W) {
        return false;
    }
    return true;
}


bool isblack(int i, int j)
{
    for (size_t k = 0; k < 9; k++) {
        if (noedge(i + di[k], j + dj[k])) {
            if (pre[i + di[k]][j + dj[k]] == black) {
                return true;
            }
        }
    }
    return false;
}


void make_pre()
{
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {

            if (pic[i][j] == white) {
                for (size_t k = 0; k < 9; k++) {
                    if (noedge(i + di[k], j + dj[k])) {
                        pre[i + di[k]][j + dj[k]] = white;
                    }
                }
            }
        }
    }

    /*
    for (size_t i = 0; i < H; i++) {
        cout << pre[i] << endl;
    }
    */
}


bool match_pic()
{
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (pic[i][j] == '#') {
                if (!isblack(i, j)) {
                    return false;
                }
            }
        }
    }
    return true;
}


int main()
{
    cin >> H >> W;
    pic.resize(H);
    pre.resize(H);
    string bline(W, '#');
    for (size_t i = 0; i < H; i++) {
        cin >> pic[i];
        pre[i] = bline;
    }

    make_pre();

    if (match_pic()) {
        cout << "possible" << endl;
        for (size_t i = 0; i < H; i++) {
            cout << pre[i] << endl;
        }
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}

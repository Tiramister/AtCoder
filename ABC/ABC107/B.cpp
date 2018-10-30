#include <iostream>
#include <set>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    string a[H];
    for (int i = 0; i < H; ++i) {
        cin >> a[i];
    }

    set<int> x, y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (a[i][j] == '#') {
                x.insert(i);
                y.insert(j);
            }
        }
    }

    for (int i : x) {
        for (int j : y) {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}

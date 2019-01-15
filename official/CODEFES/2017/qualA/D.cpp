#include <iostream>
#include <string>
using namespace std;

int main() {
    int H, W, d;
    cin >> H >> W >> d;

    string color = "RGBY";
    for (int x = 0; x < H; ++x) {
        for (int y = 0; y < W; ++y) {
            int u = x + y, v = x - y + 100000 * d;
            int kind = 0;
            kind += (u % (d * 2)) / d;
            kind += (v % (d * 2)) / d * 2;

            cout << color[kind];
        }
        cout << endl;
    }

    return 0;
}

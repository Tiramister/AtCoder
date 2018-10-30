#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;
int A[100][100];
vector<int> X, Y;
vector<int> H;

struct place {
    int x;
    int y;
};

place max_num()
{
    place max = {0, 0};
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            if (A[y][x] > A[max.y][max.x]) {
                max = {x, y};
            }
        }
    }

    return max;
}

void calc(place max_place)
{
    int max_value = min(100, A[max_place.y][max_place.x]);

    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            A[y][x] -= max(0, max_value - abs(max_place.x - x) - abs(max_place.y - y));
        }
    }
}

int main()
{
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            cin >> A[y][x];
        }
    }

    int Q;

    for (Q = 0; Q <= 1000; Q++) {

        place max = max_num();

        if (A[max.y][max.x] < 1) {
            break;
        }

        X.push_back(max.x);
        Y.push_back(max.y);
        H.push_back(min(100, A[max.y][max.x]));

        calc(max);
    }

    cout << Q << endl;

    for (int i = 0; i < Q; i++) {
        cout << X[i] << " " << Y[i] << " " << H[i] << endl;
    }

    return 0;
}

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N;
bool exs[4] = {false, false, false, false};
char S;
char color[4] = {'P', 'W', 'G', 'Y'};

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        for (size_t j = 0; j < 4; j++) {
            if (S == color[j]) {
                exs[j] = true;
            }
        }
    }

    int color_num = 0;
    for (size_t i = 0; i < 4; i++) {
        if (exs[i]) {
            color_num++;
        }
    }

    cout << (color_num == 3 ? "Three" : "Four") << endl;

    return 0;
}

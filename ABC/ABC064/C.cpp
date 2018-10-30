#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N, a;
bool colors[8];
int free_colors = 0;

void color_judge(int a)
{
    for (int i = 1; i <= 8; i++) {
        if (a < i * 400) {
            colors[i - 1] = true;
            return;
        }
    }
    free_colors++;
    return;
}

int count_colors()
{
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        cnt += colors[i];
    }
    return cnt;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        color_judge(a);
    }

    cout << max(count_colors(), 1) << " " << count_colors() + free_colors << endl;
    return 0;
}

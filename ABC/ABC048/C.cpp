#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N, x;
vector<int> a;
ll times = 0;

void eat_candy(int i);

int main()
{
    cin >> N >> x;
    a.resize(N + 1);
    a[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        eat_candy(i);
    }

    cout << times << endl;

    return 0;
}

void eat_candy(int i)
{
    if (a[i - 1] + a[i] > x) {
        times += a[i - 1] + a[i] - x;
        a[i] = x - a[i - 1];
    }
}

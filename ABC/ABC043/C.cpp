#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const int INF = 1e7;
size_t N;
int cost_min = INF;
vector<int> a;

int calc_cost(int b)
{
    int cost = 0;
    for (size_t i = 0; i < N; i++) {
        cost += (a[i] - b) * (a[i] - b);
    }
    return cost;
}

int main()
{
    cin >> N;
    a.resize(N);

    for (size_t i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int b = -100; b <= 100; b++) {
        cost_min = min(cost_min, calc_cost(b));
    }

    cout << cost_min << endl;

    return 0;
}

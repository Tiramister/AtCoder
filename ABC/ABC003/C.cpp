#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

size_t N;
int K;
vector<double> R;
double max_rate = 0;

bool calc_rate(int& cnt, double& rate, size_t& point);

int main()
{
    cin >> N >> K;
    R.resize(N);
    for (size_t i = 0; i < N; i++) {
        cin >> R[i];
    }
    sort(R.begin(), R.end());

    for (size_t i = 0; i < N; i++) {
        double rate = 0;
        int cnt = 0;
        size_t point = i;
        while (calc_rate(cnt, rate, point))
            ;

        if (rate > max_rate) {
            max_rate = rate;
        }
    }

    cout << setprecision(10) << max_rate << endl;
    return 0;
}

bool calc_rate(int& cnt, double& rate, size_t& point)
{
    if (cnt >= K) {
        return false;
    }

    while (R[point] < rate && point < N) {
        point++;
    }
    if (point >= N) {
        return false;
    } else {
        rate = (rate + R[point]) / 2;
        cnt++;
        point++;
        return true;
    }
}

#include <iomanip>
#include <iostream>

using namespace std;

long double pro[3000][3000];

int main() {
    int N;
    cin >> N;

    pro[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        long double p;
        cin >> p;

        for (int j = 0; j < N; ++j) {
            pro[i][j + 1] += pro[i - 1][j] * p;
            pro[i][j] += pro[i - 1][j] * (1 - p);
        }
    }

    long double ans = 0;
    for (int i = N; i > N - i; --i) {
        ans += pro[N][i];
    }

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}

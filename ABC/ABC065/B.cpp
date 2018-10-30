#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N;
vector<int> a;
vector<bool> pushed;
int INF = 1e7;

int check(int i)
{
    if (i == 2) {
        return 0;
    } else if (!pushed[i]) {
        pushed[i] = true;
        return check(a[i]) + 1;
    } else {
        return -1e7;
    }
}

int main()
{
    cin >> N;
    a.resize(N + 1);
    pushed.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        pushed[i] = false;
    }

    cout << max(check(1), -1) << endl;

    return 0;
}

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N, A;
int bug_sum = 0;
int bug_files = 0;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A;
        if (A > 0) {
            bug_sum += A;
            bug_files++;
        }
    }

    cout << (bug_sum - 1) / bug_files + 1 << endl;
    return 0;
}

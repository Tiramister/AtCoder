#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main()
{
    int N;
    cin >> N;

    int max_div = 0;
    int max_num = 0;

    for (int i = 1; i <= N; i++) {
        int n = i;
        int div = 0;
        while (n % 2 == 0) {
            n /= 2;
            div++;
        }
        if (max_div <= div) {
            max_num = i;
            max_div = div;
        }
    }
    cout << max_num << endl;
    return 0;
}

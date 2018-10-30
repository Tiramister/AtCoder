#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;
int N, A, B;
int sum = 0;

int digit_sum(int i)
{
    int s = 0;

    while (i > 0) {
        s += i % 10;
        i /= 10;
    }

    return s;
}

int main()
{
    cin >> N >> A >> B;

    for (int i = 1; i <= N; i++) {
        int s = digit_sum(i);
        if (s >= A && s <= B) {
            sum += i;
        }
    }

    cout << sum << endl;

    return 0;
}

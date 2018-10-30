#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

string S;
char c;
int cnt = 0;

int main()
{
    cin >> S;
    c = S[0];
    for (char s : S) {
        if (c != s) {
            cnt++;
            c = s;
        }
    }
    cout << cnt << endl;
    return 0;
}

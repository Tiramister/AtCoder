#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

string S, T;
string sub("atcoder@");

bool substable(char d);

int main()
{
    cin >> S >> T;
    for (size_t i = 0; i < S.length(); i++) {
        if (S[i] == T[i]) {
            continue;
        } else if (S[i] == '@') {
            if (substable(T[i])) {
                continue;
            }
        } else if (T[i] == '@') {
            if (substable(S[i])) {
                continue;
            }
        }

        cout << "You will lose" << endl;
        return 0;
    }

    cout << "You can win" << endl;
    return 0;
}

bool substable(char d)
{
    for (char c : sub) {
        if (c == d) {
            return true;
        }
    }
    return false;
}

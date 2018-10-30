#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

string S_, T;
vector<string> S;

bool match(string s)
{
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] != '?' && s[i] != T[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> S_ >> T;
    if (S_.size() < T.size()) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    for (size_t i = 0; i <= S_.size() - T.size(); i++) {
        string S_sub = S_.substr(i, T.size());
        if (match(S_sub)) {

            string S_ans(S_.size(), 'a');
            for (size_t j = 0; j < S_ans.size(); j++) {
                if (j >= i && j < i + T.size()) {
                    S_ans[j] = T[j - i];
                } else {
                    if (S_[j] != '?') {
                        S_ans[j] = S_[j];
                    }
                }
            }
            S.push_back(S_ans);
        }
    }

    if (S.empty()) {
        cout << "UNRESTORABLE" << endl;
    } else {
        sort(S.begin(), S.end());
        cout << S.front() << endl;
    }
    return 0;
}

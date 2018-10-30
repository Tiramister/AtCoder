#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

string s;
size_t k;
vector<string> ans;

void search(string sp)
{
    for (size_t j = 0; j < ans.size(); j++) {
        if (sp == ans[j]) {
            return;
        }
    }
    ans.push_back(sp);
}

int main()
{
    cin >> s >> k;
    if (s.size() < k) {
        cout << 0 << endl;
        return 0;
    }

    for (size_t i = 0; i <= s.size() - k; i++) {
        search(s.substr(i, k));
    }

    cout << ans.size() << endl;
    return 0;
}

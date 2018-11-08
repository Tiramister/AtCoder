#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    set<string> ans;
    for (int i = 1; i <= 1000; ++i) {
        ans.insert(to_string(i));
    }

    for (string s : ans) {
        cout << s << endl;
    }
    return 0;
}

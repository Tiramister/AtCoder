#include <iostream>
#include <string>

using namespace std;

int s2i(string S) {
    int h = stoi(S.substr(0, 2));
    int m = stoi(S.substr(2, 2));
    return h * 60 + m;
}

string i2s(int t) {
    string h = to_string(t / 60);
    if (h.size() < 2) h = "0" + h;

    string m = to_string(t % 60);
    if (m.size() < 2) m = "0" + m;

    return h + m;
}

int main() {
    int N;
    cin >> N;

    int imos[2000];
    fill(imos, imos + 2000, 0);

    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        int b = s2i(S.substr(0, 4));
        int e = s2i(S.substr(5, 4));
        ++imos[b / 5 * 5];
        --imos[(e + 4) / 5 * 5];
    }

    for (int t = 1; t < 2000; ++t) {
        imos[t] += imos[t - 1];
    }

    bool rain = false;
    for (int t = 0; t < 2000; ++t) {
        if (!rain && imos[t] > 0) {
            cout << i2s(t) << "-";
            rain = true;
        } else if (rain && imos[t] == 0) {
            cout << i2s(t) << endl;
            rain = false;
        }
    }
    return 0;
}

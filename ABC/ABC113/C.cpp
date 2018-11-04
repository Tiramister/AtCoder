#include <algorithm>
#include <iomanip>
#include <iostream>
#include <tuple>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    tuple<int, int, int> data[M];
    // (Y_i, P_i, i)の配列

    for (int i = 0; i < M; ++i) {
        int p, y;
        cin >> p >> y;
        data[i] = make_tuple(y, p, i);
    }

    // tupleをソートするときは第一要素がkeyとなる
    sort(data, data + M);

    int cnt[N + 1];
    fill(cnt, cnt + N + 1, 0);
    // 各県について、今属している市の数

    pair<int, int> id[M];
    // 各市の(属する県、県の中で誕生した順番)

    for (int i = 0; i < M; ++i) {
        int y, p, idx;
        tie(y, p, idx) = data[i];
        ++cnt[p];
        id[idx] = make_pair(p, cnt[p]);
    }

    for (int i = 0; i < M; ++i) {
        // setwで文字数、setfillで埋める文字を指定
        // iomanipをincludeする必要があるので注意
        cout << setw(6) << setfill('0') << id[i].first;
        cout << setw(6) << setfill('0') << id[i].second << endl;
    }
    return 0;
}

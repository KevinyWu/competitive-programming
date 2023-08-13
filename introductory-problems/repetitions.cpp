#include <iostream>
#define ll long long
using namespace std;


void solve() {
    string s; cin >> s;
    char c = ' ';
    int cur_len = 0, max_len = 0;
    for (char i : s) {
        if (i != c) {
            c = i;
            max_len = max(max_len, cur_len);
            cur_len = 0;
        }
        cur_len++;
    }
    max_len = max(max_len, cur_len);
    cout << max_len << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
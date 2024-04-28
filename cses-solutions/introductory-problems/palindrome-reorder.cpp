#include <iostream>
#include <string>
#define ll long long
using namespace std;


void solve() {
    string s; cin >> s;
    int freq[26] = {0};
    for (char c : s) {
        freq[c - 'A']++;
    }
    string half = "";
    string odd = "";
    for (int i = 0; i < 26; i++) {
        if (freq[i]%2 == 1) {
            if (odd == "") {
                odd = string(freq[i], 'A' + i);
            }
            else {
                cout << "NO SOLUTION\n";
                return;
            }
        }
        else {
            half += string(freq[i]/2, 'A' + i);
        }
    }
    string rev = half;
    reverse(half.begin(), half.end());
    cout << half + odd + rev << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
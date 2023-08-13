#include <iostream>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    int N = pow(2, n);
    vector<string> graycode(N);
    // add to the rightmost digits the pattern 0 1 0 1 0 1 ...
    // then add to the second rightmost digits the pattern 0 0 1 1 0 0 1 1 ...
    // (we do some swapping for the CSES judge)
    for (int i = 1; i <= n; ++i) {
        int step = pow(2, n-i+1);
        // we need zero_first for the CSES judge, which does not accept "any valid solution"
        bool zero_first = true;
        for (int j = 0; j < N; j += step) {
            for (int k = j; k < j + step / 2; ++k) {
                if (zero_first) {
                    graycode[k] += '0';
                } else {
                    graycode[k] += '1';
                }
            }
            for (int k = j + step / 2; k < j + step; ++k) {
                if (zero_first) {
                    graycode[k] += '1';
                } else {
                    graycode[k] += '0';
                }
            }
            zero_first = !zero_first;
        }
    }
    for (const string& s: graycode) {
        cout << s << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // dp[i] is the minimum ending element of a subsequence length i
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        auto x = lower_bound(dp.begin(), dp.end(), a[i]);
        if (x == dp.end()) {
            dp.push_back(a[i]);
        }
        else {
            *x = a[i];
        }
    }
    cout << dp.size() << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
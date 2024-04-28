#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    int n, x; cin >> n >> x;
    int a[n];
    // dp[i] is the minimum amount of coins needed to reach sum i
    vector<int> dp(x + 1, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= x) {
            dp[a[i]] = 1;
        }
    }
    for (int i = 1; i <= x; i++) {
        for (int c : a) {
            if (i > c && dp[i - c] != -1) {
                if (dp[i] == -1) {
                    dp[i] = dp[i - c] + 1;
                }
                else {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }
    }
    cout << dp[x] << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
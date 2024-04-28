#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    string sn, sm; cin >> sn >> sm;
    int n = sn.length(), m = sm.length();
    // dp[i][j] is the edit distance between the first i chars of n and first j chars of m
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (j == 0 || i == 0) {
                dp[i][j] = max(i, j);
                continue;
            }
            dp[i][j] = min(dp[i-1][j-1] + (sn[i-1] != sm[j-1]), min(dp[i-1][j] + 1, dp[i][j-1] + 1));
        }
    }
    cout << dp[n][m] << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
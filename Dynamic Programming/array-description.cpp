#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    int n, m; cin >> n >> m;
    ll a[n+1], MOD = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // dp[i][j] the number of ways to fill an array of the first i elements 
    // such that the last element is j
    // pad with zeros to avoid dp[i][j-1] and dp[i][j+1] being out of index
    vector<vector<ll>> dp(n+1, vector<ll>(m+2, 0));
    for (int i = 1; i <= n; i++) {
        // if the space is already filled, we only consider j = a[i];
        if (a[i] > 0) {
            if (i == 1) {
                dp[i][a[i]] = 1;
            }
            else {
                dp[i][a[i]] = dp[i-1][a[i]-1] + dp[i-1][a[i]] + dp[i-1][a[i]+1];
                dp[i][a[i]] %= MOD;
            }
            continue;
        }
        for (int j = 1; j <= m; j++) {
            // for the first element, there is 1 way for each j
            if (i == 1) {
                dp[i][j] = 1;
            }
            // otherwise consider all last elements of the first i-1 elements within 1 of j
            else {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
        }
    }
    // sum the answer
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dp[n][i];
        ans %= MOD;
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
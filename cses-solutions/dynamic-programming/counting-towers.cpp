#include <iostream>
#define ll long long
using namespace std;


void solve() {
    int t; cin >> t;
    int a[t], mx = 0;
    for (int i = 0; i < t; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int MOD = 1e9 + 7;
    // dp[i][0] is ways to make a tower with height i with a 2-wide last block
    // dp[i][1] is ways to make a tower with height i with two 1-wide last blocks
    ll dp[mx+1][2];
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= mx; i++) {
        // go through the 6 possibilities of the added layer: 
        // 1. 2-wide block, independent
        // 2. 2-wide block, connected
        // 3. 2 1-wide blocks, both independent
        // 4. 2 1-wide blocks, both connected
        // 5. 2 1-wide blocks, left independent, right connected
        // 6. 2 1-wide blocks, left connected, right independent
        ll two_wide = 2 * dp[i-1][0] +  dp[i-1][1]; 
        ll one_wide = dp[i-1][0] + 4 * dp[i-1][1];
        dp[i][0] = two_wide % MOD;
        dp[i][1] = one_wide % MOD;
    }
    for (int i = 0; i < t; i++) {
        int ans = (dp[a[i]][0] + dp[a[i]][1]) % MOD;
        cout << ans << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    ll n; cin >> n;
    int sum = (n * (n + 1)) / 2, MOD = 1e9 + 7;
    if (sum % 2 == 1) {
        cout << 0 << '\n';
        return;
    }
    int target = sum / 2;
    // dp[i][j] is number of ways to get j when using 1,2,...i
    // do this for i up to n-1; let n always be in the second set to avoid overcounting
    // do this for j up to sum/2 so our answer is dp[n-1][sum/2]
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n - 1; i++) {;
        for (int j = 0; j <= target; j++) {
            // either use or don't use i
            dp[i][j] = dp[i-1][j];
            if (j - i >= 0) {
                dp[i][j] += dp[i-1][j-i];
            }
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n-1][target] << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
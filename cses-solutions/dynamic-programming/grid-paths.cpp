#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    char a[n+1][n+1];
    int MOD = 1e9 + 7;
    // dp[i][j] is number of paths to (i,j)
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    dp[1][1] = (a[1][1] != '*');
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == '*' || (i == 1 && j == 1)) {
                continue;
            }
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n][n] << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    int a, b; cin >> a >> b;
    int c = max(a, b);
    // dp[i][j] is the number of ways to split an i x j rectangle into squares
    vector<vector<int>> dp(c+1, vector<int>(c+1, 1e9));
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            // square case
            if (j == i) {
                dp[i][j] = 0;
                continue;
            }
            // horizontal split
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
            }
            // vertical split
            for (int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k] + 1);
            }
            // answers are symmetric
            dp[j][i] = dp[i][j];
        }
    }
    cout << dp[a][b] << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
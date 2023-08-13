#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    int n, x; cin >> n >> x;
    int prices[n+1], pages[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> prices[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> pages[i];
    }
    // dp[i][j] maximum  pages you get with the first i books spending up to j dollars
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) { 
            // you can always choose to not buy the ith book
            dp[i][j] = dp[i - 1][j];
            // if you have enough money j, consider buying the ith book
            if (prices[i] <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - prices[i]] + pages[i]);
            }
        }
    }
    cout << dp[n][x] << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
#include <iostream>
#include <set>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    int a[n+1], sum = 0;
    for (int i = 1; i <=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    // dp[i][j] is true if you can make sum j with the first i coins
    set<int> ans;
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = true;
        for (int j = 1; j <= sum; ++j) {
            // either use or don't use the ith coin
            dp[i][j] = (dp[i-1][j] || (a[i] <= j && dp[i-1][j-a[i]]));
            if (dp[i][j]) {
                ans.insert(j);
            }
        }
    }
    cout << ans.size() << '\n';
    for (int i : ans) {
        cout << i << ' ';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
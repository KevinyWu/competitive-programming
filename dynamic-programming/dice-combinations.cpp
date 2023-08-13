#include <iostream>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    int dp[n+1], MOD = 1e9 + 7;
    dp[1] = 1;
    for (int i = 2; i <=n; ++i) {
        dp[i] = 0;
        if (i <= 6) {
            dp[i]++;
        }
        for (int j = 1; j <= min(6, i - 1); j++) {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
    }
    cout << dp[n] << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
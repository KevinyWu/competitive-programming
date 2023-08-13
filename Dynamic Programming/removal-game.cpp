#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    ll a[n+1], sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    // dp[l][r] is maximum of diff = score1 - score2 
    // if the game is played on interval (l, r)
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    for (int l = n; l >= 1; l--) {
        for (int r = l; r <= n; r++) {
            if (r == l) {
                dp[l][r] = a[l];
            }
            else {
                // player 1 either takes l or r
                // then player 2 goes first on the smaller game (l+1, r) or (l, r-1)
                dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
            }
        }
    }
    //sum = score1 + score2, so (sum + diff) / 2 = score1
    cout << (sum + dp[1][n]) / 2 << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
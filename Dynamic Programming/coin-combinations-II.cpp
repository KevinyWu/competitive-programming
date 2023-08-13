#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    int n, x; cin >> n >> x;
    int a[n], MOD = 1e9 + 7;
    // dp[i] is the number of ways you can reach sum i
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // this time, loop through coins first so all arrangements are unique
    for (int c : a) {
        for (int i = 1; i <= x; i++) {
            if (i >= c) {
                dp[i] += dp[i - c];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[x] << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
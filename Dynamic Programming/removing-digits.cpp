#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    // dp[i] is the minimum steps starting at i
    vector<int> dp(n + 1, 1e6);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int ten = 1;
        // loop through the digits
        while (i / ten > 0) {
            int num = (i / ten) % 10;
            dp[i] = min(1 + dp[i - num], dp[i]);
            ten *= 10;
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
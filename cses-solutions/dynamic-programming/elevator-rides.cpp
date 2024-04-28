#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    int n, x; cin >> n >> x;
    int w[n];
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    // Store all sets of people that can be taken in the elevator
    // dp[s] = {min number of rides, min weight of last ride} for people in set s
    // Set s is represented as bits, where the pth bit is 1 if the pth person is in the set
    vector<pair<int, int>> dp(1 << n);
    dp[0] = {1, 0}; // Empty set
    for (int s = 1; s < (1 << n); s++) {
        dp[s] = {n+1, 0}; // Max n+1 rides
        // Iterate through the options of people in the set to be the last to enter
        for (int p = 0; p < n; p++) {
            if (s & (1 << p)) { // If p is in the set
                auto [rides, last] = dp[s ^ (1 << p)]; // Remove p from the set
                if (last + w[p] <= x) { // If p can be added to the last ride
                    last += w[p];
                } 
                else { // If p cannot be added to the last ride
                    rides++;
                    last = w[p];
                }
                dp[s] = min(dp[s], {rides, last});
            }
        }
    }
    cout << dp[(1 << n) - 1].first << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
#include <iostream>
#include <vector>
#define ll long long
using namespace std;
 
 
void solve() {
    int n; cin >> n;
    vector<int> b(n);
    // store pairs as (b, a) for easy sorting by earliest end time
    vector<pair<int, pair<int, int>>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].second.first >> p[i].first >> p[i].second.second;
        b[i] = p[i].first;
    }
    sort(p.begin(), p.end());
    sort(b.begin(), b.end());

    // dp[i] = max value of projects by the ith end time
    vector<ll> dp(n, 0);
    dp[0] = p[0].second.second;
    for (int i = 1; i < n; i++) {
        int start = p[i].second.first, val = p[i].second.second;
        // low is the latest end time less than the current start time
        int low = lower_bound(b.begin(), b.end(), start) - b.begin() - 1;
        ll prev = 0;
        if (low != -1) {
            prev = dp[low];
        }
        dp[i] = max(dp[i-1], val + prev);
    }
    cout << dp[n-1] << '\n';
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
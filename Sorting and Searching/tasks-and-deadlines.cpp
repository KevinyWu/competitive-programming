#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    // perform tasks by shortest duration
    // note that given this order, swapping two task yields lower reward
    sort(v.begin(), v.end());
    ll total_time = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        total_time += v[i].first;
        ans += v[i].second - total_time;
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
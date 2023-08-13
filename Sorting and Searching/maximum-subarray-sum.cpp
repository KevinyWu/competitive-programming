#include <iostream>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    ll a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // pref[i] is the maximum subarray sum for subarrays ending at i
    ll pref[n + 1];
    pref[0] = 0;
    ll ans = a[0];
    for (int i = 0; i < n; ++i) {
        // we can either add element i to the subarray or start a new subarray
        pref[i + 1] = max(a[i], pref[i] + a[i]);
        ans = max(pref[i + 1], ans);
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
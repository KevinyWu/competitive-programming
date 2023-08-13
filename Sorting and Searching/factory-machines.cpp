#include <iostream>
#define ll long long
using namespace std;


void solve() {
    int n, t; cin >> n >> t;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // binary search over the answer
    ll l = 0, r = 1e18, ans = 1e18;
    while (l < r) {
        ll mid = (l + r) / 2;
        ll products = 0;
        for (ll k : a) {
            products += mid / k;
            if (products >= t) {
                r = mid;
                ans = min(ans, mid);
                break;
            }
        }
        if (products < t) {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
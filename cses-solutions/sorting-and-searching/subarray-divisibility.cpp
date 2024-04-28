#include <iostream>
#include <map>
#define ll long long
using namespace std;


void solve() {
    ll n; cin >> n;
    ll a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<ll, ll> pref;
    pref[0] = 1;
    // store prefix sums mod n
    ll ans = 0, cursum_modn = 0;
    for (int i = 0; i < n; i++) {
        cursum_modn += a[i];
        cursum_modn %= n;
        if (cursum_modn < 0) {
            cursum_modn += n;
        }
        // if there are prefix subarrays that are equivalent to cursum_modn (mod n)
        // we can remove those prefixes and obtain a 0 mod 5 subarray
        ans += pref[cursum_modn];
        pref[cursum_modn]++;
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
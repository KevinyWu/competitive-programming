#include <iostream>
#include <map>
#define ll long long
using namespace std;


void solve() {
    int n, x; cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<ll, int> pref;
    pref[0] = 1;
    // store prefix sums
    ll ans = 0, cursum = 0;
    for (int i = 0; i < n; i++) {
        cursum += a[i];
        // if there are prefix subarrays with sum cursum - x
        // we can remove those prefixes from the current sum and obtain x
        ans += pref[cursum - x];
        pref[cursum]++;
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
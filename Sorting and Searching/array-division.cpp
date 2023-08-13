#include <iostream>
#include <map>
#define ll long long
using namespace std;


void solve() {
    int n, k; cin >> n >> k;
    ll a[n], sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    // binary search over the answer
    ll l = sum/k, r = sum, ans = r;
    while (l < r) {
        ll mid = (l + r) / 2;
        ll cursum = 0, subarrays_needed = 0;
        bool good = true;
        for (int i = 0; i < n; i++) {
            // take elements until the current subarray has sum greater than mid
            if (cursum + a[i] > mid) {
                subarrays_needed++;
                cursum = 0;
                // if a single element is greater than mid, we cannot proceed
                if (a[i] > mid) {
                    good = false;
                    break;
                }
            }
            cursum += a[i];
        }
        if (subarrays_needed + 1 <= k && cursum <= mid && good) {
            ans = mid;
            r = mid;
        }
        else {
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
#include <iostream>
#define ll long long
using namespace std;


void solve() {
    int n, x; cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // use two pointers, move the right pointer as long as the current sum under x
    // otherwise move the left sum
    int ans = 0, cursum = a[0];
    int l = 0, r = 0;
    while (l <= r) {
        if (cursum == x) {
            ans++;
            r++;
            if (r == n) {
                break;
            }
            cursum += a[r] - a[l];
            l++;
        }
        else if (cursum < x) {
            r++;
            if (r == n) {
                break;
            }
            cursum += a[r];
        }
        else {
            if (r == l) {
                r++;
                l++;
                if (r == n) {
                    break;
                }
                cursum = a[r];
            }
            else {
                cursum -= a[l];
                l++;
            }
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